/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troussel <troussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 14:23:16 by troussel          #+#    #+#             */
/*   Updated: 2013/11/30 18:00:37 by troussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*smorph;
	int		i;

	if (s == NULL || f == NULL)
		return (NULL);
	smorph = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
	i = -1;
	while (s[++i])
		smorph[i] = (*f)(s[i]);
	smorph[i] = '\0';
	return (smorph);
}
