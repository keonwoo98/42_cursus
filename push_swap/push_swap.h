#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./Libft/libft.h"

typedef struct s_list
{
	int			value;
	t_list		*prev;
	t_list		*next;
}t_list;

typedef struct s_stack
{
	int			size;
	t_stack		*top;
	t_stack		*bottom;
}t_stack;

#endif
