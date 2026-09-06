#ifndef STRATAGEM_H
#define STRATAGEM_H

#include <Arduino.h>
#include <BleKeyboard.h>
#include <icons.h> // Ensure icon definitions are available here

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