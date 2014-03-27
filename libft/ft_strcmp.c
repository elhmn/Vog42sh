/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troussel <troussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 12:22:04 by troussel          #+#    #+#             */
/*   Updated: 2013/12/28 14:03:49 by troussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;
	int	stop;

	i = 0;
	stop = 0;
	if (s1 && s2)
	{
		while (s1[i] && s2[i] && !stop)
		{
			if (s1[i] == s2[i])
				i++;
			else
				stop++;
		}
	}
	else
		return (1);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
