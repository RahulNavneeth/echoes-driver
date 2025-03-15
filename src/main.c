#include "driver-linux.h"
#include "driver-mac.h"
#include "driver-windows.h"
#include "driver.h"
#include <stdint.h>
#include <stdio.h>

int32_t main() {
  printf("Echoes Driver!!!\n");
  DriverIMPL *impl;

#ifdef __APPLE__
  impl = init_driver_mac_impl("Rahul M. Navneeth : Mac");
#elif defined(__unix__)
  impl = init_driver_linux_impl("Rahul M. Navneeth : Linux");
#elif defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
  impl = init_driver_window_impl("Rahul M. Navneeth : Windows");
#endif

  if (impl == NULL) {
    printf("Err: Driver Impl is NULL\n");
    return 1;
  }

  printf("Driver Name : %s\n", impl->get_driver_name(impl));
  impl->write(impl);

  return 0;
}
