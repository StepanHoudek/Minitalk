/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoudek <shoudek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 12:40:09 by shoudek           #+#    #+#             */
/*   Updated: 2024/02/07 14:32:42 by shoudek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_to_binary(int num)
{
	int	res;
	int	i;
	int	rem;

	res = 0;
	i = 1;
	while (num > 0)
	{
		rem = num % 2;
		res = res + (i * rem);
		num = num / 2;
		i = i * 10;
	}
	return (res);
}

void	signal_handler(int signum)
{
	printf("Received signal %d\n", signum);
}

int	main(/*int argc, char *argv[]*/)
{
	char *str = "Z";
	int pid;
	int num;
	int bits;

	pid = 103177;
	num = str[0];
	bits = 8;

	while (bits > 0)
	{
		//pid = num & 1;
		if (num & 8)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		bits--;
		ft_printf("%d",num & 1);
		num >>= 1;
		usleep(10);
	}

0 0 1 1 0 0 0 0
1 0 0 0 0 0 0 0

	// if (argc != 3)
	// 	return (0);

	return (0);
}