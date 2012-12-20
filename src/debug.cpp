/*
 *  debug.cpp
 *  Timelapse+
 *
 *  Created by Elijah Parker
 *  Copyright 2012 Timelapse+
 *  Licensed under GPLv3
 *
 */
 
#include "VirtualSerial.h"
#include "debug.h"
#include "timelapseplus.h"
#include "tlp_menu_functions.h"
#include "settings.h"

extern settings conf;

/******************************************************************
 *
 *   debug
 *
 *
 ******************************************************************/

void debug(char c)
{
    if(conf.devMode == 0) return;
    VirtualSerial_PutChar(c);
}

/******************************************************************
 *
 *   debug
 *
 *
 ******************************************************************/

void debug(uint8_t c)
{
    if(conf.devMode == 0) return;
    char buf[5];
    
    int_to_str((uint16_t)c, buf);
    VirtualSerial_PutString(buf);
}

/******************************************************************
 *
 *   debug
 *
 *
 ******************************************************************/

void debug(uint16_t n)
{
    if(conf.devMode == 0) return;
    char buf[6];

    int_to_str(n, buf);
    VirtualSerial_PutString(buf);
}

/******************************************************************
 *
 *   debug
 *
 *
 ******************************************************************/

void debug(uint32_t n)
{
    if(conf.devMode == 0) return;

    uint8_t i = 0;
    char buf[10];
    while(n)
    {
        buf[i] = (char)(n % 10) + '0';
        n -= n % 10;
        n /= 10;
        i++;
    }
    while(i--) VirtualSerial_PutChar(buf[i - 1]);
}

/******************************************************************
 *
 *   debug
 *
 *
 ******************************************************************/

void debug(char *s)
{
    if(conf.devMode == 0) return;
    VirtualSerial_PutString(s);
}

/******************************************************************
 *
 *   debug
 *
 *
 ******************************************************************/

void debug_nl()
{
    if(conf.devMode == 0) return;
    VirtualSerial_PutChar('\r');
    VirtualSerial_PutChar('\n');
}
