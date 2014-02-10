/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblanche <jblanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 13:53:21 by jblanche          #+#    #+#             */
/*   Updated: 2013/11/25 13:55:58 by jblanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void		*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char			*ptrd;
	const char		*ptrs;
	unsigned char	ch;
	size_t			i;

	ptrd = (char *)dst;
	ptrs = (const char *)src;
	ch = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		ptrd[i] = ptrs[i];
		if (ptrs[i] == ch)
			return ((char *)(dst + (i + 1)));
		i++;
	}
	return (NULL);
}

