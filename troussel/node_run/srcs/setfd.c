/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setfd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troussel <troussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 16:56:28 by troussel          #+#    #+#             */
/*   Updated: 2014/03/14 12:45:15 by troussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ftsh.h"
#include "ftsh_env.h"
#include "node_run.h"
#include "error_sh.h"
#include <unistd.h>
#include <fcntl.h>

static int		openfile(char *file, int in, int appmode)
{
	if (appmode)
		return (open(file, O_CREAT | O_RDWR | O_APPEND, S_IROTH | S_IWUSR
					 | S_IWGRP | S_IRUSR | S_IRGRP));
	else if (!in)
		return (open(file, O_CREAT | O_RDWR, S_IROTH | S_IWUSR | S_IWGRP
					 | S_IRUSR | S_IRGRP));
	else if (in)
		return (open(file, O_RDONLY));
	return (0);
}

int				setpipe(t_cmd *dat, int pip[1][2][2], int swtch)
{
	(void)dat;
	if (pipe(pip[0][swtch]) == -1)
	{
		error(0, "pipe error", 0);
		return (1);
	}
	else
		return (0);
}

static int		openi(t_cmd *dat, int pip[1][2][2], int swtch)
{
	if (dat->pipe_r)
		close(pip[0][!swtch][0]);
	if ((pip[0][!swtch][0] = openfile(dat->ifile, 1, 0)) == -1)
	{
		error(UNDEF, dat->ifile, 0);
		if (dat->pipe_w)
			close(pip[0][swtch][1]);
		return (1);
	}
	return (0);
}

int				setfdfil(t_cmd *dat, int pip[1][2][2], int swtch)
{
	int	err;

	err = 0;
	if (dat->ifile)
		err += openi(dat, &pip[0], swtch);
	if (dat->ofile)
	{
		if (dat->pipe_w)
			close(pip[0][swtch][1]);
		if ((pip[0][swtch][1] = openfile(dat->ofile, 0, dat->flg_app)) == -1)
		{
			error(UNDEF, dat->ofile, 0);
			++err;
		}
	}
	return (err);
}
