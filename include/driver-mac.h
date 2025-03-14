#ifndef DRIVER_MAC_H
#define DRIVER_MAC_H

#include "driver.h"
#include <stdio.h>

typedef struct {
  DriverIMPL base;
  char *driver_name;
} DriverMacIMPL;

DriverIMPL *init_driver_mac_impl(char *);

void write_sound_mac_impl();

#endif /* DRIVER_MAC_H */
