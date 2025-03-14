#include "driver.h"
#include <stdio.h>

int32_t main() {
  printf("Echoes Driver!!!\n");
  DriverIMPL *impl;

#ifdef __APPLE__
  impl = init_driver_mac_impl("Rahul M. Navneeth");
#endif

  printf("Driver Name: %s\n",
         GET_PARENT_IMPL(DriverMacIMPL, impl)->driver_name);
  // impl->write();
  return 0;
}
