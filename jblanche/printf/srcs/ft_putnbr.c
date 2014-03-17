/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblanche <jblanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 10:49:23 by jblanche          #+#    #+#             */
/*   Updated: 2013/12/22 18:05:16 by jblanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_intlen(int n)
{
	int	ilen;

	if (n == -2147483648)
		ilen = 11;
	else if (n == 0)
		ilen = 1;
	else
		ilen = ft_strlen(ft_itoa(n));
	return (ilen);
}

static void		ft_process_nbr(int n)
{
	if (n == -2147483648)
		ft_putstr("-2147483648");
	else
	{
		if (n < 0)
		{
			ft_putchar('-');
			n *= -1;
		}
		if (n >= 10)
		{
			ft_process_nbr(n / 10);
			ft_process_nbr(n % 10);
		}
		else
			ft_putchar(48 + n);
	}
}

int				ft_putnbr(int n)
{
	int		ret;

	ret = ft_intlen(n);
	ft_process_nbr(n);
	return (ret);
}
