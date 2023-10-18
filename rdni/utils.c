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
