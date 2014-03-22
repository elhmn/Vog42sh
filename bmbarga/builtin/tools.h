/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/21 14:21:02 by bmbarga           #+#    #+#             */
/*   Updated: 2014/03/22 20:27:47 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H
# include "ftsh_env.h"
# include "ftsh.h"
# include <string.h>
# define FALSE 1
# define TRUE 0

/*
** getarg.c
*/

void	echo_print(char *str, t_env *env, int *flag);
int		ft_echo(char *str, t_env *env);
int		checksyn(char **opt, char **str, int *flag);
char	*get_arg(char *arg, char **opt);

#endif /* !TOOLS_H */
