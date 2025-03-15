#include "driver-mac.h"
#include "AudioToolBox/AudioToolbox.h"
#include "driver.h"
#include <stdio.h>
#include <stdlib.h>

void write_sound_mac_impl(DriverIMPL *base) {
  AURenderCallbackStruct callback_struct;
  printf("Sound Written : Mac\n");
  /* implement sound card write function - mac */
}

char *get_driver_name_mac_impl(DriverIMPL *base) {
  return GET_PARENT_IMPL(DriverMacIMPL, base)->driver_name;
}

AudioComponentDescription get_default_audio_component_description_mac_impl() {
  return (AudioComponentDescription){
      .componentType = kAudioUnitType_Output,
      .componentSubType = kAudioUnitSubType_DefaultOutput,
      .componentManufacturer = kAudioUnitManufacturer_Apple,
      .componentFlags = 0,
      .componentFlagsMask = 0,
  };
}

AudioStreamBasicDescription get_default_audio_format_output_stream_mac_impl() {
  AudioStreamBasicDescription audio_format_output_stream;
  audio_format_output_stream.mSampleRate = 48000;
  audio_format_output_stream.mFormatID = kAudioFormatLinearPCM;
  audio_format_output_stream.mFormatID = kAudioFormatFlagsNativeFloatPacked;
  audio_format_output_stream.mBitsPerChannel = 32;
  audio_format_output_stream.mChannelsPerFrame = 1; /* Mono */
  audio_format_output_stream.mFramesPerPacket = 1;
  audio_format_output_stream.mBytesPerFrame =
      audio_format_output_stream.mBitsPerChannel *
      audio_format_output_stream.mChannelsPerFrame;
  audio_format_output_stream.mBytesPerPacket =
      audio_format_output_stream.mBytesPerFrame *
      audio_format_output_stream.mFramesPerPacket;
  return audio_format_output_stream;
}

AudioComponent get_default_audio_component_mac_impl(
    AudioComponentDescription audio_description) {
  AudioComponent audio_component =
      AudioComponentFindNext(NULL, &audio_description);
  if (audio_component == NULL) {
    printf("Err: Failed to find the default output component\n");
    return NULL;
  }
  return audio_component;
}

DriverIMPL *init_driver_mac_impl(char *driver_name) {
  DriverMacIMPL *new_mac_driver =
      (DriverMacIMPL *)malloc(sizeof(DriverMacIMPL));
  if (new_mac_driver == NULL) {
    free(new_mac_driver);
    return NULL;
  }

  new_mac_driver->driver_name = driver_name;
  new_mac_driver->base.write = write_sound_mac_impl;
  new_mac_driver->base.get_driver_name = get_driver_name_mac_impl;

  /* if needed might as well have a separeted initialiser for audio unit */
  AudioComponent audio_component = get_default_audio_component_mac_impl(
      get_default_audio_component_description_mac_impl());

  new_mac_driver->OS_status =
      AudioComponentInstanceNew(audio_component, &new_mac_driver->audio_unit);

  if (new_mac_driver->OS_status != noErr) {
    printf("Err : Failed to create audio unit\n");
    return NULL;
  }

  AudioStreamBasicDescription audio_format =
      get_default_audio_format_output_stream_mac_impl();

  new_mac_driver->OS_status = AudioUnitSetProperty(
      new_mac_driver->audio_unit, kAudioUnitProperty_StreamFormat,
      kAudioUnitScope_Input, 0, &audio_format, sizeof(audio_format));

  if (new_mac_driver->OS_status != noErr) {
    printf("Err : Failed to set audio unit format : %d\n",
           (int)new_mac_driver->OS_status);
    return NULL;
  }

  return (DriverIMPL *)new_mac_driver;
}
