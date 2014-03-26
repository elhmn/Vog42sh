/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_walker2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 12:35:31 by bmbarga           #+#    #+#             */
/*   Updated: 2014/03/26 12:35:35 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"
#include <stdlib.h>

static char		**free_tab(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
	{
		free(tab[i]);
		tab[i] = NULL;
	}
	free(tab[i]);
	tab[i] = NULL;
	return (tab);
}

t_cmd			*free_cmd(t_cmd *cmd)
{
	if (cmd->prg)
		free(cmd->prg);
	if (cmd->ifile)
		free(cmd->ifile);
	if (cmd->ofile)
		free(cmd->ofile);
	if (cmd->arg)
	{
		cmd->arg = free_tab(cmd->arg);
		free(cmd->arg);
	}
	free(cmd);
	cmd = NULL;
	return (NULL);
}
