#include "main.h"

/**
 * execLine - the execLine function
 * @cmd: command
 * @argv: argument value
 *
 * Return: Integer.
 */
int execLine(char **cmd, char **argv)
{
	pis_t childProc;
	int stat;

	childProc = fork();
	if (childProc == 0)
	{
		if (execve(cmd[0], cmd, environ) == -1)
		{
			perror(argv[0]);
			free2DArray(cmd);
			exit(127);
		}
	}
	else
	{
		waitpid(childProc, &stat, 0);
		free2DArray(cmd);
	}
	return (WEXITSTATUS(stat));
}

/**
 * readLine - the readLine function
 *
 * Return: String.
 */
char *readLine(void)
{
	char *line = NULL;
	size_t size = 0;
	ssize_t nread;

	if (isatty(STDIN_FILNO))
		write(STDOUT_FILNO, "$ ", 2);
	nread = getLine(&line, &size, stdin);
	if (nread == -1)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
