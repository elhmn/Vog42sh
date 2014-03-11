/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troussel <troussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 16:27:18 by troussel          #+#    #+#             */
/*   Updated: 2014/03/11 16:43:37 by troussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "parse_tree.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	int		size_s1;
	char	*s2;
	int		i;

	size_s1 = ft_strlen(s1) + 1;
	s2 = (char*)malloc(size_s1);
	if (s2 == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
