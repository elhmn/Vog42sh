/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblanche <jblanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 13:53:21 by jblanche          #+#    #+#             */
/*   Updated: 2013/11/25 13:58:42 by jblanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char			*ptrd;
	const char		*ptrs;
	size_t			i;

	ptrd = (char *)dst;
	ptrs = (const char *)src;
	i = 0;
	while (i < len)
	{
		ptrd[i] = ptrs[i];
		i++;
	}
	return (dst);
}

