/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troussel <troussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 09:38:13 by troussel          #+#    #+#             */
/*   Updated: 2014/03/24 15:00:51 by troussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

static int	ft_chooser(char c, va_list ap)
{
	if (c == 'i' || c == 'd' || c == 'c')
		return (ft_pint(c, va_arg(ap, int)));
	if (c == 'u')
		return (ft_puint(c, va_arg(ap, unsigned int)));
	if (c == 's')
		return (ft_putstri(c, va_arg(ap, char*)));
	return (0);
}

int			ft_printf(const char *str, ...)
{
	int		pchar;
	va_list	ap;
	int		i;

	va_start(ap, str);
	pchar = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] == '%' && str[i + 1] != '%')
		{
			pchar += ft_chooser(str[i + 1], ap);
			i++;
		}
		else
			pchar += ft_putcar(str[i]);
	}
	va_end(ap);
	return (pchar);
}
