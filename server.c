/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emalungo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 12:13:13 by emalungo          #+#    #+#             */
/*   Updated: 2024/08/15 12:34:12 by emalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minitalk.h"

// Função para lidar com os sinais recebidos do cliente
void	handle_signal(int signal)
{
	static unsigned char	temp = 0;
	static int				bit = 0;

	if (signal == SIGUSR2)
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
}

int	main(void)
{
	ft_putstr_fd("\n", 1);
	ft_putstr_fd("\n", 1);
	ft_putstr_fd("  ___  ___ _ ____   _____ _ __ \n", 1);
	ft_putstr_fd(" / __|/ _ \\ '__\\ \\ / / _ \\ '__|\n", 1);
	ft_putstr_fd(" \\__ \\  __/ |   \\ V /  __/ |   \n", 1);
	ft_putstr_fd(" |___/\\___|_|    \\_/ \\___|_|   \n", 1);
	ft_putstr_fd("\n", 1);
	ft_putstr_fd("\n", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
	while (1)
		pause();
	return (0);
}
