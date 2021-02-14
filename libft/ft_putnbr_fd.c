/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drarlean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 17:26:57 by drarlean          #+#    #+#             */
/*   Updated: 2020/11/12 17:29:16 by drarlean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void			ft_putnbr(int fd, int n)
{
	char c;

	if (n / 10)
		ft_putnbr(fd, n / 10);
	c = '0' + n % 10;
	write(fd, &c, 1);
}

void				ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			write(fd, "-", 1);
			n = -n;
		}
		ft_putnbr(fd, n);
	}
}
