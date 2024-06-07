/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 21:23:34 by mohmazou          #+#    #+#             */
/*   Updated: 2024/06/07 10:47:58 by mohmazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(char *str)
{
	int	i;

	i = 0;
	while (ft_isspace(str[i]) && str[i])
		i++;
	return (ft_getdigit(str, i));
}

int	get_pid(char *pid_str)
{
	int	res;

	res = ft_atoi(pid_str);
	if (res <= 0 || res > 4194304)
		ft_error(pid_str, 0);
	return (res);
}

void	ft_send(int pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if ((c >> i) & 1)
		{
			if (kill(pid, SIGUSR1) == -1)
				ft_error(NULL, pid);
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				ft_error(NULL, pid);
		}
		usleep(450);
		i ++;
	}
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	i = 0;
	if (ac != 3)
		write(1, "invalid input : ./client <PID> <msg>\n", 38);
	else
	{
		pid = get_pid(av[1]);
		while (av[2][i] != 0)
			ft_send(pid, av[2][i++]);
		ft_send(pid, '\n');
		ft_send(pid, '\0');
	}
	return (0);
}
