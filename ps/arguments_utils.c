/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 09:28:06 by dnieto-c          #+#    #+#             */
/*   Updated: 2022/07/18 15:19:08 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_check_doubles(int *array, int size_array)
{
	int	i;
	int	j;

	i = 0;
	while (i < size_array)
	{
		j = i + 1;
		while (j < size_array)
		{
			if (array[i] == array[j])
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

long	ft_atoi_overflow(const char *str)
{
	long		result;
	int			i;
	int			negative;

	if (!str)
		return (0);
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
		negative = -1;
	else
		negative = 1;
	if (negative == -1)
		i++;
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (result * negative);
}

int	ft_isvalid_char(int c)
{
	if ((c >= '0' && c <= '9') || (c == '-'))
		return (1);
	return (0);
}

int	ft_arg_have_only_one_sign(char *arg)
{
	int	i;
	int	sign;

	i = 0;
	sign = 0;
	while (arg[i])
	{
		if (arg[i] == '-')
		{
			if (arg[i - 1] >= '0' && arg[i - 1] <= '9')
				return (0);
			sign++;
		}
		if (sign > 1)
			return (0);
		i++;
	}
	return (1);
}

int	ft_count_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		i++;
	return (i);
}
