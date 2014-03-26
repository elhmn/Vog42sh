/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troussel <troussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 11:46:14 by troussel          #+#    #+#             */
/*   Updated: 2014/03/22 16:42:07 by troussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftcd.h"
#include "error_sh.h"

int		ft_cd(t_cmd *dat, t_env *env)
{
	char		*target;
	int			ret;

	if (!dat->arg[1])
	{
		if (!(target = gethomedir(env)))
			return (1);
	}
	else
	{
		if (!(target = getinput(dat, env)))
			return (2);
	}
	ret = changedir(dat, target, env);
	free(target);
	return (ret);
}
