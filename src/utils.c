/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntitan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 15:54:46 by ntitan            #+#    #+#             */
/*   Updated: 2022/03/12 17:46:35 by ntitan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_isspace(int c)
{
	return (c == '\f' || c == '\n' || c == '\r'
		|| c == '\t' || c == '\v' || c == ' ');
}

int			ft_atoi(const char *str)
{
	int		result;
	char	sign;

	result = 0;
	sign = 1;
	while (ft_isspace(*(str)))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*(str++) == '-')
			sign = -1;
	}
	while (*str != '\0' && (*str <= '9' && *str >= '0'))
	{
		if (result < 0)
		{
			if (sign == 1)
				return (-1);
			else
				return (0);
		}
		result = result * 10 + (*(str++) - '0');
	}
	return (result * (int)sign);
}

int			ft_linecounter(char *str, char c)
{
	int i;
	int words;

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

static char		**memory_giver(char *str, char c)
{
	char	**res;
	int		letters;
	int		i;
	int		j;

	if ((res = (char **)malloc(sizeof(char*) * (ft_linecounter(str, c) + 1))) == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		letters = 0;
		while (str[i] == c && str[i])
			i++;
		while (str[i] != c && str[i] != '\0')
		{
			letters++;
			i++;
		}
		if (letters > 0)
			if ((res[j++] = (char *)malloc(sizeof(char) * letters + 1)) == NULL)
				return (NULL);
	}
	res[j] = 0;
	return (res);
}

char			**ft_split(char *str, char c)
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

