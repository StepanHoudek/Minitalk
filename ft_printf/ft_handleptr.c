/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handleptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoudek <shoudek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:43:29 by shoudek           #+#    #+#             */
/*   Updated: 2024/01/23 14:16:36 by shoudek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_handleptr(uintptr_t num, const char *format, int *ptr_sum)
{
	if (num == 0)
	{
		ft_putstr("(nil)", ptr_sum);
		return ;
	}
	ft_putstr("0x", ptr_sum);
	ft_puthex(num, format, ptr_sum);
}
