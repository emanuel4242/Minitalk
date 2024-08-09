/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emalungo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 10:27:49 by emalungo          #+#    #+#             */
/*   Updated: 2024/08/09 13:30:04 by emalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

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
	int	i;
	unsigned char	temp;

	i = 8; // Deve ser 8 para enviar 8 bits (1 byte)
	while (i--)
	{
		temp = (c >> i) & 1;
		if (temp == 0)
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		usleep(42);
	}
}

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		pid_t server_pid = ft_atoi(argv[1]);
		error_exit(server_pid, argv[2]);
		send_char(server_pid, argv[2]);
		return (EXIT_SUCCESS);
	}
	ft_putstr_fd("Usage: ./client <server_pid> <message>\n", 1);
	return (EXIT_FAILURE);
}