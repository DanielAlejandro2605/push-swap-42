/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 23:34:54 by marvin            #+#    #+#             */
/*   Updated: 2022/07/28 22:28:54 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_do_push_swap_one_arg(char *argv)
{
	int		*args_nums;
	char	**args_split;

	args_nums = ft_check_only_one_args(argv);
	if (args_nums)
	{
		args_split = ft_split(argv, ' ');
		if (args_split)
		{
			ft_do_push_swap(args_nums, ft_count_args(args_split));
			ft_free_tab_split(args_split);
			return (0);
		}
		else
		{
			free(args_nums);
			return (1);
		}
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	int		*args_nums;

	if (argc == 2)
	{
		if (ft_do_push_swap_one_arg(argv[1]))
			write(2, "Error\n", 6);
	}
	else if (argc > 1)
	{
		args_nums = ft_check_arguments(argv + 1);
		if (args_nums)
			ft_do_push_swap(args_nums, ft_count_args(argv + 1));
		else
			write(2, "Error\n", 6);
	}
	return (0);
}
