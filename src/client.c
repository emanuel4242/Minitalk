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

// Funcao para vaidar o PID e a String
void	error_exit(unsigned int server_pid, char *str)
{
	if (kill(server_pid, 0) != 0 && ft_isdigit(server_pid))
	{
		ft_putstr_fd("error with PID %u: %s", 1);
		ft_putstr_fd(server_pid, 1);
		ft_putstr_fd(str, 1);
		ft_putnbr_fd("\n", 1);
		exit (EXIT_FAILURE);
	}
	else if (str[0] == '\0')
	{
		ft_putstr_fd("some error string", 1);
		exit (EXIT_FAILURE);
	}
}

// Funcao para enviar cada caractere da string no PID do servidor 
void	send_char(unsigned int server_pid, const char *str)
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

// Fucao para enviar o caractere como um sinal da um PID
void	send_signal(unsigned int server_pid, unsigned char c)
{
	int	i;
	unsigned char	temp;

	i = 9;
	temp = c;
	while (--i)
	{
		temp = c >> i;
		if (temp % 2 == 0)
			kill (server_pid, SIGUSR1);
		else
			kill (server_pid, SIGUSR2);
		usleep (42);
	}
}

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		
		error_exit(ft_atoi(argv[1]), argv[2]);
		send_char(ft_atoi(argv[1]), argv[2]);
		return (EXIT_SUCCESS);
	}
	ft_putstr_fd("Usage: ./server <server_pid> <message>\n", 1);
	return (EXIT_FAILURE);
}
