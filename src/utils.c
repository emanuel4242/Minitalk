/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emalungo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 10:09:02 by emalungo          #+#    #+#             */
/*   Updated: 2024/08/09 13:54:19 by emalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

size_t	strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
	{
		write(fd, s, ft_strlen(s));
	}
}

int	ft_atoi(const char *nptr)
{
	int	sig;
	int	result;

	sig = 1;
	result = 0;
	while (*str == ' ' && (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sig = -1;
	if (*str == '+' || *str[i] == '-')
		str++;
	while (*str >= '0' && *str <= '9')
		result = result * 10 + *str++ - 48;
}
