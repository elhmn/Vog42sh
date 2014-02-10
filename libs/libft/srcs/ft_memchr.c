/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblanche <jblanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 13:53:21 by jblanche          #+#    #+#             */
/*   Updated: 2013/11/25 13:56:37 by jblanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void		*ft_memchr(const void *s, int c, size_t n)
{
	const char		*ptrs;
	unsigned char	ch;
	size_t			i;

	ptrs = (const char *)s;
	ch = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (ptrs[i] == ch)
			return ((char *)(s + i));
		i++;
	}
	return (NULL);
}

