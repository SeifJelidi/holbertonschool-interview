#include "sort.h"

/**
 * swaping - swap numbers
 * @a: array 1
 * @b: array 2
 * Return: nothing
 */
void swap(int *a, int *b)
{
	int x;

	x = *a;
	*a = *b;
	*b = x;
}

/**
 * heapify - entry to heap
 * Desc: heapify function that makes array into a heap
 * @array: pointer to an int array
 * @size: size of the array
 * @i: max point
 * @length: array length
 * Return: void function, nothing is returned
 */
void maxi(int *array, int size, int i, size_t length)
{
	int max = i;
	int right = 2 * i + 2;
	int left = 2 * i + 1;

	if (left < size && array[left] > array[max])
	{
		max = left;
	}

	if (right < size && array[right] > array[max])
	{
		max = right;
	}

	if (max != i)
	{
		swap(&array[i], &array[max]);
		print_array(array, length);
		maxi(array, size, max, length);
	}
}

/**
 * heap_sort - entry to heap sort
 * Desc: heap_sort function that sorts an array of integers in
 * ascending order using the Heap Sort algorithm
 * @array: pointer to array to sort
 * @size: size of the array
 * Return: void function, nothing is returned
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (!size || !array)
		return;
	for (i = size / 2 - 1; i >= 0; i--)
	{
		maxi(array, size, i, size);
	}
	for (i = size - 1; i > 0; i--)
	{
		if (array[0] >= array[i])
		{
			swap(&array[0], &array[i]);
			print_array(array, size);
		}
		maxi(array, i, 0, size);
	}
}
