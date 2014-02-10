/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblanche <jblanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 14:55:28 by jblanche          #+#    #+#             */
/*   Updated: 2013/12/29 17:29:01 by jblanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	ch;
	int		loc;

	loc = 0;
	ch = c;
	while (s[loc])
		loc++;
	while (s[loc] != ch)
	{
		if (s[loc] == s[0] && s[loc != s[0]])
			return (NULL);
		loc--;
	}
	return ((char *) (s + loc));
}
