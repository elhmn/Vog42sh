/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_sh.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troussel <troussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 13:34:12 by troussel          #+#    #+#             */
/*   Updated: 2014/02/25 15:10:23 by troussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef		MAINSH_H
# define	MAINSH_H
# include	"ftsh_env.h"

void	sig_handle(void);
t_env	*runcore(const char *input, t_env *env);
t_env	*initenv(char **environ, t_env *env);

#endif		/* !MAINSH_H */
