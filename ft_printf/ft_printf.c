/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoudek <shoudek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:42:47 by shoudek           #+#    #+#             */
/*   Updated: 2024/01/23 14:27:42 by shoudek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		sum;
	int		*ptr_sum;

	sum = 0;
	ptr_sum = &sum;
	va_start(args, format);
	while (*format)
		format = ft_format(format, ptr_sum, args);
	return (sum);
}
