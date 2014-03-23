/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getarg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 14:08:01 by bmbarga           #+#    #+#             */
/*   Updated: 2014/03/23 15:20:09 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "echo.h"
#include "libft.h"
#include "error_sh.h"
#include "ftsh_env.h"
//#include <stdio.h> /***************/

static char		*cpy_opt(char *arg, char **opt)
{
	int		len;
	char	*tmp;
	char	*opt_tmp;

	len = 0;
	if (*arg == '-')
		arg++;
	else
		return (NULL);
	tmp = arg;
	while (*arg && *arg != '\t' && *arg != ' ')
	{
		arg++;
		len++;
	}
	if (!(*opt = (char*)malloc(sizeof(char) * (len + 1))))
		error(0, "Out of memory", 1);
	opt_tmp = *opt;
	while (*tmp && *tmp != '\t' && *tmp != ' ')
		*opt_tmp++ = *tmp++;
	*opt_tmp = '\0';
	return (tmp);
}

static char		*cpy_arg(char *arg)
{
	char	*str;
	int		len;
	char 	*tmp;

	len = ft_strlen(arg);
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		error(0, "Out of memory", 1);
	tmp = str;
	while (*arg)
		*tmp++ = *arg++;
	return (str);
}

char	*get_arg(char *arg, char **opt)
{
	char	*tmp;
	
	tmp = NULL;
	if (arg)
	{
		if (!(arg = cpy_opt(arg, opt)))
			return (NULL);
		tmp = cpy_arg(arg);
	}
	return (tmp);
}

static int		getflag(int *flag, char *opt)
{
	while (opt && *opt && (*opt == 'n'
			|| *opt == 'e' || *opt == 'E'))
	{
		if (*opt == 'n')
			flag[0] = 'n';
		else if (*opt == 'e')
			flag[1] = 'e';
		else if (*opt == 'E')
			flag[2] = 'E';
		opt++;
	}
	if (*opt != 'n' && *opt != 'e' 
			&& *opt != 'E' && *opt)
		return (FALSE);
	return (TRUE);
}

static void set_flag(int *flag)
{
	flag[0] = 0;
	flag[1] = 0;
	flag[2] = 0;
}

int		checksyn(char **opt, char **str, int *flag)
{
	char	*tmp1;
	char	*tmp2;

	if (getflag(flag, *opt) == FALSE) //strjoin "-opt" && "str"
	{
		set_flag(flag);
//		printf("GET_FLAG == FALSE  ::-> opt = [%s] && str = [%s]\n", *opt, *str);
		tmp1 = ft_strjoin("-", *opt);
		tmp2 = ft_strjoin(tmp1, *str);
		free(*str);
		*str = tmp2;
		free(tmp1);
		free(*opt);
		return (TRUE);
	}
	return (TRUE);
}
