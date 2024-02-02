/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoudek <shoudek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:03:46 by shoudek           #+#    #+#             */
/*   Updated: 2024/01/18 09:53:47 by shoudek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	word_count(const char *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	if (s[0] == '\0')
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i - 1] != c && s[i - 1] != '\0')
		{
			count++;
		}
		i++;
	}
	if (s[i - 1] != c && s[i - 1] != '\0')
		count++;
	return (count);
}

void	ft_free(char **ptr, int word)
{
	while (word--)
		free(ptr[word]);
	free(ptr);
}

size_t	word_len(char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

char	**fill_word(const char *s, char c, char **ptr, int count)
{
	int		i;
	size_t	len;
	int		word;

	len = 0;
	i = 0;
	word = 0;
	while (word < count)
	{
		while (s[i] == c)
			i++;
		len = word_len((char *)s + i, c);
		ptr[word] = ft_substr(s + i, 0, len);
		if (!ptr[word])
		{
			ft_free(ptr, word);
			return (0);
		}
		word++;
		i += len;
	}
	return (ptr);
}

char	**ft_split(const char *s, char c)
{
	int		count;
	char	**ptr;

	count = word_count(s, c);
	ptr = malloc((count + 1) * sizeof(char **));
	if (ptr == NULL)
		return (NULL);
	ptr[count] = 0;
	return (fill_word((char *)s, c, ptr, count));
}

/*
#include <stdio.h>

int	main(void)
{
	char	**ptr;
	int		i;

	// printf("%d",);
	ptr = ft_split("ahoj,jak", ',');
	i = 0;
	while (ptr[i] != 0)
	{
		printf("%s\n", ptr[i]);
		i++;
	}
}
*/
