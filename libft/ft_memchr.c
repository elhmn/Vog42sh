/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troussel <troussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 12:11:06 by troussel          #+#    #+#             */
/*   Updated: 2014/01/26 14:38:28 by troussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*ptr;

	if (n == 0)
		return (NULL);
	ptr = (unsigned char*)s;
	i = 0;
	while (i != n)
	{
		if (ptr[i] == (unsigned char)c)
			return ((void*)(s + i));
		i++;
	}
	return (NULL);
}
