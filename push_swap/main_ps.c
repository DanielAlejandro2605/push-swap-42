/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 10:05:53 by dnieto-c          #+#    #+#             */
/*   Updated: 2022/07/01 10:07:40 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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