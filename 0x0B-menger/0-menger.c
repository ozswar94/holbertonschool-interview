#include "menger.h"
#include <stdio.h>
#include <math.h>


/**
* surface_print - draw wall or hole
* @r: row
* @c: column
* Return: char space if is a hole overwise the char #
*/
static char surface_print(unsigned int r, unsigned int c)
{
	while (r && c)
	{
		if (r % 3 == 1 && c % 3 == 1)
			return (' ');
		r /= 3, c /= 3;
	}
	return ('#');
}

/**
* menger - draws a 2D Menger Sponge
* @level: the level of the Menger Sponge to draw
*/
void menger(int level)
{
	unsigned int size, r, c;

	if (level < 0)
		return;

	size = pow(CUBEBASE, level);

	for (r = 0; r < size; r++)
	{
		for (c = 0; c < size; c++)
			putchar(surface_print(r, c));
		putchar('\n');
	}
}
