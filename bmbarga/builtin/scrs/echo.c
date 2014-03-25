/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/21 14:04:41 by bmbarga           #+#    #+#             */
/*   Updated: 2014/03/25 18:21:41 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh_env.h"
#include "echo.h"
#include "libft.h"
#include <stdlib.h>
//#include <stdio.h> /***************/

static void rm_endspace(char *str)
{
	int		i;

	i = 0;
	while (str && str[i])
		i++;
	i--;
	str[i] = '\0';
}

static char	*maptostr(char **arg)
{
	int		i;
	char	*str;
	char	*tmp1;
	char	*tmp2;

	i = 1;
	str = (char*)malloc(sizeof(char));
	*str = '\0';
//	dprintf(2, "tmp1 = [%s]\n", str);
	while (arg[i])
	{
		tmp1 = ft_strjoin(arg[i], " ");
//	dprintf(2, "tmp1 = [%s]\n", tmp1);
		tmp2 = ft_strjoin(str, tmp1);
	//dprintf(2, "tmp2 = [%s]\n", tmp2);
		free(str);
		str = tmp2;
		free(tmp1);
		i++;
	}
	i--;
	if (i)
		rm_endspace(str);
	return (str);
}

#include <stdio.h>/*************/

int		ft_echo(t_cmd *cmd, t_env *env) //change the type of the first arg in cmd
{
	char	*opt;
	char	*str;
	char	*arg;
	int		flag[3] = {0};

/********/
//	int i;

//	i = 0;
//	dprintf(2, "***************************\n");
//	while (cmd->arg[++i])
//		dprintf(2, "arg %d = [%s]\n", i, cmd->arg[i]);
//	dprintf(2, "***************************\n");
/*******/

//	ft_putendl("************* START *****************");
	arg = maptostr(cmd->arg);
//	dprintf(2, "str = [%s]\n", arg);
	//	printf("STR = [%s]\n", arg);
	if (!(str = get_arg(arg, &opt)))
	{
	//		printf("1-> opt = [%s] && str = [%s]\n", opt, str); /*******************/
		echo_print(arg, env, flag);	
	}
	else
	{
		if (checksyn(&opt, &str, flag) == TRUE)
			str++;
		echo_print(str, env, flag);
	//		printf("2-> opt = [%s] && str = [%s]\n", opt, str); /*********************/
	}
//	ft_putendl("************* END *****************");
//	dprintf(2, "HELP\n");/********/
	return (0);
}
