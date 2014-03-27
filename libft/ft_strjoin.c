/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troussel <troussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 14:49:33 by troussel          #+#    #+#             */
/*   Updated: 2013/12/03 17:08:10 by troussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size;
	char	*fusion;

	if (s1 == NULL && s2)
		size = ft_strlen(s2) + 1;
	else if (s2 == NULL && s1)
		size = ft_strlen(s1) + 1;
	else if (s1 && s2)
		size = ft_strlen(s1) + ft_strlen(s2) + 1;
	else
		return (NULL);
	fusion = (char*)malloc(sizeof(char) * size);
	if (!fusion)
		return (NULL);
	fusion = ft_strcpy(fusion, (char*)s1);
	ft_strlcat(fusion, s2, size);
	return (fusion);
}
