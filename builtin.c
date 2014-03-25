#include <string.h>
#include <stdio.h>
#include "ftsh.h"
#include "ftsh_env.h"

int     ft_cd(t_cmd *dat, t_env *env);
int     ft_unsetenv(t_cmd *dat, t_env *env);
int     ft_setenv(t_cmd *dat, t_env *env);
int     ft_echo(t_cmd *dat, t_env *env);

int ft_exit(void)
{
	printf("sym exit\n");
	return (0);
}

int ft_env(void)
{
	printf("env\n");
	return (0);
}
/*
int ft_echo(t_cmd *dat)
{
	if (dat->arg[1])
		printf("%s", dat->arg[1]);
	printf("\n");
	return (0);
}
*/
int	isbuiltin(t_cmd *dat)
{
	if (!dat->prg)
		return (0);
	if (!strcmp(dat->prg, "cd"))
		return (1);
	else if (!strcmp(dat->prg, "echo"))
		return (1);
	else if (!strcmp(dat->prg, "exit"))
		return (1);
	else if (!strcmp(dat->prg, "env"))
		return (1);
	else if (!strcmp(dat->prg, "setenv"))
		return (1);
	else if (!strcmp(dat->prg, "unsetenv"))
		return (1);
	else
		return (0);
}

int	builtin(t_cmd *dat, t_env *env)
{
	(void)dat;
	(void)env;
	if (!strcmp(dat->prg, "cd"))
		return (ft_cd(dat, env));
	else if (!strcmp(dat->prg, "echo"))
		return (ft_echo(dat, env));
	else if (!strcmp(dat->prg, "exit"))
		return (ft_exit());
	else if (!strcmp(dat->prg, "env"))
		return (ft_env());
	else if (!strcmp(dat->prg, "setenv"))
		return (ft_setenv(dat, env));
	else if (!strcmp(dat->prg, "unsetenv"))
		return (ft_unsetenv(dat, env));
	else
		return (1);
}
