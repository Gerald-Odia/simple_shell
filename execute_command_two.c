#include "shell_header.h"

/**
* execute_command_two - Execute the given command
* @pid: input
*/

void execute_command_two(pid_t pid)
{
	int status;

		waitpid(pid, &status, 0);

		if (WIFEXITED(status))
		{
			_printf("Command executed with status %d\n", WEXITSTATUS(status));
		}
		else
		{
			_printf("Command execution failed\n");
		}
}
