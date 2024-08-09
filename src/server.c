/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emalungo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 10:08:52 by emalungo          #+#    #+#             */
/*   Updated: 2024/08/09 18:26:47 by emalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

volatile sig_atomic_t	g_char = 0;
volatile int	g_bit_count = 0;

void	handle_signal(int signal)
{
	static unsigned char current_char;
	static int				i;
	
	current_char = current_char | (signal == SIGUSR1);
	i++;
	if (i == 8)
	{
		if (current_char == SIGUSR1)
			g_char |= (0 << g_bit_count);
		else if (current_char == SIGUSR2)
			g_char |= (1 << g_bit_count);
		g_bit_count++;
		if (g_bit_count = 8)
		{
			write(1, &g_char, 1);
			g_char = 0;
			g_bit_count = 0;
		}
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	sa.sa_sigaction = &handle_signal;
	sa.sa_flags = SA_SIGINFO | SA_RESTART;
	sigemptyset(&sa.sa_mask);

	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);

	printf("Server PID: %d\n", getpid());

	while (1)
		pause();
	return (0);
}
