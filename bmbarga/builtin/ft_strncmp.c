/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblanche <jblanche@student.42.fr> 	        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/16 20:28:55 by jblanche          #+#    #+#             */
/*   Updated: 2013/12/27 18:15:59 by jblanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	n--;
	i = 0;
	while (i < n)
	{
		if (!s1[i] || !s2[i])
			break ;
		else if (s1[i] == s2[i])
			i++;
		else
			break ;
	}
	return ((unsigned char)(s1[i]) - (unsigned char)(s2[i]));
}

