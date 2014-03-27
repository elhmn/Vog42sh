/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troussel <troussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 13:16:31 by troussel          #+#    #+#             */
/*   Updated: 2013/11/25 17:29:08 by troussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;
	size_t			ret;
	size_t			timer;

	timer = size;
	if (size >= ft_strlen(dst))
		ret = ft_strlen(dst) + ft_strlen(src);
	else
		ret = size + ft_strlen(src);
	j = -1;
	while (dst[++j] != '\0' && timer != 0)
		timer--;
	if (timer == 0)
		return (ret);
	i = 0;
	while ((j != (size - 1)) && src[i])
	{
		dst[j] = src[i];
		j++;
		i++;
	}
	dst[j] = '\0';
	return (ret);
}
