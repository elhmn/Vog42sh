/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblanche <jblanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/16 14:21:58 by jblanche          #+#    #+#             */
/*   Updated: 2013/12/08 18:49:06 by jblanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char		*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		j;

	i = 0;
	j = 0;
	if (n > 0)
		n--;
	else
		return (s1);
	if (s2[0] == '\0')
		return (s1);
	while (s1[j] != '\0')
		j++;
	while (n >= i)
	{
		if (s2[i] != '\0')
			s1[j] = s2[i];
		else
			s1[j] = '\0';
		i++;
		j++;
	}
	s1[j] = '\0';
	return (s1);
}

