/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freetabc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troussel <troussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 17:14:51 by troussel          #+#    #+#             */
/*   Updated: 2014/01/15 15:48:46 by troussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	**ft_freetabc(char **grid)
{
	int	i;

	i = -1;
	while (grid[++i])
	{
		free(grid[i]);
		grid[i] = NULL;
	}
	free(grid);
	grid = NULL;
	return (NULL);
}
