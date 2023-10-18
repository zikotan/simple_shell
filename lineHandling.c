#include "main.h"

/**
 * execLine - the execLine function
 * @cmd: command
 * @argv: argument value
 * @ind: index
 *
 * Return: Integer.
 */
int execLine(char **cmd, char **argv, int ind)
{
	pid_t childProc;
	int stat;
	char *CMD;

	CMD = findPath(cmd[0]);
	if (!CMD)
	{
		myError(argv[0], cmd[0], ind);
		free2DArray(cmd);
		return (127);
	}
	childProc = fork();
	if (childProc == 0)
	{
		if (execve(CMD, cmd, environ) == -1)
		{
			free(CMD);
			CMD = NULL;
			free2DArray(cmd);
		}
	}
	else
	{
		waitpid(childProc, &stat, 0);
		free2DArray(cmd);
		free(CMD);
		CMD = NULL;
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

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);
	nread = getline(&line, &size, stdin);
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
