#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

#define LIM "\t\n"

extern char **environ;
char *findEnv(char *arg);
char *findPath(char *cmd);

char *intToAscii(int a);
void strRev(char *ch, int s);
void free2DArray(char **arrays);
void myError(char *id, char *cmd, int i);

char *readLine(void);
char **splitLine(char *line);
char *findEnv(char **cmd, char **argv);

char *duplicate(const char *dup);
int compare(char *ch1, char *ch2);
int length(char *ch);
char *catt(char *to, char *from);
char *coppy(char *to, char *from);

#endif
