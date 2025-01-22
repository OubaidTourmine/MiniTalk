/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: outourmi <outourmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 21:29:21 by outourmi          #+#    #+#             */
/*   Updated: 2025/03/11 02:37:31 by outourmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	confirm_msg(int signal)
{
	if (signal == SIGUSR2)
		write(1, "message recieved\n", 18);
}

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
