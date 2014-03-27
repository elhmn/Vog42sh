/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troussel <troussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 13:13:14 by troussel          #+#    #+#             */
/*   Updated: 2013/11/25 16:42:28 by troussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	int		i;
	char	*ptr_dst;
	char	*ptr_src;
	char	*src_cpy;

	ptr_dst = (char*)dst;
	ptr_src = (char*)src;
	src_cpy = (char*)malloc(sizeof(char) * ft_strlen(ptr_src));
	ft_strcpy(src_cpy, ptr_src);
	i = 0;
	while (i != (int)n)
	{
		ptr_dst[i] = src_cpy[i];
		i++;
	}
	return (dst);
}
