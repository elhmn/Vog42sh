/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblanche <jblanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/03 15:09:21 by jblanche          #+#    #+#             */
/*   Updated: 2013/12/03 15:22:37 by jblanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_realloc(void *ptr, size_t size)
{
	char	*bak;

	bak = (char *)malloc(sizeof(bak) * ft_strlen(ptr));
	ft_memcpy(bak, ptr, ft_strlen(ptr));
	ptr = (char *)malloc(sizeof(char *) * size);
	ft_memcpy(ptr, bak, ft_strlen(bak));
	return (ptr);
}
