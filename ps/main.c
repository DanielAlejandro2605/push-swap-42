/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 23:34:54 by marvin            #+#    #+#             */
/*   Updated: 2022/07/17 19:32:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char *argv[])
{
	int		*args_nums;
	char	**args_split;

	if (argc == 2)
	{
		args_nums = ft_check_only_one_args(argv[1]);
		args_split = ft_split(argv[1], ' ');
		if (args_nums)
			ft_do_push_swap(args_nums, ft_count_args(args_split));
		else
			write(2, "Error\n", 6);
		ft_free_tab_split(args_split);
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
