/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tok.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troussel <troussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 17:06:14 by troussel          #+#    #+#             */
/*   Updated: 2014/02/28 17:25:46 by troussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef		PARSETOK_H
# define 	PARSETOK_H

t_tokl	add_tokl(t_lex *lex, t_tokl *lst);

void	rmrf_lex(t_lex *lex);
void	ft_strdel(char **as);

#endif		/* !PARSETOK_H */
