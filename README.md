# 🎮 Helldivers 2 BLE Macro Pad (CYD / ESP32)

An interactive, touch-screen Bluetooth macro pad built for **Helldivers 2** using the Cheap Yellow Display (CYD / ESP32-2432S028). Features dynamic stratagem selection, cooldown timer overlays, custom RGB565 icons, non-volatile memory for key assignments, and swipe gestures.

If a Helldivers 2 Macro pad sounds a bit cheaty and un-democratic, plus the bots (AI) did help me get this all working - so it might not be for everyone, but if it's useful to you, then enjoy!

---

## 🛠️ Hardware Requirements

* **ESP32-2432S028** (Known as the **Cheap Yellow Display / CYD**)
* Micro-USB or USB-C cable (depending on your board version) for power and flashing (on my CYD I have both Micro-USB and USB-C, but could only flash with the Micro-USB).

---

## 📦 Software Dependencies

Before uploading the sketch, ensure you have the **Arduino IDE** installed alongside the following core libraries:

1. **ESP32 Board Package** (v2.x or v3.x)
2. **[ESP32-BLE-Keyboard](https://github.com/T-vK/ESP32-BLE-Keyboard)** (For Bluetooth HID capabilities)
3. **[LovyanGFX](https://github.com/lovyan03/LovyanGFX)** (For high-performance display driver management)
4. **[XPT2046_Touchscreen](https://github.com/PaulStoffregen/XPT2046_Touchscreen)** (For touch inputs)
5. **Preferences** (Included with the core ESP32 package for NVS storage)

---

## ⚙️ In-Game Configuration (Helldivers 2)

For the macro pad to successfully input stratagem codes, you must adjust your keybinds in Helldivers 2:

1. Open **Helldivers 2** → **Options** → **Controller / Keyboard & Mouse** → **Change Bindings**.
2. Set **Open Stratagem List** to `Left Control` (or ensure `Left Control` triggers the stratagem menu).
3. Set **Stratagem Inputs (Up, Down, Left, Right)** to the **Arrow Keys**:

---

## 🚀 Installation & Setup

1. **Clone or Download the Repository:**

2. Open the Project:
   Open the main .ino file in Arduino IDE. Ensure all project files (stratagem.h, stratagem.cpp, icons.h) are located in the same sketch folder.

3. Configure Board Settings in Arduino IDE:
   * Board: ESP32 Dev Module (or ESP32-WROOM-32)
   * Flash Size: 4MB (32Mb)
   * Partition Scheme: Huge APP (3MB No OTA / 1MB SPIFFS) 
   * Upload Speed: 115200 

4. Upload: Connect your CYD board via USB and click Upload.

---

## 📲 How to Connect & Use

1. Pairing via Bluetooth:
   * Power on the device.
   * Open Bluetooth & other devices on your PC.
   * Search for new devices and pair with HELLDIVER-PAD.

2. Touch Controls & Gestures:
   * Tap Slot: Sends the assigned stratagem macro instantly and starts the visual cooldown timer (The timer is set to the base cooldown - so might not match your ship module upgrades).
   * Long-Press Slot (~0.7s): Opens the Category Selection screen to assign a new stratagem to that slot (saved automatically to internal storage).
   * Horizontal Swipe (Left / Right): Pages through stratagems on the selection menu.
   * Upward Swipe: Rotates the display and touch grid 180 degrees (saved automatically to internal storage).

---

## 📄 License

This project is licensed under the GNU General Public License v3.0 (GPLv3) - see the LICENSE file for details. 

You are free to use, study, share, and modify this software, provided that any derivative works or distributed modified versions remain open-source under the same GPLv3 license.
   



