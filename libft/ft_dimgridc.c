/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dimgridc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troussel <troussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 17:14:51 by troussel          #+#    #+#             */
/*   Updated: 2014/02/06 13:50:15 by troussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	**ft_dimgridc(char **grid, int line, int col)
{
	int	i;

	grid = (char**)malloc(sizeof(*grid) * (line + 1));
	if (!grid)
		return (NULL);
	grid[line] = 0;
	i = -1;
	while (++i != line)
	{
		grid[i] = ft_strnew(col + 1);
		if (!grid[i])
			return (NULL);
		grid[i][col] = 0;
	}
	return (grid);
}
