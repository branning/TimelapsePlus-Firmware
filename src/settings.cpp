/*
 *  settings.cpp
 *  Timelapse+
 *
 *  Created by Elijah Parker
 *  Copyright 2012 Timelapse+
 *  Licensed under GPLv3
 *
 */
 
#include <avr/eeprom.h>
#include <string.h>
#include "settings.h"
#include "5110LCD.h"
#include "IR.h"
#include "shutter.h"
#include "remote.h"
#include "timelapseplus.h"
#include "tlp_menu_functions.h"

settings conf_eep EEMEM;
volatile settings conf;

extern LCD lcd;
extern IR ir;
extern Remote remote;
extern shutter timer;

/******************************************************************
 *
 *   settings_save
 *
 *
 ******************************************************************/

void settings_save()
{
    eeprom_write_block((const void*)&conf, &conf_eep, sizeof(settings));
}

/******************************************************************
 *
 *   settings_load
 *
 *
 ******************************************************************/

void settings_load()
{
    eeprom_read_block((void*)&conf, &conf_eep, sizeof(settings));
    lcd.color(conf.lcdColor);
    ir.make = conf.cameraMake;
}

/******************************************************************
 *
 *   settings_update
 *
 *
 ******************************************************************/

void settings_update()
{
    settings_save();
    settings_load();
}

void settings_update_camera_fps()
{
    settings_update();
    if(remote.notifyCameraFPS) remote.send(REMOTE_CAMERA_FPS, REMOTE_TYPE_SEND);
}

void settings_update_camera_make()
{
    settings_update();
    if(remote.notifyCameraMake) remote.send(REMOTE_CAMERA_MAKE, REMOTE_TYPE_SEND);
}

/******************************************************************
 *
 *   settings_default
 *      restores factory defaults
 *
 ******************************************************************/

void settings_default()
{
    timer.setDefault();
    strcpy((char*)conf.sysName, "sys01");
    conf.warnTime = 2;
    conf.mirrorTime = 2;
    conf.cameraFPS = 33;
    conf.bulbMode = 0;
    conf.lcdColor = 0;
    conf.cameraMake = CANON;
    conf.settingsVersion = SETTINGS_VERSION;
    conf.lcdBacklightTime = 3;
    conf.sysOffTime = 12;
    conf.flashlightOffTime = 3;
    conf.devMode = 0;
    conf.auxPort = AUX_MODE_DISABLED;
    settings_save();
    settings_load();
}

/******************************************************************
 *
 *   settings_init
 *
 *
 ******************************************************************/

void settings_init()
{
    settings_load();

    if(eeprom_read_byte((const uint8_t*)&conf_eep) == 255 || conf.settingsVersion != SETTINGS_VERSION)
    {
        settings_default();

        // This is where we'd put a setup wizard
    }
}
