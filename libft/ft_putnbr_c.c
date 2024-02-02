/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoudek <shoudek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:33:26 by shoudek           #+#    #+#             */
/*   Updated: 2024/02/02 12:55:35 by shoudek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_c(int n, int *ptr_sum)
{
	long int	num;

	num = n;
	if (num < 0)
	{
		ft_putchar_c('-', ptr_sum);
		num *= -1;
	}
	if (num > 9)
	{
		ft_putnbr_c(num / 10, ptr_sum);
		ft_putnbr_c(num % 10, ptr_sum);
	}
	else
		ft_putchar_c(num % 10 + '0', ptr_sum);
}
