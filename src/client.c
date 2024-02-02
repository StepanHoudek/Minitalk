/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoudek <shoudek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 12:40:09 by shoudek           #+#    #+#             */
/*   Updated: 2024/02/02 13:58:59 by shoudek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "smalltalk.h"

void	signal_handler(int signum)
{
	printf("Received signal %d\n", signum);
}

int	main(int argc, char *argv[])
{
	sigset_t set;

	sigemptyset(&set);

	sigaddset(&set, SIGUSR1);
	if (sigismember(&set, SIGTSTP))
	{
		printf("// SIGTSTP is in the set");
	}
	sigaddset(&set, SIGUSR2);
	if (sigismember(&set, SIGUSR2))
	{
		printf("SIGTSTP is in the set");
	}

	if (!argv)
		return (0);
	if (argc != 3)
		return (0);

	return (0);
}