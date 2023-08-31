#include "main.h"

/**
 * get_endianness - to checks the endianness
 *
 * Return: and 0 if big endian, 1 if little endian
 */
int get_endianness(void)
{
	unsigned int x;
	char *c;

	x = 1;
	c = (char *) &x;

	return ((int)*c);
}
