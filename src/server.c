/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoudek <shoudek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 12:40:09 by shoudek           #+#    #+#             */
/*   Updated: 2024/02/02 13:34:55 by shoudek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "smalltalk.h"

void	signal_handler(int signum)
{
	printf("Received signal %d\n", signum);
}

int	main(void)
{
	struct sigaction action;
	action.sa_handler = signal_handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = 0;

	ft_printf("%d",getpid());

	sigaction(SIGINT, &action, NULL);

	while (1)
	{
		// Do some work
	}

	return (0);
}