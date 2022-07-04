

#include "../includes/checker.h"

int main(int argc, char *argv[])
{
    int *args_nums;

    if (argc > 1)
    {
        args_nums = ft_check_arguments(argv + 1);
        if (args_nums)
           ft_checker(args_nums, ft_count_args(argv + 1));
        else
            printf(ERROR_MESSAGE);
    }
    else
        printf("\n");
    return (0);
}