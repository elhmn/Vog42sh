/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chkaccess.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troussel <troussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 11:46:14 by troussel          #+#    #+#             */
/*   Updated: 2014/03/22 16:42:07 by troussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftcd.h"
#include "error_sh.h"
#include <sys/stat.h>

int		chk_access(char *target)
{
	struct stat	buf;

	if (!stat(target, &buf))
	{
		if (S_ISDIR(buf.st_mode))
			return (0);
		error(0, "cd: target is not a valid directory", 0);
		return (1);
	}
	error(NSFOD, target, 0);
	return (1);
}
