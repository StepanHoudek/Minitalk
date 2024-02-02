/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoudek <shoudek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 12:09:01 by shoudek           #+#    #+#             */
/*   Updated: 2024/01/18 09:53:11 by shoudek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	j;

	j = 0;
	while (j < n)
	{
		if (((unsigned char *)s)[j] == (unsigned char)c)
			return ((void *)(s + j));
		j++;
	}
	return (0);
}

/*
#include <stdio.h>

int	main(void)
{
	printf("%p", ft_memchr("ahoj", 'h', 5));
}
*/
