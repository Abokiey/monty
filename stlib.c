#include "monty.h"
/**
 * _calloc - concatenate 2 strings
 * @nmemb: no. of elements
 * @size: the type of element
 * Return: void pointer
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *pt = NULL;
	unsigned int j;

	if (nmemb == 0 || size == 0)
	{
		return (NULL);
	}
	pt = malloc(nmemb * size);

	if (pt == NULL)
	{
		return (NULL);
	}
	for (j = 0; j < (nmemb * size); j++)
	{
		*((char *)(pt) + j) = 0;
	}
	return (pt);
}
/**
 * _realloc - change the size and copy the previous data
 * @ptr: mallocced pointer to reallocate
 * @old_size: previous size
 * @new_size: new size after reaallocation
 * Return: void ptr
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p = NULL;
	unsigned int j;

	if (new_size == old_size)
		return (ptr);
	if (ptr == NULL)
	{
		p = malloc(new_size);
		if (!p)
			return (NULL);
		return (p);
	}
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	if (new_size > old_size)
	{
		p = malloc(new_size);
		if (!p)
			return (NULL);
		for (j = 0; j < old_size; j++)
			p[j] = *((char *)ptr + j);
		free(ptr);
	}
	else
	{
		p = malloc(new_size);
		if (!p)
			return (NULL);
		for (j = 0; j < new_size; j++)
			p[j] = *((char *)ptr + j);
		free(ptr);
	}
	return (p);
}
