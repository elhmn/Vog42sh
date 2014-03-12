/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_run.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troussel <troussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 16:56:28 by troussel          #+#    #+#             */
/*   Updated: 2014/03/12 16:01:12 by troussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh_env.h"
#include "node_run.h"
#include <unistd.h>

static int		launch(t_cmd *dat, t_env *env, int pip[2][2], int swtch)
{
		fk = fork();
		if (!fk)
			execute(dat, env, pip, swtch);
		else
			waitpid(fk, &env->last_ret, WUNTRACED);
		return (env->last_return);
}

int				node_run(t_cmd *dat, t_env *env)
{
	static int	swtch = 1;
	static int	pip[2][2];
	pid_t		fk;

	swtch = (swtch ? 0 : 1);
	if (!pipe_w && !pipe_r && isbuiltin(dat))
	{
		env->last_ret = execute(dat, env, pip, swtch);
		return (env->last_ret);
	}
	if (dat->pipe_w)
	{
		if (setpipe(dat, &pip, swtch))
			return ((env->last_ret = 1));
	}
	if (dat->ifile || dat->ofile)
	{
		if (setfdfil(dat, &pip, swtch))
			return ((env->last_ret = 1))
	}
	if (isbuiltin(dat) || seekbin(dat, env->path))
		return (launch(dat, env, pip, swtch);
	else
		return ((env->last_ret = 127));
}
