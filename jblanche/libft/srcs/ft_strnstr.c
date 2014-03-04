/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblanche <jblanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/16 18:18:40 by jblanche          #+#    #+#             */
/*   Updated: 2013/12/01 12:54:27 by jblanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char		*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	if (s2[0] == '\0' || s2 == NULL)
		return ((char *)s1);
	while (s1[i] && i < n)
	{
		if (s1[i] == s2[j])
		{
			while (s1[i + j] == s2[j])
			{
				if (!s2[j + 1] && (i + j) < n)
				{
					return ((char *)s1 + i);
				}
				j++;
			}
		}
		i++;
		j = 0;
	}
	return (NULL);
}
