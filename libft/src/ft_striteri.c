/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 08:55:38 by dnieto-c          #+#    #+#             */
/*   Updated: 2022/05/11 12:34:11 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s || !(*s) || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

/*static void	ft_test(unsigned int index, char *s)
{
	if (s[index] >= 'a' && s[index] <= 'z')
		s[index] -= 32;
	else if (s[index] >= 'A' && s[index] <= 'Z')
		s[index] += 32;
}

int	main(void)
{
	char str[] = "0000000000";
	printf("%s\n", str);
	ft_striteri(str, &ft_test);
	printf("%s\n", str);
}*/