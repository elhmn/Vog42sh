/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troussel <troussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 19:49:58 by troussel          #+#    #+#             */
/*   Updated: 2013/11/30 17:52:13 by troussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_strclr(char *s)
{
	if (s != NULL)
		s = (char*)ft_memset((void*)s, '\0', (size_t)(ft_strlen(s) + 1));
}