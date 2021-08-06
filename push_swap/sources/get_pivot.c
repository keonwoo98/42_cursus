#include "push_swap.h"

void
	swap_int(int *arr, int a, int b)
{
	int			temp;

	temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

void
	sort_arr(int *arr, int size)
{
	int			i;
	int			j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] > arr[j])
				swap_int(arr, i, j);
			j++;
		}
		i++;
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
	sort_arr(arr, size);
	mid_num = arr[size / 2];
	free (arr);
	return (mid_num);
}

int
	get_min_num(t_node *head, int size)
{
	int				min;

	min = head->num;
	while (size--)
	{
		if (min > head->num)
			min = head->num;
		if (head->next)
			head = head->next;
		else
			break ;
	}
	return (min);
}

int
	get_max_num(t_node *head, int size)
{
	int				max;

	max = head->num;
	while (size--)
	{
		if (max < head->num)
			max = head->num;
		if (head->next)
			head = head->next;
		else
			break ;
	}
	return (max);
}
