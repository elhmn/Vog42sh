/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnclr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblanche <jblanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/05 12:39:43 by jblanche          #+#    #+#             */
/*   Updated: 2013/12/27 17:37:32 by jblanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strnclr(char *str, int n)
{
	char	*tmp;
	int		len;

	len = n;
	while (str[len])
		len++;
	tmp = (char *)malloc(sizeof(tmp) * len);
	len = 0;
	while (str[n])
		tmp[len++] = str[n++];
	return (tmp);
}
