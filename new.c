#include "shell_header.h"

/**
 * main - forking process
 *
 * Return: success
 */

<<<<<<< HEAD
int main(void)
{
	char command[MAX_COMMAND_LENGTH];

	while (1)
	{
		_printf("#cisfun$ ");
		if (fgets(command, sizeof(command), stdin) == NULL)
		{
			_printf("\n");
			exit(0);
		}
		/*Remove newline character*/
=======
int main() {
	char command[MAX_COMMAND_LENGTH];

	while (1) {
		printf("#cisfun$ ");
		if (fgets(command, sizeof(command), stdin) == NULL) {
			printf("\n");
			break;
			exit(0);
		}
>>>>>>> 9ad1e40c3f8cc82e2fbfa2c641e74a38c5684b86
		command[strcspn(command, "\n")] = 0;

		pid_t pid = fork();

<<<<<<< HEAD
		if (pid == -1)
		{
			perror("fork");
			exit(1);
		}
		else if (pid == 0)
		{
			/*Child process*/
			if (execlp(command, command, (char *)NULL) == -1)
				fprintf(stderr, "./shell: %s: No such file or directory\n", command);
			exit(1);
		}
		else
		{
			/*Parent process*/
			wait(NULL);
		}
	}
=======
		if (pid == -1) {
			perror("fork");
			exit(1);
		} else if (pid == 0) {

			if (execlp(command, command, (char *)NULL) == -1) {
				fprintf(stderr, "./shell: %s: No such file or directory\n", command);
				exit(1);
			}
		} else {
			// Parent process
			wait(NULL);
		}
	}

>>>>>>> 9ad1e40c3f8cc82e2fbfa2c641e74a38c5684b86
	return (0);
}
