/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troussel <troussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 14:40:49 by troussel          #+#    #+#             */
/*   Updated: 2013/11/25 16:45:24 by troussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	sizeout;
	int		i;

	i = 0;
	sizeout = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		sizeout++;
		i++;
	}
	return (sizeout);
}
