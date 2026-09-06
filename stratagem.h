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

#ifndef STRATAGEM_H
#define STRATAGEM_H

#include <Arduino.h>
#include <BleKeyboard.h>
#include <icons.h>

// 1. Structure definition
struct Stratagem {
    const char* name;
    int type;       
    int category;   
    uint32_t cd;    
    uint8_t macro[10]; 
    int len;
    const uint16_t* icon;
};

// 2. Constants and extern declarations
extern const int TOTAL_STRATAGEMS;
extern const char* catNames[];
extern Stratagem library[];

#endif 
