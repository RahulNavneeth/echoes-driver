#include "driver-mac.h"
#include "AudioToolBox/AudioToolbox.h"
#include "CoreAudio/CoreAudio.h"
#include "driver.h"
#include <stdio.h>
#include <stdlib.h>

void write_sound_mac_impl(DriverIMPL *base) {
  printf("Sound Written - Mac\n");
  /* implement sound card write function - mac */
}

char *get_driver_name_mac_impl(DriverIMPL *base) {
  return GET_PARENT_IMPL(DriverMacIMPL, base)->driver_name;
}

AudioComponentDescription get_default_audio_component_mac_impl() {
  return (AudioComponentDescription){
      .componentType = kAudioUnitType_Output,
      .componentSubType = kAudioUnitSubType_DefaultOutput,
      .componentManufacturer = kAudioUnitManufacturer_Apple,
      .componentFlags = 0,
      .componentFlagsMask = 0,
  };
}

DriverIMPL *init_driver_mac_impl(char *driver_name) {
  DriverMacIMPL *new_mac_driver =
      (DriverMacIMPL *)malloc(sizeof(DriverMacIMPL));
  if (new_mac_driver == NULL)
    return NULL;

  new_mac_driver->driver_name = driver_name;
  new_mac_driver->base.write = write_sound_mac_impl;
  new_mac_driver->base.get_driver_name = get_driver_name_mac_impl;

  return (DriverIMPL *)new_mac_driver;
}
