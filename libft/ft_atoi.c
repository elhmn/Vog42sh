/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troussel <troussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 16:04:07 by troussel          #+#    #+#             */
/*   Updated: 2014/01/26 14:37:37 by troussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_isbs(char c)
{
	if (c == '\t' || c == '\f' || c == '+')
		return (1);
	if (c == '\r' || c == '\n' || c == '\v' || c == ' ')
		return (1);
	return (0);
}

int			ft_atoi(const char *str)
{
	int	i;
	int	ret_int;
	int	neg;

	ret_int = 0;
	neg = 0;
	i = 0;
	while (ft_isbs(str[i]))
		i++;
	if (str[i] == 45)
	{
			neg++;
			i++;
	}
	while (str[i] && ft_isdigit(str[i]))
	{
		ret_int *= 10;
		ret_int += (str[i] - 48);
		i++;
	}
	if (neg == 1)
		ret_int = -ret_int;
	return (ret_int);
}
