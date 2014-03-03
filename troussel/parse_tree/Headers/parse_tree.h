/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tree.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troussel <troussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 17:06:14 by troussel          #+#    #+#             */
/*   Updated: 2014/03/03 15:32:32 by troussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef		PARSETREE_H
# define 	PARSETREE_H

t_lex		*treat_cmd(char **prg, t_lex *tok);
t_lex		*treat_inf(char **ifile, t_lex *tok);
t_lex		*treat_arg(char ***arg, t_lex *tok);

t_cmd		*add_cmdd(t_cmd *lst);
t_tree		*add_leaf(t_cmd *elm);

char		*ft_strdup(const char *s1);
size_t		ft_strlen(const char *s);

#endif		/* !PARSETREE_H */
