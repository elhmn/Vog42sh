/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblanche <jblanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 17:56:22 by jblanche          #+#    #+#             */
/*   Updated: 2013/12/01 18:00:42 by jblanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memalloc(size_t size)
{
	char	*str;

	str = (char*) malloc(sizeof(*str) * size);
	if (!str)
		return (NULL);
	ft_memset(str, 0, size);
	return ((void *) str);
}
