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
	struct sigaction	sa;

	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	sa.sa_handler = handle_signal;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
