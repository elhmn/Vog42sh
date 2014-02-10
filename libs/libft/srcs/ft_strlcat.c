/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblanche <jblanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/30 16:13:32 by jblanche          #+#    #+#             */
/*   Updated: 2013/12/01 12:51:31 by jblanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static void	ft_cat(const char *s, char *d, int freesp)
{
	while (*s)
	{
		if (freesp != 1)
		{
			*d = *s;
			d++;
			freesp--;
		}
		s++;
	}
	*d = '\0';
}

size_t		ft_strlcat(char *dest, const char *src, size_t size)
{
	char		*d;
	const char	*s;
	size_t		len;
	size_t		freesp;

	d = dest;
	s = src;
	freesp = size;
	while (freesp && *d)
	{
		d++;
		freesp--;
	}
	len = d - dest;
	freesp = size - len;
	if (!freesp)
		return (len + ft_strlen(src));
	ft_cat(s, d, freesp);
	return (len + ft_strlen(src));
}
