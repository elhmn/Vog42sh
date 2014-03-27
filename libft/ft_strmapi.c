/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troussel <troussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 14:36:01 by troussel          #+#    #+#             */
/*   Updated: 2013/11/30 18:00:04 by troussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*smorph;
	int		i;

	if (s == NULL || f == NULL)
		return (NULL);
	smorph = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
	i = -1;
	while (s[++i])
		smorph[i] = (*f)((unsigned int)i, s[i]);
	smorph[i] = '\0';
	return (smorph);
}
