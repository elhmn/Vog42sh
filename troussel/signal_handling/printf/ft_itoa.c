/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troussel <troussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 17:55:55 by troussel          #+#    #+#             */
/*   Updated: 2014/01/29 11:05:25 by troussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ftprintf.h"

static char	*ft_zero(char *ptr)
{
	ptr[0] = '0';
	ptr[1] = '\0';
	return (ptr);
}

static char	*ft_spcase(char *ptr, int n)
{
	ptr[0] = (n > 0 ? '2' : '-');
	ptr[1] = (n > 0 ? '1' : '2');
	ptr[2] = (n > 0 ? '4' : '1');
	ptr[3] = (n > 0 ? '7' : '4');
	ptr[4] = (n > 0 ? '4' : '7');
	ptr[5] = (n > 0 ? '8' : '4');
	ptr[6] = (n > 0 ? '3' : '8');
	ptr[7] = (n > 0 ? '6' : '3');
	ptr[8] = (n > 0 ? '4' : '6');
	ptr[9] = (n > 0 ? '7' : '4');
	ptr[10] = (n > 0 ? '\0' : '8');
	if (n < 0)
		ptr[11] = '\0';
	return (ptr);
}

char		*ft_itoa(int n)
{
	char	*ptr;
	int		neg_flag;
	int		i;
	int		len;

	ptr = (char*)malloc(sizeof(char) * (ft_ilen(n) + 1));
	if (!ptr)
		return (ft_zero(ptr));
	if (n == 0)
		return (ft_zero(ptr));
	if (n == 2147483647 || n == (-2147483647 - 1))
		return (ft_spcase(ptr, n));
	neg_flag = (n < 0 ? 1 : 0);
	len = ft_ilen(n);
	n = (n < 0 ? -n : n);
	i = -1;
	while (++i != len)
	{
		ptr[len - 1 - i] = n % 10 + '0';
		n = n / 10;
	}
	ptr[len] = '\0';
	if (neg_flag)
		ptr[0] = 45;
	return (ptr);
}
