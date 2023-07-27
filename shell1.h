#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

extern char **environ;

char *_getenv(const char *var_name);
size_t _strlen(const char *str);
char *_strcat(char *destination, const char *source);
char *_strcpy(char *dest, const char *src);
char *_strdup(const char *str);
char *get_location(char *command);
void execmd(char **argv);

#endif
