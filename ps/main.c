/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 23:34:54 by marvin            #+#    #+#             */
/*   Updated: 2022/07/05 00:02:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int main(int argc, char *argv[])
{
    int *args_nums;

    if (argc > 1)
    {
        args_nums = ft_check_arguments(argv + 1);
        if (args_nums)
           ft_do_push_swap(args_nums, ft_count_args(argv + 1));
        else
            printf(ERROR_MESSAGE);
    }
    else
        printf("\n");
    return (0);
}