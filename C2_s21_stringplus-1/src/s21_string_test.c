#include "s21_string.h"

#include <check.h>
#include <string.h>

/* s21_memchr_test */

START_TEST(s21_memchr_test) {
  char string[1024] = {0};
  strcat(string, "Some intellectual text");
  fail_unless(s21_memchr(string, 'l', 22) == memchr(string, 'l', 22));
  fail_unless(s21_memchr(string, '\t', 15) == memchr(string, '\t', 15));
  fail_unless(s21_memchr(string, '\n', 15) == memchr(string, '\n', 10));
  fail_unless(s21_memchr(string, '\0', 25) == memchr(string, '\0', 25));
  fail_unless(s21_memchr(string, 'v', 1) == memchr(string, 'v', 1));
  fail_unless(s21_memchr(string, ' ', 0) == memchr(string, ' ', 0));
  fail_unless(s21_memchr(string, ' ', 0) == memchr(string, ' ', 0));
  fail_unless(s21_memchr(string, '6', 22) == memchr(string, '6', 22));
  fail_unless(s21_memchr(string, '9', 22) == memchr(string, '9', 22));
  fail_unless(s21_memchr(string, 't', 22) == memchr(string, 't', 22));
}
END_TEST

/* s21_memcmp_test */

START_TEST(s21_memcmp_test) {
  char firstString[1024] = "AmogusSussyBalls";
  char secondString[256] = "Sussy";
  fail_unless(s21_memcmp(firstString, secondString, 13) ==
              memcmp(firstString, secondString, 13));
  fail_unless(s21_memcmp(firstString, secondString, 12) ==
              memcmp(firstString, secondString, 12));
  fail_unless(s21_memcmp(firstString, secondString, 11) ==
              memcmp(firstString, secondString, 11));
  fail_unless(s21_memcmp(firstString, secondString, 7) ==
              memcmp(firstString, secondString, 7));
  fail_unless(s21_memcmp(firstString, secondString, 3) ==
              memcmp(firstString, secondString, 3));
  fail_unless(s21_memcmp(firstString, secondString, 1) ==
              memcmp(firstString, secondString, 1));
}
END_TEST

/* s21_memcpy_test */

START_TEST(s21_memcpy_test) {
  char firstString[1024] = "AmogusSussyBalls";
  char secondString[256] = "Sussy";
  char thirdString[256] = "12344857";
  char fourthString[256] = "'\t'";
  char fifthString[256] = "  \t15";
  char sixthString[256] = "\0";
  fail_unless(s21_memcpy(firstString, secondString, 15) ==
              memcpy(firstString, secondString, 15));
  fail_unless(s21_memcpy(thirdString, fourthString, 15) ==
              memcpy(thirdString, fourthString, 15));
  fail_unless(s21_memcpy(fifthString, sixthString, 1) ==
              memcpy(fifthString, sixthString, 1));
  fail_unless(s21_memcpy(fifthString, firstString, 10) ==
              memcpy(fifthString, firstString, 10));
  fail_unless(s21_memcpy(sixthString, firstString, 0) ==
              memcpy(sixthString, firstString, 0));
  fail_unless(s21_memcpy(sixthString, fourthString, 5) ==
              memcpy(sixthString, fourthString, 5));
  fail_unless(s21_memcpy(sixthString, thirdString, 10) ==
              memcpy(sixthString, thirdString, 10));
  fail_unless(s21_memcpy(sixthString, secondString, 1) ==
              memcpy(sixthString, secondString, 1));
  fail_unless(s21_memcpy(sixthString, secondString, 10) ==
              memcpy(sixthString, secondString, 10));
  fail_unless(s21_memcpy(sixthString, fifthString, 2) ==
              memcpy(sixthString, fifthString, 2));
  fail_unless(s21_memcpy(sixthString, sixthString, 150) ==
              memcpy(sixthString, sixthString, 150));
}
END_TEST

/* s21_memset_test */

START_TEST(s21_memset_test) {
  char firstString[1024] = {0};
  char secondString[256] = {0};
  strcat(firstString, "amogus");
  strcat(secondString, "fortnite");
  fail_unless(s21_memset(firstString, 'Z', 15) == memset(firstString, 'Z', 15));
  fail_unless(s21_memset(firstString, '\t', 6) == memset(firstString, '\t', 6));
  fail_unless(s21_memset(firstString, '\0', 1) == memset(firstString, '\0', 1));
  fail_unless(s21_memset(firstString, '\n', 10) ==
              memset(firstString, '\n', 10));
  fail_unless(s21_memset(firstString, 'J', 5) == memset(firstString, 'J', 5));
  fail_unless(s21_memset(firstString, ' ', 5) == memset(firstString, ' ', 5));
  fail_unless(s21_memset(firstString, '^', 5) == memset(firstString, '^', 5));
  fail_unless(s21_memset(firstString, '&', 1024) ==
              memset(firstString, '&', 1024));
}
END_TEST

/* Test for s21_strchr */

START_TEST(s21_strchr_test) {
  char firstString[1024] = {0};
  strcat(firstString, "fortnite");
  char secondString[256] = {0};
  strcat(secondString, "ballz");
  fail_unless(s21_strchr(firstString, 't') == strchr(firstString, 't'));
  fail_unless(s21_strchr(secondString, 'z') == strchr(secondString, 'z'));
  fail_unless(s21_strchr(firstString, '?') == strchr(firstString, '?'));
  fail_unless(s21_strchr(firstString, '\t') == strchr(firstString, '\t'));
  fail_unless(s21_strchr(secondString, '%') == strchr(secondString, '%'));
  fail_unless(s21_strchr(secondString, 'A') == strchr(secondString, 'A'));
  memset(firstString, '\0', 1024);
  strcat(firstString, "\tABOBA\t");
  memset(secondString, '\0', 256);
  strcat(secondString, "Some intellectual text: ");
  ck_assert_ptr_null(s21_strchr(firstString, 'a'));
  ck_assert_ptr_null(strchr(firstString, 'a'));
  ck_assert_ptr_null(s21_strchr(firstString, '?'));
  ck_assert_ptr_null(strchr(firstString, '?'));
  ck_assert_ptr_null(s21_strchr(secondString, '%'));
  ck_assert_ptr_null(strchr(secondString, '%'));
  ck_assert_str_eq(s21_strchr(firstString, '\t'), strchr(firstString, '\t'));
  ck_assert_str_eq(s21_strchr(secondString, 'S'), strchr(secondString, 'S'));
  ck_assert_str_eq(s21_strchr(secondString, ':'), strchr(secondString, ':'));
}
END_TEST

/* Test for s21_strcspn */

START_TEST(s21_strcspn_test) {
  char firstString[1024] = {0};
  strcat(firstString, "LOST: Z-8-15-16-23-42");
  fail_unless(s21_strcspn(firstString, "1234567890") ==
              strcspn(firstString, "1234567890"));
  fail_unless(s21_strcspn(firstString, "890") == strcspn(firstString, "890"));
  fail_unless(s21_strcspn(firstString, "OS") == strcspn(firstString, "OS"));
  fail_unless(s21_strcspn(firstString, "-") == strcspn(firstString, "-"));
  fail_unless(s21_strcspn(firstString, ":") == strcspn(firstString, ":"));
  fail_unless(s21_strcspn(firstString, " ") == strcspn(firstString, " "));
  fail_unless(s21_strcspn(firstString, "\0") == strcspn(firstString, "\0"));
}
END_TEST

/* Test for s21_strerror */

START_TEST(s21_strerror_test) {
  for (int index = 0; index < 200; index++) {
    ck_assert_str_eq(s21_strerror(index), strerror(index));
  }
}
END_TEST

/* Test for s21_strlen */

START_TEST(s21_strlen_test) {
  char firstString[1024] = {0};
  strcat(firstString, "fortniteballz");
  char secondString[256] = {0};
  strcat(firstString, "obamaisblack");
  char thirdString[256] = {0};
  strcat(thirdString, "\t\t\t\n");
  fail_unless(s21_strlen(firstString) == strlen(firstString));
  fail_unless(s21_strlen(secondString) == strlen(secondString));
  fail_unless(s21_strlen(thirdString) == strlen(thirdString));
  memset(firstString, '\0', 1024);
  strcat(firstString, " ");
  memset(secondString, '\0', 256);
  strcat(secondString, "\0");
  memset(thirdString, '\0', 256);
  strcat(thirdString, "//\\||!!%%&#\0");
  fail_unless(s21_strlen(firstString) == strlen(firstString));
  fail_unless(s21_strlen(secondString) == strlen(secondString));
  fail_unless(s21_strlen(thirdString) == strlen(thirdString));
}
END_TEST

/* Test for_s21_strncat */

START_TEST(s21_strncat_test) {
  char firstString[1024] = {0};
  strcat(firstString, "fortnite");
  char secondString[256] = {0};
  strcat(secondString, "putYourDAwayWaltuh");
  fail_unless(s21_strncat(firstString, secondString, 1) ==
              strncat(firstString, secondString, 1));
  fail_unless(s21_strncat(firstString, secondString, 10) ==
              strncat(firstString, secondString, 10));
  fail_unless(s21_strncat(firstString, secondString, 20) ==
              strncat(firstString, secondString, 20));
  fail_unless(s21_strncat(secondString, firstString, 1) ==
              strncat(secondString, firstString, 1));
  fail_unless(s21_strncat(secondString, firstString, 10) ==
              strncat(secondString, firstString, 10));
  fail_unless(s21_strncat(secondString, firstString, 20) ==
              strncat(secondString, firstString, 20));
  memset(firstString, '\0', 1024);
  strcat(firstString, "Some intellectual text");
  memset(secondString, '\0', 256);
  strcat(secondString, "\t\b\t\0\b");
  fail_unless(s21_strncat(firstString, secondString, 1) ==
              strncat(firstString, secondString, 1));
  fail_unless(s21_strncat(firstString, secondString, 10) ==
              strncat(firstString, secondString, 10));
  fail_unless(s21_strncat(firstString, secondString, 20) ==
              strncat(firstString, secondString, 20));
  fail_unless(s21_strncat(secondString, firstString, 1) ==
              strncat(secondString, firstString, 1));
  fail_unless(s21_strncat(secondString, firstString, 10) ==
              strncat(secondString, firstString, 10));
  fail_unless(s21_strncat(secondString, firstString, 20) ==
              strncat(secondString, firstString, 20));
}
END_TEST

/* Test for s21_strncmp */

START_TEST(s21_strncmp_test) {
  char firstString[1024] = {0};
  char secondString[256] = {0};
  strcat(firstString, "PWC REDAN");
  strcat(secondString, "PWC WAGNER");
  fail_unless(s21_strncmp(firstString, secondString, 3) ==
              strncmp(firstString, secondString, 3));
  fail_unless(s21_strncmp(firstString, secondString, 10) ==
              strncmp(firstString, secondString, 10));
  fail_unless(s21_strncmp(firstString, secondString, 15) ==
              strncmp(firstString, secondString, 15));
  fail_unless(s21_strncmp(firstString, secondString, 256) ==
              strncmp(firstString, secondString, 256));
  memset(firstString, '\0', 1024);
  strcat(firstString, "solo\tvey");
  memset(secondString, '\0', 256);
  strcat(secondString, "voro\tbey");
  fail_unless(s21_strncmp(secondString, firstString, 0) ==
              strncmp(secondString, firstString, 0));
  fail_unless(s21_strncmp(secondString, firstString, 3) ==
              strncmp(secondString, firstString, 3));
  fail_unless(s21_strncmp(secondString, firstString, 5) ==
              strncmp(secondString, firstString, 5));
  fail_unless(s21_strncmp(secondString, firstString, 10) ==
              strncmp(secondString, firstString, 10));
  fail_unless(s21_strncmp(secondString, firstString, 15) ==
              strncmp(secondString, firstString, 15));
  fail_unless(s21_strncmp(secondString, firstString, 256) ==
              strncmp(secondString, firstString, 256));
}
END_TEST

/* Test for s21_strncpy */

START_TEST(s21_strncpy_test) {
  char firstString[1024] = {0};
  strcat(firstString, "some text");
  char secondString[256] = {0};
  strcat(secondString, "something to copy");
  ck_assert_str_eq(s21_strncpy(firstString, secondString, 0),
                   strncpy(firstString, secondString, 0));
  ck_assert_str_eq(s21_strncpy(firstString, secondString, 5),
                   strncpy(firstString, secondString, 5));
  ck_assert_str_eq(s21_strncpy(firstString, secondString, 10),
                   strncpy(firstString, secondString, 10));
  ck_assert_str_eq(s21_strncpy(firstString, secondString, 15),
                   strncpy(firstString, secondString, 15));
  ck_assert_str_eq(s21_strncpy(firstString, secondString, 256),
                   strncpy(firstString, secondString, 256));
  memset(firstString, '\0', 1024);
  strcat(firstString, "AMOG\tUS\0");
  memset(secondString, '\0', 256);
  strcat(secondString, "sample_text");
  ck_assert_str_eq(s21_strncpy(secondString, firstString, 0),
                   strncpy(secondString, firstString, 0));
  ck_assert_str_eq(s21_strncpy(secondString, firstString, 5),
                   strncpy(secondString, firstString, 5));
  ck_assert_str_eq(s21_strncpy(secondString, firstString, 15),
                   strncpy(secondString, firstString, 15));
  ck_assert_str_eq(s21_strncpy(secondString, firstString, 30),
                   strncpy(secondString, firstString, 30));
  ck_assert_str_eq(s21_strncpy(secondString, firstString, 256),
                   strncpy(secondString, firstString, 256));
}
END_TEST

/* Test for s21_strpbrk */

START_TEST(s21_strpbrk_test) {
  char firstString[1024] = {0};
  char secondString[256] = {0};
  strcat(firstString, "test_text\ttext");
  strcat(secondString, "zzzzzzz_\t");
  fail_unless(s21_strpbrk(firstString, secondString) ==
              strpbrk(firstString, secondString));
  fail_unless(s21_strpbrk(secondString, firstString) ==
              strpbrk(secondString, firstString));
  ck_assert_str_eq(s21_strpbrk(firstString, secondString),
                   strpbrk(firstString, secondString));
  ck_assert_str_eq(s21_strpbrk(secondString, firstString),
                   strpbrk(secondString, firstString));
  memset(firstString, '\0', 1024);
  strcat(firstString, "LOST: Z-8-15-16-23-42");
  memset(secondString, '\0', 256);
  strcat(secondString, "1234567890");
  fail_unless(s21_strpbrk(firstString, secondString) ==
              strpbrk(firstString, secondString));
  fail_unless(s21_strpbrk(secondString, firstString) ==
              strpbrk(secondString, firstString));
  ck_assert_str_eq(s21_strpbrk(firstString, secondString),
                   strpbrk(firstString, secondString));
  ck_assert_str_eq(s21_strpbrk(secondString, firstString),
                   strpbrk(secondString, firstString));
  memset(firstString, '\0', 1024);
  fail_unless(s21_strpbrk(firstString, secondString) ==
              strpbrk(firstString, secondString));
}
END_TEST

/* Test for s21_strstr */

START_TEST(s21_strstr_test) {
  char haystack[1024] = {0};
  char needle[256] = "balls";
  char needle2[256] = "nite";
  char needle3[256] = "I";
  char needle4[256] = "\0";
  char needle5[256] = " ";
  char needle6[256] = "fortniteBallsIm g";
  char needle7[256] = "fortniteBallsIm G";
  char needle8[256] = "\tfort\nnite\t";
  strcat(haystack, "fortniteBallsIm G");
  fail_unless(s21_strstr(haystack, needle) == strstr(haystack, needle));
  fail_unless(s21_strstr(haystack, needle2) == strstr(haystack, needle2));
  fail_unless(s21_strstr(haystack, needle3) == strstr(haystack, needle3));
  fail_unless(s21_strstr(haystack, needle4) == strstr(haystack, needle4));
  fail_unless(s21_strstr(haystack, needle5) == strstr(haystack, needle5));
  fail_unless(s21_strstr(haystack, needle6) == strstr(haystack, needle6));
  fail_unless(s21_strstr(haystack, needle7) == strstr(haystack, needle7));
  fail_unless(s21_strstr(haystack, needle8) == strstr(haystack, needle8));
}
END_TEST

/* Test for s21_strtok */

START_TEST(s21_strtok_test) {
  char firstString[1024] = {0};
  char delim[256] = "/";
  char delim9[256] = "/";
  char delim2[256] = "|";
  char delim3[256] = "\\";
  char delim4[256] = " ";
  char delim5[256] = "1";
  char delim6[256] = "Z";
  char delim7[256] = ".";
  char delim8[256] = ":";
  strcat(firstString, "FORT/NI|TE\\BAL SS1SUSZPAUK.TROLL:FACE");
  ck_assert_str_eq(s21_strtok(firstString, delim), strtok(firstString, delim));
  ck_assert_str_eq(s21_strtok(firstString, delim2),
                   strtok(firstString, delim2));
  ck_assert_str_eq(s21_strtok(firstString, delim3),
                   strtok(firstString, delim3));
  ck_assert_str_eq(s21_strtok(firstString, delim4),
                   strtok(firstString, delim4));
  ck_assert_str_eq(s21_strtok(firstString, delim5),
                   strtok(firstString, delim5));
  ck_assert_str_eq(s21_strtok(firstString, delim6),
                   strtok(firstString, delim6));
  ck_assert_str_eq(s21_strtok(firstString, delim7),
                   strtok(firstString, delim7));
  ck_assert_str_eq(s21_strtok(firstString, delim8),
                   strtok(firstString, delim8));
  fail_unless(s21_strtok(firstString, delim) == strtok(firstString, delim));
  fail_unless(s21_strtok(firstString, delim2) == strtok(firstString, delim2));
  fail_unless(s21_strtok(firstString, delim3) == strtok(firstString, delim3));
  fail_unless(s21_strtok(firstString, delim4) == strtok(firstString, delim4));
  fail_unless(s21_strtok(firstString, delim5) == strtok(firstString, delim5));
  fail_unless(s21_strtok(firstString, delim6) == strtok(firstString, delim6));
  fail_unless(s21_strtok(firstString, delim7) == strtok(firstString, delim7));
  char *my_strtok = s21_strtok(firstString, delim);
  char *orig_strtok = strtok(firstString, delim9);
  while (my_strtok != s21_NULL) {
    ck_assert_str_eq(my_strtok, orig_strtok);
    my_strtok = s21_strtok(s21_NULL, delim);
    orig_strtok = strtok(s21_NULL, delim9);
  }
}
END_TEST

START_TEST(s21_to_upper_test) {
  char *string = "aboba";
  char *newString = s21_to_upper(string);
  if (newString) {
    ck_assert_str_eq(s21_to_upper(newString), "ABOBA");
    free(newString);
  }
}
END_TEST

START_TEST(s21_to_upper_test2) {
  char *string = "fOrTnItE";
  char *newString = s21_to_upper(string);
  if (newString) {
    ck_assert_str_eq(s21_to_upper(newString), "FORTNITE");
    free(newString);
  }
}
END_TEST

START_TEST(s21_to_lower_test) {
  char *string = "ABOBA";
  char *newString = s21_to_lower(string);
  if (newString) {
    ck_assert_str_eq(newString, "aboba");
    free(newString);
  }
}
END_TEST

START_TEST(s21_to_lower_test2) {
  char *string = "FoRtNiTe";
  char *newString = s21_to_lower(string);
  if (newString) {
    ck_assert_str_eq(newString, "fortnite");
    free(newString);
  }
}
END_TEST

START_TEST(s21_to_lower_test3) {
  char *string = "BAllz";
  char *newString = s21_to_lower(string);
  if (newString) {
    ck_assert_str_eq(newString, "ballz");
    free(newString);
  }
}
END_TEST

START_TEST(s21_to_lower_test4) {
  char *string = "a240A2B2022Aa";
  char *newString = s21_to_lower(string);
  if (newString) {
    ck_assert_str_eq(newString, "a240a2b2022aa");
    free(newString);
  }
}
END_TEST

START_TEST(s21_strcat_test) {
  char string[2048] = "some text";
  char cat_string[256] = "yayaytayaa";
  char string2[2048] = "\t   \t   \t a";
  char cat_string2[256] = "y";
  char string3[2048] = "SomeText    ";
  char cat_string3[256] = "";
  fail_unless(s21_strcat(string, cat_string), strcat(string, cat_string));
  fail_unless(s21_strcat(string2, cat_string2), strcat(string2, cat_string2));
  fail_unless(s21_strcat(string3, cat_string3), strcat(string3, cat_string3));
}
END_TEST

START_TEST(s21_strrchr_test) {
  char firstString[1024] = {0};
  strcat(firstString, "fortnite");
  char secondString[256] = {0};
  strcat(secondString, "ballz");
  fail_unless(s21_strrchr(firstString, 't') == strrchr(firstString, 't'));
  fail_unless(s21_strrchr(secondString, 'z') == strrchr(secondString, 'z'));
  fail_unless(s21_strrchr(firstString, '?') == strrchr(firstString, '?'));
  fail_unless(s21_strrchr(firstString, '\t') == strrchr(firstString, '\t'));
  fail_unless(s21_strrchr(secondString, '%') == strrchr(secondString, '%'));
  fail_unless(s21_strrchr(secondString, 'A') == strrchr(secondString, 'A'));
  memset(firstString, '\0', 1024);
  strcat(firstString, "\tABOBA\t");
  memset(secondString, '\0', 256);
  strcat(secondString, "Some intellectual text: ");
  ck_assert_ptr_null(s21_strrchr(firstString, 'a'));
  ck_assert_ptr_null(strrchr(firstString, 'a'));
  ck_assert_ptr_null(s21_strrchr(firstString, '?'));
  ck_assert_ptr_null(strrchr(firstString, '?'));
  ck_assert_ptr_null(s21_strrchr(secondString, '%'));
  ck_assert_ptr_null(strrchr(secondString, '%'));
  ck_assert_str_eq(s21_strrchr(firstString, '\t'), strrchr(firstString, '\t'));
  ck_assert_str_eq(s21_strrchr(secondString, 'S'), strrchr(secondString, 'S'));
  ck_assert_str_eq(s21_strrchr(secondString, ':'), strrchr(secondString, ':'));
}
END_TEST

START_TEST(s21_insert_test) {
  char firstString[2048] = {0};
  strcat(firstString, "some text");
  char secondString[2048] = {0};
  strcat(secondString, "TEXT");
  char *newString = s21_insert(firstString, secondString, 2);
  if (newString) {
    ck_assert_str_eq(newString, "soTEXTme text");
    free(newString);
  }
}
END_TEST

START_TEST(s21_insert_test2) {
  char firstString[2048] = {0};
  strcat(firstString, "some text");
  char secondString[2048] = {0};
  strcat(secondString, "TEXT");
  char *newString = s21_insert(firstString, secondString, 5);
  if (newString) {
    ck_assert_str_eq(newString, "some TEXTtext");
    free(newString);
  }
}
END_TEST

START_TEST(s21_insert_test3) {
  char firstString[2048] = {0};
  strcat(firstString, "some text");
  char secondString[2048] = {0};
  strcat(secondString, "TEXT");
  char *newString = s21_insert(firstString, secondString, 0);
  if (newString) {
    ck_assert_str_eq(newString, "TEXTsome text");
    free(newString);
  }
}
END_TEST

START_TEST(s21_insert_test4) {
  char firstString[2048] = {0};
  strcat(firstString, "some text");
  char secondString[2048] = {0};
  strcat(secondString, "TEXT");
  char *newString = s21_insert(firstString, secondString, 11);
  if (newString) {
    ck_assert_ptr_null(newString);
    free(newString);
  }
}
END_TEST

START_TEST(s21_insert_test5) {
  char firstString[2048] = {0};
  strcat(firstString, "some text");
  char secondString[2048] = {0};
  strcat(secondString, "TEXT");
  char *newString = s21_insert(firstString, secondString, -11);
  if (newString) {
    ck_assert_ptr_null(newString);
    free(newString);
  }
}
END_TEST

START_TEST(s21_insert_test6) {
  char firstString[2048] = {0};
  char secondString[2048] = {0};
  strcat(secondString, "TEXT");
  char *newString = s21_insert(firstString, secondString, 0);
  if (newString) {
    ck_assert_str_eq(newString, "TEXT");
    free(newString);
  }
}
END_TEST

START_TEST(s21_trim_test) {
  char firstString[2048] = {0};
  strcat(firstString, "nanannsnfortnite ban llzannnana");
  char *trimString = "na";
  char *newString = s21_trim(firstString, trimString);
  if (newString) {
    ck_assert_str_eq(newString, "snfortnite ban llz");
    free(newString);
  }
}
END_TEST

START_TEST(s21_trim_test2) {
  char firstString[2048] = {0};
  strcat(firstString, "!!  Hello, World!");
  char *newString = s21_trim(firstString, "!");
  if (newString) {
    ck_assert_str_eq(newString, "  Hello, World");
    free(newString);
  }
}
END_TEST

START_TEST(s21_trim_test3) {
  char firstString[2048] = {0};
  strcat(firstString, "!!  Hello, World!");
  char *newString = s21_trim(firstString, " ");
  if (newString) {
    ck_assert_str_eq(newString, "!!  Hello, World!");
    free(newString);
  }
}
END_TEST

START_TEST(s21_trim_test4) {
  char firstString[2048] = {0};
  strcat(firstString, "!!  Hello, World!");
  char *newString = s21_trim(firstString, " , World!");
  if (newString) {
    ck_assert_str_eq(newString, "He");
    free(newString);
  }
}
END_TEST

START_TEST(s21_sprintf_test) {
  char firstString[20];
  char secondString[20];
  s21_sprintf(firstString, "Fortnite: %c", 'f');
  sprintf(secondString, "Fortnite: %c", 'f');
  ck_assert_str_eq(firstString, secondString);
}
END_TEST

START_TEST(s21_sprintf_test2) {
  char firstString[20];
  char secondString[20];
  s21_sprintf(firstString, "Fortnite: %c", 'b');
  sprintf(secondString, "Fortnite: %c", 'b');
  ck_assert_str_eq(firstString, secondString);
}
END_TEST

START_TEST(s21_sprintf_test3) {
  char firstString[20];
  char secondString[20];
  char c = 'z';
  s21_sprintf(firstString, "Fortnite: %-5c", c);
  sprintf(secondString, "Fortnite: %-5c", c);
  ck_assert_str_eq(firstString, secondString);
}
END_TEST

START_TEST(s21_sprintf_test4) {
  char firstString[20];
  char secondString[20];
  char c = 'v';
  s21_sprintf(firstString, "Fortnite: %5c", c);
  sprintf(secondString, "Fortnite: %5c", c);
  ck_assert_str_eq(firstString, secondString);
}
END_TEST

START_TEST(s21_sprintf_test5) {
  char firstString[20];
  char secondString[20];
  s21_sprintf(firstString, "Fortnite: %lc", 'b');
  sprintf(secondString, "Fortnite: %lc", 'b');
  ck_assert_str_eq(firstString, secondString);
}
END_TEST

START_TEST(s21_sprintf_test6) {
  char firstString[20];
  char secondString[20];
  int d = 69;
  s21_sprintf(firstString, "Int: %d int", d);
  sprintf(secondString, "Int: %d int", d);
  ck_assert_str_eq(firstString, secondString);
}
END_TEST

START_TEST(s21_sprintf_test7) {
  char firstString[20];
  char secondString[20];
  int d = 69;
  s21_sprintf(firstString, "Int: %5d int", d);
  sprintf(secondString, "Int: %5d int", d);
  ck_assert_str_eq(firstString, secondString);
}
END_TEST

START_TEST(s21_sprintf_test8) {
  char firstString[20];
  char secondString[20];
  int d = 69;
  s21_sprintf(firstString, "Int: %5d%d%d int", d, -4, 228);
  sprintf(secondString, "Int: %5d%d%d int", d, -4, 228);
  ck_assert_str_eq(firstString, secondString);
}
END_TEST

START_TEST(s21_sprintf_test9) {
  char firstString[20];
  char secondString[20];
  int d = 69;
  s21_sprintf(firstString, "Int: %1.1d", d);
  sprintf(secondString, "Int: %1.1d", d);
  ck_assert_str_eq(firstString, secondString);
}
END_TEST

START_TEST(s21_sprintf_test10) {
  char firstString[20];
  char secondString[20];
  int d = 69;
  s21_sprintf(firstString, "Int: %.5d", d);
  sprintf(secondString, "Int: %.5d", d);
  ck_assert_str_eq(firstString, secondString);
}
END_TEST

START_TEST(s21_sprintf_test11) {
  char firstString[20];
  char secondString[20];
  int d = 69;
  s21_sprintf(firstString, "Int: %-.5d", d);
  sprintf(secondString, "Int: %-.5d", d);
  ck_assert_str_eq(firstString, secondString);
}
END_TEST

START_TEST(s21_sprintf_test12) {
  char firstString[20];
  char secondString[20];
  int d = -0;
  s21_sprintf(firstString, "Int: %d int", d);
  sprintf(secondString, "Int: %d int", d);
  ck_assert_str_eq(firstString, secondString);
}
END_TEST

START_TEST(s21_sprintf_test13) {
  char firstString[40];
  char secondString[40];
  int d = 2147483647;
  s21_sprintf(firstString, "Int: %d int", d);
  sprintf(secondString, "Int: %d int", d);
  ck_assert_str_eq(firstString, secondString);
}
END_TEST

START_TEST(s21_sprintf_test14) {
  char firstString[40];
  char secondString[40];
  int d = -2147483647;
  s21_sprintf(firstString, "Int: %d int", d);
  sprintf(secondString, "Int: %d int", d);
  ck_assert_str_eq(firstString, secondString);
}
END_TEST

START_TEST(s21_sprintf_test15) {
  char firstString[40];
  char secondString[40];
  long int d = 214748364912;
  s21_sprintf(firstString, "Int: %ld int", d);
  sprintf(secondString, "Int: %ld int", d);
  ck_assert_str_eq(firstString, secondString);
}
END_TEST

START_TEST(s21_sprintf_test16) {
  char firstString[40];
  char secondString[40];
  long int d = -214748364912;
  s21_sprintf(firstString, "Int: %ld int", d);
  sprintf(secondString, "Int: %ld int", d);
  ck_assert_str_eq(firstString, secondString);
}
END_TEST

START_TEST(s21_sprintf_test17) {
  char firstString[40];
  char secondString[40];
  long int d = 9223372036854775807;
  s21_sprintf(firstString, "Int: %ld int", d);
  sprintf(secondString, "Int: %ld int", d);
  ck_assert_str_eq(firstString, secondString);
}
END_TEST

START_TEST(s21_sprintf_test18) {
  char firstString[40];
  char secondString[40];
  long int d = -9223372036854775807;
  s21_sprintf(firstString, "Int: %ld int", d);
  sprintf(secondString, "Int: %ld int", d);
  ck_assert_str_eq(firstString, secondString);
}
END_TEST

START_TEST(s21_sprintf_test19) {
  char firstString[30];
  char secondString[30];
  short int d = 32767;
  s21_sprintf(firstString, "Int: %hd fortnite", d);
  sprintf(secondString, "Int: %hd fortnite", d);
  ck_assert_str_eq(firstString, secondString);
}
END_TEST

START_TEST(s21_sprintf_test20) {
  char firstString[30];
  char secondString[30];
  int d = 327699;
  s21_sprintf(firstString, "Int: %11.10d fortnite", d);
  sprintf(secondString, "Int: %11.10d fortnite", d);
  ck_assert_str_eq(firstString, secondString);
}
END_TEST

START_TEST(s21_sprintf_test21) {
  char firstString[20];
  char secondString[20];
  int d = 69;
  s21_sprintf(firstString, "Int: %5i%i%i int", d, -4, 228);
  sprintf(secondString, "Int: %5i%i%i int", d, -4, 228);
  ck_assert_str_eq(firstString, secondString);
}
END_TEST

START_TEST(s21_sprintf_test22) {
  char firstString[20];
  char secondString[20];
  int d = 69;
  s21_sprintf(firstString, "Int: %1.1i", d);
  sprintf(secondString, "Int: %1.1i", d);
  ck_assert_str_eq(firstString, secondString);
}
END_TEST

START_TEST(s21_sprintf_test23) {
  char firstString[20];
  char secondString[20];
  int d = 69;
  s21_sprintf(firstString, "Int: %.5i", d);
  sprintf(secondString, "Int: %.5i", d);
  ck_assert_str_eq(firstString, secondString);
}
END_TEST

START_TEST(s21_sprintf_test24) {
  char firstString[20];
  char secondString[20];
  int d = 69;
  s21_sprintf(firstString, "Int: %-.5i", d);
  sprintf(secondString, "Int: %-.5i", d);
  ck_assert_str_eq(firstString, secondString);
}
END_TEST

START_TEST(s21_sprintf_test25) {
  char firstString[20];
  char secondString[20];
  int d = -0;
  s21_sprintf(firstString, "Int: %i int", d);
  sprintf(secondString, "Int: %i int", d);
  ck_assert_str_eq(firstString, secondString);
}
END_TEST

START_TEST(s21_sprintf_test26) {
  char firstString[40];
  char secondString[40];
  int d = 2147483647;
  s21_sprintf(firstString, "Int: %i int", d);
  sprintf(secondString, "Int: %i int", d);
  ck_assert_str_eq(firstString, secondString);
}
END_TEST

START_TEST(s21_sprintf_test27) {
  char firstString[40];
  char secondString[40];
  int d = -2147483647;
  s21_sprintf(firstString, "Int: %i int", d);
  sprintf(secondString, "Int: %i int", d);
  ck_assert_str_eq(firstString, secondString);
}
END_TEST

START_TEST(s21_sprintf_test28) {
  char firstString[40];
  char secondString[40];
  long int d = 214748364912;
  s21_sprintf(firstString, "Int: %li int", d);
  sprintf(secondString, "Int: %li int", d);
  ck_assert_str_eq(firstString, secondString);
}
END_TEST

START_TEST(s21_sprintf_test29) {
  char firstString[40];
  char secondString[40];
  long int d = -214748364912;
  s21_sprintf(firstString, "Int: %li int", d);
  sprintf(secondString, "Int: %li int", d);
  ck_assert_str_eq(firstString, secondString);
}
END_TEST

START_TEST(s21_sprintf_test30) {
  char firstString[40];
  char secondString[40];
  long int d = 9223372036854775807;
  s21_sprintf(firstString, "Int: %li int", d);
  sprintf(secondString, "Int: %li int", d);
  ck_assert_str_eq(firstString, secondString);
}
END_TEST

START_TEST(s21_sprintf_test31) {
  char firstString[40];
  char secondString[40];
  long int d = -9223372036854775807;
  s21_sprintf(firstString, "Int: %li int", d);
  sprintf(secondString, "Int: %li int", d);
  ck_assert_str_eq(firstString, secondString);
}
END_TEST

START_TEST(s21_sprintf_test32) {
  char firstString[30];
  char secondString[30];
  short int d = 32767;
  s21_sprintf(firstString, "Int: %hi fortnite", d);
  sprintf(secondString, "Int: %hi fortnite", d);
  ck_assert_str_eq(firstString, secondString);
}
END_TEST

START_TEST(s21_sprintf_test33) {
  char firstString[30];
  char secondString[30];
  int d = 327699;
  s21_sprintf(firstString, "Int: %11.10i fortnite", d);
  sprintf(secondString, "Int: %11.10i fortnite", d);
  ck_assert_str_eq(firstString, secondString);
}
END_TEST

START_TEST(s21_sprintf_test34) {
  char firstString[40];
  char secondString[40];
  int d = 327710;
  s21_sprintf(firstString, "Int: %-+10.5i fortnite", d);
  sprintf(secondString, "Int: %-+10.5i fortnite", d);
  ck_assert_str_eq(firstString, secondString);
}
END_TEST

START_TEST(s21_sprintf_test35) {
  char firstString[40];
  char secondString[40];
  int d = 327710;
  s21_sprintf(firstString, "Int: %+.5i fortnite", d);
  sprintf(secondString, "Int: %+.5i fortnite", d);
  ck_assert_str_eq(firstString, secondString);
}
END_TEST

START_TEST(s21_sprintf_test36) {
  char firstString[40];
  char secondString[40];
  float f = -13.373;
  s21_sprintf(firstString, "Float: %.6f ballz", f);
  sprintf(secondString, "Float: %.6f ballz", f);
  ck_assert_str_eq(firstString, secondString);
}
END_TEST

START_TEST(s21_sprintf_test37) {
  char firstString[40];
  char secondString[40];
  float f = 13.373;
  s21_sprintf(firstString, "Float: %2.6f ballz", f);
  sprintf(secondString, "Float: %2.6f ballz", f);
  ck_assert_str_eq(firstString, secondString);
}
END_TEST

START_TEST(s21_sprintf_test38) {
  char firstString[40];
  char secondString[40];
  float f = 13.373;
  s21_sprintf(firstString, "Float: %2.2f ballz", f);
  sprintf(secondString, "Float: %2.2f ballz", f);
  ck_assert_str_eq(firstString, secondString);
}
END_TEST

START_TEST(s21_sprintf_test39) {
  char firstString[40];
  char secondString[40];
  float f = 13.373;
  s21_sprintf(firstString, "Float: %2.2f ballz", f);
  sprintf(secondString, "Float: %2.2f ballz", f);
  ck_assert_str_eq(firstString, secondString);
}
END_TEST

START_TEST(s21_sprintf_test40) {
  char firstString[40];
  char secondString[40];
  float f = 1.000210021;
  s21_sprintf(firstString, "Float: %f ballz", f);
  sprintf(secondString, "Float: %f ballz", f);
  ck_assert_str_eq(firstString, secondString);
}
END_TEST

START_TEST(s21_sprintf_test41) {
  char firstString[40];
  char secondString[40];
  float f = 0;
  s21_sprintf(firstString, "Float: %f ballz", f);
  sprintf(secondString, "Float: %f ballz", f);
  ck_assert_str_eq(firstString, secondString);
}
END_TEST

START_TEST(s21_sprintf_test42) {
  char firstString[40];
  char secondString[40];
  float f = 0.;
  s21_sprintf(firstString, "Float: %f ballz", f);
  sprintf(secondString, "Float: %f ballz", f);
  ck_assert_str_eq(firstString, secondString);
}
END_TEST

START_TEST(s21_sprintf_test43) {
  char firstString[40];
  char secondString[40];
  float f = -123.123;
  s21_sprintf(firstString, "Float: %f ballz", f);
  sprintf(secondString, "Float: %f ballz", f);
  ck_assert_str_eq(firstString, secondString);
}
END_TEST

START_TEST(s21_sprintf_test44) {
  char firstString[40];
  char secondString[40];
  float f = -.0000001;
  s21_sprintf(firstString, "Float: %f ballz", f);
  sprintf(secondString, "Float: %f ballz", f);
  ck_assert_str_eq(firstString, secondString);
}
END_TEST

START_TEST(s21_sprintf_test45) {
  char firstString[40];
  char secondString[40];
  float f = -.00001;
  s21_sprintf(firstString, "Float: %f ballz", f);
  sprintf(secondString, "Float: %f ballz", f);
  ck_assert_str_eq(firstString, secondString);
}
END_TEST

START_TEST(s21_sprintf_test46) {
  char firstString[40];
  char secondString[40];
  float f = .00001;
  s21_sprintf(firstString, "Float: %f ballz", f);
  sprintf(secondString, "Float: %f ballz", f);
  ck_assert_str_eq(firstString, secondString);
}
END_TEST

START_TEST(s21_sprintf_test47) {
  char firstString[40];
  char secondString[40];
  float f = -.0000021;
  s21_sprintf(firstString, "Float: %10f ballz", f);
  sprintf(secondString, "Float: %10f ballz", f);
  ck_assert_str_eq(firstString, secondString);
}
END_TEST

START_TEST(s21_sprintf_test48) {
  char firstString[40];
  char secondString[40];
  float f = -.0000021;
  s21_sprintf(firstString, "Float: %3.5f ballz", f);
  sprintf(secondString, "Float: %3.5f ballz", f);
  ck_assert_str_eq(firstString, secondString);
}
END_TEST

START_TEST(s21_sprintf_test49) {
  char firstString[40];
  char secondString[40];
  double f = -.0000021;
  s21_sprintf(firstString, "Double: %3.5lf ballz", f);
  sprintf(secondString, "Double: %3.5lf ballz", f);
  ck_assert_str_eq(firstString, secondString);
}
END_TEST

START_TEST(s21_sprintf_test50) {
  char firstString[40];
  char secondString[40];
  double f = .0000021;
  s21_sprintf(firstString, "Double: %10lf ballz", f);
  sprintf(secondString, "Double: %10lf ballz", f);
  ck_assert_str_eq(firstString, secondString);
}
END_TEST

START_TEST(s21_sprintf_test51) {
  char firstString[256];
  char secondString[256];
  double f = .0000021;
  double f2 = 1551.111235512;
  double f3 = 15231425.12451435;
  double f4 = -12546014.11;
  s21_sprintf(firstString, "Double: %10lf %3.2lf %-lf %+lf ballz", f, f2, f3,
              f4);
  sprintf(secondString, "Double: %10lf %3.2lf %-lf %+lf ballz", f, f2, f3, f4);
  ck_assert_str_eq(firstString, secondString);
}
END_TEST

START_TEST(s21_sprintf_test52) {
  char firstString[40];
  char secondString[40];
  char *s = "text";
  s21_sprintf(firstString, "String: %s sus", s);
  sprintf(secondString, "String: %s sus", s);
  ck_assert_str_eq(firstString, secondString);
}
END_TEST

START_TEST(s21_sprintf_test53) {
  char firstString[40];
  char secondString[40];
  char *s = "text";
  s21_sprintf(firstString, "String: %.3s sus", s);
  sprintf(secondString, "String: %.3s sus", s);
  ck_assert_str_eq(firstString, secondString);
}
END_TEST

START_TEST(s21_sprintf_test54) {
  char firstString[40];
  char secondString[40];
  char *s = "text";
  s21_sprintf(firstString, "String: %.6s sus", s);
  sprintf(secondString, "String: %.6s sus", s);
  ck_assert_str_eq(firstString, secondString);
}
END_TEST

START_TEST(s21_sprintf_test55) {
  char firstString[40];
  char secondString[40];
  char *s = "text with space";
  s21_sprintf(firstString, "String: %6.9s sus", s);
  sprintf(secondString, "String: %6.9s sus", s);
  ck_assert_str_eq(firstString, secondString);
}
END_TEST

START_TEST(s21_sprintf_test56) {
  char firstString[40];
  char secondString[40];
  char *s = "text with space";
  s21_sprintf(firstString, "String: %-6.9s sus", s);
  sprintf(secondString, "String: %-6.9s sus", s);
  ck_assert_str_eq(firstString, secondString);
}
END_TEST

START_TEST(s21_sprintf_test57) {
  char firstString[40];
  char secondString[40];
  wchar_t *s = L"wide chars: ";
  s21_sprintf(firstString, "%-6.9ls", s);
  sprintf(secondString, "%-6.9ls", s);
  ck_assert_str_eq(firstString, secondString);
}
END_TEST

START_TEST(s21_sprintf_test58) {
  char firstString[40];
  char secondString[40];
  wchar_t *s = L"wide chars: ";
  s21_sprintf(firstString, "%6.9ls", s);
  sprintf(secondString, "%6.9ls", s);
  ck_assert_str_eq(firstString, secondString);
}
END_TEST

START_TEST(s21_sprintf_test59) {
  char firstString[40];
  char secondString[40];
  wchar_t *s = L"wide chars: ";
  s21_sprintf(firstString, "ABOBA: %ls", s);
  sprintf(secondString, "ABOBA: %ls", s);
  ck_assert_str_eq(firstString, secondString);
}
END_TEST

START_TEST(s21_sprintf_test60) {
  char firstString[40];
  char secondString[40];
  wchar_t *s = L"wide chars: ";
  s21_sprintf(firstString, "ABOBA: %ls sss", s);
  sprintf(secondString, "ABOBA: %ls sss", s);
  ck_assert_str_eq(firstString, secondString);
}
END_TEST

START_TEST(s21_sprintf_test61) {
  char firstString[30];
  char secondString[30];
  char *format = "wchar: %5c";
  char w = 'c';
  int a = s21_sprintf(firstString, format, w);
  int b = sprintf(secondString, format, w);
  ck_assert_str_eq(firstString, secondString);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(s21_sprintf_test62) {
  char firstString[30];
  char secondString[30];
  char *format = "wchar: %-5lc";
  unsigned long w = L'~';
  int a = s21_sprintf(firstString, format, w);
  int b = sprintf(secondString, format, w);
  ck_assert_str_eq(firstString, secondString);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(s21_sprintf_test63) {
  char firstString[30];
  char secondString[30];
  char *format = "wchar: %lc";
  wchar_t w = L'1';
  int a = s21_sprintf(firstString, format, w);
  int b = sprintf(secondString, format, w);
  ck_assert_str_eq(firstString, secondString);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(s21_sprintf_test64) {
  char firstString[BUFF_SIZE];
  char secondString[BUFF_SIZE];
  char *format = "wchar: %43ls";
  wchar_t w[] = L"àààààà";
  int a = s21_sprintf(firstString, format, w);
  int b = sprintf(secondString, format, w);
  ck_assert_str_eq(firstString, secondString);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(s21_sprintf_test65) {
  char firstString[BUFF_SIZE];
  char secondString[BUFF_SIZE];
  char *format = "wchar: %6.69ls";
  wchar_t w[] = L"àààààà";
  int a = s21_sprintf(firstString, format, w);
  int b = sprintf(secondString, format, w);
  ck_assert_str_eq(firstString, secondString);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(s21_sprintf_test66) {
  char firstString[BUFF_SIZE];
  char secondString[BUFF_SIZE];
  ck_assert_int_eq(
      s21_sprintf(firstString, "%s%s%s%s", "Aboba", " ", "Babybe", "fortnite"),
      sprintf(secondString, "%s%s%s%s", "Aboba", " ", "Babybe", "fortnite"));
  ck_assert_str_eq(firstString, secondString);
}
END_TEST

START_TEST(s21_sprintf_test67) {
  char firstString[40];
  char secondString[40];
  unsigned int u = 69696969;
  s21_sprintf(firstString, "Amogus: %u unsigned", u);
  sprintf(secondString, "Amogus: %u unsigned", u);
  ck_assert_str_eq(firstString, secondString);
}
END_TEST

START_TEST(s21_sprintf_test68) {
  char firstString[40];
  char secondString[40];
  unsigned int u = 69696969;
  s21_sprintf(firstString, "Amogus: %-.5u unsigned", u);
  sprintf(secondString, "Amogus: %-.5u unsigned", u);
  ck_assert_str_eq(firstString, secondString);
}
END_TEST

START_TEST(s21_sprintf_test69) {
  char firstString[50];
  char secondString[50];
  unsigned int u = 69696969;
  s21_sprintf(firstString, "Unsigned: %.5u fortnite", u);
  sprintf(secondString, "Unsigned: %.5u fortnite", u);
  ck_assert_str_eq(firstString, secondString);
}
END_TEST

START_TEST(s21_sprintf_test70) {
  char firstString[40];
  char secondString[40];
  unsigned int u = 69696969;
  s21_sprintf(firstString, "%-.5u aboba", u);
  sprintf(secondString, "%-.5u aboba", u);
  ck_assert_str_eq(firstString, secondString);
}
END_TEST

START_TEST(s21_sprintf_test71) {
  char firstString[40];
  char secondString[40];
  unsigned int u = 1;
  s21_sprintf(firstString, "Unsigned: %u aboba", u);
  sprintf(secondString, "Unsigned: %u aboba", u);
  ck_assert_str_eq(firstString, secondString);
}
END_TEST

START_TEST(s21_sprintf_test72) {
  char firstString[40];
  char secondString[40];
  unsigned int u = -0;
  s21_sprintf(firstString, "Unsigned: %u aboba", u);
  sprintf(secondString, "Unsigned: %u aboba", u);
  ck_assert_str_eq(firstString, secondString);
}
END_TEST

START_TEST(s21_sprintf_test73) {
  char firstString[50];
  char secondString[50];
  unsigned int u = 2147483647;
  s21_sprintf(firstString, "Unsigned: %u aboba", u);
  sprintf(secondString, "Unsigned: %u aboba", u);
  ck_assert_str_eq(firstString, secondString);
}
END_TEST

START_TEST(s21_sprintf_test74) {
  char firstString[50];
  char secondString[50];
  unsigned int u = -2147483647;
  s21_sprintf(firstString, "Unsigned: %u aboba", u);
  sprintf(secondString, "Unsigned: %u aboba", u);
  ck_assert_str_eq(firstString, secondString);
}
END_TEST

START_TEST(s21_sprintf_test75) {
  char firstString[60];
  char secondString[60];
  unsigned long u = 214748364912;
  s21_sprintf(firstString, "Unsigned: %lu aboba", u);
  sprintf(secondString, "Unsigned: %lu aboba", u);
  ck_assert_str_eq(firstString, secondString);
}
END_TEST

START_TEST(s21_sprintf_test76) {
  char firstString[60];
  char secondString[60];
  unsigned long u = -9223372036854775807;
  s21_sprintf(firstString, "Unsigned: %lu aboba", u);
  sprintf(secondString, "Unsigned: %lu aboba", u);
  ck_assert_str_eq(firstString, secondString);
}
END_TEST

START_TEST(s21_sprintf_test77) {
  char firstString[60];
  char secondString[60];
  unsigned long u = 9223372036854775807;
  s21_sprintf(firstString, "Unsigned: %lu aboba", u);
  sprintf(secondString, "Unsigned: %lu aboba", u);
  ck_assert_str_eq(firstString, secondString);
}
END_TEST

START_TEST(s21_sprintf_test78) {
  char firstString[30];
  char secondString[30];
  unsigned short int u = 32767;
  s21_sprintf(firstString, "Unsigned: %hu aboba", u);
  sprintf(secondString, "Unsigned: %hu aboba", u);
  ck_assert_str_eq(firstString, secondString);
}
END_TEST

START_TEST(s21_sprintf_test79) {
  char firstString[30];
  char secondString[30];
  unsigned short int u = 32770;
  s21_sprintf(firstString, "Unsigned: %hu aboba", u);
  sprintf(secondString, "Unsigned: %hu aboba", u);
  ck_assert_str_eq(firstString, secondString);
}
END_TEST

START_TEST(s21_sprintf_test80) {
  char firstString[40];
  char secondString[40];
  unsigned int u = 327710;
  s21_sprintf(firstString, "Unsigned: %11.10u aboba", u);
  sprintf(secondString, "Unsigned: %11.10u aboba", u);
  ck_assert_str_eq(firstString, secondString);
}
END_TEST

START_TEST(s21_sprintf_test81) {
  char firstString[512];
  char secondString[512];
  char *d = "2048";
  s21_sprintf(firstString, "%101s", d);
  sprintf(secondString, "%101s", d);
  ck_assert_str_eq(firstString, secondString);
}
END_TEST

START_TEST(s21_sprintf_test82) {
  char firstString[512];
  char secondString[512];
  char c = 'z';
  s21_sprintf(firstString, "%13lc", c);
  sprintf(secondString, "%13lc", c);
  ck_assert_str_eq(firstString, secondString);
}
END_TEST

START_TEST(s21_sprintf_test83) {
  char firstString[512];
  char secondString[512];
  char c = 'z';
  s21_sprintf(firstString, "%-13lc", c);
  sprintf(secondString, "%-13lc", c);
  ck_assert_str_eq(firstString, secondString);
}
END_TEST

START_TEST(s21_sprintf_test84) {
  char firstString[512];
  char secondString[512];
  char *format = "wchar: %lc";
  wchar_t w = L'A';
  int a = s21_sprintf(firstString, format, w);
  int b = s21_sprintf(secondString, format, w);
  ck_assert_str_eq(firstString, secondString);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(s21_sprintf_test85) {
  char firstString[512];
  char secondString[512];
  char *format = "%s";
  char *val = "21S ASDOADBFAUODFBAS agsdfjgoals 2341";
  int a = s21_sprintf(firstString, format, val);
  int b = sprintf(secondString, format, val);
  ck_assert_int_eq(a, b);
  ck_assert_str_eq(firstString, secondString);
}
END_TEST

START_TEST(s21_sprintf_test86) {
  char firstString[512];
  char secondString[512];
  char *format = "%15s";
  char *val = "21S ASDOADBFAUODFBAS agsdfjgoals 2341";
  int a = s21_sprintf(firstString, format, val);
  int b = sprintf(secondString, format, val);
  ck_assert_int_eq(a, b);
  ck_assert_str_eq(firstString, secondString);
}
END_TEST

START_TEST(s21_sprintf_test87) {
  char firstString[512];
  char secondString[512];
  char *format = "%.15s";
  char *val = "21S ASDOADBFAUODFBAS agsdfjgoals 2341";
  int a = s21_sprintf(firstString, format, val);
  int b = sprintf(secondString, format, val);
  ck_assert_int_eq(a, b);
  ck_assert_str_eq(firstString, secondString);
}
END_TEST

START_TEST(s21_sprintf_test88) {
  char firstString[512];
  char secondString[512];
  char *format = "%15.15s";
  char *val = "21S ASDOADBFAUODFBAS agsdfjgoals 2341";
  int a = s21_sprintf(firstString, format, val);
  int b = sprintf(secondString, format, val);
  ck_assert_int_eq(a, b);
  ck_assert_str_eq(firstString, secondString);
}
END_TEST

START_TEST(s21_sprintf_test89) {
  char firstString[512];
  char secondString[512];
  char *format = "%-6.9s";
  char *val = "21S ASDOADBFAUODFBAS agsdfjgoals 2341";
  int a = s21_sprintf(firstString, format, val);
  int b = sprintf(secondString, format, val);
  ck_assert_int_eq(a, b);
  ck_assert_str_eq(firstString, secondString);
}
END_TEST

START_TEST(s21_sprintf_test90) {
  char firstString[512];
  char secondString[512];
  char *format = "%+-6.9s";
  char *val = "21S ASDOADBFAUODFBAS agsdfjgoals 2341";
  int a = s21_sprintf(firstString, format, val);
  int b = sprintf(secondString, format, val);
  ck_assert_int_eq(a, b);
  ck_assert_str_eq(firstString, secondString);
}
END_TEST

START_TEST(s21_sprintf_test91) {
  char firstString[512];
  char secondString[512];
  char *format = "% s";
  char *val = "21S ASDOADBFAUODFBAS agsdfjgoals 2341";
  int a = s21_sprintf(firstString, format, val);
  int b = sprintf(secondString, format, val);
  ck_assert_int_eq(a, b);
  ck_assert_str_eq(firstString, secondString);
}
END_TEST

START_TEST(s21_sprintf_test92) {
  char firstString[512];
  char secondString[512];
  char *format = "%s";
  char *val = "dA 9sDNsa NAID saDYBU DSnaJ Sd";
  int a = s21_sprintf(firstString, format, val);
  int b = sprintf(secondString, format, val);
  ck_assert_int_eq(a, b);
  ck_assert_str_eq(firstString, secondString);
}
END_TEST

START_TEST(s21_sprintf_test93) {
  char firstString[512];
  char secondString[512];
  char *format = "%s%s%s";
  char *val = "dA 9sDNsa NAID)";
  int a = s21_sprintf(firstString, format, val, val, val);
  int b = sprintf(secondString, format, val, val, val);
  ck_assert_int_eq(a, b);
  ck_assert_str_eq(firstString, secondString);
}
END_TEST

START_TEST(s21_sprintf_test94) {
  char firstString[512];
  char secondString[512];
  char *format = "wchar: %hs";
  wchar_t w[] = L"àààààà";
  int a = s21_sprintf(firstString, format, w);
  int b = sprintf(secondString, format, w);
  ck_assert_int_eq(a, b);
  ck_assert_str_eq(firstString, secondString);
}
END_TEST

char c[255] = {}, d[255] = {}, x1 = 't';
int n = 2100, n1 = 0, n2 = -21;
short sh = 123, sh1 = -123;
float f = 21.21, f1 = -21.21;
long int lg = 12345678912345, lg1 = -12345678912345;

START_TEST(s21_sprintf_test_percent) {
  s21_sprintf(c, "%% %d", n);
  sprintf(d, "%% %d", n);
  ck_assert_str_eq(c, d);
}
END_TEST

START_TEST(s21_sprintf_test_d) {
  s21_sprintf(c, "%d %d %d %hd %hd %ld %ld %10ld", n, n1, n2, sh, sh1, lg, lg1,
              lg1);
  sprintf(d, "%d %d %d %hd %hd %ld %ld %10ld", n, n1, n2, sh, sh1, lg, lg1,
          lg1);
  ck_assert_str_eq(c, d);
}
END_TEST

START_TEST(s21_sprintf_test_d2) {
  s21_sprintf(c, "%-10d %10d %10d %2d", 21, n2, n, 10);
  sprintf(d, "%-10d %10d %10d %2d", 21, n2, n, 10);
  ck_assert_str_eq(c, d);
}
END_TEST

START_TEST(s21_sprintf_test_d3) {
  s21_sprintf(c, "%3.9d %.d %+-.5d %-+9.6d %.10d %.10d %2.2d %.d %.d % d %.0d",
              10, n, n2, 42, 21, 10, n, n2, -21, x1, 21);
  sprintf(d, "%3.9d %.d %+-.5d %-+9.6d %.10d %.10d %2.2d %.d %.d % d %.0d", 10,
          n, n2, 42, 21, 10, n, n2, -21, x1, 21);
  ck_assert_str_eq(c, d);
}
END_TEST

START_TEST(s21_sprintf_test_c) {
  s21_sprintf(c, "%c %10c %-10c", '!', 'a', 'b');
  sprintf(d, "%c %10c %-10c", '!', 'a', 'b');
  ck_assert_str_eq(c, d);
}
END_TEST

START_TEST(s21_sprintf_test_c2) {
  s21_sprintf(c, "%c %c %c", CHAR_MAX, CHAR_MIN, UCHAR_MAX);
  sprintf(d, "%c %c %c", CHAR_MAX, CHAR_MIN, UCHAR_MAX);
  ck_assert_str_eq(c, d);
}
END_TEST

START_TEST(s21_sprintf_test_s) {
  s21_sprintf(c, "%s %10s %-10s %-3s %.s %.3s %.10s", "hello", "aboba", "hello",
              "aboba", "hello", "aboba", "hello");
  sprintf(d, "%s %10s %-10s %-3s %.s %.3s %.10s", "hello", "aboba", "hello",
          "aboba", "hello", "aboba", "hello");
  ck_assert_str_eq(c, d);
}
END_TEST

START_TEST(s21_sprintf_test_s2) {
  s21_sprintf(c, "%ls %10ls %-10ls %-3ls %.ls %.3ls %.10ls", L"hello", L"aboba",
              L"hello", L"aboba", L"hello", L"aboba", L"hello");
  sprintf(d, "%ls %10ls %-10ls %-3ls %.ls %.3ls %.10ls", L"hello", L"aboba",
          L"hello", L"aboba", L"hello", L"aboba", L"hello");
  ck_assert_str_eq(c, d);
}

Suite *s21_memchr_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("\033[0;32ms21_memchr\033[0m");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_memchr_test);
  suite_add_tcase(s, tc_core);
  return s;
}

Suite *s21_memcmp_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("\033[0;32ms21_memcmp\033[0m");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_memcmp_test);
  suite_add_tcase(s, tc_core);
  return s;
}

Suite *s21_memcpy_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("\033[0;32ms21_memcpy\033[0m");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_memcpy_test);
  suite_add_tcase(s, tc_core);
  return s;
}

Suite *s21_memset_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("\033[0;32ms21_memset\033[0m");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_memset_test);
  suite_add_tcase(s, tc_core);
  return s;
}

Suite *s21_strchr_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("\033[0;32ms21_strchr\033[0m");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_strchr_test);
  suite_add_tcase(s, tc_core);
  return s;
}

Suite *s21_strcspn_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("\033[0;32ms21_strcspn\033[0m");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_strcspn_test);
  suite_add_tcase(s, tc_core);
  return s;
}

Suite *s21_strerror_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create(("\033[0;32ms21_strerror\033[0m"));
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_strerror_test);
  suite_add_tcase(s, tc_core);
  return s;
}

Suite *s21_strlen_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create(("\033[0;32ms21_strlen\033[0m"));
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_strlen_test);
  suite_add_tcase(s, tc_core);
  return s;
}

Suite *s21_strncat_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create(("\033[0;32ms21_strncat\033[0m"));
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_strncat_test);
  suite_add_tcase(s, tc_core);
  return s;
}

Suite *s21_strncmp_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("\033[0;32ms21_strncmp\033[0m");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_strncmp_test);
  suite_add_tcase(s, tc_core);
  return s;
}

Suite *s21_strncpy_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("\033[0;32ms21_strncpy\033[0m");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_strncpy_test);
  suite_add_tcase(s, tc_core);
  return s;
}

Suite *s21_strpbrk_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("\033[0;32ms21_strpbrk\033[0m");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_strpbrk_test);
  suite_add_tcase(s, tc_core);
  return s;
}

Suite *s21_strstr_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("\033[0;32ms21_strstr\033[0m");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_strstr_test);
  suite_add_tcase(s, tc_core);
  return s;
}

Suite *s21_strtok_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("\033[0;32ms21_strtok\033[0m");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_strtok_test);
  suite_add_tcase(s, tc_core);
  return s;
}

Suite *s21_to_upper_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("\033[0;32ms21_to_upper\033[0m");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_to_upper_test);
  tcase_add_test(tc_core, s21_to_upper_test2);
  suite_add_tcase(s, tc_core);
  return s;
}

Suite *s21_to_lower_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("\033[0;32ms21_to_lower\033[0m");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_to_lower_test);
  tcase_add_test(tc_core, s21_to_lower_test2);
  tcase_add_test(tc_core, s21_to_lower_test3);
  tcase_add_test(tc_core, s21_to_lower_test4);
  suite_add_tcase(s, tc_core);
  return s;
}

Suite *s21_strcat_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("\033[0;32ms21_strcat\033[0m");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_strcat_test);
  suite_add_tcase(s, tc_core);
  return s;
}

Suite *s21_strrchr_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("\033[0;32ms21_strrchr\033[0m");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_strrchr_test);
  suite_add_tcase(s, tc_core);
  return s;
}

Suite *s21_insert_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("\033[0;32ms21_insert\033[0m");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_insert_test);
  tcase_add_test(tc_core, s21_insert_test2);
  tcase_add_test(tc_core, s21_insert_test3);
  tcase_add_test(tc_core, s21_insert_test4);
  tcase_add_test(tc_core, s21_insert_test5);
  tcase_add_test(tc_core, s21_insert_test6);
  suite_add_tcase(s, tc_core);
  return s;
}

Suite *s21_trim_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("\033[0;32ms21_trim\033[0m");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_trim_test);
  tcase_add_test(tc_core, s21_trim_test2);
  tcase_add_test(tc_core, s21_trim_test3);
  tcase_add_test(tc_core, s21_trim_test4);
  suite_add_tcase(s, tc_core);
  return s;
}

Suite *s21_sprintf_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("\033[0;32ms21_sprintf\033[0m");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_sprintf_test);
  tcase_add_test(tc_core, s21_sprintf_test2);
  tcase_add_test(tc_core, s21_sprintf_test3);
  tcase_add_test(tc_core, s21_sprintf_test4);
  tcase_add_test(tc_core, s21_sprintf_test5);
  tcase_add_test(tc_core, s21_sprintf_test6);
  tcase_add_test(tc_core, s21_sprintf_test7);
  tcase_add_test(tc_core, s21_sprintf_test8);
  tcase_add_test(tc_core, s21_sprintf_test9);
  tcase_add_test(tc_core, s21_sprintf_test10);
  tcase_add_test(tc_core, s21_sprintf_test11);
  tcase_add_test(tc_core, s21_sprintf_test12);
  tcase_add_test(tc_core, s21_sprintf_test13);
  tcase_add_test(tc_core, s21_sprintf_test14);
  tcase_add_test(tc_core, s21_sprintf_test15);
  tcase_add_test(tc_core, s21_sprintf_test16);
  tcase_add_test(tc_core, s21_sprintf_test17);
  tcase_add_test(tc_core, s21_sprintf_test18);
  tcase_add_test(tc_core, s21_sprintf_test19);
  tcase_add_test(tc_core, s21_sprintf_test20);
  tcase_add_test(tc_core, s21_sprintf_test21);
  tcase_add_test(tc_core, s21_sprintf_test22);
  tcase_add_test(tc_core, s21_sprintf_test23);
  tcase_add_test(tc_core, s21_sprintf_test24);
  tcase_add_test(tc_core, s21_sprintf_test25);
  tcase_add_test(tc_core, s21_sprintf_test26);
  tcase_add_test(tc_core, s21_sprintf_test27);
  tcase_add_test(tc_core, s21_sprintf_test28);
  tcase_add_test(tc_core, s21_sprintf_test29);
  tcase_add_test(tc_core, s21_sprintf_test30);
  tcase_add_test(tc_core, s21_sprintf_test31);
  tcase_add_test(tc_core, s21_sprintf_test32);
  tcase_add_test(tc_core, s21_sprintf_test33);
  tcase_add_test(tc_core, s21_sprintf_test34);
  tcase_add_test(tc_core, s21_sprintf_test35);
  tcase_add_test(tc_core, s21_sprintf_test36);
  tcase_add_test(tc_core, s21_sprintf_test37);
  tcase_add_test(tc_core, s21_sprintf_test38);
  tcase_add_test(tc_core, s21_sprintf_test39);
  tcase_add_test(tc_core, s21_sprintf_test40);
  tcase_add_test(tc_core, s21_sprintf_test41);
  tcase_add_test(tc_core, s21_sprintf_test42);
  tcase_add_test(tc_core, s21_sprintf_test43);
  tcase_add_test(tc_core, s21_sprintf_test44);
  tcase_add_test(tc_core, s21_sprintf_test45);
  tcase_add_test(tc_core, s21_sprintf_test46);
  tcase_add_test(tc_core, s21_sprintf_test47);
  tcase_add_test(tc_core, s21_sprintf_test48);
  tcase_add_test(tc_core, s21_sprintf_test49);
  tcase_add_test(tc_core, s21_sprintf_test50);
  tcase_add_test(tc_core, s21_sprintf_test51);
  tcase_add_test(tc_core, s21_sprintf_test52);
  tcase_add_test(tc_core, s21_sprintf_test53);
  tcase_add_test(tc_core, s21_sprintf_test54);
  tcase_add_test(tc_core, s21_sprintf_test55);
  tcase_add_test(tc_core, s21_sprintf_test56);
  tcase_add_test(tc_core, s21_sprintf_test57);
  tcase_add_test(tc_core, s21_sprintf_test58);
  tcase_add_test(tc_core, s21_sprintf_test59);
  tcase_add_test(tc_core, s21_sprintf_test60);
  tcase_add_test(tc_core, s21_sprintf_test61);
  tcase_add_test(tc_core, s21_sprintf_test62);
  tcase_add_test(tc_core, s21_sprintf_test63);
  tcase_add_test(tc_core, s21_sprintf_test64);
  tcase_add_test(tc_core, s21_sprintf_test65);
  tcase_add_test(tc_core, s21_sprintf_test66);
  tcase_add_test(tc_core, s21_sprintf_test67);
  tcase_add_test(tc_core, s21_sprintf_test68);
  tcase_add_test(tc_core, s21_sprintf_test69);
  tcase_add_test(tc_core, s21_sprintf_test70);
  tcase_add_test(tc_core, s21_sprintf_test71);
  tcase_add_test(tc_core, s21_sprintf_test72);
  tcase_add_test(tc_core, s21_sprintf_test73);
  tcase_add_test(tc_core, s21_sprintf_test74);
  tcase_add_test(tc_core, s21_sprintf_test75);
  tcase_add_test(tc_core, s21_sprintf_test76);
  tcase_add_test(tc_core, s21_sprintf_test77);
  tcase_add_test(tc_core, s21_sprintf_test78);
  tcase_add_test(tc_core, s21_sprintf_test79);
  tcase_add_test(tc_core, s21_sprintf_test80);
  tcase_add_test(tc_core, s21_sprintf_test81);
  tcase_add_test(tc_core, s21_sprintf_test82);
  tcase_add_test(tc_core, s21_sprintf_test83);
  tcase_add_test(tc_core, s21_sprintf_test84);
  tcase_add_test(tc_core, s21_sprintf_test85);
  tcase_add_test(tc_core, s21_sprintf_test86);
  tcase_add_test(tc_core, s21_sprintf_test87);
  tcase_add_test(tc_core, s21_sprintf_test88);
  tcase_add_test(tc_core, s21_sprintf_test89);
  tcase_add_test(tc_core, s21_sprintf_test90);
  tcase_add_test(tc_core, s21_sprintf_test91);
  tcase_add_test(tc_core, s21_sprintf_test92);
  tcase_add_test(tc_core, s21_sprintf_test93);
  tcase_add_test(tc_core, s21_sprintf_test94);
  tcase_add_test(tc_core, s21_sprintf_test_percent);
  tcase_add_test(tc_core, s21_sprintf_test_d);
  tcase_add_test(tc_core, s21_sprintf_test_d2);
  tcase_add_test(tc_core, s21_sprintf_test_d3);
  tcase_add_test(tc_core, s21_sprintf_test_c);
  tcase_add_test(tc_core, s21_sprintf_test_c2);
  tcase_add_test(tc_core, s21_sprintf_test_s);
  tcase_add_test(tc_core, s21_sprintf_test_s2);
  suite_add_tcase(s, tc_core);
  return s;
}

void case_test(Suite *s, int *fail) {
  SRunner *runner = srunner_create(s);
  srunner_run_all(runner, CK_NORMAL);
  *fail = srunner_ntests_failed(runner);
  srunner_free(runner);
}

int main() {
  int failed = 0;
  case_test(s21_memchr_suite(), &failed);
  case_test(s21_memcmp_suite(), &failed);
  case_test(s21_memcpy_suite(), &failed);
  case_test(s21_memset_suite(), &failed);
  case_test(s21_strchr_suite(), &failed);
  case_test(s21_strcspn_suite(), &failed);
  case_test(s21_strerror_suite(), &failed);
  case_test(s21_strlen_suite(), &failed);
  case_test(s21_strncat_suite(), &failed);
  case_test(s21_strncmp_suite(), &failed);
  case_test(s21_strncpy_suite(), &failed);
  case_test(s21_strpbrk_suite(), &failed);
  case_test(s21_strstr_suite(), &failed);
  case_test(s21_strtok_suite(), &failed);
  case_test(s21_to_upper_suite(), &failed);
  case_test(s21_to_lower_suite(), &failed);
  case_test(s21_strcat_suite(), &failed);
  case_test(s21_strrchr_suite(), &failed);
  case_test(s21_insert_suite(), &failed);
  case_test(s21_trim_suite(), &failed);
  case_test(s21_sprintf_suite(), &failed);

  return failed;
}