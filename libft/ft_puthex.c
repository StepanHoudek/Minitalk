/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoudek <shoudek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:27:16 by shoudek           #+#    #+#             */
/*   Updated: 2024/02/02 12:54:33 by shoudek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puthex(uintptr_t num, const char *format, int *ptr_sum)
{
	char	*hex;

	if (*(format + 1) != 'p')
		num = (unsigned int)num;
	if (*(format + 1) == 'X')
		hex = "ABCDEF";
	else
		hex = "abcdef";
	if (num < 16)
	{
		if (num < 10)
			ft_putnbr_c(num, ptr_sum);
		else
			ft_putchar_c(hex[num - 10], ptr_sum);
	}
	else
	{
		ft_puthex(num / 16, format, ptr_sum);
		ft_puthex(num - ((num / 16) * 16), format, ptr_sum);
	}
}
