/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troussel <troussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 13:27:51 by troussel          #+#    #+#             */
/*   Updated: 2014/03/14 13:34:50 by troussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "node_run.h"
#include "ftsh_env.h"
#include "error_sh.h"
#include "builtin.h"/**********************/
#include <unistd.h>
#include <stdlib.h>

static int	*save_fd(int *sav_fd)
{
	if (!(sav_fd = (int*)malloc(sizeof(int) * 2)))
		return (NULL);
	if ((sav_fd[0] = dup(0)) == -1)
		return (NULL);
	if ((sav_fd[0] = dup(1)) == -1)
		return (NULL);
	return (sav_fd);
}

static int	*dup_exec(t_cmd *dat, int pip[2][2], int swtch, int *sav_fd)
{
	if (!(sav_fd = save_fd(sav_fd)))
		return (NULL);
	if (dat->ifile || dat->pipe_r)
	{
		if (dup2(pip[!swtch][0], 0) == -1)
			return (NULL);
		close(pip[!swtch][0]);
	}
	if (dat->ofile || dat->pipe_w)
	{
		if (dup2(pip[swtch][1], 1) == -1)
			return (NULL);
		close(pip[swtch][1]);
	}
	return (sav_fd);
}

static void	restore_fd(t_cmd *dat, int *fd)
{
	if (dat->ifile || dat->pipe_r)
	{
		dup2(fd[0], 0);
		close(fd[0]);
	}
	if (dat->ofile || dat->pipe_w)
	{
		dup2(fd[1], 1);
		close(fd[1]);
	}
	free(fd);
	fd = NULL;
}

int			execute(t_cmd *dat, t_env *env, int pip[2][2], int swtch)
{
	int	*sav_fd;
	int	ret;

	sav_fd = NULL;
	if (dat->ifile || dat->ofile || dat->pipe_w || dat->pipe_r)
	{
		if (!(sav_fd = dup_exec(dat, pip, swtch, sav_fd)))
			return (-1);
	}
	if (isbuiltin(dat))
	{
		if (dat->pipe_w || dat->pipe_r)
			exit(builtin(dat, env));
		else
		{
			ret = builtin(dat, env);
			restore_fd(dat, sav_fd);
			return (ret);
		}
	}
	else if (seekbin(dat, env->path))
		run_bin(dat, env);
	else
		error(CMDNF, dat->prg, 1);
	return (0);
}
