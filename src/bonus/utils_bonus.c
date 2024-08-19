/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emalungo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 11:41:19 by emalungo          #+#    #+#             */
/*   Updated: 2024/08/15 12:01:23 by emalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk_bonus.h"

// Função para calcular o comprimento da string
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

// Função para escrever uma string no fd fornecido
void	ft_putstr_fd(char *s, int fd)
{
	if (s)
	{
		write(fd, s, ft_strlen(s));
	}
}

// Função para converter uma string em um inteiro
int	ft_atoi(const char *str)
{
	int	sig;
	int	result;

	sig = 1;
	result = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sig = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str >= '0' && *str <= '9')
		result = result * 10 + (*str++ - '0');
	return (result * sig);
}

// Função para escrever um número inteiro no fd fornecido
void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(-n, fd);
	}
	else if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(n % 10 + '0', fd);
	}
	else
		ft_putchar_fd(n + '0', fd);
}

// Função auxiliar para escrever um caractere no fd fornecido
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
