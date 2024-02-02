/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoudek <shoudek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:22:54 by shoudek           #+#    #+#             */
/*   Updated: 2024/01/23 12:45:37 by shoudek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *s, int *ptr_sum)
{
	if (s == NULL)
	{
		ft_putstr("(null)", ptr_sum);
		return ;
	}
	while (*s)
		ft_putchar(*s++, ptr_sum);
}
