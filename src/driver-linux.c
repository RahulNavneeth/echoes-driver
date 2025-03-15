#include "driver-linux.h"
#include "driver.h"
#include <stdio.h>
#include <stdlib.h>

void write_sound_linux_impl(DriverIMPL *base) {
  printf("Sound Written - linux\n");
  /* implement sound card write function - linux */
}

DriverIMPL *init_driver_linux_impl(char *driver_name) {
  DriverLinuxIMPL *new_mac_driver =
      (DriverLinuxIMPL *)malloc(sizeof(DriverLinuxIMPL));
  if (new_mac_driver == NULL)
    return NULL;
  new_mac_driver->driver_name = driver_name;
  new_mac_driver->base.write = write_sound_linux_impl;
  return (DriverIMPL *)new_mac_driver;
}
