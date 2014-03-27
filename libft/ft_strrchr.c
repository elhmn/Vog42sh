/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troussel <troussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 10:39:25 by troussel          #+#    #+#             */
/*   Updated: 2014/03/27 13:33:52 by troussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	int		i;
	int		flag_set;

	ptr = (char*)s;
	flag_set = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			ptr = (char*)&s[i];
			flag_set = 1;
		}
		i++;
	}
	if (s[i] == c)
	{
		ptr = (char*)&s[i];
		flag_set = 1;
	}
	if (flag_set)
		return (ptr);
	return (NULL);
}
