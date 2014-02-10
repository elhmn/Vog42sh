/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_oct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblanche <jblanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/20 10:24:59 by jblanche          #+#    #+#             */
/*   Updated: 2013/12/22 17:56:59 by jblanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_convert_oct(unsigned int nb)
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
		res[i++] = nb % 8;
		nb = nb / 8;
	}
	while (--i >= 0)
		ret += ft_putnbr(res[i]);
	return (ret);
}
