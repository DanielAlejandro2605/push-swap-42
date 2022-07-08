/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 15:43:06 by dnieto-c          #+#    #+#             */
/*   Updated: 2022/07/02 15:43:06 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_is_valid_format_args(char **args)
{
	int			i;
	int			j;

	i = 0;
	while (args[i])
	{
		if (ft_strlen_int(args[i]) == 0 || ft_strlen_int(args[i]) > 11)
			return (0);
		if (!(ft_arg_have_only_one_sign(args[i])))
			return (0);
		j = 0;
		while (args[i][j])
		{
			if (!ft_isvalid_char(args[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_is_valid_range(char **args)
{
	long int		*array_args;
	int				size_args;
	int				i;

	size_args = ft_count_args(args);
	array_args = (long int *)malloc(sizeof(long int) * (size_args));
	i = 0;
	while (args[i] && i < size_args)
	{
		array_args[i] = ft_atoi_overflow(args[i]);
		if (array_args[i] < MIN_INT || array_args[i] > MAX_INT)
		{
			free(array_args);
			return (0);
		}
		i++;
	}
	free(array_args);
	return (1);
}

int	*ft_check_arguments(char **args)
{
	int	*args_nums;
	int	size_args;
	int	i;

	if (ft_is_valid_format_args(args) && ft_is_valid_range(args))
	{
		size_args = ft_count_args(args);
		args_nums = (int *)malloc(sizeof(int) * (size_args));
		i = 0;
		while (args[i] && i < size_args)
		{
			args_nums[i] = ft_atoi(args[i]);
			i++;
		}
		if (ft_check_doubles(args_nums, size_args))
			return (args_nums);
		else
		{
			free(args_nums);
			return (NULL);
		}
	}
	return (NULL);
}
