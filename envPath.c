#include "main.h"

/**
 * findEnv - the findEnv function
 * @arg: argument
 *
 * Return: String.
 */
char *findEnv(char *arg)
{
	char *help, *left, *right, *Env;
	int i;

	for (i = 0; environ[i]; i++)
	{
		help = duplicate(environ[i]);
		left = strtok(help, "=");
		if (compare(left, arg) == 0)
		{
			right = strtok(NULL, "\n");
			Env = duplicate(right);
			free(help);
			return (Env);
		}
		free(help);
		help = NULL;
	}
	return (NULL);
}

/**
 * findPath - the findPath function
 * @cmd: command
 *
 * Return: String.
 */
char *findPath(char *cmd)
{
	char *envPath, *CMD, *stock;
	int i;
	struct stat stt;

	for (i = 0; cmd[i]; i++)
	{
		if (cmd[i] == '/')
		{
			if (stat(cmd, &stt) == 0)
				return (duplicate(cmd));
			return (NULL);
		}
	}
	envPath = findEnv("PATH");
	if (!envPath)
		return (NULL);
	stock = strtok(envPath, ":");
	while (stock)
	{
		CMD = malloc(length(stock) + length(cmd) + 2);
		if (CMD)
		{
			coppy(CMD, stock);
			catt(CMD, "/");
			coppy(CMD, cmd);
			if (stat(CMD, &stt) == 0)
			{
				free(envPath);
				return (CMD);
			}
			free(CMD);
			CMD = NULL;
			stock = strtok(NULL, ":");
		}
	}
	free(envPath);
	return (NULL);
}
