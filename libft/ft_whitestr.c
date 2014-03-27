/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_whitestr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troussel <troussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/12 13:43:18 by troussel          #+#    #+#             */
/*   Updated: 2013/12/12 17:30:07 by troussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_whitestr(size_t i)
{
	char	*str;
	int		j;

	str = ft_strnew(i + 1);
	j = -1;
	while (++j != (int)i)
		str[j] = ' ';
	return (str);
}
