#include "driver.h"
#include <stdio.h>

#ifndef DRIVER_MAC_H
#define DRIVER_MAC_H

typedef struct {
  DriverIMPL *base;
  char *driver_name;
} DriverWindowsIMPL;

DriverIMPL *init_driver_windows_impl(char *);

void write_sound_windows_impl();

#endif /* DRIVER_MAC_H */
