/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: outourmi <outourmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 21:29:21 by outourmi          #+#    #+#             */
/*   Updated: 2025/03/11 06:01:30 by outourmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(char *str)
{
	int	i;
	int	signe;
	int	result;

	i = 0;
	result = 0;
	signe = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - 48;
		i++;
	}
	if (str[i] != '\0')
	{
		return (0);
	}
	return (result * signe);
}

void	ft_send_bits(int pid, char i)
{
	int	c;

	c = 0x80;
	while (c)
	{
		if ((c & i) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		c = c >> 1;
		usleep(125);
	}
}

int	main(int ac, char **av)
{
	int	i;
	int	pid;

	if (ac == 3)
	{
		i = 0;
		pid = ft_atoi(av[1]);
		if (pid <= 0 || av[2][0] == '\0')
		{
			write(2, "Error in PID or the message is empty\n", 38);
			exit(1);
		}
		while (av[2][i])
		{
			ft_send_bits(pid, av[2][i]);
			i++;
		}
		ft_send_bits(pid, '\n');
	}
	else
		write(2, "Too many or few arguments\n", 27);
}
