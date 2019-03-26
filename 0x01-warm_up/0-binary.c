#include "search_algos.h"
/**
 * binary_search - searches for an integer in a sorted int array with a Binary algo
 * @array: Array to search
 * @size: size of array
 * @value: Int to search in array
 * Return: the index where value is located
 */
int binary_search(int *array, size_t size, int value)
{
	if (array == NULL)
		return (-1);
	return (binary_helper(array, 0, size -1, value));
}
/**
 * binary_helper - searches for an integer in an array of integers
 * @arr: Array to search
 * @strt: Start postion of array
 * @end: End positon of the array
 * @val: Integer to search for in array
 */
int binary_helper(int *arr, size_t strt, size_t end, int val)
{
	size_t mid = strt + ((end + 1) - strt) / 2;

	print_helper(arr, strt, end);
	if (arr[mid] == val)
		return (mid);
	if (end >= strt)
	{
		if (arr[mid] > val)
			return (binary_helper(arr, strt, mid - 1, val));
		return (binary_helper(arr, mid + 1, end, val));
	}
	return (-1);
}
/**
 * print_helper - Helps return format to stdout
 * @arr: Array to print
 * @strt: Start positon of array
 * @end: End position of array
 */
void print_helper(int *arr, size_t strt, size_t end)
{
	if (strt > end)
		return;
	printf("Searching in array: ");
	if (strt == end)
	{
		printf("%i", arr[end]);
		printf("\n");
		return;
	}
	while(strt <= end)
	{
		printf("%i", arr[strt]);
		if (strt != end)
			printf(", ");
		strt++;
	}
	printf("\n");
}
