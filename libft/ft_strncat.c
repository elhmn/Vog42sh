/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troussel <troussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 11:53:24 by troussel          #+#    #+#             */
/*   Updated: 2013/11/25 16:45:39 by troussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	int				i;
	unsigned int	j;

	i = 0;
	while (s1[i] != '\0')
		i++;
	j = 0;
	while (j != n && s2[j])
	{
		s1[i] = s2[j];
		j++;
		i++;
	}
	s1[i] = '\0';
	return (s1);
}
