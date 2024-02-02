/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsnbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoudek <shoudek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:33:26 by shoudek           #+#    #+#             */
/*   Updated: 2024/02/02 12:56:56 by shoudek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putunsnbr(unsigned int n, int *ptr_sum)
{
	unsigned long int	num;

	num = n;
	if (num > 9)
	{
		ft_putnbr_c(num / 10, ptr_sum);
		ft_putnbr_c(num % 10, ptr_sum);
	}
	else
		ft_putchar_c(num % 10 + '0', ptr_sum);
}
