/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initenv.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troussel <troussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 12:51:57 by troussel          #+#    #+#             */
/*   Updated: 2014/03/26 13:42:46 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		INITENV_H
# define	INITENV_H
# include	"ftsh_env.h"

t_venv	*add_venv(char *var, t_venv *lst);
t_path	*compute_path(t_venv *pathvar, t_path *lst);

#endif
