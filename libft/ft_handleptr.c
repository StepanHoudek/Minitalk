/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handleptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoudek <shoudek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:43:29 by shoudek           #+#    #+#             */
/*   Updated: 2024/02/02 12:58:20 by shoudek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_handleptr(uintptr_t num, const char *format, int *ptr_sum)
{
	if (num == 0)
	{
		ft_putstr_c("(nil)", ptr_sum);
		return ;
	}
	ft_putstr_c("0x", ptr_sum);
	ft_puthex(num, format, ptr_sum);
}
