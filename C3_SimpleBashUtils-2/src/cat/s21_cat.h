#ifndef S21_CAT_H
#define S21_CAT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct flags {
  int numberNonBlank;  //-b
  int endl;            //-e
  int allSymbols;      //-v
  int number;          //-n
  int squeezeBlank;    //-s
  int tabs;            //-t
} Flags;

void Parser(int argc, char* argv[], Flags* flags);
void Printer(FILE* file, Flags* flags);

#endif  // S21_CAT_H