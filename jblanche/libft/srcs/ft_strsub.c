/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblanche <jblanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 04:30:55 by jblanche          #+#    #+#             */
/*   Updated: 2014/03/18 14:49:01 by jblanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t size)
{
	char	*new_str;
	size_t	i;

	if (!ft_isdigit(size))
		return (NULL);
	i = 0;
	new_str = ft_strnew(size);
	ft_putendl("chk2");
	if (!s || !new_str)
		return (NULL);
	ft_putendl("chk3");
	while (i < size && *s)
	{
	ft_putendl("chk4");
		new_str[i] = s[start];
		i++;
		start++;
	}
	ft_putendl("chk5");
	return (new_str);
}
