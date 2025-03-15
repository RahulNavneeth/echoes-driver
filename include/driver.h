#ifndef DRIVER_H
#define DRIVER_H

#include <stdio.h>

#define GET_PARENT_IMPL(type, base_driver) ((type *)base_driver)

typedef struct DriverIMPL {
  void (*write)(struct DriverIMPL *);
  char *(*get_driver_name)(struct DriverIMPL *);
  /* other functions  */
} DriverIMPL;

#endif /* DRIVER_H */
