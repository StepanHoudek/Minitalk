/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoudek <shoudek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 16:43:58 by shoudek           #+#    #+#             */
/*   Updated: 2024/01/16 10:39:45 by shoudek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	i;

	if ((size_t)start + len > ft_strlen(s))
		len = ft_strlen(s) - (size_t)start;
	if ((size_t)start >= ft_strlen(s))
	{
		substr = malloc(sizeof(char));
		if (!substr)
			return (0);
		substr[0] = 0;
		return (substr);
	}
	substr = malloc(sizeof(char) * len + 1);
	if (!substr)
		return (0);
	i = 0;
	while (s[i + start] != '\0' && i < (unsigned int)len)
	{
		substr[i] = s[i + start];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

/*
#include <stdio.h>

int	main(void)
{
	char	*str;

	str = "ahoj";
	printf("%s", ft_substr(str, 1, 2));
}
*/
