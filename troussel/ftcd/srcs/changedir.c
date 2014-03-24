/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   changedir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troussel <troussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 11:46:14 by troussel          #+#    #+#             */
/*   Updated: 2014/03/22 16:42:07 by troussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftcd.h"
#include "error_sh.h"
#include <unistd.h>
#include <stdlib.h>

int				changedir(t_cmd *dat, char *target, t_env *env)
{
	char		*oldpwd;
	size_t		size;

	oldpwd = NULL;
	size = pathconf(".", _PC_PATH_MAX);
	if (chk_access(target))
		return (3);
	oldpwd = getcwd(oldpwd, size);
	if (!chdir(target))
	{
		env->var = updt_oldpwd(oldpwd, env);
		env->var = updt_pwd(target, env);
		if (dat->arg[1] && dat->arg[1][0] == '-')
			show_change(env);
		return (0);
	}
	if (oldpwd)
		free(oldpwd);
	error(UNDEF, "cd: dir change failed", 0);
	return (4);
}
