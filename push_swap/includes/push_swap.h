#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../sources/Libft/libft.h"
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

typedef struct s_cmd
{
	int			ra;
	int			rb;
	int			pa;
	int			pb;
}t_cmd;

t_stack			*command;

void			print_command(int flag);
void			print_command2(int flag);
void			print(t_stack *command);

void			print_error(void);
t_stack			*init_stack(void);
t_node			*init_node(int num);
t_cmd			*init_cmd(void);
void			push(t_stack *stack, int num);
void			create_list(char **argv, t_stack *a);
void			is_duplicate(t_stack *a);
void			swap(t_stack *stack, int flag);
void			push_pop(t_stack *from, t_stack *to, int flag);
void			rotate(t_stack *stack, int flag);
void			reverse_rotate(t_stack *stack, int flag);

void			two_elements_a(t_stack *a);
void			two_elements_b(t_stack *a, t_stack *b);
void			three_elements_a(t_stack *a);
void			four_elements_a(t_stack *a, t_stack *b);
void			five_elements_a(t_stack *a, t_stack *b);

int				get_mid_num(t_node *head, int size);
int				get_min_num(t_node *head, int size);
int				get_max_num(t_node *head, int size);
int				is_a_sorted(t_stack *stack, int cnt);
int				is_b_sorted(t_stack *a, t_stack *b, int cnt);
void			a_to_b(t_stack *a, t_stack *b, int cnt);
void			b_to_a(t_stack *a, t_stack *b, int cnt);
void			rrr(t_stack *a, t_stack *b, t_cmd *cmd);

void			free_arr(char **str);
void			free_stack(t_stack *stack);
void			free_all(t_stack *a, t_stack *b, t_stack *command);

#endif
