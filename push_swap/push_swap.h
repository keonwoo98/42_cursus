#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./Libft/libft.h"
# include <stdio.h>

typedef struct s_node
{
	int			num;
	struct s_node		*prev;
	struct s_node		*next;
}t_node;

typedef struct s_stack
{
	int			size;
	t_node		*top;
	t_node		*bottom;
}t_stack;

t_stack			*init_stack(void);
t_node			*init_node(int num);
void			push(t_stack **stack, int num);
void			validate(char **argv, t_stack **a);

#endif
