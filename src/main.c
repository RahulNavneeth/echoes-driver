#include "IO.h"
#include "driver.h"
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>

// Will remove later, since capturing will be handles by the engine
void set_raw_mode(int enable) {
  static struct termios oldt, newt;
  if (enable) {
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  } else {
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  }
}

void sample_input_capture() {
  /* Sample input capturing */
  char ch;
  set_raw_mode(1);
  while (1) {
    ch = getchar();

    write_audio(
        generate_test_tone(440.0 * pow(1.05946309436, (int)ch % 97), 0.5, 0.3));

    if (ch == '*')
      break;
  }
  set_raw_mode(0);
}

int32_t main() {
  printf("Echoes Driver!!!\n");

  init_audio_driver("Rahul M. Navneeth [MAC]");

  DriverIMPL *impl = get_driver_impl();

  printf("Driver Name : %s\n", impl->get_driver_name(impl));

  /* impl->sound_check() */;
  sample_input_capture();

  /* Wait for the function call */
  char ch;
  while (1) {
    ch = getchar();
    if (ch == '*')
      break;
  }

  cleanup_audio_driver();
  return 0;
}
