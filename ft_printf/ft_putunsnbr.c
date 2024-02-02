/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsnbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoudek <shoudek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:33:26 by shoudek           #+#    #+#             */
/*   Updated: 2024/01/23 14:30:50 by shoudek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putunsnbr(unsigned int n, int *ptr_sum)
{
	unsigned long int	num;

	num = n;
	if (num > 9)
	{
		ft_putnbr(num / 10, ptr_sum);
		ft_putnbr(num % 10, ptr_sum);
	}
	else
		ft_putchar(num % 10 + '0', ptr_sum);
}
