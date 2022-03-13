/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntitan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 21:47:57 by ntitan            #+#    #+#             */
/*   Updated: 2022/03/14 00:17:16 by ntitan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "math.h"

int	ft_mod(int a)
{
	if (a < 0)
		return (a * (-1));
	else
		return (a);
	return (0);
}

int	ft_max(int a, int b)
{
	if (a < b)
		return (b);
	if (a > b)
		return (a);
	return (0);
}

void	isometric(float *x, float *y, float z)
{
	*x = (*x - *y) * cos(0.8) + 150;
	*y = (*x + *y) * sin(0.8) - z + 150;
}

int	ft_atoi(const char *str)
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

void	get_step(float *x_step, float *y_step, float buff)
{
	if (buff)
	{
		*x_step /= buff;
		*y_step /= buff;
	}
}
