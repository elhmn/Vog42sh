/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpytab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troussel <troussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/27 13:32:07 by troussel          #+#    #+#             */
/*   Updated: 2014/01/31 11:25:46 by troussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	**ft_strcpytab(char **tab)
{
	char	**cpy;
	int		depth;

	depth = -1;
	while (tab[++depth])
		;
	cpy = (char**)malloc(sizeof(char*) * (depth + 1));
	cpy[depth] = '\0';
	depth = -1;
	while (tab[++depth])
		cpy[depth] = ft_strdup(tab[depth]);
	return (cpy);
}
