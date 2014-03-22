/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getarg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 14:08:01 by bmbarga           #+#    #+#             */
/*   Updated: 2014/03/22 17:37:38 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

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
	*opt = (char*)malloc(sizeof(char) * (len + 1));
	if (!opt)
		return (NULL);
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
	int 	tmp;

	len = ft_strlen(arg);
	str = (char*)malloc(sizeof(char) * (len + 1));
	tmp = str;
	if (!tmp)
		return (NULL);
	while (*arg)
		*tmp++ = arg++;
	return (str);
}

char	**get_arg(char *arg, char *opt, char *str)
{
	char	*tmp;
	int		len;

	len = 0;
	if (arg)
	{
		if (!(arg = cpy_opt(arg, &opt)))
			return (NULL);
		if (!(*str = cpy_arg(arg)))
			retutn (NULL);
	}
	return (NULL);
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
	if (!flag[0] && !flag[1] && !flag[2])
		return (FALSE);
	return (TRUE);
}

int		checksyn(char **opt, char **str, int *flag)
{
	char	*tmp1;
	char	*tmp2;

		if (getflag(flag, opt) == FALSE) //strjoin "-opt" && "str"
	{
		tmp1 = ft_strjoin(*opt, "-");
		tmp2 = ft_strjoin(tmp1, *str);
		free(*str);
		*str = tmp2;
		free(tmp1);
		free(*opt);
		return (TRUE);
	}
	return (TRUE);
}
