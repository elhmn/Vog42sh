/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troussel <troussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 19:55:29 by troussel          #+#    #+#             */
/*   Updated: 2013/11/30 18:02:16 by troussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	int	res;

	if (s1 == NULL || s2 == NULL)
		return (-1);
	res = ft_strcmp(s1, s2);
	if (res == 0)
		return (1);
	else
		return (0);
	return (0);
}
