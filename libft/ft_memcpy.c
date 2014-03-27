/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troussel <troussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 10:53:01 by troussel          #+#    #+#             */
/*   Updated: 2013/11/25 16:42:16 by troussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int		i;
	char	*ptr_dst;
	char	*ptr_src;

	ptr_dst = (char*)dst;
	ptr_src = (char*)src;
	i = -1;
	while (i++ != (int)n - 1)
		ptr_dst[i] = ptr_src[i];
	return (dst);
}
