/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftsh_env.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troussel <troussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 11:46:14 by troussel          #+#    #+#             */
/*   Updated: 2014/03/27 12:47:54 by jblanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		FTSH_ENV_H
# define	FTSH_ENV_H

typedef struct	s_varenv
{
	char			*var;
	char			*val;
	struct s_varenv	*nxt;
}				t_venv;

typedef struct	s_path
{
	char			*dir;
	struct s_path	*nxt;
}				t_path;

typedef struct	s_env
{
	struct s_varenv	*var;
	struct s_path	*path;
	char			**env;
	int				last_ret;
}				t_env;

#endif
