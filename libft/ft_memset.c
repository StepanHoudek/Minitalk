/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoudek <shoudek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 12:59:12 by shoudek           #+#    #+#             */
/*   Updated: 2024/01/08 14:47:54 by shoudek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = c;
		i++;
	}
	return (s);
}
/*
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	char	*str;

	str = malloc(sizeof(char) * 10);
	str[4] = 'c';
	printf("%p", ft_memset(str, 'a', 4));
}
*/
