#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./Libft/libft.h"
# include <stdio.h>

typedef struct s_node	t_node;

typedef struct s_node
{
	int			num;
	t_node		*prev;
	t_node		*next;
}t_node;

typedef struct s_stack
{
	int			size;
	t_node		*top;
	t_node		*bottom;
}t_stack;

void			print_error(void);
void			print_error_msg(char *msg);
t_stack			*init_stack(void);
t_node			*init_node(int num);
void			push(t_stack *stack, int num);
void			create_list(char **argv, t_stack *a);
void			is_duplicate(t_stack *a);
void			swap(t_node *left, t_node *right, t_stack *stack);
void			push_pop(t_stack *from, t_stack *to);
void			rotate(t_stack *stack);
void			reverse_rotate(t_stack *stack);

void			quick_sort(t_node *head);
void			print_list(t_node *head);

#endif
