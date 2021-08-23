#include <stdlib.h>
#include <stdio.h>
#include "slide_line.h"

/**
 * next_num_index - find index of next non-zero number
 * @line: array
 * @size: size of array
 * @curr_i: index to start searching from
 * @direction: direction
 * Return: -1 on failure, index on success
 */
int next_num_index(int *line, int size, int curr_i, int direction)
{
	int i;

	if (direction == SLIDE_LEFT)
	{
		i = curr_i + 1;
		while (i < size)
		{
			if (line[i] != 0)
				return (i);
			i++;
		}
	} else
	{
		i = curr_i - 1;
		while (i >= 0)
		{
			if (line[i] != 0)
				return (i);
			i--;
		}
	}
	return (-1);
}

/**
 * swap_zeros - slides zeros to start or end of array
 * depending on direction
 * @line: array
 * @size: size of array
 * @direction: direction
 * Return: size of array of only numbers non-zero
 */
size_t swap_zeros(int *line, size_t size, int direction)
{
	size_t i, n;
	int ni;

	if (direction == SLIDE_LEFT)
	{
		for (i = 0; i < size; i++)
		{
			if (line[i] == 0)
			{
				ni = next_num_index(line, size, i, direction);
				if (ni == -1)
					n = i;
				line[i] = line[ni];
				line[ni] = 0;
			}
		}
	} else
	{
		for (i = size - 1; i > 0; i--)
		{
			if (line[i] == 0)
			{
				ni = next_num_index(line, size, i, direction);
				if (ni == -1)
					n = i;
				line[i] = line[ni];
				line[ni] = 0;
			}
		}
	}
	return (n);
}

/**
 * slide_line - slides and merges an array of integers
 * @line: array
 * @size: size of array
 * @direction: direction
 * Return: 0 on failure, 1 on success
 */
int slide_line(int *line, size_t size, int direction)
{
	size_t nmax = swap_zeros(line, size, direction), i;

	if (direction == SLIDE_LEFT)
	{
		for (i = 0; i < nmax; i++)
		{
			if (direction == SLIDE_LEFT)
			{
				if (line[i] == line[i + 1])
				{
					line[i] *= 2;
					line[i + 1] = 0;
				}
			}
		}
	} else
	{
		for (i = size - 1; i > 0; i--)
		{
			if (line[i] == line[i - 1])
			{
				line[i] *= 2;
				line[i - 1] = 0;
			}
		}
	}
	nmax = swap_zeros(line, size, direction);
	return (1);
}
