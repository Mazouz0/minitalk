/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 19:37:35 by mohmazou          #+#    #+#             */
/*   Updated: 2024/06/07 10:47:50 by mohmazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <stdio.h>

void	ft_error(char *str_pid, int int_pid);
int		ft_isdigit(int c);
int		ft_isspace(char c);
int		ft_getdigit(char *str, int i);
int		ft_atoi(char *str);
void	ft_putnbr(int n);

#endif
