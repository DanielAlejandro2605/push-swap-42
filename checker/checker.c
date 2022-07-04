#include "checker.h"

int	ft_checker(int *args_nums, int size_args_num)
{
	t_stack	*a;
    t_stack	*b;

    a = ft_initialize_a(args_nums, size_args_num);
    b = ft_initialize_b();

	if (ft_stack_is_sort(&a) && ft_stack_is_empty(&b))
		ft_printf("OK");
	else
		ft_printf("KO");
	ft_free_stack(a);
	ft_free_stack(b);
}

void	ft_execute_list_instrunctions(void)
{
	char	*instruction;

	instruction = get_next_line(1);
	while (instruction)
	{
		ft_printf("Lei una instruction\n");
		free(instruction);
		instruction = get_next_line(1);
	}
}


// char	*ft_get_list_instructions(void)
// {
//     char	*instruction_concatenation;
//     char	*instruction;
//     int		fd;
	
// 	fd = open("instructions_file2.txt", O_RDONLY);
//    	instruction_concatenation = NULL;
//     instruction = get_next_line(fd);
//     while (instruction)
//     {
//         instruction_concatenation = ft_concatenation(instruction_concatenation, instruction);
//         free(instruction);
//         instruction = get_next_line(fd);
//     }
//     return(instruction_concatenation);
// }

// void	ft_exec_function(char *operation_name, l_stack *a, l_stack *b)
// {
// 	printf("\n\n\ndiff %d\n\n\n", ft_strncmp(operation_name, "rra", ft_strlen("rra")) == 0);
// 	ft_rra(&a, &b);
// 	// if ((ft_strncmp(operation_name, "sa", ft_strlen("sa"))) == 0)
// 	// 	ft_sa(a, b);
// 	// else if ((ft_strncmp(operation_name, "sb", ft_strlen("sb"))) == 0)
// 	// 	ft_sb(a, b);
// 	// else if ((ft_strncmp(operation_name, "ss", ft_strlen("ss"))) == 0)
// 	// 	ft_ss(a, b);
// 	// else if ((ft_strncmp(operation_name, "pa", ft_strlen("pa"))) == 0)
// 	// 	ft_pa(a, b);
// 	// else if ((ft_strncmp(operation_name, "pb", ft_strlen("pb"))) == 0)
// 	// 	ft_pb(a, b);
// 	// else if ((ft_strncmp(operation_name, "ra", ft_strlen("ra"))) == 0)
// 	// 	ft_ra(a, b);
// 	// else if ((ft_strncmp(operation_name, "rb", ft_strlen("rb"))) == 0)
// 	// 	ft_rb(a, b);
// 	// else if ((ft_strncmp(operation_name, "rr", ft_strlen("rr"))) == 0)
// 	// 	ft_rr(a, b);
// 	// else if ((ft_strncmp(operation_name, "rra", ft_strlen("rra"))) == 0)
// 	// {
// 	// 	printf("HERE?\n");
// 	// 	ft_rra(a, b);
// 	// }
// 	// else if ((ft_strncmp(operation_name, "rrb", ft_strlen("rrb"))) == 0)
// 	// 	ft_rrb(a, b);
// 	// else if ((ft_strncmp(operation_name, "rrr", ft_strlen("rrr"))) == 0)
// 	// 	ft_rrr(a, b);
// }

// int	ft_stack_is_sort(l_stack **s)
// {
// 	l_stack	*tmp_s1;
// 	l_stack	*next_tmp_s1;

// 	tmp_s1 = *s;
// 	next_tmp_s1 = tmp_s1->next;

// 	while (next_tmp_s1)
// 	{
// 		//printf("i %d && j : %d\n", tmp_s1->value, next_tmp_s1->value);
// 		if (tmp_s1->value > next_tmp_s1->value)
// 			return (0);
// 		tmp_s1 = tmp_s1->next;
// 		next_tmp_s1 = tmp_s1->next;
// 	}
// 	return(1);
// }

// int	ft_stack_is_empty(l_stack **b)
// {
// 	if (*b == NULL)
// 		return (1);
// 	return (0);
// }