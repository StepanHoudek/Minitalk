/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoudek <shoudek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:22:54 by shoudek           #+#    #+#             */
/*   Updated: 2024/02/02 12:56:26 by shoudek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_c(char *s, int *ptr_sum)
{
	if (s == NULL)
	{
		ft_putstr_c("(null)", ptr_sum);
		return ;
	}
	while (*s)
		ft_putchar_c(*s++, ptr_sum);
}
