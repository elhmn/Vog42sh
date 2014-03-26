/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftcd.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troussel <troussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 15:15:50 by troussel          #+#    #+#             */
/*   Updated: 2014/03/26 13:23:15 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef			FTCD_H
# define		FTCD_H
# include		"ftsh.h"
# include		"ftsh_env.h"

char	*gethomedir(t_env *env);
char	*getinput(t_cmd *dat, t_env *env);
char	*tild_replace(char *target, char *arg, t_venv *var);
int		changedir(t_cmd *dat, char *target, t_env *env);

int		chk_access(char *target);
int		chg_dir(char *target);
t_env	*updt_oldpwd(char *oldpwd, t_env *env);
t_env	*updt_pwd(char *target, t_env *env);
void	show_change(t_env *env);

#endif
