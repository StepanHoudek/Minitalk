/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoudek <shoudek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:17:36 by shoudek           #+#    #+#             */
/*   Updated: 2024/01/18 09:53:05 by shoudek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	num_len(long int num)
{
	int			i;

	i = 0;
	if (num == 0)
		return (1);
	if (num < 0)
	{
		i++;
		num *= -1;
	}
	while (num > 0)
	{
		num /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int			i;
	long int	num;
	char		*ptr;

	num = n;
	i = num_len(num);
	ptr = malloc(sizeof(char) * (i + 1));
	if (ptr == NULL)
		return (NULL);
	ptr[i] = '\0';
	if (num == 0)
		ptr[0] = '0';
	if (num < 0)
	{
		ptr[0] = '-';
		num = num * -1;
	}
	while (num)
	{
		ptr[--i] = num % 10 + '0';
		num /= 10;
	}
	return (ptr);
}

/*
int	main(void)
{
	printf("%s\n", ft_itoa(2147483647));
	// ft_itoa(2147483648);
}
*/
