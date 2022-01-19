/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youssama <youssama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 19:21:53 by youssama          #+#    #+#             */
/*   Updated: 2022/01/19 18:11:00 by youssama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	fin_msg(int sig)
{
	if (sig == SIGUSR1)
	{
		ft_putstr("✅✅✅ MESSAGE SENT ✅✅✅\n");
		exit(1);
	}
}

static void	hand(int sig)
{
	if (sig == SIGUSR2)
		usleep(200);
}

static int	send(int x, char k)
{
	int	i;
	int	y;

	i = 7;
	y = 0;
	while (i >= 0)
	{
		if (kill(x, SIGUSR1 + ((k >> i) & 1)) == -1)
			y = 1;
		if (y == 1)
			break ;
		i--;
		usleep(500);
	}
	return (y);
}

void	aff(int i, int pid)
{
	if (i == 1)
		ft_putstr("⏳⏳⏳ SENDING MESSAGE PLEASE WAIT ⏳⏳⏳\n");
	if (pid <= 0)
	{
		ft_putstr("Invalid pid");
		exit(1);
	}
}

int	main(int c, char **v)
{
	int	i;
	int	err;

	i = 0;
	signal(SIGUSR1, fin_msg);
	signal(SIGUSR2, hand);
	if (c != 3)
	{
		ft_putstr("invalid PID AND MESSAGE");
		return (0);
	}
	if (c == 3)
	{
		aff(0,ft_atoi(v[1]));
		while (v[2][i])
		{
			err = send(ft_atoi(v[1]), v[2][i++]);
			if (err == 1)
			{
				ft_putstr("❌❌❌ ERROR MESSAGE WAS NOT SENT ❌❌❌");
				return (0);
			}
			aff(i,1);
		}
		send(ft_atoi(v[1]), '\0');
	}
	return (0);
}
