#include "search_algos.h"

/**
 * print_array - Prints an array
 * @array: pointer at the first element of array
 * @f_h: first half of array
 * @s_h: second half of array
 */
void print_array(int *array, int f_h, int s_h)
{
	int i;

	for (i = f_h; i < s_h; i++)
		printf("%d, ", array[i]);

	printf("%d\n", array[i]);
}

/**
 * s_f - Binary search function
 * @arr: the array
 * @s: the start of array
 * @e: the end of array
 * @v: Value to search
 * Return: Index of the value at the array
 */
int s_f(int *arr, size_t s, size_t e,  int v)
{
	size_t mid;

	if (s > e)
		return (-1);

	mid = (e + s) / 2;
	printf("Searching in array: ");
	print_array(arr, s, e);
	if (arr[mid] == v && arr[mid - 1] != v)
	{
		return (mid);
	}
	if (arr[mid] < v)
	{
		return (s_f(arr, mid + 1, e,  v));
	}
	else
		return (s_f(arr, s, mid, v));
}

/**
 * advanced_binary - Advanced binary search
 * @array: is a pointer to the first element of the array to search in
 * @size: is the number of elements in array
 * @value: is the value to search for
 * Return: index of value
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);

	return (s_f(array, 0, size - 1, value));
}
