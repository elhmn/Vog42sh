/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tree.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troussel <troussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 17:06:14 by troussel          #+#    #+#             */
/*   Updated: 2014/03/11 16:43:23 by troussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef		PARSETREE_H
# define 	PARSETREE_H
# include	"ftsh.h"

t_lex		*treat_cmd(char **prg, t_lex *tok);
t_lex		*treat_redir(t_cmd **cmd, t_lex *tok);
t_lex		*treat_inf(char **ifile, t_lex *tok);
t_lex		*treat_outf(char **ofile, int *flg_app, t_lex *tok);
t_lex		*treat_arg(char ***arg, t_lex *tok);
t_lex		*treat_pipe(int *pipe_w, t_lex *tok);

t_cmd		*add_cmdd(t_cmd *lst);
t_tree		*add_leaf(t_cmd *elm);

char		*ft_strdup(const char *s1);
int			ft_strlen(const char *s);
void		ft_strdel(char **as);

#endif		/* !PARSETREE_H */
