/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 18:50:25 by dnieto-c          #+#    #+#             */
/*   Updated: 2022/07/08 18:50:25 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	ft_checker(char **argv)
{
	int		*args_nums;
	t_stack	*a;
	t_stack	*b;

	args_nums = ft_check_arguments(argv + 1);
	if (args_nums)
	{
		a = ft_initialize_a(args_nums, ft_count_args(argv + 1));
		b = ft_initialize_b();
		ft_exec_list_instructions(a, b);
		if (ft_stack_is_sorted(a) && ft_stack_is_empty(b))
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
		ft_free_stack(a);
		ft_free_stack(b);
	}
	else
		ft_error();
}

void	ft_exec_list_instructions(t_stack *a, t_stack *b)
{
	char		*operation;

	operation = get_next_line(0);
	while (operation)
	{
		ft_exec_one_operation(operation, a, b);
		free(operation);
		operation = get_next_line(0);
	}
}

void	ft_exec_one_operation(char *op, t_stack *a, t_stack *b)
{
	if ((ft_strcmp(op, "sa\n")) == 0)
		ft_sa(a, 1);
	else if ((ft_strcmp(op, "sb\n")) == 0)
		ft_sb(b, 1);
	else if ((ft_strcmp(op, "ss\n")) == 0)
		ft_ss(a, b, 1);
	else if ((ft_strcmp(op, "pa\n")) == 0)
		ft_pa(a, b, 1);
	else if ((ft_strcmp(op, "pb\n")) == 0)
		ft_pb(a, b, 1);
	else if ((ft_strcmp(op, "ra\n")) == 0)
		ft_ra(a, 1);
	else if ((ft_strcmp(op, "rb\n")) == 0)
		ft_rb(b, 1);
	else if ((ft_strcmp(op, "rr\n")) == 0)
		ft_rr(a, b, 1);
	else if ((ft_strcmp(op, "rra\n")) == 0)
		ft_rra(a, 1);
	else if ((ft_strcmp(op, "rrb\n")) == 0)
		ft_rrb(b, 1);
	else if ((ft_strcmp(op, "rrr\n")) == 0)
		ft_rrr(a, b, 1);
	else
		ft_error();
}

int	ft_stack_is_sorted(t_stack *s)
{
	int	i;

	i = 0;
	while (i < (s->length - 1))
	{
		if (s->tab[i] > s->tab[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	ft_stack_is_empty(t_stack *s)
{
	if (s->length == 0)
		return (1);
	return (0);
}
