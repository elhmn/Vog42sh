/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblanche <jblanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 04:30:55 by jblanche          #+#    #+#             */
/*   Updated: 2013/12/01 22:11:51 by jblanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t size)
{
	char	*new_str;
	size_t	i;

	i = 0;
	new_str = ft_strnew(size);
	if (!new_str)
		return (NULL);
	while (i < size && *s)
	{
		new_str[i] = s[start];
		i++;
		start++;
	}
	return (new_str);
}
