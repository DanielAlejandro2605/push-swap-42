/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 10:22:38 by dnieto-c          #+#    #+#             */
/*   Updated: 2022/07/17 22:00:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_print_stack_a(t_stack *s)
{
	int     i;

	i = 0;
	ft_printf("*******************\n");
	ft_printf("    DATA OF A\n");
	ft_printf("   top    : %d\n", s->top);
	ft_printf("   length : %d\n", s->length);
	ft_printf("*******************\n");
	while (i < s->length)
    {
        ft_printf("         %d\n", s->tab[i]);
        i++;
    }
	ft_printf("        ---\n");
	ft_printf("         a ");
	ft_printf("\n");
}

static void	ft_print_stack_b(t_stack *s)
{
	int     i;

	i = 0;
	ft_printf("*******************\n");
	ft_printf("    DATA OF B\n");
	ft_printf("   top    : %d\n", s->top);
	ft_printf("   length : %d\n", s->length);
	ft_printf("*******************\n");
	// if(!s->tab)
	// 	ft_printf("No Inizializada");
	while (i < s->length)
    {
        ft_printf("         %d\n", s->tab[i]);
        i++;
    }
	ft_printf("        ---\n");
	ft_printf("         b ");
	ft_printf("\n");
}
void	ft_do_push_swap(int *args, int amount_args)
{
	if (ft_args_is_already_sorted(args, amount_args))
	{
		free (args);
		return ;
	}
	else
		ft_push_swap(args, amount_args);
}

int	ft_args_is_already_sorted(int *args, int amount_args)
{
	int	i;

	i = 0;
	while (i < amount_args - 1)
	{
		if (args[i] > args[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	ft_push_swap(int *args_nums, int size_args_num)
{
	t_stack	*a;
	t_stack	*b;

	a = ft_initialize_a(args_nums, size_args_num);
	b = ft_initialize_b();
	if (a->length <= 3)
		ft_sort_3(a);
	else
		ft_sort(a, b);
	ft_free_stack(a);
	ft_free_stack(b);
}
