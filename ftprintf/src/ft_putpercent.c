/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpercent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntitan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 21:56:52 by ntitan            #+#    #+#             */
/*   Updated: 2022/01/08 16:03:22 by ntitan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_strlen(char *str)
{
	int	cnt;

	cnt = 0;
	while (str[cnt])
		cnt++;
	return (cnt);
}

int	ft_putchar(va_list src, __attribute__((unused)) int *flags)
{
	char	c;

	c = va_arg(src, int);
	return (write(1, &c, 1));
}

int	ft_putstr(va_list src, __attribute__((unused)) int *flags)
{
	char	*str;

	str = va_arg(src, char *);
	if (str == NULL)
		return (write(1, "(null)", 6));
	return (write(1, str, ft_strlen(str)));
}

int	ft_putpercent(
		__attribute__((unused)) va_list src,
		__attribute((unused)) int *flag)
{
	return (write(1, "%", 1));
}
