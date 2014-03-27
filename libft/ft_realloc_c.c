/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troussel <troussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/03 17:03:00 by troussel          #+#    #+#             */
/*   Updated: 2014/01/26 14:39:08 by troussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_realloc_c(char *ptr, size_t size)
{
	char	*cpy;
	int		i;

	i = -1;
	while (ptr[++i] && ptr)
		;
	while (i != 0 && (cpy = (char*)malloc(sizeof(char) * i)) == NULL)
		i--;
	if (!i)
		return (NULL);
	cpy = ft_memmove(cpy, ptr, (size_t)i);
	while (size != 0 && (ptr = (char*)malloc(sizeof(void) * size)) == NULL)
		size--;
	ft_strclr(ptr);
	ptr = ft_memmove(ptr, cpy, (size_t)i);
	free(cpy);
	return (ptr);
}
