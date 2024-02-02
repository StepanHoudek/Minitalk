/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoudek <shoudek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 13:06:08 by shoudek           #+#    #+#             */
/*   Updated: 2024/01/08 14:49:06 by shoudek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	j;
	size_t	s;

	if (!big && len == 0)
		return (0);
	if (*little == '\0')
		return ((char *)big);
	j = 0;
	while (big[j] != '\0' && j < len)
	{
		s = 0;
		while (big[j + s] != '\0' && big[j + s] == little[s] && j + s < len)
		{
			if (little[s + 1] == '\0')
				return ((char *)big + j);
			s++;
		}
		j++;
	}
	return (0);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	*big;
	char	*little;

	big = "42 1337 Network 2021 piscine Benguerir Khouribga";
	little = "Network";
	printf("haystack: %s\n", ft_strnstr(big, little, 20));
	printf("haystack: %s\n", strnstr(big, little, 20));
}
*/
