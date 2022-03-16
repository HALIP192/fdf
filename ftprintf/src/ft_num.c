/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntitan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 23:03:52 by ntitan            #+#    #+#             */
/*   Updated: 2022/01/08 16:25:33 by ntitan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	flags_bonus(int *flags, long long *val)
{
	if (*val < 0)
	{
		*val *= -1;
		return (write(1, "-", 1));
	}
	if (flags[2])
	{
		if (*val == 0)
			return (write(1, "+0", 2));
		else
			return (write(1, "+", 1));
	}
	else if (flags[1])
	{
		if (*val == 0)
			return (write(1, " 0", 2));
		else
			return (write(1, " ", 1));
	}
	if (*val == 0)
		return (write(1, "0", 1));
	return (0);
}

int	ft_putdig(va_list src, int *flags)
{
	long long		val;
	int				cnt;
	char			buff[12];
	int				with_flags;

	cnt = 0;
	val = va_arg(src, int);
	with_flags = flags_bonus(flags, &val);
	while (val)
	{
		buff[11 - cnt] = '0' + val % 10;
		cnt++;
		val /= 10;
	}
	write(1, buff + 12 - cnt, cnt);
	return (cnt + with_flags);
}

int	ft_putudig(va_list src, __attribute((unused)) int *flags)
{
	unsigned int	val;
	int				cnt;
	char			buff[12];

	cnt = 0;
	val = va_arg(src, unsigned int);
	if (val == 0)
	{
		buff[11] = '0';
		cnt = 1;
	}
	while (val)
	{
		buff[11 - cnt] = '0' + val % 10;
		val /= 10;
		cnt++;
	}
	return (write(1, buff + 12 - cnt, cnt));
}
