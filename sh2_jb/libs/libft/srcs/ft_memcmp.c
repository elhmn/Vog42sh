/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblanche <jblanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 13:53:21 by jblanche          #+#    #+#             */
/*   Updated: 2013/12/01 12:47:05 by jblanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*ptrs1;
	char	*ptrs2;
	size_t	i;
	int		calc;

	i = 0;
	n--;
	ptrs1 = (char *)s1;
	ptrs2 = (char *)s2;
	if ((int)n == -1 || ptrs1 == NULL || ptrs2 == NULL)
		return (0);
	while (i < n)
	{
		if (ptrs1[i] == ptrs2[i])
			i++;
		else
			break ;
	}
	calc = ptrs1[i] - ptrs2[i];
	return (calc);
}
