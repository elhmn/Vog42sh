/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troussel <troussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 14:28:33 by troussel          #+#    #+#             */
/*   Updated: 2013/11/25 16:45:54 by troussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	int				stop;

	if (n == 0)
		return (0);
	i = 0;
	stop = 0;
	while (s1[i] && s2[i] && !stop && i != (n - 1))
	{
		if (s1[i] == s2[i])
			i++;
		else
			stop++;
	}
	if (s1[i] != s2[i])
		stop++;
	if (stop)
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}
