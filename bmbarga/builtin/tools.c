/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/21 14:16:44 by bmbarga           #+#    #+#             */
/*   Updated: 2014/03/22 16:18:10 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"
#include <unistd.h>
#include <stdlib.h>

void		ft_putstr(char *str)
{
	if (str)
		while (*str)
			write(1, str++, 1);
}

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

static char	*put_env(char *str, t_venv *var)
{
	char	*tmp;
	int		ret;

	ret = 200;
	tmp = str + 1;
	while (var->next
			&& ret = ft_strncmp(tmp, var->var, ft_strlen(var->var)))
		var = var->next;
	if (!var->next)
		ret = ft_strncmp(tmp, var->var, ft_strlen(var->var))
	if (!ret)
	{
		ft_putstr(var->val);
		return (str + ftstrlen(var->var));
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
			ft_putchar(*str);
			str++;
		}
		if (flag[0] != '\n')
			ft_putchar('\n');
	}
}
