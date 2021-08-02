#include "push_swap.h"

void
	swap_int(int *a, int *b)
{
	int			t;

	t = *a;
	*a = *b;
	*b = t;
}

t_node
	*last_node(t_node *root)
{
	while (root && root->next)
		root = root->next;
	return (root);
}

t_node
	*partition(t_node *tail, t_node *head)
{
	int			pivot;
	t_node		*i;
	t_node		*j;

	pivot = head->num;
	i = tail->prev;
	j = tail;
	while (j != head)
	{
		if (j->num <= pivot)
		{
			if (i == NULL)
				i = tail;
			else
				i = i->next;
			swap_int(&(i->num), &(j->num));
		}
		j = j->next;
	}
	if (i == NULL)
		i = tail;
	else
		i = i->next;
	swap_int(&(i->num), &(head->num));
	return (i);
}

void
	_quick_sort(t_node *tail, t_node *head)
{
	t_node		*pivot;

	if (head != NULL && tail != head && tail != head->next)
	{
		pivot = partition(tail, head);
		_quick_sort(tail, pivot->prev);
		_quick_sort(pivot->next, head);
	}
}

void
	quick_sort(t_node *head)
{
	t_node		*tail;

	tail = last_node(head);
	_quick_sort(head, tail);
}

void
	print_list(t_node *head)
{
	while (head)
	{
		printf("%d\n", head->num);
		head = head->next;
	}
}
