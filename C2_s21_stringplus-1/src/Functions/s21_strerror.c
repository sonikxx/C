#include "../s21_string.h"

char *s21_strerror(int errnum) {
  ARRAY;
  static char error_message[128];
  if ((errnum < 0) || (errnum >= ERR_MAX)) {
#ifdef __linux__
    s21_sprintf(error_message, "Unknown error %d", errnum);
#elif __APPLE__
    s21_sprintf(error_message, "Unknown error: %d", errnum);
#endif
  } else {
    s21_sprintf(error_message, "%s", errlist[errnum]);
  }
  return error_message;
}