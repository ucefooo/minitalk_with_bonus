/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youssama <youssama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 15:43:52 by youssama          #+#    #+#             */
/*   Updated: 2022/01/18 19:32:04 by youssama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send(int pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		kill(pid, SIGUSR1 + ((c >> i) & 1));
		i--;
		usleep(500);
	}
}

int	main(int c, char **v)
{
	int	i;
	int	pid;

	if (c != 3)
		ft_putstr("invalid PID AND MESSAGE");
	if (c == 3)
	{
		pid = ft_atoi(v[1]);
		i = 0;
		while (v[2][i])
			send(pid, v[2][i++]);
	}
	return (0);
}
