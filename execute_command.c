#include "shell_header.h"

/**
* execute_command - Execute the given command
* @command: Command to execute
*/

void execute_command(char *command)
{
	char *args[MAX_COMMAND_LENGTH];

	size_t arg_count = 0;

	pid_t pid;

	char *token = strtok(command, " ");

	while (token != NULL && arg_count < MAX_COMMAND_LENGTH - 1)
	{
		args[arg_count++] = token;
		token = strtok(NULL, " ");
	}
	args[arg_count] = NULL;

	pid = fork();

	if (pid == -1)
	{
		perror("Fork error");
		exit(EXIT_FAILURE);
	}

	if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			perror("Command execution error");
		}
	}
	else
	{
	    execute_command_two(pid);
	}
}
