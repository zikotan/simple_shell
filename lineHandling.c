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

/**
 * splitLine - the splitLine function
 * @line: the line
 *
 * Return: String.
 */

char **splitLine(char *line)
{
	char *split = NULL, *help = NULL, **cmd = NULL;
	int count = 0, i = 0;

	if (!line)
		return (NULL);
	help = duplicate(line);
	split = strtok(help, LIM);
	if (split == NULL)
	{
		free(line);
		line = NULL;
		free(help);
		help = NULL;
		return (NULL);
	}
	while (split)
	{
		count++;
		split = strtok(NULL, LIM);
	}
	free(help), help = NULL;
	cmd = malloc(sizeof(char *) * (count + 1));
	if (!cmd)
	{
		free(line), line = NULL;
		return (NULL);
	}
	split = strtok(line, LIM);
	while (split)
	{
		cmd[i] = duplicate(split);
		split = strtok(NULL, LIM);
		i++;
	}
	free(line), line = NULL;
	cmd[i] = NULL;
	return (cmd);
}
