#include "checker.h"

int	ft_valid_args(char **args)
{
	int	i;
	int	j;

	i = 0;
	while (args[i])
	{
		if (ft_strlen(args[i]) > 11)
			return (0);
		j = 0;
		while (args[i][j])
		{
			if (!ft_isvalid_char(args[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_isvalid_char(int c)
{
	if ((c >= '0' && c <= '9') || (c == '+') || (c == '-'))
		return (1);
	return (0);
}

int    ft_count_args(char **args)
{
    int i;

    i = 0;
    while (args[i])
        i++;
    return (i);
}

int	ft_check_doubles(int *array, int size_array)
{
	int	i;
	int	j;

	i = 0;
	while (i < size_array)
	{
		j = i + 1;
		while (j < size_array)
		{
			if (array[i] == array[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	*ft_apply_atoi_args(char **args)
{
	int		*array_args;
	int		size_args;
	int		i;

	size_args = ft_count_args(args);
	array_args = (int *)malloc(sizeof(int) * (size_args));
	i = 0;
    while (args[i] && i < size_args)
	{
		array_args[i] = ft_atoi(args[i]);
		if (!(array_args[i] > MIN_INT && array_args[i] <= MAX_INT))
		{
			if (!(array_args[i] == MIN_INT))
			{
				printf(ARGUMENTS_NOT_INT_LIMITS);
				free(array_args);
				return (NULL);
			}
		}
		i++;
	}
	if (ft_check_doubles(array_args, size_args))
		return (array_args);
	else
	{
        printf (DOUBLES_ARG_MESSAGE);
		free(array_args);
		return NULL;
	}
}