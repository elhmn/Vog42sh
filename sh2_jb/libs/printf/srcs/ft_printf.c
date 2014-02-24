/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblanche <jblanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 15:32:08 by jblanche          #+#    #+#             */
/*   Updated: 2013/12/22 16:30:38 by jblanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_flags(va_list *ap, int i, const char *str, int *ret)
{
	if (str[i] == '%')
		*ret += ft_putchar('%');
	else if (str[i] == 'd' || str[i] == 'i')
		*ret += ft_putnbr(va_arg(*ap, int));
	else if (str[i] == 'c')
		*ret += ft_putchar(va_arg(*ap, int));
	else if (str[i] == 's')
		*ret += ft_putstr(va_arg(*ap, char *));
	else if (str[i] == 'o')
		*ret += ft_convert_oct(va_arg(*ap, int));
	else if (str[i] == 'x')
		*ret += ft_convert_hex(va_arg(*ap, int), 0);
	else if (str[i] == 'X')
		*ret += ft_convert_hex(va_arg(*ap, int), 1);
	else if (str[i] == 'u')
		*ret += ft_putuint(va_arg(*ap, int));
}

int				ft_printf(const char *format, ...)
{
	va_list		ap;
	int			i;
	int			ret;

	i = 0;
	ret = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			ft_flags(&ap, i, format, &ret);
		}
		else
			ret += ft_putchar(format[i]);
		i++;
	}
	va_end(ap);
	return (ret);
}
