#include "../includes/stack.h"

void	ft_print_stack_a(t_stack *s)
{
	int     i;

	i = 0;
	ft_printf("*******************\n");
	ft_printf("    DATA OF A\n");
	ft_printf("   top    : %d\n", s->top);
	ft_printf("   length : %d\n", s->length);
	ft_printf("*******************\n");
	while (i < s->length)
    {
        ft_printf("         %d\n", s->tab[i]);
        i++;
    }
	ft_printf("        ---\n");
	ft_printf("         a ");
	ft_printf("\n");
}

void	ft_print_stack_b(t_stack *s)
{
	int     i;

	i = 0;
	ft_printf("*******************\n");
	ft_printf("    DATA OF B\n");
	ft_printf("   top    : %d\n", s->top);
	ft_printf("   length : %d\n", s->length);
	ft_printf("*******************\n");
	while (i < s->length)
    {
        ft_printf("         %d\n", s->tab[i]);
        i++;
    }
	ft_printf("        ---\n");
	ft_printf("         b ");
	ft_printf("\n");
}