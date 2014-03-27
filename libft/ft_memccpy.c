/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troussel <troussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 10:54:54 by troussel          #+#    #+#             */
/*   Updated: 2013/11/25 16:41:36 by troussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memccpy(void *s1, void *s2, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*ptr_s1;
	unsigned char	*ptr_s2;

	ptr_s1 = s1;
	ptr_s2 = s2;
	i = 0;
	while (i != (n))
	{
		ptr_s1[i] = ptr_s2[i];
		if (ptr_s2[i] == (unsigned char)c)
			return (s1 + i + 1);
		i++;
	}
	return (NULL);
}
