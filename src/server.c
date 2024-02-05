/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoudek <shoudek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 12:40:09 by shoudek           #+#    #+#             */
/*   Updated: 2024/02/05 17:29:58 by shoudek          ###   ########.fr       */
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

int	get_binary_from_array(int i)
{
	int	x;
	int	num;

	x = 1;
	num = 0;
	while (x <= (i + 1))
	{
		num += arr[x];
		num *= 10;
		x++;
	}
	return (num);
}

int	check_end(int i)
{
	int	zero_count;
	int	num;

	zero_count = 0;
	num = 0;
	i--;
	while (arr[i--] == 0)
	{
		zero_count++;
	}
	if (zero_count >= 7)
	{
		return (i);
	}
	else
		return (0);
}

void	print_array(void)
{
	int	i;

	i = 1;
	while (arr[i++] != -1)
		printf("%d\n", arr[i]);
	return ;
}

int	to_decimal(int num)
{
	int	last_digit;
	int	base;
	int	decimal;

	base = 1;
	decimal = 0;
	while (num)
	{
		last_digit = num % 10;
		num /= 10;
		decimal += last_digit * base;
		base *= 2;
	}
	return (decimal);
}

int	add_signal(int signum)
{
	int	i;
	int	sig;

	if (signum == SIGUSR1)
		sig = 0;
	else
		sig = 1;
	i = 1;
	if (!arr)
	{
		arr = malloc(sizeof(int) * 2048);
		arr[0] = -1;
		arr[2] = -1;
	}
	while (arr[i++] != -1)
		;
	arr[i - 1] = sig;
	arr[i] = -1;
	return (i);
}

void	signal_handler(int signum)
{
	int	binary;
	int	end_i;

	printf("Received signal %d\n", signum);
	end_i = check_end(add_signal(signum));
	binary = 0;
	if (end_i)
		binary = get_binary_from_array(end_i);
	if (binary)
	{
		ft_printf("\n");
		ft_putnbr_fd(to_decimal(binary), 1);
		free(arr);
		arr = NULL;
	}
	// print_array();
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