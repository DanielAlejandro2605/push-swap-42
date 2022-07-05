#include "checker.h"

void    ft_print_stack(l_stack *begin_list)
{
    l_stack *tmp;

	if (begin_list)
	{
		tmp = begin_list;
		printf("\n");
		while (tmp)
		{
			printf(" %d\n", tmp->value);
			tmp = tmp->next;
		}
	}
}

void    ft_print_stack_a(l_stack *a)
{
    ft_print_stack(a);
    printf("---\n");
	printf(" a \n");
}

void    ft_print_stack_b(l_stack *b)
{
    ft_print_stack(b);
    printf("---\n");
	printf(" b \n");
}

void    ft_print_args(char **args)
{
    int i;

    i = 0;
    while (args[i])
    {
        printf("%d\n", ft_atoi(args[i]));
        i++;
    }
}