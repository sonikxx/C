#include "../s21_string.h"

int s21_sprintf(char *buf, const char *format, ...) {
  va_list args;
  va_start(args, format);  // initialization argc
  s21_copy_to_buf(buf, format, args);
  va_end(args);
  return s21_strlen(buf);
}

void s21_copy_to_buf(char *buf, const char *string, va_list args) {
  int i[2] = {0, 0};
  /* i[0] for format (string)
     i[1] for buf */
  for (; i[0] < (int)s21_strlen(string); i[0]++, i[1]++) {
    if (string[i[0]] == '%' && string[i[0] + 1] == '%') {
      buf[i[1]] = string[i[0]];
    } else if (string[i[0]] == '%' && (string[i[0] + 1]) != '%') {
      s21_format_processing(string, i, buf, args);
    } else {
      buf[i[1]] = string[i[0]];
    }
  }
  buf[i[1]] = '\0';
}

void s21_format_processing(const char *format, int *i, char *buf,
                           va_list args) {
  format_t params;
  params.minus = 0;
  params.plus = 0;
  params.space = 0;
  params.zero = 0;
  params.length = ' ';
  params.width = 0;
  params.isprec = 0;
  params.prec = 0;
  params.spec = '\0';
  for (; i[0] < (int)s21_strlen(format) &&
         s21_strchr("cdifsu", format[i[0]]) == NULL;
       i[0]++) {
    switch (format[i[0]]) {
      case '+':
        params.plus = 1;
        break;
      case '-':
        params.minus = 1;
        break;
      case ' ':
        params.space = 1;
        break;
      case 'l':
        params.length = 'l';
        break;
      case 'h':
        params.length = 'h';
        break;
      case '.':
        params.isprec = 1;
        break;
    }
    if (params.isprec && format[i[0]] == '-')
      params.prec = 0;
    else if (params.isprec && (format[i[0]] >= '0' && format[i[0]] <= '9')) {
      params.prec = params.prec * 10 + format[i[0]] - 48;
    } else if (format[i[0]] >= '0' && format[i[0]] <= '9') {
      params.width = params.width * 10 + format[i[0]] - 48;
    }
  }
  params.spec = format[i[0]];
  s21_format_and_buff(i, buf, args, params);
}

void s21_format_and_buff(int *i, char *buf, va_list args, format_t params) {
  // %[flags][width][.prec][length]specifier
  switch (params.spec) {
    case 'c':
      if (params.length == 'l') {
        s21_lc_to_buf(va_arg(args, wchar_t), params, buf, i);
      } else if (params.length == 'h')
        s21_lc_to_buf(va_arg(args, wint_t), params, buf, i);
      else {
        s21_c_to_buf(va_arg(args, int), params, buf, i);
      }
      break;
    case 'd':
    case 'i':
      if (params.length == 'l')
        s21_d_to_buf(va_arg(args, long int), params, buf, i, 10);
      else if (params.length == 'h')
        s21_d_to_buf((short)va_arg(args, int), params, buf, i, 10);
      else {
        s21_d_to_buf(va_arg(args, int), params, buf, i, 10);
      }
      break;
    case 'f':
      s21_f_to_buf(va_arg(args, double), params, buf, i);
      break;
    case 's':
      s21_s_to_buf(args, params, buf, i);
      break;
    case 'u':
      s21_u_to_buf(va_arg(args, uint64_t), params, buf, i, 10);
      break;
  }
}

void s21_c_to_buf(const char c, format_t params, char *buf, int *i) {
  if (params.width && !params.minus) {
    for (int j = 0; j < params.width - 1; j++) {
      buf[i[1]] = ' ';
      i[1]++;
    }
    buf[i[1]] = c;
  } else if (params.width && params.minus) {
    buf[i[1]] = c;
    i[1]++;
    for (int j = 0; j < params.width - 1; j++) {
      buf[i[1]] = ' ';
      i[1]++;
    }
    i[1]--;
  } else {
    buf[i[1]] = c;
  }
}

void s21_d_to_buf(int64_t d, format_t params, char *buf, int *i, int base) {
  int m = 0;

  if (d < 0 && d != 0) {
    d = -d;
    m = 1;
  }
  char temp[BUFF_SIZE] = {'\0'};
  int j = 0;

  if (d == 0) {
    temp[0] = '0';
    j++;
  } else {
    while (d != 0) {
      // temp[j] = d%10 + 48;
      temp[j] = "0123456789abcdef"[d % base];
      j++;
      d /= base;
    }
  }

  int len = (int)(s21_strlen(temp));

  while (len < params.prec) {
    temp[j++] = '0';
    params.prec--;
  }
  if (params.space && !m) temp[j] = ' ';
  if (params.plus && !m) temp[j] = '+';
  if (m) temp[j] = '-';

  s21_format_flag(temp, params, buf, i, 0);
}

void s21_format_flag(char *temp, format_t params, char *buf, int *i, int mode) {
  int base_w = (int)s21_strlen(temp);
  /* add spaces if parametr = width*/
  if (params.width && !params.minus) {
    for (int j = 0; j < params.width - mode - base_w; j++) {
      buf[i[1]++] = ' ';
    }
    for (int j = 0; j < base_w; j++) buf[i[1]++] = temp[base_w - 1 - j];
    i[1]--;
  } else if (params.width && params.minus) {
    for (int j = 0; j < base_w; j++) buf[i[1]++] = temp[base_w - 1 - j];
    for (int j = 0; j < params.width - mode - base_w; j++) buf[i[1]++] = ' ';
    i[1]--;
  } else {
    for (int j = 0; j < base_w; j++) buf[i[1]++] = temp[base_w - 1 - j];
    i[1]--;
  }
}

void s21_f_to_buf(long double f, format_t params, char *buf, int *i) {
  int m = 0;
  if (f < 0. && f != 0.) {
    f = -f;
    m = 1;
  }
  int count = 0;
  long double man = 0;
  long double ipartd = 0;
  long long ipart = 0;
  char temp[BUFF_SIZE] = {'\0'};
  man += modfl(f, &ipartd);
  ipart = ipartd;
  long long del = 0;
  if (params.prec) {
    del = pow(10, params.prec);
    man = roundl(man * del) / del;
  } else {
    del = pow(10, 6);
    man = roundl(man * del) / del;
  }
  if (!params.prec && params.isprec) man = roundl(man);
  int j = 0;
  if (!(!params.prec && params.isprec) || (params.spec != 'f' && !params.prec))
    temp[j++] = '.';
  if (ipart == 0) temp[j++] = '0';
  while (ipart != 0) {
    temp[j] = (long int)ipart % 10 + '0';
    j++;
    ipart /= 10;
  }
  if (params.space && !m) temp[j] = ' ';
  if (params.plus && !m) temp[j] = '+';
  if (m) temp[j] = '-';
  if (params.spec == 'f' && !params.prec)
    count = 6;
  else if (params.prec == 0 && params.isprec)
    count = 1;
  else if (params.prec)
    count = params.prec;
  s21_format_flag(temp, params, buf, i, count);
  i[1]++;
  if (!(!params.prec && params.isprec)) {
    long long mani = man * pow(10, count) + 0.05;
    char temp1[BUFF_SIZE] = {'\0'};
    int k = 0;
    for (; k < count; k++) {
      temp1[k] = mani % 10 + '0';
      mani /= 10;
    }
    k--;
    for (; k >= 0; k--) {
      buf[i[1]++] = temp1[k];
    }
  }
  i[1]--;
}

void s21_s_to_buf(va_list args, format_t params, char *buf, int *i) {
  int j = 0;
  char temp[BUFF_SIZE] = {'\0'};
  if (params.length == 'l') {
    const wchar_t *wstr = va_arg(args, wchar_t *);
    if (wstr != NULL) {
      j = wcstombs(temp, wstr, BUFF_SIZE);
      if (params.width && !params.minus) {
        for (int k = 0; k < params.width - j; k++) {
          buf[i[1]++] = ' ';  //==
        }
      }
      j = 0;
      while (temp[j] != '\0' && (!params.isprec || j < params.prec)) {
        buf[i[1]++] = temp[j++];
      }
      if (params.width && params.minus) {
        for (int k = 0; k < params.width - j; k++) {
          buf[i[1]++] = ' ';
        }
      }
      i[1]--;
    } else {
      s21_strcat(buf, "(null)");
      i[1] += 5;
    }
  } else {
    char *str = va_arg(args, char *);
    if (str != NULL) {
      j = s21_strlen(str);
      if (params.width && !params.minus) {
        for (int k = 0; k < params.width - j; k++) {
          buf[i[1]++] = ' ';
        }
      }
      j = 0;
      while (*str != '\0' && (!params.isprec || j < params.prec)) {
        buf[i[1]++] = *str;  //==
        str++;
        j++;
      }
      if (params.width && params.minus) {
        for (int k = 0; k < params.width - j; k++) {
          buf[i[1]++] = ' ';
        }
      }
      i[1]--;
    } else {
      s21_strcat(buf, "(null)");
      i[1] += 5;
    }
  }
}

void s21_lc_to_buf(wchar_t c1, format_t params, char *buf, int *i) {
  char tmp[10] = {0};
  tmp[0] = c1;

  if (params.width && !params.minus) {
    for (int j = 0; j < params.width - 1; j++) {
      buf[i[1]] = ' ';
      i[1]++;
    }

    buf[i[1]] = '\0';
    i[1] = s21_strlen(s21_strcat(buf, tmp)) - 1;

  } else if (params.width && params.minus) {
    i[1] = s21_strlen(s21_strcat(buf, tmp));
    for (int j = 0; j < params.width - 1; j++) {
      buf[i[1]] = ' ';
      i[1]++;
    }
    i[1]--;
  } else {
    i[1] = s21_strlen(s21_strcat(buf, tmp));
  }
}

void s21_u_to_buf(uint64_t d, format_t params, char *buf, int *i, int base) {
  if (params.length == 'l') {
    d = (uint64_t)d;
  } else if (params.length == 'h') {
    d = (uint16_t)d;
  } else if (params.length == ' ') {
    d = (uint32_t)d;
  }

  char temp[BUFF_SIZE] = {'\0'};
  int j = 0;

  if (d == 0) {
    temp[0] = '0';
    j++;
  } else {
    while (d != 0) {
      temp[j] = "0123456789abcdef"[d % base];
      j++;
      d /= base;
    }
  }
  int len = (int)s21_strlen(temp);

  while (len < params.prec) {
    temp[j++] = '0';
    params.prec--;
  }
  if (params.space) temp[j] = ' ';
  if (params.plus) temp[j] = '+';

  s21_format_flag(temp, params, buf, i, 0);
}

// int main() {
// //   char str[256];
// //   char sys_str[256];
// //   // s21_sprintf(str, "%-5c", 'b');
// //   // sprintf(sys_str, "%-5c", 'b');
// //   // printf("%s\n", str);
// //   // printf("%s\n", sys_str);
// //   // s21_sprintf(str, "%5c", 'b');
// //   // sprintf(sys_str, "%5c", 'b');
// //   // printf("%s\n", str);
// //   // printf("%s\n", sys_str);
// //   // char c = 'z';
// //   // float d = 57.159405;
// //   // char *s = "none";
// //   unsigned long int u = 32771;
// //   int i = 5;
// //   char c = 'z';
// //   float f = 150.15;
// //   char *s = "hello";
// //   s21_sprintf(str, "%BOBA");
// //   sprintf(sys_str, "%BOBA");

// //   printf("%s\n", str);
// //   printf("%s\n", sys_str);

//   char firstString[20];
//   char secondString[20];
//   char c = 'z';
//   s21_sprintf(firstString, "Fortnite: %-5c", c);
//   sprintf(secondString, "Fortnite: %-5c", c);
//   printf("%s\n%s", firstString, secondString);

//   return 0;
// }