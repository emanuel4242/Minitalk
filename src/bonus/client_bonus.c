/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emalungo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 11:32:46 by emalungo          #+#    #+#             */
/*   Updated: 2024/08/19 16:19:14 by emalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk_bonus.h"

volatile sig_atomic_t	g_received = 0;

// Função para lidar com o sinal de confirmação do servidor
void	signal_received(int signal)
{
	if (signal == SIGUSR1)
		g_received = 1;
}

// Função para validar o PID e a String
void	error_exit(pid_t server_pid, char *str)
{
	if (kill(server_pid, 0) != 0)
	{
		ft_putstr_fd("Invalid PID\n", 1);
		exit(EXIT_FAILURE);
	}
	if (str[0] == '\0')
	{
		ft_putstr_fd("String cannot be empty\n", 1);
		exit(EXIT_FAILURE);
	}
}

// Função para enviar cada caractere da string no PID do servidor 
void	send_char(pid_t server_pid, const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		send_signal(server_pid, str[i]);
		i++;
	}
	send_signal(server_pid, '\0');
}

// Função para enviar o caractere como um sinal para um PID
void	send_signal(pid_t server_pid, unsigned char c)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		g_received = 0;
		if ((c >> bit) & 1)
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		while (!g_received)
			usleep(42);
		bit--;
	}
}

int	main(int argc, char **argv)
{
	pid_t	server_pid;

	if (argc == 3)
	{
		ft_putstr_fd("\n", 1);
		ft_putstr_fd("       _ _            _   \n", 1);
		ft_putstr_fd("      | (_)          | |  \n", 1);
		ft_putstr_fd("   ___| |_  ___ _ __ | |_ \n", 1);
		ft_putstr_fd("  / __| | |/ _ \\ '_ \\| __|\n", 1);
		ft_putstr_fd(" | (__| | |  __/ | | | |_ \n", 1);
		ft_putstr_fd("  \\___|_|_|\\___|_| |_|\\__|\n", 1);
		ft_putstr_fd("\n", 1);
		server_pid = ft_atoi(argv[1]);
		signal(SIGUSR1, signal_received);
		error_exit(server_pid, argv[2]);
		send_char(server_pid, argv[2]);
		return (EXIT_SUCCESS);
	}
	ft_putstr_fd("Usage: ./client <server_pid> <message>\n", 1);
	return (EXIT_FAILURE);
}
