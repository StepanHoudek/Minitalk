/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoudek <shoudek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 12:40:09 by shoudek           #+#    #+#             */
/*   Updated: 2024/02/07 14:28:45 by shoudek          ###   ########.fr       */
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

unsigned char	c;

void	signal_handler(int signum)
{
	static int				bit_itr = -1;
	static unsigned char	c = 0;
	int						temp;

	printf("Received signal |%d|\n", signum);
	if (bit_itr < 0)
		bit_itr = 8;
	c <<= 1;
	if (signum == 12)
		c |= 1;
	bit_itr--;
	if (bit_itr == 0)
	{

		temp = c;
		temp = c && 1;
		c >>= c;
		ft_printf("Character: |%c|\n", c);
		bit_itr = -1;
		c = 0;
	}
	return ;
	// print_array();

0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 1
0 0 0 0 0 0 1 1
0 0 0 1 1 0 0 0
0 0 1 1 0 0 0 1
0 1 1 0 0 0 1 0



0 1 0 0 0 1 1 0
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

	// signal_handler(SIGUSR2);
	// signal_handler(SIGUSR1);
	// signal_handler(SIGUSR2);
	// signal_handler(SIGUSR2);
	// signal_handler(SIGUSR1);
	// signal_handler(SIGUSR2);
	// signal_handler(SIGUSR1);

	// int i = 7;
	// while (i--)
	// 	signal_handler(SIGUSR1);
	// return (0);
}