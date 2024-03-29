/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 16:31:49 by dnieto-c          #+#    #+#             */
/*   Updated: 2022/07/17 18:23:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

static int	ft_count_words(const char *str, char c)
{
	int		i;
	int		number_words;

	number_words = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i] && str[i] != c)
		{
			number_words++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (number_words);
}

static char	*ft_create_word(const char *str, int start, int end)
{
	int		i;
	char	*word;

	word = (char *)malloc(sizeof(char) * end - start + 1);
	if (!word)
		return (NULL);
	i = 0;
	while (start < end)
	{
		word[i] = str[start];
		start++;
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *str, char c)
{
	int		words;
	int		i;
	int		j;
	char	**tab;
	int		index;

	words = ft_count_words(str, c);
	tab = (char **)malloc(sizeof(char *) * (words + 1));
	if (!tab)
		return (NULL);
	i = 0;
	index = 0;
	while (index < words)
	{
		while (str[i] && str[i] == c)
			i++;
		j = i;
		while (str[j] && str[j] != c)
			j++;
		tab[index++] = ft_create_word(str, i, j);
		i = j + 1;
	}
	tab[index] = NULL;
	return (tab);
}
