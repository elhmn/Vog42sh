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

t_lex		*init_lex(t_lex *lex);
t_lex		*free_lex(t_lex *lex);
t_lex		*add_lex(t_lex *lex);

#endif /* !LEXER_H */
