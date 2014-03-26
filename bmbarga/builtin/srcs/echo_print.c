/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/23 14:16:42 by bmbarga           #+#    #+#             */
/*   Updated: 2014/03/26 14:47:07 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "echo.h"
#include "ftsh_env.h"
#include "ftsh.h"
#include "libft.h"

static int		spe_strlen(char *str)
{
	int		len;

	len = 0;
	while (str && *str && ft_isalnum(*str))
	{
		len++;
		str++;
	}
	return (len);
}

static char		*spe_strchr(char *str, int c)
{
	while (str && *str && ft_isalnum(*str) && *str != c)
		str++;
	return (str);
}

static char		*put_env(char *str, t_venv *var, t_env *env)
{
	char	*tmp;
	int		ret;

	ret = 200;
	tmp = str + 1;
	if (*tmp == '?')
	{
		ft_putnbr(env->last_ret);
		return (tmp);
	}
	while (var && ar->nxt
			&& (ret = ft_strncmp(tmp, var->var, spe_strlen(tmp))))
		var = var->nxt;
	if (var && !var->nxt)
		ret = ft_strncmp(tmp, var->var, spe_strlen(tmp));
	if (!ret)
	{
		ft_putstr(var->val);
		return (str + spe_strlen(var->var));
	}
	return (spe_strchr(tmp, '$'));
}

void			echo_print(char *str, t_env *env, int *flag)
{
	if (str)
	{
		while (*str)
		{
			if (*str == '$')
				str = put_env(str, env->var, env);
			else
				ft_putchar(*str);
			str++;
		}
		if (flag[0] != 'n')
			ft_putchar('\n');
	}
	else
		ft_putchar('\n');
}
