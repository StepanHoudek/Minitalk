/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoudek <shoudek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 12:40:09 by shoudek           #+#    #+#             */
/*   Updated: 2024/02/07 15:04:10 by shoudek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char *argv[])
{
	unsigned char	c;
	int				bits;
	int				i;

	if (argc != 3)
		return (0);
	i = 0;
	while (argv[2][i])
	{
		bits = 8;
		c = argv[2][i];
		while (bits > 0)
		{
			if (c & 0b10000000)
				kill(ft_atoi(argv[1]), SIGUSR2);
			else
				kill(ft_atoi(argv[1]), SIGUSR1);
			bits--;
			c <<= 1;
			usleep(50);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}
