#include <stdio.h>

#ifndef DRIVER_H
#define DRIVER_H

#define GET_PARENT_IMPL(type, base_driver) ((type *)base_driver)

typedef struct DriverIMPL {
  void (*write)();
  /* other functions  */
} DriverIMPL;

typedef struct {
  DriverIMPL *base;
  char *driver_name;
  /* other Mac specific elements  */
} DriverMacIMPL;

/* future implementation
typedef struct {
  DriverIMPL *base;
  char *driver_name;
  other Windows specific elements
} DriverWindowsIMPL;

typedef struct {
  DriverIMPL *base;
  char *driver_name;
  other Linux specific elements
} DriverLinuxIMPL;
*/

/* OS specific driver initialisers */
DriverIMPL *init_driver_mac_impl(char *);
/* future implementation
DriverIMPL *init_driver_linux_impl(char *);
DriverIMPL *init_driver_windows_impl(char *);
*/

void write_sound_mac_impl();
/* future implementation
void write_sound_windows_impl();
void write_sound_linux_impl();
*/

#endif /* DRIVER_H */
