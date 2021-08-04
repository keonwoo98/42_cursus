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
