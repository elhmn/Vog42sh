/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_sh.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troussel <troussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 13:46:37 by troussel          #+#    #+#             */
/*   Updated: 2014/02/25 14:45:21 by troussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef		ERRORSH_H
# define	ERRORSH_H
# include	<stdlib.h>

# define	CMDNF 1
# define	ARG_M 2
# define	ARG_F 3

void	puterror(char const *s);
void	error(int code, char *str, int esc_seq);

#endif		/* !ERRORSH_H */
