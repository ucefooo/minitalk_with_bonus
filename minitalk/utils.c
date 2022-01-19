/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youssama <youssama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 00:26:06 by youssama          #+#    #+#             */
/*   Updated: 2022/01/18 19:10:43 by youssama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
		ft_putchar(s[i++]);
}

void	ft_putnbr(int l)
{
	long long	n;

	n = l;
	if (n >= 10)
		ft_putnbr(n / 10);
	ft_putchar((n % 10) + 48);
}

int	ft_atoi(char *s)
{
	int	i;
	int	r;
	int	k;

	i = 0;
	r = 0;
	k = 1;
	if (!s)
		return (0);
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'
		|| s[i] == '\v' || s[i] == '\f' || s[i] == '\r')
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			k *= -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
		r = (r * 10) + (s[i++] - '0');
	return (r * k);
}
