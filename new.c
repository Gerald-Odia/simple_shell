#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100

int main() {
	char command[MAX_COMMAND_LENGTH];

	while (1) {
		printf("#cisfun$ ");
		if (fgets(command, sizeof(command), stdin) == NULL) {
			printf("\n");
			break;
			exit(0);
		}
		command[strcspn(command, "\n")] = 0;

		pid_t pid = fork();

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

	return (0);
}
