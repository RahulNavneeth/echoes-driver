#include "driver.h"
#include "driver-windows.h"
#include <stdio.h>
#include <stdlib.h>

void write_sound_windows_impl(DriverIMPL *base) {
  printf("Sound Written - Windows\n");
  /* implement sound card write function - Windows */
}

DriverIMPL *init_driver_windows_impl(char *driver_name) {
  DriverWindowsIMPL *new_mac_driver =
      (DriverWindowsIMPL *)malloc(sizeof(DriverWindowsIMPL));
  if (new_mac_driver == NULL)
    return NULL;
  new_mac_driver->driver_name = driver_name;
  new_mac_driver->base.write = write_sound_windows_impl;

  return (DriverIMPL *)new_mac_driver;
}
