#ifndef DRIVER_H
#define DRIVER_H

#include <stdio.h>

#define GET_PARENT_IMPL(type, base_driver) ((type *)base_driver)

typedef struct DriverIMPL {
  void (*write)();
  /* other functions  */
} DriverIMPL;

#endif /* DRIVER_H */
