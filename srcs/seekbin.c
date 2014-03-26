/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seekbin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troussel <troussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/12 16:54:09 by troussel          #+#    #+#             */
/*   Updated: 2014/03/14 13:36:49 by troussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node_run.h"
#include "error_sh.h"
#include "libft.h"
#include <unistd.h>

static int	chk_xperm(char *str, int free_flg)
{
	if (access(str, X_OK) == -1)
	{
		error(PERM, str, 0);
		if (free_flg)
			ft_strdel(&str);
		return (0);
	}
	if (free_flg)
		ft_strdel(&str);
	return (1);
}

int			seekbin(t_cmd *dat, t_path *lst)
{
	char	*bin_path;
	t_path	*tmp;

	if (!dat->prg)
		return (0);
	if (access(dat->prg, F_OK) == 0)
		return (chk_xperm(dat->prg, 0));
	tmp = lst;
	while (tmp)
	{
		bin_path = ft_strjoin(tmp->dir, dat->prg);
		if (access(bin_path, F_OK) == 0)
			return (chk_xperm(bin_path, 1));
		ft_strdel(&bin_path);
		tmp = tmp->nxt;
	}
	return (0);
}
