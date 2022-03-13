/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntitan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 22:09:09 by ntitan            #+#    #+#             */
/*   Updated: 2022/01/08 16:25:55 by ntitan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	ft_putchar(va_list src, __attribute__((unused)) int *flag);
int	ft_putstr(va_list src, __attribute__((unused)) int *flag);
int	ft_puthex(va_list src, int *flag);
int	ft_putdig(va_list src, int *flag);
int	ft_putudig(va_list src, __attribute__((unused)) int *flag);
int	ft_puthex(va_list src, int *flag);
int	ft_puthex_l(va_list src, int *flag);
int	ft_puthex_a(va_list src, int *flag);
int	ft_putchar(va_list src, __attribute__((unused)) int *flag);
int	ft_putstr(va_list src, __attribute__((unused)) int *flag);
int	ft_putpercent(__attribute__((unused)) va_list src,
		__attribute__((unused)) int *flag);
#endif
