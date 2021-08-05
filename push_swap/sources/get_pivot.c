#include "push_swap.h"

void
	swap_int(int *arr, int a, int b)
{
	int			temp;

	temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

int
	partition(int *arr, int left, int right)
{
	int			pivot;
	int			low;
	int			high;

	pivot = arr[left];
	low = left + 1;
	high = right;
	while (low <= high)
	{
		while (low <= right && pivot >= arr[low])
			low++;
		while (high >= (left + 1) && pivot <= arr[high])
			high--;
		if (low <= high)
			swap_int(arr, low, high);
	}
	swap_int(arr, left, high);
	return (high);
}

void
	quick_sort_arr(int *arr, int left, int right)
{
	int			pivot;

	if (left <= right)
	{
		pivot = partition(arr, left, right);
		quick_sort_arr(arr, left, pivot - 1);
		quick_sort_arr(arr, pivot + 1, right);
	}
}

int
	get_mid_num(t_node *head, int size)
{
	int			i;
	int			mid_num;
	int			*arr;

	i = 0;
	arr = (int *)malloc(sizeof(int) * size);
	if (!arr)
		print_error();
	while (head && i < size)
	{
		arr[i++] = head->num;
		head = head->next;
	}
	quick_sort_arr(arr, 0, size - 1);
	mid_num = arr[size / 2];
	free (arr);
	return (mid_num);
}

int
	get_small_pivot(t_node *head, int size)
{
	int			i;
	int			pivot;
	int			*arr;

	i = 0;
	arr = (int *)malloc(sizeof(int) * size);
	if (!arr)
		print_error();
	while (head && i < size)
	{
		arr[i++] = head->num;
		head = head->next;
	}
	quick_sort_arr(arr, 0, size - 1);
	pivot = arr[size / 3];
	free (arr);
	return (pivot);
}

int
	get_big_pivot(t_node *head, int size)
{
	int			i;
	int			pivot;
	int			*arr;

	i = 0;
	arr = (int *)malloc(sizeof(int) * size);
	if (!arr)
		print_error();
	while (head && i < size)
	{
		arr[i++] = head->num;
		head = head->next;
	}
	quick_sort_arr(arr, 0, size - 1);
	i = size / 3;
	pivot = arr[i * 2];
	free (arr);
	return (pivot);
}

int
	get_min_num(t_node *head, int size)
{
	int			i;
	int			min_num;
	int			*arr;

	i = 0;
	arr = (int *)malloc(sizeof(int) * size);
	if (!arr)
		print_error();
	while (head && i < size)
	{
		arr[i++] = head->num;
		head = head->next;
	}
	quick_sort_arr(arr, 0, size - 1);
	min_num = arr[0];
	free (arr);
	return (min_num);
}

int
	get_max_num(t_node *head, int size)
{
	int			i;
	int			max_num;
	int			*arr;

	i = 0;
	arr = (int *)malloc(sizeof(int) * size);
	if (!arr)
		print_error();
	while (head && i < size)
	{
		arr[i++] = head->num;
		head = head->next;
	}
	quick_sort_arr(arr, 0, size - 1);
	i--;
	max_num = arr[i];
	free (arr);
	return (max_num);
}
