/* Author: Steffen Viken Valvaag <steffenv@cs.uit.no> */
#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct list;

/*
 * The type of comparison functions.
 */
typedef int (*cmpfunc_t)(void *, void *);

/*
 * Reads the given file, and parses it into words (tokens).
 * Adds the words to the given list, in the same order that they
 * occur in the file.
 *
 * This tokenizer ignores punctuation and whitespace, so if the file
 * contains the text "Hello! This is an example...." the recognized
 * words will be "Hello", "This", "is", "an", and "example".
 */
void tokenize_file(FILE *file, struct list *list);

/* 
 * Takes two char arguments and compares them.
 * Returns -1 if the first is smaller than the second, 1
 * if the second is smaller than the first, and 0 if
 * they are equal.
 */
int compare_char(void *arg1, void* arg2);
#endif
