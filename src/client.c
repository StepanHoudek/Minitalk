/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoudek <shoudek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 12:40:09 by shoudek           #+#    #+#             */
/*   Updated: 2024/02/05 17:33:08 by shoudek          ###   ########.fr       */
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
	int num;
	char *str = "Z";
	int to_send;
	int pid;

	pid = 184313;

	// if (argc != 3)
	// 	return (0);

	num = ft_to_binary(str[0]);
	while (num > 0)
	{
		to_send = num % 10;
		num /= 10;
		if (to_send)
		{
			printf("%d\n", to_send);
			kill(pid, SIGUSR2);
		}
		else
		{
			printf("%d\n", to_send);
			kill(pid, SIGUSR1);
		}
		usleep(100);
	}
	to_send = 7;
	while (to_send--)
	{
		kill(pid, SIGUSR1);
		usleep(100);
	}
	return (0);
}