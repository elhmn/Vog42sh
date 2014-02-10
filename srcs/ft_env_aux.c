/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_aux.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblanche <jblanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 16:33:28 by jblanche          #+#    #+#             */
/*   Updated: 2013/12/29 20:03:33 by jblanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

void	ft_chg_str_in_tab(char **tab, char *str)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] != '=')
		i++;
	while (tab[j] && ft_strncmp(tab[j], str, i) != 0)
		j++;
	if (!tab[j])
	{
		ft_error(3, "env");
		return ;
	}
	else
	{
		if (ft_strlen(tab[j]) > ft_strlen(str))
			tab[j] = ft_realloc(tab[j], ft_strlen(str) - ft_strlen(tab[j]));
		ft_bzero(tab[j], ft_strlen(tab[j]));
		ft_strcpy(tab[j], str);
	}
}
