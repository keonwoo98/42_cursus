/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keokim <keokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 09:53:18 by keokim            #+#    #+#             */
/*   Updated: 2021/08/09 09:53:22 by keokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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

typedef struct s_cmd
{
	int			ra;
	int			rb;
	int			pa;
	int			pb;
	int			s_pivot;
	int			b_pivot;
	int			cnt;
}t_cmd;

void			print_command(int flag);
void			print(t_stack *command);

void			print_error(void);
t_stack			*init_stack(void);
t_node			*init_node(int num);
t_cmd			*init_cmd(int cnt);
void			push(t_stack *stack, int num);
void			create_list(char **argv, t_stack *a);
long long		ft_atoi_long(const char *str);
void			is_duplicate(t_stack *a);
void			swap(t_stack *stack, t_stack *command, int flag);
void			push_pop(t_stack *from, \
				t_stack *to, t_stack *command, int flag);
void			rotate(t_stack *stack, t_stack *command, int flag);
void			reverse_rotate(t_stack *stack, t_stack *command, int flag);

void			two_elements_a(t_stack *a, t_stack *command);
void			two_elements_b(t_stack *a, t_stack *b, t_stack *command);
void			three_elements_a(t_stack *a, t_stack *command);
void			five_elements_a(t_stack *a, t_stack *b, t_stack *command);

int				get_mid_num(t_node *head, int size);
int				get_min_num(t_node *head, int size);
int				get_max_num(t_node *head, int size);
int				is_a_sorted(t_stack *stack, int cnt);
int				is_b_sorted(t_stack *a, t_stack *b, t_stack *command, int cnt);
void			a_to_b(t_stack *a, t_stack *b, t_stack *command, int cnt);
void			b_to_a(t_stack *a, t_stack *b, t_stack *command, int cnt);
void			rrr(t_stack *a, t_stack *b, t_stack *command, t_cmd *cmd);

void			free_arr(char **str);
void			free_stack(t_stack *stack);
void			free_all(t_stack *a, t_stack *b, t_stack *command);

#endif
