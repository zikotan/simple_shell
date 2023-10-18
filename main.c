#include "main.h"

/**
 * main - the main function
 * @argc: argument counter
 * @argv: argument value
 *
 * Return: always 0.
 */
int main(int argc, char **argv)
{
	char *line = NULL, **cmd = NULL;
	int stat = 0, ind = 0;
	(void) argc;

	while (1)
	{
		line = readLine();
		if (line == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (stat);
		}
		ind++;
		cmd = splitLine(line);
		if (!cmd)
			continue;
		stat = execLine(cmd, argv);
	}
}
