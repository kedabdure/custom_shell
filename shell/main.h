#ifndef MAIN_H
#define MAIN_H
//#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
//#include <string.h>
#include <fcntl.h>
#include <sys/types.h>

#define MAX_INPUT_SIZE 1024
#define MAX_PATH_LENGTH 256
#define MAX_ARGUMENTS 64

char *excutels_l(char *buf);
char *find_path(char *buf);
void execute_command_with_args(char *command, char *argv[]);
void execute_command(char *buf, char *argv[]);
void _putchar(char c);
int _printf(const char *format, ...);
size_t _strlen(const char *str);
void _strcpy(char *dest, const char *src);
void _strcat(char *dest, const char *src);
void custom_write(const char *str);
char* _strchr(const char *str, char c);
char *read_command(void);
int handleCharacter(va_list args, char *buffer, int count);
int handleString(va_list args, char *buffer, int count);
int handlePercentage(char *buffer, int count);
char *_strdup(const char *source);
char *_getenv(const char *name);
int _strncmp(const char *str1, const char *str2, size_t n);

#endif /*MAIN_H*/
