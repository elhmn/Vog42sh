/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troussel <troussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 17:27:04 by troussel          #+#    #+#             */
/*   Updated: 2014/01/26 14:38:50 by troussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putstr(const char *s)
{
	int	i;

	if (s)
	{
		i = -1;
		while (s[++i])
			;
		write(1, s, i);
	}
}