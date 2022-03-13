/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntitan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 20:20:50 by ntitan            #+#    #+#             */
/*   Updated: 2022/01/08 16:07:14 by ntitan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_dectohex(char *buff, size_t l, unsigned int val, int flag)
{
	const char	*hex_l = "0123456789abcdef";
	const char	*hex_a = "0123456789ABCDEF";
	char		*hex;
	int			cnt;

	if (flag)
		hex = (char *)hex_a;
	else
		hex = (char *)hex_l;
	cnt = 0;
	if (val == 0)
	{
		buff[l - 1] = '0';
		cnt = 1;
	}
	while (val)
	{
		buff[l - 1 -(cnt++)] = hex[val % 16];
		val /= 16;
	}
	return (cnt);
}

static int	ft_dectohex_2(char *buff, size_t l, size_t val)
{
	const char	*hex = "0123456789abcdef";
	int			len;

	len = 0;
	while (val)
	{
		buff[l - 1 - (len++)] = hex[val % 16];
		val /= 16;
	}
	return (len);
}

int	ft_puthex(va_list src, int *flags)
{
	char	mas[20];
	int		cnt;
	size_t	val;
	int		fl;

	val = (size_t)va_arg(src, void *);
	fl = 0;
	if (val == 0)
		return (write(1, "(nil)", 5));
	if (flags[2])
		fl = write(1, "+", 1);
	else if (flags[1])
		fl = write(1, " ", 1);
	write(1, "0x", 2);
	cnt = ft_dectohex_2(mas, 17, val);
	return (2 + write(1, mas + 17 - cnt, cnt) + fl);
}

int	ft_puthex_l(va_list src, int *flag)
{
	int		len;
	char	buff[12];

	len = ft_dectohex(buff, 12, va_arg(src, int), 0);
	if (flag[0] && !(len == 1 && buff[11] == '0'))
		return (write(1, "0x", 2) + write(1, buff + 12 - len, len));
	else
		return (write(1, buff + 12 - len, len));
}

int	ft_puthex_a(va_list src, int *flag)
{
	int		len;
	char	buff[12];

	len = ft_dectohex(buff, 12, va_arg(src, int), 1);
	if (flag[0] && !(len == 1 && buff[11] == '0'))
		return (write(1, "0X", 2) + write(1, buff + 12 - len, len));
	else
		return (write(1, buff + 12 - len, len));
}
