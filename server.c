/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 19:34:55 by mohmazou          #+#    #+#             */
/*   Updated: 2024/06/06 15:30:16 by mohmazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	first_msg(int pid)
{
	int	w;

	w = 0;
	write(1, "the PID < ", 11);
	ft_putnbr(pid);
	write(1, " >\n", 4);
	write(1, "waiting for msg ", 17);
	while (w < 5)
	{
		write(1, ".", 2);
		usleep(400000);
		w ++;
	}
	write(1, "\n", 1);
}

void	ft_handler(int signal, siginfo_t *info, void *s)
{
	static int	c;
	static int	i;
	static int	c_pid ;

	s = NULL;
	if (!c_pid)
		c_pid = info->si_pid;
	if (c_pid != info->si_pid)
	{
		c_pid = info->si_pid;
		c = 0;
		i = 0;
	}
	c |= ((signal == SIGUSR1) << i++);
	if (i == 8)
	{
		write(1, &c, 1);
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	sa;

	pid = getpid();
	sa.sa_sigaction = ft_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	first_msg(pid);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}
