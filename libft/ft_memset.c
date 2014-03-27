/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troussel <troussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 15:30:19 by troussel          #+#    #+#             */
/*   Updated: 2013/11/25 16:42:39 by troussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	int				i;
	unsigned char	*ptr;

	ptr = b;
	i = -1;
	if (len > 0 && b)
	{
		while (i++ != ((int)len - 1))
			ptr[i] = (unsigned char)c;
	}
	return (b);
}
