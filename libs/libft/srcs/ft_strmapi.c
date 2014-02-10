/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblanche <jblanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 03:41:32 by jblanche          #+#    #+#             */
/*   Updated: 2013/12/01 19:46:41 by jblanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new_str;
	unsigned int	i;

	i = 0;
	new_str = ft_strnew(ft_strlen(s));
	if (!new_str)
		return (NULL);
	while (*(s + i))
	{
		*(new_str + i) = f(i, *(s + i));
		i++;
	}
	return (new_str);
}
