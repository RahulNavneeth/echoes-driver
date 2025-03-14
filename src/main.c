#include "driver-linux.h"
#include "driver-mac.h"
#include "driver-windows.h"
#include "driver.h"
#include <stdio.h>

int32_t main() {
  printf("Echoes Driver!!!\n");
  DriverIMPL *impl;

#ifdef __APPLE__
  impl = init_driver_mac_impl("Rahul M. Navneeth : Mac");
  printf("Driver Name: %s\n",
         GET_PARENT_IMPL(DriverMacIMPL, impl)->driver_name);
#elifdef __linux__
  impl = init_driver_linux_impl("Rahul M. Navneeth : Linux");
  printf("Driver Name: %s\n",
         GET_PARENT_IMPL(DriverLinuxIMPL, impl)->driver_name);
#elifdef defined(WIN32) || defined(_WIN32) || defined(__WIN32__) ||            \
    defined(__NT__)
  impl = init_driver_window_impl("Rahul M. Navneeth : Windows");
#endif

  // impl->write();
  return 0;
}
