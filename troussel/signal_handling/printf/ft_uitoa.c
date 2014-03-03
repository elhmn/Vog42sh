/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troussel <troussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 13:07:39 by troussel          #+#    #+#             */
/*   Updated: 2014/01/29 11:06:24 by troussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ftprintf.h"

static char	*ft_zero(char *ptr)
{
	ptr[0] = '0';
	ptr[1] = '\0';
	return (ptr);
}

char		*ft_uitoa(unsigned int n)
{
	char	*ptr;
	int		i;
	int		len;

	ptr = (char*)malloc(sizeof(char) * (ft_ilen(n) + 1));
	if (!ptr)
		return (ft_zero(ptr));
	if (n == 0)
		return (ft_zero(ptr));
	len = ft_uilen(n);
	i = -1;
	while (++i != len)
	{
		ptr[len - 1 - i] = n % 10 + '0';
		n = n / 10;
	}
	ptr[len] = '\0';
	return (ptr);
}
