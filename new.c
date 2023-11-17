#include "shell_header.h"

/**
 * main - forking process
 * Return: success
 */

int main(void)
{
	char command[MAX_COMMAND_LENGTH];
	
	while (1)
	{
		_printf("#cisfun$ ");
		if (fgets(command, sizeof(command), stdin) == NULL)
		{
			_printf("\n");
			break;
			exit(0);
		}
		command[strcspn(command, "\n")] = 0;
		
		pid_t pid = fork();
		
		if (pid == -1)
		{
			perror("fork");
			exit(1);
		}
		else if (pid == 0)
		{
			if (execlp(command, command, (char *)NULL) == -1)
			{
				fprintf(stderr, "./shell: %s: No such file or directory\n", command);
				exit(1);
			}
		}
		else
		{
			wait(NULL);
		}
		if (pid == -1)
		{
			perror("fork");
			exit(1);
		}
		else if (pid == 0)
		{
			if (execlp(command, command, (char *)NULL) == -1)
			{
				fprintf(stderr, "./shell: %s: No such file or directory\n", command);
				exit(1);
			}
		}
		else
		{
			wait(NULL);
		}
	}
	return (0);
}