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
