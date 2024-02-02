/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoudek <shoudek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:34:29 by shoudek           #+#    #+#             */
/*   Updated: 2024/01/08 14:46:58 by shoudek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = '\0';
		i++;
	}
}

/*
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	char	*str;
	char	*ptr;

	str = malloc(sizeof(char) * 10);
	str[5] = 'c';
	str[1] = 'a';
	ft_bzero(str, 4);
	ptr = &str[0];
	printf("%s", ptr);
}
*/
