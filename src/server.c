/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoudek <shoudek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 12:40:09 by shoudek           #+#    #+#             */
/*   Updated: 2024/02/05 16:06:40 by shoudek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// client receives string and server pid
// client transcodes string to binary and sends individual 1 and 0 to server
// server initiates a sigset and adds the signals to the set
// client ends the message with sending '/0' encoded in binary OR
// 		server doesnt receive a signal for X miliseconds
// server then decodes from binary to ascii and prints out

// First step - send multiple signals to server

#include "minitalk.h"

int		*arr;

int	check_end(int i)
{
	int	zero_count;

	zero_count = 0;
	i--;
	while (arr[i--] == 10)
	{
		zero_count++;
	}
	if (zero_count >= 4)
		return (1);
	else
		return (0);
}

void	print_array(void)
{
	int	i;

	i = 0;
	while (arr[i++] != -1)
		printf("%d\n", arr[i]);
	return ;
}

int	add_signal(int signum)
{
	int	i;

	i = 0;
	if (!arr)
	{
		arr = malloc(sizeof(int) * 2048);
		arr[1] = -1;
	}
	while (arr[i++] != -1)
		;
	arr[i - 1] = signum;
	arr[i] = -1;
	return (i);
}

void	signal_handler(int signum)
{
	printf("Received signal %d\n", signum);
	printf("%d\n",check_end(add_signal(signum)));
	print_array();
}

int	main(void)
{
	struct sigaction action;

	action.sa_handler = signal_handler;
	sigemptyset(&action.sa_mask);
	sigaddset(&action.sa_mask, SIGINT);
	sigaddset(&action.sa_mask, SIGTERM);
	action.sa_flags = 0;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);

	ft_printf("%d", getpid());

	while (1)
		;
	return (0);
}