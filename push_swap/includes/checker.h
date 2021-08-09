#ifndef CHECKER_H
# define CHECKER_H

# include "../sources/Libft/libft.h"

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
t_stack			*init_stack(void);
t_node			*init_node(int num);
void			push(t_stack *stack, int num);
void			create_list(char **argv, t_stack *a);
long long		ft_atoi_long(const char *str);
int				get_next_line(int fd, char **line);
void			is_duplicate(t_stack *a);
void			do_operation(char *line, t_stack *a, t_stack *b);
void			do_swap(t_stack *stack);
void			do_push_pop(t_stack *from, t_stack *to);
void			do_rotate(t_stack *stack);
void			do_reverse_rotate(t_stack *stack);
void			free_arr(char **str);
void			free_stack(t_stack *stack);
void			free_all(t_stack *a, t_stack *b);

#endif
