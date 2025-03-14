#include <stdio.h>

#ifndef DRIVER_H
#define DRIVER_H

#define GET_PARENT_IMPL(type, base_driver) ((type *)base_driver)

typedef struct DriverIMPL {
  void (*write)();
  /* other functions  */
} DriverIMPL;

#endif /* DRIVER_H */
