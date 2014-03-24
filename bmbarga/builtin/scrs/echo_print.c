/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/23 14:16:42 by bmbarga           #+#    #+#             */
/*   Updated: 2014/03/24 13:59:16 by troussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "echo.h"
#include "ftsh_env.h"
#include "ftsh.h"
#include "libft.h"

#include <stdio.h>/********/


static char	*put_env(char *str, t_venv *var)
{
	char	*tmp;
	int		ret;

	ret = 200;
	tmp = str + 1;
	while (var->nxt
			&& (ret = ft_strncmp(tmp, var->var, ft_strlen(var->var))))
		var = var->nxt;
	if (!var->nxt)
		ret = ft_strncmp(tmp, var->var, ft_strlen(var->var));
	if (!ret)
	{
		ft_putstr(var->val);
		return (str + ft_strlen(var->var));
	}
	return (str); //if var_env doesn't exist
}

void		echo_print(char *str, t_env *env, int *flag)
{
	if (str)
	{
		while (*str)
		{
			if (*str == '$')
				str = put_env(str, env->var);
			else
				ft_putchar(*str);
			str++;
		}
		if (flag[0] != 'n')
			ft_putchar('\n');
	}
}
