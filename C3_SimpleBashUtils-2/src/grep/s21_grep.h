#ifndef S21_GREP_H
#define S21_GREP_H

#define _GNU_SOURCE  // getline
#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF 2048

typedef struct flags {
  int e;
  int i;
  int v;
  int c;
  int l;
  int n;
  int h;
  int s;
  int f;
  int o;
  int e_f;
  char pattern[BUF];
  int print_filename;
  int multiple_files;
} Flag;

void Parser(int argc, char* argv[], Flag* flags);
void PatternForE(Flag* flags);
void PatternFromFile(Flag* flags, char* optarg);
void Reader(char* argv[], Flag flags);
void FlagO(char* current_line, regex_t compiled, Flag flags, int line_counter,
           char* argv[]);
void Printer(char* current_line, char* argv[], Flag flags, int* match_found,
             int line_counter);

#endif  // S21_GREP_H