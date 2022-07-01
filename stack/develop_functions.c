#include "stack.h"

void	ft_print_stack_a(t_stack *s)
{
	int     i;

	i = 0;
	printf("*******************\n");
	printf("    DATA OF A\n");
	printf("   top    : %d\n", s->top);
	printf("   length : %d\n", s->length);
	printf("*******************\n");
	while (i < s->length)
    {
        printf("         %d\n", s->tab[i]);
        i++;
    }
	printf("        ---\n");
	printf("         a ");
	printf("\n");
}

void	ft_print_stack_b(t_stack *s)
{
	int     i;

	i = 0;
	printf("*******************\n");
	printf("    DATA OF B\n");
	printf("   top    : %d\n", s->top);
	printf("   length : %d\n", s->length);
	printf("*******************\n");
	// if(!s->tab)
	// 	printf("No Inizializada");
	while (i < s->length)
    {
        printf("         %d\n", s->tab[i]);
        i++;
    }
	printf("        ---\n");
	printf("         b ");
	printf("\n");
}