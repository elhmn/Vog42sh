/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 04:42:54 by bmbarga           #+#    #+#             */
/*   Updated: 2014/03/21 16:05:48 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"
#include <stdlib.h>
#include <string.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	char	*tmp_s1;

	tmp_s1 = ft_strnew(ft_strlen(s2) + ft_strlen(s1));
	ft_strcpy(tmp_s1, s1);
	new_str = ft_strnew(ft_strlen(s2) + ft_strlen(s1));
	if (!new_str)
		return (NULL);
	ft_strcpy(new_str, ft_strcat(tmp_s1, s2));
	return (new_str);
}
