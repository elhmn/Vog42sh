/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblanche <jblanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 17:54:08 by jblanche          #+#    #+#             */
/*   Updated: 2014/03/27 12:42:21 by jblanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H
# include "libft.h"
# include "lexer.h"
# include "ftsh.h"
t_lex	*init_lex(t_lex *lex);
t_lex	*free_lex(t_lex *lex);
t_lex	*add_lex(t_lex *lex, char *elm, int tok);
t_venv	*find_env_var(t_venv *env, char *var);
int		is_spec(char *str);
char	*ft_strtrim_lex(char *s);
#endif
