/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoudek <shoudek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:42:33 by shoudek           #+#    #+#             */
/*   Updated: 2024/01/18 09:54:00 by shoudek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	j;
	size_t	result;

	j = 0;
	result = 0;
	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (!dst && size == 0)
		return (0);
	if (size > dstlen)
		result = srclen + dstlen;
	else
		result = srclen + size;
	while (size != 0 && src[j] && dstlen < size - 1)
		dst[dstlen++] = src[j++];
	if (size > dstlen)
		dst[dstlen] = '\0';
	return (result);
}

/*
int	main(void)
{
	char	dst[10] = "Hello";
	char	src[20] = ", world";

	ft_strlcat(dst, src, 12);
	printf("%s", dst);
}
*/
