#include "shell_header.h"
/**
* handle_signal - Signal handler for child processes
* @signo: Signal number
*/
void handle_signal(int signo)
{
	if (signo == SIGCHLD)
	{
		int status;

		waitpid(-1, &status, WNOHANG);  /* Reap zombie processes */
	}
}
