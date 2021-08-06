#include "push_swap.h"

void
	print_command(int flag)
{
	if (flag == 0)
		return ;
	else if (flag == 1)
		ft_putstr_fd("sa\n", 1);
	else if (flag == 2)
		ft_putstr_fd("sb\n", 1);
	else if (flag == 3)
		ft_putstr_fd("ss\n", 1);
	else if (flag == 4)
		ft_putstr_fd("pa\n", 1);
	else if (flag == 5)
		ft_putstr_fd("pb\n", 1);
	else if (flag == 6)
		ft_putstr_fd("ra\n", 1);
	else if (flag == 7)
		ft_putstr_fd("rb\n", 1);
	else if (flag == 8)
		ft_putstr_fd("rr\n", 1);
	else if (flag == 9)
		ft_putstr_fd("rra\n", 1);
	else if (flag == 10)
		ft_putstr_fd("rrb\n", 1);
	else if (flag == 11)
		ft_putstr_fd("rrr\n", 1);
}

void
	remove_command(t_stack *command)
{
	if ((command->top->num == 1 && command->top->next->num == 1) \
		|| (command->top->num == 2 && command->top->next->num == 2) \
		|| (command->top->num == 4 && command->top->next->num == 5) \
		|| (command->top->num == 5 && command->top->next->num == 4) \
		|| (command->top->num == 6 && command->top->next->num == 9) \
		|| (command->top->num == 7 && command->top->next->num == 10) \
		|| (command->top->num == 9 && command->top->next->num == 6) \
		|| (command->top->num == 10 && command->top->next->num == 7))
	{
		command->top->num = 0;
		command->top->next->num = 0;
	}
}

void
	print(t_stack *command)
{
	while (command->top->next)
	{
		if ((command->top->num == 6 && command->top->next->num == 7) \
			|| (command->top->num == 7 && command->top->next->num == 6))
		{
			command->top->num = 8;
			command->top->next->num = 0;
		}
		else if ((command->top->num == 9 && command->top->next->num == 10) \
			|| (command->top->num == 10 && command->top->next->num == 9))
		{
			command->top->num = 11;
			command->top->next->num = 0;
		}
		else if ((command->top->num == 1 && command->top->next->num == 2) \
			|| (command->top->num == 2 && command->top->next->num == 1))
		{
			command->top->num = 3;
			command->top->next->num = 0;
		}
		remove_command(command);
		print_command(command->top->num);
		command->top = command->top->next;
	}
	print_command(command->top->num);
}
