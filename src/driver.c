#include "driver.h"
#include <stdio.h>
#include <stdlib.h>

void write_sound_mac_impl() {
  printf("Sound Written - Mac\n");
  /* implement sound card write function - mac */
}

DriverIMPL *init_driver_mac_impl(char *driver_name) {
  DriverMacIMPL *new_mac_driver =
      (DriverMacIMPL *)malloc(sizeof(DriverMacIMPL));
  DriverIMPL *new_base_driver = (DriverIMPL *)malloc(sizeof(DriverIMPL));
  if (new_mac_driver == NULL || new_base_driver == NULL)
    return NULL;
  new_mac_driver->driver_name = driver_name;
  new_mac_driver->base = new_base_driver;
  new_mac_driver->base->write = write_sound_mac_impl;
  return (DriverIMPL *)new_mac_driver;
}
