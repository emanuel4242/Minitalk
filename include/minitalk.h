/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emalungo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 11:22:39 by emalungo          #+#    #+#             */
/*   Updated: 2024/08/15 12:00:57 by emalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/types.h>

// Prototipos das funções
void	error_exit(pid_t server_pid, char *str);
void	send_char(pid_t server_pid, const char *str);
void	send_signal(pid_t server_pid, unsigned char c);
size_t	ft_strlen(const char *s);
void	ft_putstr_fd(char *s, int fd);
int		ft_atoi(const char *str);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);

#endif
