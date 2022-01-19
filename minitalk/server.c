/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youssama <youssama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 15:44:07 by youssama          #+#    #+#             */
/*   Updated: 2022/01/18 19:05:47 by youssama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle(int sig)
{
	static int	i;
	static char	k;

	k = (k << 1) | (sig & 1);
	i++;
	if (i == 8)
	{
		ft_putchar(k);
		k = 0;
		i = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_putstr("PID: ");
	ft_putnbr(pid);
	ft_putchar('\n');
	signal(SIGUSR1, handle);
	signal(SIGUSR2, handle);
	while (1)
		pause();
	return (0);
}
