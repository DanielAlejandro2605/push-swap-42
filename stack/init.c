
#include "../includes/stack.h"

t_stack	*ft_initialize_a(int *args_nums, int size_args_num)
{
    t_stack	*a;

    a = (t_stack *)malloc(sizeof(t_stack));
    if (!a)
        return (NULL);
    a->top = args_nums[0];
    a->length = size_args_num;
    a->tab = args_nums;
	return (a);
}

t_stack	*ft_initialize_b(void)
{
    t_stack	*b;

    b = (t_stack *)malloc(sizeof(t_stack));
    if (!b)
        return (NULL);
    b->top = -1;
    b->length = 0;
    b->tab = NULL;
    return (b);
}
