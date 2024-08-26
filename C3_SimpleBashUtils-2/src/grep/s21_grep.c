#include "s21_grep.h"

int main(int argc, char* argv[]) {
  if (argc > 2) {
    Flag flags = {0};
    Parser(argc, argv, &flags);
    if (flags.e_f == 0) {
      sprintf(flags.pattern, "%s", argv[optind]);
      optind++;
    }
    if (argc - optind > 1) flags.multiple_files = 1;
    if (flags.multiple_files == 1 && flags.h == 0) flags.print_filename = 1;
    while (optind < argc) {
      Reader(argv, flags);
      optind++;
    }
  }
  return 0;
}

void Parser(int argc, char* argv[], Flag* flags) {
  int currentFlag = 0;
  const char* short_flag = "e:ivclnhsf:o";
  while ((currentFlag = getopt_long(argc, argv, short_flag, 0, 0)) != -1) {
    switch (currentFlag) {
      case 'e':
        flags->e = 1;
        PatternForE(flags);
        flags->e_f = 1;
        break;
      case 'i':
        flags->i = 1;
        break;
      case 'v':
        flags->v = 1;
        break;
      case 'c':
        flags->c = 1;
        break;
      case 'l':
        flags->l = 1;
        break;
      case 'n':
        flags->n = 1;
        break;
      case 'h':
        flags->h = 1;
        break;
      case 's':
        flags->s = 1;
        break;
      case 'f':
        flags->f = 1;
        PatternFromFile(flags, optarg);
        flags->e_f = 1;
        break;
      case 'o':
        flags->o = 1;
        break;
      default:
        fprintf(stderr, "usage: ./s21_grep [e:ivclnhsf:o] pattern [file...]\n");
        exit(1);
        break;
    }
  }
  if (flags->v == 1 || flags->c == 1 || flags->l == 1) flags->o = 0;
}

void PatternForE(Flag* flags) {
  if ((strlen(flags->pattern) + strlen(optarg)) < (BUF - 2)) {
    if (flags->e_f == 1) strcat(flags->pattern, "|");
    if (strlen(optarg) == 0)  // ''
      strcat(flags->pattern, ".");
    else
      strcat(flags->pattern, optarg);
  }
}

void PatternFromFile(Flag* flags, char* optarg) {
  FILE* file = fopen(optarg, "r");
  if (file == NULL && flags->s == 0) {
    fprintf(stderr, "s21_grep: %s: No such file or directory\n", optarg);
  }
  if (file != NULL) {
    char current_line[1];
    current_line[0] = '\0';
    char current = '\0';
    char prev = '\n';
    while ((current = fgetc(file)) != EOF) {
      if (strlen(flags->pattern) < (BUF - 2)) {
        if (flags->e_f == 1 && prev == '\n') {
          strcat(flags->pattern, "|");
        }
        if (current != '\n') {
          current_line[0] = current;
          strcat(flags->pattern, current_line);
        }
        if (current == '\n' && prev == '\n') {
          strcat(flags->pattern, ".");
        }
        if (current == '\n') flags->e_f = 1;
        prev = current;
      }
    }
    fclose(file);
  }
}

void Reader(char* argv[], Flag flags) {
  FILE* file = fopen(argv[optind], "r");
  if (file == NULL && flags.s == 0)
    fprintf(stderr, "s21_grep: %s: No such file or directory\n", argv[optind]);
  if (file != NULL) {
    int reg_flags = REG_EXTENDED;
    regex_t compiled;
    if (flags.i == 1) reg_flags = REG_ICASE;
    if (regcomp(&compiled, flags.pattern, reg_flags) == 0) {
      char* current_line = NULL;
      size_t line_size = 0;
      int line_counter = 0;
      int line_found = 0;
      int match_found = 0;
      while (getline(&current_line, &line_size, file) != EOF) {
        line_counter++;
        if (flags.o == 1) {
          FlagO(current_line, compiled, flags, line_counter, argv);
        } else {
          if (current_line != NULL)
            line_found = regexec(&compiled, current_line, 0, 0, 0);
          if (flags.v == 0 && line_found == 0)
            Printer(current_line, argv, flags, &match_found, line_counter);
          if (flags.v == 1 && line_found == 1)
            Printer(current_line, argv, flags, &match_found, line_counter);
        }
      }
      if (flags.c == 1) {
        if (flags.print_filename == 1) printf("%s:", argv[optind]);
        if (flags.l == 1 && match_found != 0) match_found = 1;  //-lc
        printf("%d\n", match_found);
      }
      if (flags.l == 1 && match_found != 0) printf("%s\n", argv[optind]);
      if (current_line != NULL) free(current_line);
      regfree(&compiled);
    }
    fclose(file);
  }
}

void FlagO(char* current_line, regex_t compiled, Flag flags, int line_counter,
           char* argv[]) {
  regmatch_t pattern_match = {0};
  if (flags.v == 1) {
    if (regexec(&compiled, current_line, 1, &pattern_match, 0))
      printf("%s", current_line);
  } else {
    if (regexec(&compiled, current_line, 1, &pattern_match, 0) == 0) {
      if (flags.print_filename == 1) {
        if (flags.n == 1)
          printf("%s:%d:%.*s\n", argv[optind], line_counter,
                 (int)(pattern_match.rm_eo - pattern_match.rm_so),
                 current_line + pattern_match.rm_so);
        else
          printf("%s:%.*s\n", argv[optind],
                 (int)(pattern_match.rm_eo - pattern_match.rm_so),
                 current_line + pattern_match.rm_so);
      } else {
        if (flags.n == 1)
          printf("%d:%.*s\n", line_counter,
                 (int)(pattern_match.rm_eo - pattern_match.rm_so),
                 current_line + pattern_match.rm_so);
        else
          printf("%.*s\n", (int)(pattern_match.rm_eo - pattern_match.rm_so),
                 current_line + pattern_match.rm_so);
      }
      char* remaining = current_line + pattern_match.rm_eo;
      while (regexec(&compiled, remaining, 1, &pattern_match, 0) == 0) {
        printf("%.*s\n", (int)(pattern_match.rm_eo - pattern_match.rm_so),
               remaining + pattern_match.rm_so);
        remaining += pattern_match.rm_eo;
      }
    }
  }
}

void Printer(char* current_line, char* argv[], Flag flags, int* match_found,
             int line_counter) {
  if (flags.l == 0 && flags.c == 0) {
    if (flags.print_filename == 1) printf("%s:", argv[optind]);
    if (flags.n == 1) printf("%d:", line_counter);
    char* temp = strchr(current_line, '\n');
    if (temp != NULL) *temp = '\0';
    printf("%s\n", current_line);
  }
  (*match_found)++;
}