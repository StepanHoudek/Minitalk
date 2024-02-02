/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoudek <shoudek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 12:37:58 by shoudek           #+#    #+#             */
/*   Updated: 2024/01/16 15:00:59 by shoudek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int				len;
	unsigned int	i;
	char			*ptr;

	if (s == 0 || f == 0)
	{
		return (0);
	}
	len = ft_strlen(s);
	i = 0;
	ptr = malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		ptr[i] = (*f)(i, s[i]);
		i++;
	}
	ptr[i] = 0;
	return (ptr);
}

/*
char	sample_func(unsigned int i, char c)
{
	return (c + 1);
}
#include <stdio.h>

int	main(void)
{
	char const	*ptr;

	ptr = "LoReM iPsUm";
	printf("%s", ft_strmapi(ptr, &mapi));
}

#include <unistd.h>
char	mapi(unsigned int i, char c)
{
	static int	indexArray[11] = {0};

	if (i > 10 || indexArray[i] == 1)
		write(1, "wrong index\n", 12);
	else
		indexArray[i] = 1;
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	else if (c >= 'A' && c <= 'Z')
		return (c + 32);
	else
		return (c);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int	main(int argc, const char *argv[])
{
	char	*str;
	char	*strmapi;

	str = (char *)malloc(sizeof(*str) * 12);
	strcpy(str, "LoReM iPsUm");
	printf("%s\n", str);
	strmapi = ft_strmapi(str, &mapi);
	printf("%s", strmapi);
	if (strmapi == str)
		printf("%s", "\nA new string was not returned");
	if (strmapi[11] != '\0')
		printf("%s", "\nString is not null terminated");
	return (0);
}
*/
