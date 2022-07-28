/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 21:55:11 by dnieto-c          #+#    #+#             */
/*   Updated: 2022/07/28 23:07:18 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	*ft_error_split(char **args_split)
{
	ft_free_tab_split(args_split);
	return (NULL);
}

void	*ft_error_tab(int *args_nums)
{
	free(args_nums);
	return (NULL);
}

int	ft_error_int_limit(long int *array_args)
{
	free(array_args);
	return (0);
}

int	ft_error_op_list(t_lstop *operation_lst, int *max_5_values)
{
	ft_free_tab(max_5_values);
	ft_free_list_op(operation_lst);
	return (1);
}

int	ft_parsing_zero_arg(char *arg)
{
	if (ft_strcmp(arg, "-") == 0
		||ft_strcmp(arg, "0-") == 0
		|| ft_strcmp(arg, "-0") == 0
		|| ft_strncmp(arg, "-0", 2) == 0)
		return (1);
	return (0);
}
