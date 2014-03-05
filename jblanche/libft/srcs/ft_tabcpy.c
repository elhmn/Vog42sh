/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblanche <jblanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/27 16:44:40 by jblanche          #+#    #+#             */
/*   Updated: 2013/12/27 16:58:00 by jblanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	**ft_tabcpy(char **tab)
{
	int		i;
	char	**ret;

	i = 0;
	while (tab[i])
		i++;
	ret = (char **)malloc(sizeof(ret) * (i + 1));
	ret[i + 1] = NULL;
	i = 0;
	while (tab[i++])
	{
		ret[i] = (char *)malloc(sizeof (ret[i]) * ((ft_strlen(tab[i]) + 1)));
		ft_strcpy(ret[i], tab[i]);
	}
	return (tab);
}
