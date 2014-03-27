/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troussel <troussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 10:16:35 by troussel          #+#    #+#             */
/*   Updated: 2013/11/25 16:46:17 by troussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strncpy(char *s1, const char *s2, size_t n)
{
	int	i;

	i = -1;
	while (++i != (int)n)
	{
		if (i <= (int)ft_strlen(s2))
			s1[i] = s2[i];
		else
			s1[i] = '\0';
	}
	return (s1);
}
