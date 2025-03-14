#include "driver.h"
#include <stdio.h>

#ifndef DRIVER_LINUX_H
#define DRIVER_LINUX_H

typedef struct {
  DriverIMPL *base;
  char *driver_name;
} DriverLinuxIMPL;

DriverIMPL *init_driver_linux_impl(char *);

void write_sound_linux_impl();

#endif /* DRIVER_MAC_H */
