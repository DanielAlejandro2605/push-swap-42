/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 22:14:41 by dnieto-c          #+#    #+#             */
/*   Updated: 2022/07/08 22:14:41 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_free_list_op(t_lstop *op_list)
{
	t_lstop	*tmp;

	while (op_list)
	{
		tmp = op_list;
		op_list = op_list->next;
		ft_free_inst_list(tmp->list_inst);
		free (tmp);
	}
}

void	ft_free_inst_list(t_lsti *list)
{
	free(list);
	list = NULL;
}

void	ft_free_tab_split(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
