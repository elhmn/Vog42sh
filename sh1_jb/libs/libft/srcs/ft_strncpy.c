/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblanche <jblanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/16 16:18:38 by jblanche          #+#    #+#             */
/*   Updated: 2013/12/27 16:44:08 by jblanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strncpy(char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		j;

	i = 0;
	j = 0;
	while (i < n)
	{
		if (s2[i] == '\0')
		{
			while (s1[j])
			{
				s1[j] = '\0';
				j++;
			}
			break ;
		}
		else
			s1[j] = s2[i];
		j++;
		i++;
	}
	while (s1[j])
		j++;
	s1[j] = '\0';
	return (s1);
}
