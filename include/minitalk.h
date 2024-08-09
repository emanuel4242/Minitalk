/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emalungo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 13:39:03 by emalungo          #+#    #+#             */
/*   Updated: 2024/08/09 13:39:06 by emalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITAILK_H
# define MINITALK_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <string.h>

// function for client

void	error_exit(unsigned int server_pid, char *str);
void	send_char(unsigned int server_pid, const char *str);
void    send_signal(unsigned int server_pid, unsigned char c);
void	send_signal(unsigned int server_pid, unsigned char c);

int	ft_isdigit(int i);
int	ft_atoi(const char *nptr);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);

#endif