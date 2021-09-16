#include "menger.h"

/**
 * check_space - check space.
 * @row: row index
 * @col: col index
 * Return: 1 or 0
*/
int check_space(size_t row, size_t col)
{
	for (; row && col; row /= 3, col /= 3)
		if (row % 3 == 1 && col % 3 == 1)
			return (1);
	return (0);
}

/**
 * menger - draws a 2D Menger Sponge
 * @level: the level of the Menger Sponge to draw
 */
void menger(int level)
{
	size_t size, row, col;

	if (level < 0)
		return;

	size = pow(3, level);

	for (row = 0; row < size; ++row)
	{
		for (col = 0; col < size; ++col)
			printf(check_space(row, col) ? " " : "#");
		printf("\n");
	}

}
