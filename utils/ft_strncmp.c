/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 23:31:37 by dnieto-c          #+#    #+#             */
/*   Updated: 2022/07/22 23:32:01 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	diff;
	int				i;

	if ((int)n < 0)
		return (-1);
	i = 0;
	diff = 0;
	while (i < (int)n && !diff && s1[i] && s2[i])
	{
		diff = (unsigned char)s1[i] - (unsigned char)s2[i];
		i++;
	}
	if (i < (int)n && !diff && (s1[i] == '\0' || s2[i] == '\0'))
		diff = (unsigned char)s1[i] - (unsigned char)s2[i];
	return (diff);
}
