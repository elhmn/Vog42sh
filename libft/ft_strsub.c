/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troussel <troussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 13:01:05 by troussel          #+#    #+#             */
/*   Updated: 2013/11/30 18:03:24 by troussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char	*fresh;

	if (s == NULL)
		return (NULL);
	fresh = (char*)malloc(sizeof(char) * (len + 1));
	if (!fresh)
		return (NULL);
	fresh = ft_strncpy(fresh, &s[start], len);
	if (!(ft_strlen(&s[start]) < len))
		fresh[len] = '\0';
	return (fresh);
}
