/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblanche <jblanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 19:59:18 by jblanche          #+#    #+#             */
/*   Updated: 2013/12/29 19:59:20 by jblanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "includes/libft.h"

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
