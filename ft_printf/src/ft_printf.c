/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntitan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 22:19:15 by ntitan            #+#    #+#             */
/*   Updated: 2022/01/08 16:02:16 by ntitan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	bonus_flag(const char **str, int *i, int flags[3])
{
	while (**str == '#' || **str == ' ' || **str == '+')
	{
		if (**str == '#')
			flags[0] = 1;
		if (**str == ' ')
			flags[1] = 1;
		if (**str == '+')
			flags[2] = 1;
		(*str)++;
		(*i)++;
	}
}

static int	start_check(const char *src, va_list list, int *i)
{
	static const char	mas[] = "cspdiuxX%";
	static int			(*func[])(va_list, int *) = {
		ft_putchar, ft_putstr, ft_puthex,
		ft_putdig, ft_putdig, ft_putudig,
		ft_puthex_l, ft_puthex_a, ft_putpercent};
	int					flag[3];
	size_t				len;

	flag[0] = 0;
	flag[1] = 0;
	flag[2] = 0;
	bonus_flag(&src, i, flag);
	len = 0;
	while (mas[len])
	{
		if (*src != mas[len])
			len++;
		else
		{
			(*i)++;
			return (func[len](list, flag));
		}
	}
	return (0);
}

int	ft_printf(const char *src, ...)
{
	va_list	list;
	int		cnt;
	int		i;

	va_start(list, src);
	cnt = 0;
	i = 0;
	if (src)
	{
		while (src[i])
		{
			if (src[i] == '%')
				cnt += start_check(src + (++i), list, &i);
			else
			{
				write(1, src + (i++), 1);
				cnt++;
			}
		}
	}
	va_end(list);
	return (cnt);
}
