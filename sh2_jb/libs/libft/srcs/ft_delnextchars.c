/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delnextchars.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblanche <jblanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/12 15:59:49 by jblanche          #+#    #+#             */
/*   Updated: 2014/01/04 11:10:08 by jblanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_delnextchars(char **str, int c)
{
	int		i;
	int		j;
	char	ch;
	char	*tmp;

	tmp = ft_strnew(ft_strlen(*str));
	ch = (char)c;
	i = 0;
	while (str[0][i] != ch)
		i++;
	i++;
	j = i;
	ft_strncat(tmp, *str, i);
	while (str[0][i])
	{
		while (str[0][i] == ch)
			i++;
		tmp[j++] = str[0][i++];
	}
	*str = ft_strnew(ft_strlen(tmp));
	ft_memcpy(*str, tmp, ft_strlen(tmp));
}
