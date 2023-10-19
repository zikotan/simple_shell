#include "main.h"

/**
 * duplicate - the duplicate function
 * @dup: the constant String
 *
 * Return: String.
 */
char *duplicate(const char *dup)
{
	char *p;
	int i, size = 0;

	if (dup == NULL)
		return (NULL);
	while (*dup != '\0')
	{
		size++;
		dup++;
	}
	dup = dup - size;
	p = malloc(sizeof(char) * (size + 1));
	if (p == NULL)
		return (NULL);
	for (i = 0; i <= size; i++)
		p[i] = dup[i];
	return (p);
}

/**
 * length - the length function
 * @ch: the string
 *
 * Return: Integer.
 */
int length(char *ch)
{
	int l = 0;

	while (ch[l])
		l++;
	return (l);
}

/**
 * compare - the compare function
 * @ch1: string 1
 * @ch2: string 2
 *
 * Return: Integer.
 */
int compare(char *ch1, char *ch2)
{
	int comp;

	comp = (int)*ch1 - (int)*ch2;
	while (*ch1)
	{
		if (ch1 != ch2)
			break;
		ch1++;
		ch2++;
		comp = (int)*ch1 - (int)*ch2;
	}
	return (comp);
}

/**
 * coppy - the coppy function
 * @to: string 1
 * @from: string 2
 *
 * Return: String.
 */
char *coppy(char *to, char *from)
{
	int i = 0;

	while (from[i])
	{
		to[i] = from[i];
		i++;
	}
	to[i] = '\0';
	return (to);
}

/**
 * catt - the catt function
 * @to: string 1
 * @from: string 2
 *
 * Return: String.
 */
char *catt(char *to, char *from)
{
	char *pointer = to;

	while (*pointer)
		pointer++;
	while (*from)
	{
		*pointer = *from;
		pointer++;
		from++;
	}
	*pointer = '\0';
	return (to);
}
