#include "../includes/push_swap.h"

void	ft_free_list_op(list_op *op_list)
{
	list_op	*tmp;

	while (op_list)
	{
		tmp = op_list;
		op_list = op_list->next;
        ft_free_inst_list(tmp->list_inst);
		free (tmp);
	}
}

void    ft_free_inst_list(lst_ins *list)
{
    free(list);
    list = NULL;
}