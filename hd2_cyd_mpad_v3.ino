/*
 * Helldivers 2 BLE Macro Pad
 * Copyright (C) 2026 Leo Beauchamp
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <https://www.gnu.org/licenses/>.
 */

#include <BleKeyboard.h>
#include <SPI.h>
#define LGFX_USE_V1
#include <LovyanGFX.hpp>
#include <XPT2046_Touchscreen.h> 
#include <Preferences.h>        
#include <icons.h> // Icons in RGB565le
#include "stratagem.h"



class LGFX_CYD : public lgfx::LGFX_Device {
    lgfx::Panel_ST7789  _panel_instance; lgfx::Bus_SPI _bus_instance;
public:
    LGFX_CYD() {
        {
            auto cfg = _bus_instance.config();
            cfg.spi_host = VSPI_HOST; cfg.spi_mode = 0;
            cfg.freq_write = 40000000; cfg.freq_read = 16000000;
            cfg.pin_sclk = 14; cfg.pin_mosi = 13; cfg.pin_miso = 12; cfg.pin_dc = 2;
            _bus_instance.config(cfg); _panel_instance.setBus(&_bus_instance);
        }
        {
            auto cfg = _panel_instance.config();
            cfg.pin_cs = 15; cfg.pin_rst = -1;
            cfg.panel_width = 240; cfg.panel_height = 320; cfg.offset_x = 0; cfg.offset_y = 0;
            _panel_instance.config(cfg);
        }
        setPanel(&_panel_instance);
    }
};

LGFX_CYD lcd;
XPT2046_Touchscreen ts(33, 36); 
BleKeyboard bleKeyboard("HELLDIVER-PAD", "Super Earth", 100);
Preferences prefs;
SPIClass touchSPI(VSPI);

#define TS_MINX 200
#define TS_MAXX 3850
#define TS_MINY 200
#define TS_MAXY 3750

uint32_t COL_RED, COL_BLUE, COL_GREEN, COL_YELLOW;
uint32_t COL_DARK_RED, COL_DARK_BLUE, COL_DARK_GREEN, COL_DARK_YELLOW;

int currentScreen = 0; int selectedSlot = 0; int currentCategory = 0; int menuPage = 0;
int activeSlots[12];
unsigned long activatedTimestamps[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int lastDisplayedSeconds[] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};

unsigned long lastScreenChangeTime = 0;

bool touchActive = false;
unsigned long touchStartTime = 0;
int touchStartX = 0;
int touchStartY = 0;

// Global rotation variable (1 or 3)
int screenRotation = 3;




// Function to apply orientation to Display and Touch hardware
void setDisplayRotation(int rot) {
    screenRotation = rot;
    lcd.setRotation(screenRotation);
    ts.setRotation(screenRotation);
    prefs.putInt("rotation", screenRotation);
}

uint32_t getStratColor(int index, bool darkened) {
    if (library[index].type == 0) return darkened ? COL_DARK_RED : COL_RED;
    if (library[index].type == 1) return darkened ? COL_DARK_BLUE : COL_BLUE;
    if (library[index].type == 2) return darkened ? COL_DARK_GREEN : COL_GREEN;
    return darkened ? COL_DARK_YELLOW : COL_YELLOW;
}

void drawBluetoothIcon(int x, int y, bool connected) {
    uint16_t color = connected ? lcd.color888(30, 140, 255) : lcd.color888(90, 90, 90);
    lcd.drawLine(x, y, x, y + 10, color);
    lcd.drawLine(x, y, x + 3, y + 3, color);
    lcd.drawLine(x + 3, y + 3, x - 3, y + 7, color);
    lcd.drawLine(x - 3, y + 7, x + 3, y + 7, color);
    lcd.drawLine(x + 3, y + 7, x, y + 10, color);
}

void drawTwoLineString(const char* text, int centerX, int centerY) {
    lcd.setTextSize(1); String str = String(text); int firstSpace = str.indexOf(' ');
    if (firstSpace == -1) { lcd.drawCentreString(text, centerX, centerY - 4); return; }
    int lastSpace = str.lastIndexOf(' '); int midPoint = str.length() / 2;
    int bestSpace = (abs(firstSpace - midPoint) < abs(lastSpace - midPoint)) ? firstSpace : lastSpace;
    String line1 = str.substring(0, bestSpace); String line2 = str.substring(bestSpace + 1);
    lcd.drawCentreString(line1.c_str(), centerX, centerY - 10); lcd.drawCentreString(line2.c_str(), centerX, centerY + 2);
}

void drawStratagemIcon(int centerX, int centerY, const uint16_t* iconData, float scale = 1.3f) {
    if (iconData == nullptr) return; 

    // Create a temporary 32x32 sprite to hold the raw RGB565 data
    LGFX_Sprite iconSprite(&lcd);
    iconSprite.setColorDepth(16);
    iconSprite.createSprite(32, 32);
    iconSprite.pushImage(0, 0, 32, 32, iconData);

    // Render the sprite centered at (centerX, centerY) scaled up
    // pushRotateZoom(x, y, angle, scale_x, scale_y)
    iconSprite.pushRotateZoom(centerX, centerY, 0, scale, scale);

    iconSprite.deleteSprite();
}

void updateTimersOverlay() {
    unsigned long currentMillis = millis();
    bool statusLink = bleKeyboard.isConnected();
    drawBluetoothIcon(6, 4, statusLink);

    for (int i = 0; i < 12; i++) {
        int col = i % 4; int row = i / 4; int xPos = col * 80; int yPos = row * 80;
        unsigned long targetCD = library[activeSlots[i]].cd * 1000;
        bool isCooling = (activatedTimestamps[i] != 0 && (currentMillis - activatedTimestamps[i] < targetCD));
        
        if (isCooling) {
            int remSeconds = (targetCD - (currentMillis - activatedTimestamps[i])) / 1000;
            if (remSeconds != lastDisplayedSeconds[i]) {
                lastDisplayedSeconds[i] = remSeconds;
                
                lcd.fillRect(xPos + 1, yPos + 1, 78, 78, getStratColor(activeSlots[i], true));
                lcd.setTextColor(TFT_WHITE); 
                
                // Draw 1.3x icon on darkened background
                drawStratagemIcon(xPos + 40, yPos + 24, library[activeSlots[i]].icon, 1.3f);
                
                // Countdown timer text at the bottom
                lcd.setTextSize(2); 
                char tBuf[8]; 
                sprintf(tBuf, "%ds", remSeconds);
                lcd.drawCentreString(tBuf, xPos + 40, yPos + 54);
            }
        } else {
            if (lastDisplayedSeconds[i] != -1) {
                lastDisplayedSeconds[i] = -1;
                
                lcd.fillRect(xPos + 1, yPos + 1, 78, 78, getStratColor(activeSlots[i], false));
                lcd.setTextColor(TFT_WHITE); 
                
                // Restore 1.3x icon and original two-line string
                drawStratagemIcon(xPos + 40, yPos + 24, library[activeSlots[i]].icon, 1.3f);
                drawTwoLineString(library[activeSlots[i]].name, xPos + 40, yPos + 58);
            }
        }
    }
}

void drawMainUI() {
    lcd.fillScreen(TFT_BLACK);
    for (int i = 0; i < 12; i++) {
        int col = i % 4; int row = i / 4; int xPos = col * 80; int yPos = row * 80;
        lastDisplayedSeconds[i] = -1;
        lcd.fillRect(xPos + 1, yPos + 1, 78, 78, getStratColor(activeSlots[i], false));
        lcd.setTextColor(TFT_WHITE);
        
        // Scaled up icon (1.3x) centered slightly higher
        drawStratagemIcon(xPos + 40, yPos + 24, library[activeSlots[i]].icon, 1.3f);
        
        drawTwoLineString(library[activeSlots[i]].name, xPos + 40, yPos + 58);
    }
    drawBluetoothIcon(6, 4, bleKeyboard.isConnected());
}

void drawCategoryUI() {
    lcd.fillScreen(TFT_BLACK); lcd.setTextColor(TFT_WHITE); lcd.setTextSize(1);
    char head[48]; sprintf(head, "SLOT %d CATEGORY SELECTION", selectedSlot + 1); lcd.drawString(head, 24, 6);
    for (int i = 0; i < 8; i++) {
        int col = i % 2; int row = i / 2; int xPos = 10 + (col * 155); int yPos = 24 + (row * 46);
        uint32_t fCol = (i < 2) ? COL_RED : (i < 5) ? COL_BLUE : (i < 7) ? COL_GREEN : COL_YELLOW;
        lcd.fillRect(xPos, yPos, 145, 40, fCol); lcd.drawCentreString(catNames[i], xPos + 72, yPos + 16);
    }
    lcd.fillRect(10, 212, 300, 22, TFT_DARKGRAY); 
    lcd.setTextSize(2); 
    lcd.drawCentreString("CANCEL", 160, 215);
}

void drawSettingsUI() {
    lcd.fillScreen(TFT_BLACK); lcd.setTextColor(TFT_WHITE); lcd.setTextSize(1);
    lcd.fillRect(0, 0, 70, 22, TFT_DARKGRAY); lcd.drawCentreString("< BACK", 35, 5);
    int fIndices[TOTAL_STRATAGEMS]; int fCount = 0;
    for (int i = 0; i < TOTAL_STRATAGEMS; i++) { if (library[i].category == currentCategory) fIndices[fCount++] = i; }
    int maxPages = (fCount + 7) / 8;
    char title[48]; sprintf(title, "SELECT STRATAGEM - PG %d/%d", menuPage + 1, maxPages); lcd.drawString(title, 82, 5);
    lcd.fillRect(250, 0, 70, 22, TFT_DARKGRAY); lcd.drawCentreString("NEXT >", 285, 5);

    int startIndex = menuPage * 8; 
    for (int i = 0; i < 8; i++) {
        int targetIdx = startIndex + i; if (targetIdx >= fCount) break;
        int realIdx = fIndices[targetIdx];
        int col = i % 2; int row = i / 2; int xPos = 10 + (col * 155); int yPos = 28 + (row * 44); 
        lcd.fillRect(xPos, yPos, 145, 38, getStratColor(realIdx, false));
        
        // Draw 32x32 icon offset to the left
        drawStratagemIcon(xPos + 22, yPos + 19, library[realIdx].icon, 1.2f);
        
        // Shift text right to fit next to icon
        drawTwoLineString(library[realIdx].name, xPos + 88, yPos + 19);
    }

    lcd.setTextColor(TFT_LIGHTGREY);
    lcd.setTextSize(2);
    lcd.drawCentreString("<---SWIPE--->", 160, 220);
}

void sendStratagem(const uint8_t inputs[], int length) {
    if (!bleKeyboard.isConnected()) return;

    bleKeyboard.press(KEY_LEFT_CTRL);
    delay(120);

    for (int i = 0; i < length; i++) {
        bleKeyboard.press(inputs[i]);
        delay(75 + random(0, 5));
        bleKeyboard.release(inputs[i]);
        delay(75 + random(0, 5));
    }

    bleKeyboard.release(KEY_LEFT_CTRL);
    delay(30);
    bleKeyboard.releaseAll();
}

void setup() {
    Serial.begin(115200); pinMode(21, OUTPUT); digitalWrite(21, HIGH); 
    lcd.init();
    
    COL_RED = lcd.color888(235, 30, 30); COL_BLUE = lcd.color888(30, 100, 235); COL_GREEN = lcd.color888(30, 210, 30); COL_YELLOW = lcd.color888(235, 200, 10);
    COL_DARK_RED = lcd.color888(55, 6, 6); COL_DARK_BLUE = lcd.color888(6, 18, 55); COL_DARK_GREEN = lcd.color888(6, 45, 6); COL_DARK_YELLOW = lcd.color888(50, 42, 2);
    
    prefs.begin("hd2_macro", false);
    screenRotation = prefs.getInt("rotation", 3);
    
    int defaultLayout[] = {76, 74, 18, 11, 12, 7, 30, 24, 66, 67, 52, 53}; 
    for (int i = 0; i < 12; i++) { 
        char key[8]; sprintf(key, "s%d", i); 
        activeSlots[i] = prefs.getInt(key, defaultLayout[i]); 
    }
    
    touchSPI.begin(25, 39, 32, 33); 
    ts.begin(touchSPI); 
    setDisplayRotation(screenRotation);
    
    drawMainUI(); 
    bleKeyboard.begin();
}

void redrawCurrentScreen() {
    if (currentScreen == 0) drawMainUI();
    else if (currentScreen == 1) drawCategoryUI();
    else if (currentScreen == 2) drawSettingsUI();
}

void loop() {
    static unsigned long lastOverlayUpdate = 0; static bool lastBleState = false;
    if (currentScreen == 0 && (millis() - lastOverlayUpdate >= 200 || bleKeyboard.isConnected() != lastBleState)) { 
        lastBleState = bleKeyboard.isConnected(); updateTimersOverlay(); lastOverlayUpdate = millis(); 
    }
    
    if (ts.touched()) {
        TS_Point rawPt = ts.getPoint();
        int x = map(rawPt.x, TS_MINX, TS_MAXX, 0, 320); int y = map(rawPt.y, TS_MINY, TS_MAXY, 0, 240);
        if (!touchActive) { touchActive = true; touchStartTime = millis(); touchStartX = x; touchStartY = y; }
        
        if (currentScreen == 0 && touchActive && (millis() - touchStartTime > 700) && (millis() - lastScreenChangeTime > 350)) {
            int col = touchStartX / 80; int row = touchStartY / 80; 
            selectedSlot = (row * 4) + col; currentScreen = 1; lastScreenChangeTime = millis(); drawCategoryUI();
            touchActive = false; while(ts.touched()) { delay(10); } return;
        }
        delay(10);
    } else {
        if (touchActive) {
            touchActive = false; unsigned long duration = millis() - touchStartTime;
            TS_Point releasePt = ts.getPoint(); 
            int releaseX = map(releasePt.x, TS_MINX, TS_MAXX, 0, 320);
            int releaseY = map(releasePt.y, TS_MINY, TS_MAXY, 0, 240);
            
            if (millis() - lastScreenChangeTime < 350) return;

            int swipeDistanceX = releaseX - touchStartX;
            int swipeDistanceY = releaseY - touchStartY;

            // Detect Upward Swipe (minimum 60px distance up) to flip orientation 180 degrees
            if (swipeDistanceY < -60 && abs(swipeDistanceX) < 40) {
                int newRot = (screenRotation == 3) ? 1 : 3;
                setDisplayRotation(newRot);
                lastScreenChangeTime = millis();
                redrawCurrentScreen();
                return;
            }

            // Horizontal Swiping on Stratagem Selection Screen
            if (currentScreen == 2 && abs(swipeDistanceX) > 60) {
                int fCount = 0; for (int i = 0; i < TOTAL_STRATAGEMS; i++) { if (library[i].category == currentCategory) fCount++; }
                int maxPages = (fCount + 7) / 8;
                if (swipeDistanceX < -60) { if (menuPage < maxPages - 1) { menuPage++; drawSettingsUI(); } } 
                else if (swipeDistanceX > 60) { if (menuPage > 0) { menuPage--; drawSettingsUI(); } else { currentScreen = 1; lastScreenChangeTime = millis(); drawCategoryUI(); } }
                return;
            }

            int x = touchStartX; int y = touchStartY;
            if (currentScreen == 0 && duration <= 700) {
                int col = x / 80; int row = y / 80; int slot = (row * 4) + col; 
                if(slot >= 0 && slot < 12) { activatedTimestamps[slot] = millis(); sendStratagem(library[activeSlots[slot]].macro, library[activeSlots[slot]].len); drawMainUI(); }
            } 
            else if (currentScreen == 1) {
                if (y >= 212) { currentScreen = 0; lastScreenChangeTime = millis(); drawMainUI(); return; }
                int cCol = (x - 10) / 155; int cRow = (y - 24) / 46;
                if (cCol >= 0 && cCol < 2 && cRow >= 0 && cRow < 4) { currentCategory = (cRow * 2) + cCol; menuPage = 0; currentScreen = 2; lastScreenChangeTime = millis(); drawSettingsUI(); }
            } 
            else if (currentScreen == 2) {
                int fIndices[TOTAL_STRATAGEMS]; int fCount = 0;
                for (int i = 0; i < TOTAL_STRATAGEMS; i++) { if (library[i].category == currentCategory) fIndices[fCount++] = i; }
                if (y <= 24) {
                    if (x <= 70) { if (menuPage > 0) { menuPage--; drawSettingsUI(); } else { currentScreen = 1; lastScreenChangeTime = millis(); drawCategoryUI(); } } 
                    else if (x >= 250) { int maxPages = (fCount + 7) / 8; if (menuPage < maxPages - 1) { menuPage++; drawSettingsUI(); } }
                    return;
                }
                int cCol = (x - 10) / 155; int cRow = (y - 28) / 44;
                if (cCol >= 0 && cCol < 2 && cRow >= 0 && cRow < 4) {
                    int gridIdx = (cRow * 2) + cCol; int targetIdx = (menuPage * 8) + gridIdx;
                    if (targetIdx < fCount) {
                        activeSlots[selectedSlot] = fIndices[targetIdx]; activatedTimestamps[selectedSlot] = 0;
                        char key[8]; sprintf(key, "s%d", selectedSlot); prefs.putInt(key, fIndices[targetIdx]);
                        currentScreen = 0; lastScreenChangeTime = millis(); drawMainUI(); return;
                    }
                }
            }
        }
    }
}
