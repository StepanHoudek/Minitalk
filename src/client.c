/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoudek <shoudek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 12:40:09 by shoudek           #+#    #+#             */
/*   Updated: 2024/02/05 13:00:00 by shoudek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int signum)
{
	printf("Received signal %d\n", signum);
}

int	main(int argc, char *argv[])
{
	sigset_t set;

	sigemptyset(&set);

	sigaddset(&set, SIGUSR1);
	if (sigismember(&set, SIGUSR1))
	{
		printf("// SIGUSR1 is in the set");
	}
	sigaddset(&set, SIGUSR2);
	if (sigismember(&set, SIGUSR2))
	{
		printf("SIGUSR2 is in the set");
	}
	kill(120500, SIGUSR1);

	if (!argv)
		return (0);
	if (argc != 3)
		return (0);

	return (0);
}