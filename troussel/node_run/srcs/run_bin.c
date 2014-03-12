/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_bin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troussel <troussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/12 16:00:46 by troussel          #+#    #+#             */
/*   Updated: 2014/03/12 17:14:23 by troussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node_run.h"
#include "ftsh_env.h"
#include "libft.h"

void		run_bin(t_cmd *dat, t_env *env)
{
	char	*bin_path;
	t_path	*tmp;

	tmp = env->path;
	bin_path = NULL;
	if (execve(dat->prg, dat->arg, env->env) == -1)
	{
		while (tmp)
		{
			bin_path = ft_strjoin(tmp->dir, dat->prg);
			execve(bin_path, dat->arg, env->env);
			ft_strdel(&bin_path);
			tmp = tmp->nxt;
		}
	}
	error(UNDEF, "A binary file disappeared", 1);
}

