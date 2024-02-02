/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoudek <shoudek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:16:59 by shoudek           #+#    #+#             */
/*   Updated: 2024/02/02 12:57:44 by shoudek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

const char	*ft_format(const char *format, int *ptr_sum, va_list args)
{
	if (*format != '%')
	{
		ft_putchar_c(*format, ptr_sum);
		return (format += 1);
	}
	if (*(format + 1) == '%' && *format == '%')
		ft_putchar_c('%', ptr_sum);
	if (*(format + 1) == 'c')
		ft_putchar_c(va_arg(args, int), ptr_sum);
	if (*(format + 1) == 's')
		ft_putstr_c(va_arg(args, char *), ptr_sum);
	if (*(format + 1) == 'd' || *(format + 1) == 'i')
		ft_putnbr_c(va_arg(args, int), ptr_sum);
	if (*(format + 1) == 'x' || *(format + 1) == 'X')
		ft_puthex(va_arg(args, int), format, ptr_sum);
	if (*(format + 1) == 'u')
		ft_putunsnbr(va_arg(args, unsigned int), ptr_sum);
	if (*(format + 1) == 'p')
		ft_handleptr(va_arg(args, uintptr_t), format, ptr_sum);
	return (format += 2);
}
