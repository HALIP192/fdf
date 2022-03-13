/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntitan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 15:54:46 by ntitan            #+#    #+#             */
/*   Updated: 2022/03/13 22:57:56 by ntitan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_isspace(int c)
{
	return (c == '\f' || c == '\n' || c == '\r'
		|| c == '\t' || c == '\v' || c == ' ');
}

int	ft_linecounter(char *str, char c)
{
	int	i;
	int	words;

	words = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == c && str[i] != '\0')
			i++;
		if (str[i])
			words++;
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (words);
}

static int	get_letters(char *str, int *i, char c)
{
	int	letters;

	letters = 0;
	while (str[*i] == c && str[*i])
		(*i)++;
	while (str[*i] != c && str[*i] != '\0')
	{
		letters++;
		(*i)++;
	}
	return (letters);
}

char	**memory_giver(char *str, char c)
{
	char	**res;
	int		letters;
	int		i;
	int		j;

	res = (char **)malloc(sizeof(char *) * (ft_linecounter(str, c) + 1));
	if (res == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		letters = get_letters(str, &i, c);
		if (letters > 0)
		{
			res[j] = (char *)malloc(sizeof(char) * letters + 1);
			if (res[j++] == NULL)
				return (NULL);
		}
	}
	res[j] = 0;
	return (res);
}

char	**ft_split(char *str, char c)
{
	char	**res;
	int		i;
	int		j;
	int		str_number;
	int		size;

	if (str == NULL)
		return (NULL);
	size = ft_linecounter(str, c);
	res = memory_giver(str, c);
	if (res == NULL)
		return (NULL);
	i = 0;
	str_number = 0;
	while (str_number < size)
	{
		while (str[i] == c && str[i])
			i++;
		j = 0;
		while (str[i] != c && str[i])
			res[str_number][j++] = str[i++];
		res[str_number][j] = '\0';
		str_number++;
	}
	return (res);
}
