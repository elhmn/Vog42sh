/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblanche <jblanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 16:20:30 by jblanche          #+#    #+#             */
/*   Updated: 2013/11/20 16:50:39 by jblanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	ch;
	int		loc;

	loc = 0;
	ch = c;
	while (s && s[loc])
	{
		if (s[loc] == ch)
			return ((char *)(s + loc));
		loc++;
	}
	return (NULL);
}

