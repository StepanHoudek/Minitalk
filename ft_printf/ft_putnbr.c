/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoudek <shoudek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:33:26 by shoudek           #+#    #+#             */
/*   Updated: 2024/01/18 15:36:20 by shoudek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n, int *ptr_sum)
{
	long int	num;

	num = n;
	if (num < 0)
	{
		ft_putchar('-', ptr_sum);
		num *= -1;
	}
	if (num > 9)
	{
		ft_putnbr(num / 10, ptr_sum);
		ft_putnbr(num % 10, ptr_sum);
	}
	else
		ft_putchar(num % 10 + '0', ptr_sum);
}
