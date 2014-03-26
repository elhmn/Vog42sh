/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblanche <jblanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 18:17:42 by jblanche          #+#    #+#             */
/*   Updated: 2014/03/26 18:29:57 by jblanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		FT_ENV_H
# define	FT_ENV_H
# include	"libft.h"
# include	"ftsh_env.h"
# include	"ftsh.h"
void		free_var(t_venv *varenv);
void		free_env(t_env *env);
t_venv		*app_venv(char *var, char *val, t_venv *lst);
t_env		*envdup(t_env *ori);
t_venv		*find_env_var(t_venv *env, char *var);
void		print_env(t_venv *env);
#endif
