/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troussel <troussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 15:24:37 by troussel          #+#    #+#             */
/*   Updated: 2014/03/24 15:02:10 by troussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

int	ft_putcar(char c)
{
	ft_putchar(c);
	return (1);
}

int	ft_pint(char c, int num)
{
	if (c == 'i' || c == 'd')
	{
		ft_putnbr(num);
		return (ft_ilen(num));
	}
	else if (c == 'c')
		return (ft_putcar(num));
	return (0);
}

int	ft_putstri(char c, char *str)
{
	if (c == 's')
	{
		if (str == NULL)
		{
			ft_putstr("(null)");
			return (6);
		}
		else
			ft_putstr(str);
		return (ft_strlen(str));
	}
	return (0);
}

int	ft_puint(char c, unsigned int num)
{
	if (c == 'u')
	{
		ft_putnbrui(num);
		return (ft_uilen(num));
	}
	return (0);
}
