#include "s21_cat.h"

int main(int argc, char* argv[]) {
  if (argc > 1) {
    Flags flags = {0};
    Parser(argc, argv, &flags);
    int start_count = 1;
    while (argv[start_count][0] == '\0') {
      ++start_count;
    }
    for (; start_count < argc; ++start_count) {
      FILE* file = fopen(argv[start_count], "r");
      if (file == NULL)
        fprintf(stderr, "s21_cat: %s: No such file or directory\n",
                argv[start_count]);
      else {
        Printer(file, &flags);
        fclose(file);
      }
    }
  }
  return 0;
}

void Parser(int argc, char* argv[], Flags* flags) {
  int count = 1;
  while (count < argc) {
    if (argv[count][0] == '-' && argv[count][1] != '-') {
      for (size_t i = 1; i < strlen(argv[count]); ++i) {
        switch (argv[count][i]) {
          case 'b':
            flags->numberNonBlank = 1;
            break;
          case 'e':
            flags->endl = 1;
            flags->allSymbols = 1;
            break;
          case 'v':
            flags->allSymbols = 1;
            break;
          case 'E':
            flags->endl = 1;
            break;
          case 'n':
            flags->number = 1;
            break;
          case 's':
            flags->squeezeBlank = 1;
            break;
          case 't':
            flags->allSymbols = 1;
            flags->tabs = 1;
            break;
          case 'T':
            flags->tabs = 1;
            break;
          default:
            fprintf(stderr, "usage: [-beEvnstTv] [file ...]\n");
            exit(1);
            break;
        }
      }
      memset(argv[count], '\0', strlen(argv[count]));
    }
    if (argv[count][0] == '-' && argv[count][1] == '-') {
      if (strcmp(argv[count], "--number-nonblank") == 0) {
        flags->numberNonBlank = 1;
        memset(argv[count], '\0', strlen(argv[count]));
      } else if (strcmp(argv[count], "--number") == 0) {
        flags->number = 1;
        memset(argv[count], '\0', strlen(argv[count]));
      } else if (strcmp(argv[count], "--squeeze-blank") == 0) {
        flags->squeezeBlank = 1;
        memset(argv[count], '\0', strlen(argv[count]));
      } else {
        fprintf(stderr, "usage: [-beEvnstTv] [file ...]\n");
        exit(1);
      }
    }
    ++count;
  }
}

void Printer(FILE* file, Flags* flags) {
  int counter = 1;
  int flag_s = 0;
  char tmp = '\0';
  for (char prev = '\n'; tmp != EOF; prev = tmp) {
    tmp = getc(file);
    if (flags->squeezeBlank && prev == '\n' && tmp == '\n') {
      ++flag_s;
      if (flag_s > 1) {
        continue;
      }
    } else {
      flag_s = 0;
    }
    if (flags->numberNonBlank && tmp != '\n' && prev == '\n' && tmp != EOF) {
      printf("%6d\t", counter++);
    }
    if (flags->number && !flags->numberNonBlank && prev == '\n' && tmp != EOF) {
      printf("%6d\t", counter++);
    }
    if (flags->endl && tmp == '\n') {
      putchar('$');
    }
    if (flags->tabs && tmp == 9) {
      putchar('^');
      putchar('I');
      continue;
    }
    if (flags->allSymbols) {
      if ((tmp >= 0 && tmp < 9) || (tmp > 10 && tmp < 32)) {
        putchar('^');
        tmp += 64;
      }
      if (tmp == 127) {
        putchar('^');
        putchar('?');
        continue;
      }
    }
    if (tmp != EOF) {
      putchar(tmp);
    }
  }
}
