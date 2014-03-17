/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblanche <jblanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 17:54:08 by jblanche          #+#    #+#             */
/*   Updated: 2014/02/28 18:59:55 by jblanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H
# include "../libft/includes/libft.h"
# include "lexer.h"
# include "ftsh.h"
t_lex		*init_lex(t_lex *lex);
t_lex		*free_lex(t_lex *lex);
t_lex		*add_lex(t_lex *lex, char *elm, int tok);
char		*ft_strtrim_lex(char *s);
int		ft_printf(const char *str, ...)__attribute__((format(printf, 1, 2)));
#endif /* !LEXER_H */
