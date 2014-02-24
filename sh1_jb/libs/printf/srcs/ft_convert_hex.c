/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblanche <jblanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/20 10:20:50 by jblanche          #+#    #+#             */
/*   Updated: 2013/12/22 18:10:27 by jblanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_convert_hex_caps(int i, int *res)
{
	int		ret;

	ret = 0;
	if (res[i] == 10)
		ret += ft_putchar('A');
	else if (res[i] == 11)
		ret += ft_putchar('B');
	else if (res[i] == 12)
		ret += ft_putchar('C');
	else if (res[i] == 13)
		ret += ft_putchar('D');
	else if (res[i] == 14)
		ret += ft_putchar('E');
	else if (res[i] == 15)
		ret += ft_putchar('F');
	return (ret);
}

static int		ft_convert_hex_nocaps(int i, int *res)
{
	int		ret;

	ret = 0;
	if (res[i] == 10)
		ret += ft_putchar('a');
	else if (res[i] == 11)
		ret += ft_putchar('b');
	else if (res[i] == 12)
		ret += ft_putchar('c');
	else if (res[i] == 13)
		ret += ft_putchar('d');
	else if (res[i] == 14)
		ret += ft_putchar('e');
	else if (res[i] == 15)
		ret += ft_putchar('f');
	return (ret);
}

int				ft_convert_hex(unsigned int nb, int caps)
{
	int		res[20];
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	if (nb == 0)
		ret = 1;
	while (nb != 0)
	{
		res[i++] = nb % 16;
		nb = nb / 16;
	}
	while (--i >= 0)
		if (res[i] > 9 && caps == 0)
			ret += ft_convert_hex_nocaps(i, res);
		else if (res[i] > 9 && caps == 1)
			ret += ft_convert_hex_caps(i, res);
		else
			ret += ft_putnbr(res[i]);
	return (ret);
}
