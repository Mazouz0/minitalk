/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 20:29:16 by mohmazou          #+#    #+#             */
/*   Updated: 2024/06/06 15:36:39 by mohmazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_error(char *str_pid, int int_pid)
{
	int	i;

	i = 0;
	write(2, "invalid PID : ", 15);
	if (!int_pid && str_pid)
		while (*str_pid)
			write(2, str_pid++, 1);
	else
		ft_putnbr(int_pid);
	write(2, "\n", 1);
	exit(1);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_isspace(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	ft_getdigit(char *str, int i)
{
	long int	res;
	long int	tmp;

	tmp = 0;
	res = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
		{
			res = (str[i] - 48) + tmp * 10;
			if (res < tmp)
				return (0);
			tmp = res;
			i ++;
		}
		else
			ft_error(str, 0);
	}
	return (res);
}

void	ft_putnbr(int n)
{
	long	nb;
	char	tmp;

	nb = n;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	if (nb <= 9)
	{
		tmp = nb + '0';
		write(1, &tmp, 1);
	}
	else
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
}
