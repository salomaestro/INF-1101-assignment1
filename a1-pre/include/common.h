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

#endif
