/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoudek <shoudek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:21:41 by shoudek           #+#    #+#             */
/*   Updated: 2024/01/08 15:55:39 by shoudek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*ptr;
	int		i;

	if (!s1 || !set)
		return (0);
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] != '\0' && ft_strchr(set, s1[start]))
		start++;
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	ptr = malloc(sizeof(char) * (end - start) + 1);
	if (!ptr)
		return (0);
	i = 0;
	while (start < end)
	{
		ptr[i++] = s1[start++];
	}
	ptr[i] = '\0';
	return (ptr);
}

/*
#include <stdio.h>

int	main(void)
{
	printf("%s", ft_strtrim("vfHHOvHfv", "vf"));
}
*/
