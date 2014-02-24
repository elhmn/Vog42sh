/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblanche <jblanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 19:59:35 by jblanche          #+#    #+#             */
/*   Updated: 2013/12/29 19:59:37 by jblanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int	ft_is_blank(char c)
{
	return (c == ' ' || c == '	');
}

char		*ft_strtrim(char const *s)
{
	char	*new_str;
	size_t	i;
	size_t	len;

	len = ft_strlen(s) - 1;
	i = 0;
	while (ft_is_blank(s[i]) && s[i])
		i++;
	if (!s[i])
		return (ft_strnew(1));
	while (len != i && ft_is_blank(s[len]))
		len--;
	if (!i && len == ft_strlen(s) - 1)
	{
		new_str = ft_strsub(s, 0, ft_strlen(s));
		return (new_str);
	}
	new_str = ft_strsub(s, i, len - i + 1);
	if (!new_str)
		return (NULL);
	return (new_str);
}
