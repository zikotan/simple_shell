#include "main.h"

/**
 * free2DArray - the free2DArray function
 * @arrays: the array
 *
 * Return: Nothing.
 */
void free2DArray(char **arrays)
{
	int i;

	if (!arrays)
		return;

	for (i = 0; arrays[i]; i++)
	{
		free(arrays[i]);
		arrays[i] = NULL;
	}
	free(arrays);
	arrays = NULL;
}

/**
 * myError - the myError function
 * @id: the name
 * @cmd: the command
 * @i: the index
 *
 * Return: Nothing.
 */
void myError(char *id, char *cmd, int i)
{
	char *ind, err[] = ": not found\n";

	ind = intToAscii(i);
	write(STDERR_FILENO, id, length(id));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, ind, length(ind));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, length(cmd));
	write(STDERR_FILENO, err, length(err));
	free(ind);
}

/**
 * intToAscii - the intToAscii function
 * @a: the integer
 *
 * Return: String.
 */
char *intToAscii(int a)
{
	char buff[15];
	int i = 0;

	if (a == 0)
		buff[i++] = '0';
	else
	{
		while (a > 0)
		{
			buff[i++] = (a % 10) + '0';
			a /= 10;
		}
	}
	buff[i] = '\0';
	strRev(buff, i);
	return (duplicate(buff));
}

/**
 * strRev - the strRev function
 * @ch: the string
 * @s: the size
 *
 * Return: Nothing.
 */
void strRev(char *ch, int s)
{
	char help;
	int begin = 0, stop = s - 1;

	while (begin < stop)
	{
		help = ch[begin];
		ch[begin] = ch[stop];
		ch[stop] = help;
		begin++;
		stop--;
	}
}
