/* Copyright 2001,2002 Roger Dingledine, Matej Pfajfar. */
/* See LICENSE for licensing information */
/* $Id$ */

#ifndef __TEST_H
#define __TEST_H

#include <string.h>

#define STMT_BEGIN  do {
#define STMT_END    } while (0)

#define test_fail()                                             \
  STMT_BEGIN                                                    \
    printf("\nFile %s: line %d (%s): assertion failed.",        \
      __FILE__,                                                 \
      __LINE__,                                                 \
      __PRETTY_FUNCTION__);                                     \
    return;                                                     \
  STMT_END

#define test_assert(expr)                                       \
  STMT_BEGIN \
  if(expr) { printf("."); } else {                              \
    printf("\nFile %s: line %d (%s): assertion failed: (%s)\n", \
      __FILE__,                                                 \
      __LINE__,                                                 \
      __PRETTY_FUNCTION__,                                      \
      #expr);                                                   \
    return;                                                     \
  } STMT_END

#define test_eq(expr1, expr2)                                   \
  STMT_BEGIN if(expr1==expr2) { printf("."); } else {                \
    printf("\nFile %s: line %d (%s): Assertion failed: (%s==%s)\n"\
           "      (%ld != %ld)\n",                              \
      __FILE__,                                                 \
      __LINE__,                                                 \
      __PRETTY_FUNCTION__,                                      \
      #expr1, #expr2,                                           \
      (long)expr1, (long)expr2);                                \
    return;                                                     \
  } STMT_END

#define test_neq(expr1, expr2)                                  \
  STMT_BEGIN if(expr1!=expr2) { printf("."); } else {                \
    printf("\nFile %s: line %d (%s): Assertion failed: (%s!=%s)\n"\
           "      (%ld == %ld)\n",                              \
      __FILE__,                                                 \
      __LINE__,                                                 \
      __PRETTY_FUNCTION__,                                      \
      #expr1, #expr2,                                           \
      (long)expr1, (long)expr2);                                \
    return;                                                     \
  } STMT_END

#define test_streq(expr1, expr2)                                \
  STMT_BEGIN if(!strcmp(expr1,expr2)) { printf("."); } else {        \
    printf("\nFile %s: line %d (%s): Assertion failed: (%s==%s)\n"\
           "      (%s != %s)\n",                                \
      __FILE__,                                                 \
      __LINE__,                                                 \
      __PRETTY_FUNCTION__,                                      \
      #expr1, #expr2,                                           \
      expr1, expr2);                                            \
    return;                                                     \
  } STMT_END

#define test_strneq(expr1, expr2)                               \
  STMT_BEGIN if(strcmp(expr1,expr2)) { printf("."); } else {         \
    printf("\nFile %s: line %d (%s): Assertion failed: (%s!=%s)\n"\
           "      (%s == %s)\n",                                \
      __FILE__,                                                 \
      __LINE__,                                                 \
      __PRETTY_FUNCTION__,                                      \
      #expr1, #expr2,                                           \
      expr1, expr2);                                            \
    return;                                                     \
  } STMT_END

#define test_memeq(expr1, expr2, len)                           \
  STMT_BEGIN if(!memcmp(expr1,expr2,len)) { printf("."); } else {    \
    printf("\nFile %s: line %d (%s): Assertion failed: (%s==%s)\n", \
      __FILE__,                                                 \
      __LINE__,                                                 \
      __PRETTY_FUNCTION__,                                      \
      #expr1, #expr2);                                          \
    return;                                                     \
  } STMT_END

#endif

/*
  Local Variables:
  mode:c
  indent-tabs-mode:nil
  c-basic-offset:2
  End:
*/
