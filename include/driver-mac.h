#ifndef DRIVER_MAC_H
#define DRIVER_MAC_H

#include "AudioToolBox/AudioToolbox.h"
#include "CoreAudio/CoreAudio.h"
#include "driver.h"
#include <stdio.h>

typedef struct {
  DriverIMPL base;
  AudioUnit audio_unit; /* instance of audio component */
  char *driver_name;
} DriverMacIMPL;

DriverIMPL *init_driver_mac_impl(char *);
AudioComponentDescription get_default_audio_component_mac_impl();

void write_sound_mac_impl(DriverIMPL *);
char *get_driver_name_mac_impl(DriverIMPL *);

#endif /* DRIVER_MAC_H */
