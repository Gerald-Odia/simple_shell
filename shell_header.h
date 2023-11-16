#ifndef SHELL_HEADER_H
#define SHELL_HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <signal.h>

#define MAX_COMMAND_LENGTH 100

void handle_signal(int signo);
void execute_command(char *command);
int _printf(const char *format, ...);
void execute_command_two(pid_t pid);
int main(void);

#endif /* SHELL_HEADER_H */
