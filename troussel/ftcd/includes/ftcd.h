/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftcd.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troussel <troussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 15:15:50 by troussel          #+#    #+#             */
/*   Updated: 2014/03/22 15:15:53 by troussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef			FTCD_H
# define		FTCD_H
# include		"ftsh.h"
# include		"ftsh_env.h"

char	*gethomedir(t_env *env);
char	*getinput(t_cmd *dat, t_env *env);
int		*changedir(t_cmd *dat, char *target, t_env *env);

#endif			/* !FTCD_H */
