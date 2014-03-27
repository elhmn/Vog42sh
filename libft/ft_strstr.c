/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troussel <troussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 10:40:19 by troussel          #+#    #+#             */
/*   Updated: 2013/11/25 16:47:36 by troussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*ptr;
	int		i;
	int		j;

	if (needle == NULL || needle[0] == '\0')
		return ((char*)haystack);
	i = 0;
	while (haystack[i])
	{
		if (haystack[i] == needle[0])
		{
			ptr = (char*)&haystack[i];
			j = 0;
			while (needle[j] == haystack[i + j])
			{
				if (needle[j + 1] == '\0')
					return (ptr);
				j++;
			}
		}
		i++;
	}
	return (NULL);
}
