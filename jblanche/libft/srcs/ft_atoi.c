/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblanche <jblanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 10:42:24 by jblanche          #+#    #+#             */
/*   Updated: 2013/12/27 18:14:43 by jblanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_atoi(const char *str)
{
	int		nbr;
	int		sign;

	sign = 1;
	nbr = 0;
	while ((*str == '\n' || *str == '\v' || *str == '\t')
			|| (*str == '\f' || *str == ' ' || *str == '\r' || *str == '+'))
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (*str && ft_isdigit(*str))
	{
		nbr = nbr * 10 + (*str - '0');
		str++;
	}
	return (sign * nbr);
}
