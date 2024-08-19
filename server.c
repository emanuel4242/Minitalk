/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emalungo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 12:13:13 by emalungo          #+#    #+#             */
/*   Updated: 2024/08/19 16:25:21 by emalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minitalk.h"

// Função para lidar com os sinais recebidos do cliente
void	handle_signal(int signal, siginfo_t *info, void *context)
{
	static unsigned char	temp = 0;
	static int				bit = 0;	

	(void)context;
	if (signal == SIGUSR1)
		temp |= (1 << (7 - bit));
	bit++;
	if (bit == 8)
	{
		if (temp == '\0')
			ft_putchar_fd('\n', 1);
		else
			ft_putchar_fd(temp, 1);
		bit = 0;
		temp = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	ft_putstr_fd("\n", 1);
	ft_putstr_fd("\n", 1);
	ft_putstr_fd("  ___  ___ _ ____   _____ _ __ \n", 1);
	ft_putstr_fd(" / __|/ _ \\ '__\\ \\ / / _ \\ '__|\n", 1);
	ft_putstr_fd(" \\__ \\  __/ |   \\ V /  __/ |   \n", 1);
	ft_putstr_fd(" |___/\\___|_|    \\_/ \\___|_|   \n", 1);
	ft_putstr_fd("\n", 1);
	ft_putstr_fd("\n", 1);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handle_signal;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	while (1)
		pause();
	return (0);
}
