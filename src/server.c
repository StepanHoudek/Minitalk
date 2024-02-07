/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoudek <shoudek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 12:40:09 by shoudek           #+#    #+#             */
/*   Updated: 2024/02/07 15:24:10 by shoudek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int signum)
{
	static int				bit_itr = -1;
	static unsigned char	c = 0;

	if (bit_itr < 0)
		bit_itr = 8;
	c <<= 0b00000001;
	if (signum == 12)
		c |= 1;
	bit_itr--;
	if (bit_itr == 0)
	{
		ft_printf("%c", c);
		bit_itr = -1;
		c = 0;
	}
	return ;
}

void	config_signals(void)
{
	struct sigaction	action;

	action.sa_handler = signal_handler;
	sigemptyset(&action.sa_mask);
	sigaddset(&action.sa_mask, SIGINT);
	sigaddset(&action.sa_mask, SIGTERM);
	action.sa_flags = 0;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
}

int	main(void)
{
	ft_printf("Server pid: %d\n", getpid());
	while (1)
		config_signals();
	return (EXIT_SUCCESS);
}
