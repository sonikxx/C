#include "../s21_string.h"

void *s21_trim(const char *src, const char *trim_chars) {
  s21_size_t src_lenght = s21_strlen(src);
  char *buf = (char *)calloc(src_lenght + 1, sizeof(char));
  if (!buf) return s21_NULL;
  s21_strcpy(buf, src);
  char *beggining = buf, *end = buf + src_lenght - 1;
  while (s21_strchr(trim_chars, *beggining)) {
    beggining++;
  }
  while (s21_strchr(trim_chars, *end)) {
    end--;
  }
  if (*end != '\0') *(end + 1) = '\0';
  char *res = (char *)calloc((end - beggining) + 2, sizeof(char));
  if (!res) return s21_NULL;
  s21_strcpy(res, beggining);
  free(buf);
  return res;
}
