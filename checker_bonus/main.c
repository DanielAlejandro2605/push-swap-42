/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 18:49:15 by dnieto-c          #+#    #+#             */
/*   Updated: 2022/07/08 23:21:54 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int	main(int argc, char *argv[])
{
	char	**args_split;

	if (argc == 1)
		return (0);
	else if (argc == 2)
	{
		args_split = ft_split(argv[1], ' ');
		ft_checker(args_split);
		ft_free_tab_split(args_split);
	}
	else if (argc > 2)
		ft_checker(argv);
	return (0);
}
