/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troussel <troussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 17:17:16 by troussel          #+#    #+#             */
/*   Updated: 2013/11/27 17:17:17 by troussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	char			*ptr;
	unsigned int	i;
	int				j;

	if (needle == NULL || needle[0] == '\0')
		return ((char*)haystack);
	i = 0;
	while (haystack[i] && (i != ((unsigned int)n)) && n > 0)
	{
		if (haystack[i] == needle[0])
		{
			ptr = (char*)&haystack[i];
			j = 0;
			while ((needle[j] == haystack[i + j]) && (i + j != n))
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
