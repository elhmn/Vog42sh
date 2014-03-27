/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troussel <troussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 15:06:45 by troussel          #+#    #+#             */
/*   Updated: 2013/11/27 15:19:39 by troussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*area;

	area = (void*)malloc(sizeof(void) * size);
	if (!area)
		return (NULL);
	ft_bzero(area, size);
	return (area);
}
