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
