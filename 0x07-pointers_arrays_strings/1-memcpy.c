#include "main.h"

/**
 * *_memcpy - copies memory area
 * @dest: destination memory area
 * @src: memory area to copy from
 * @n: number of bytes to copy
 *
 * Return: pointer to dest
 */

char *_memcpy(char *dest, char *src, unsigned int n)

{
	unsigned int count;

	for (count = 0; count < n; count++)
		*(dest + count) = *(src + count);
	return (dest);
}
