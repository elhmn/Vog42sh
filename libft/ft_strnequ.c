/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troussel <troussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 20:00:47 by troussel          #+#    #+#             */
/*   Updated: 2013/11/30 18:20:56 by troussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int	res;

	if (s1 == NULL || s2 == NULL)
		return (-1);
	res = ft_strncmp(s1, s2, n);
	if (res == 0)
		return (1);
	else
		return (0);
	return (0);
}
