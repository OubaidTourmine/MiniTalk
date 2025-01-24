/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: outourmi <outourmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 01:59:38 by outourmi          #+#    #+#             */
/*   Updated: 2025/03/11 02:47:28 by outourmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_putchar ('-');
		ft_putchar ('2');
		nb = 147483648;
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb = nb * -1;
	}
	if (nb < 10)
	{
		ft_putchar (nb + 48);
	}
	else
	{
		ft_putnbr(nb / 10);
		ft_putchar(nb % 10 + 48);
	}
}

void	chi_haja(int *bit, char *i, siginfo_t *sig)
{
	static pid_t	pid = 0;

	if (pid == 0)
	{
		pid = sig->si_pid;
	}
	if (pid != sig->si_pid)
	{
		pid = sig->si_pid;
		*i = 0;
		*bit = 0;
	}
}

void	ft_handler(int signal, siginfo_t *sig, void *context)
{
	static int	bit = 0;
	static char	i = 0;

	(void)context;
	chi_haja(&bit, &i, sig);
	if (signal == SIGUSR1)
	{
