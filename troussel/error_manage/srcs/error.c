/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troussel <troussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 13:52:07 by troussel          #+#    #+#             */
/*   Updated: 2014/03/07 16:31:07 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "error_sh.h"

static void	code_seq(int code)
{
	if (code == CMDNF)
		puterror(": command not found\n");
	else if (code == ARG_M)
		puterror("Too many arguments\n");
	else if (code == ARG_F)
		puterror("Too few arguments\n");
	else if (code == PERM)
		puterror("Permission denied\n");
	else if (code == SYN)
		puterror("syntax error near unexpected token ");
	else if (code == NSFOD)
		puterror("No such file or directory\n");
	else if (code >= UNDEF)
		puterror("Undefined error\n");
}

void		error(int code, char *str, int esc_seq)
{
	if (code || str)
		puterror("42sh: ");
	if (str)
		puterror(str);
	if (code && str)
		puterror(": ");
	if (code)
		code_seq(code);
	if (esc_seq)
	{
		puterror("\nexit\n");
		if (code)
			exit(code);
		exit(-1);
	}
}
