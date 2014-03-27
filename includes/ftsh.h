/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftsh.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 15:41:51 by bmbarga           #+#    #+#             */
/*   Updated: 2014/03/27 12:51:57 by jblanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		FTSH_H
# define	FTSH_H
# include	"ftsh_env.h"

typedef struct		s_lex
{
	char			*elm;
	int				tok;
	struct s_lex	*nxt;
}					t_lex;

typedef struct		s_cmd
{
	char			*prg;
	char			**arg;
	char			*ifile;
	char			*ofile;
	int				flg_app;
	int				pipe_w;
	int				pipe_r;
	struct s_cmd	*nxt;
}					t_cmd;

typedef struct		s_tree
{
	struct s_cmd	*data;
	struct s_tree	*left;
	struct s_tree	*right;
}					t_tree;

typedef struct		s_forest
{
	struct s_tree	*wood;
	struct s_forest	*nxt;
}					t_for;

typedef struct		s_toklst
{
	struct s_lex	*lst;
	struct s_toklst	*nxt;
}					t_tokl;

enum				e_tok
{
	CMD,
	ARG,
	FIL,
	OUT,
	IN,
	APP,
	PIPE,
	SEMIC,
	AND,
	OR,
	VOID
};

void				sig_handle(void);
void				prompt(char *str);
int					get_next_line(int const fd, char **line);

t_lex				*lexer(char *str);
t_for				*parser(t_lex *lst);
int					parse_syn(t_lex *lst);
t_tokl				*parse_tok(t_lex *lst);
t_for				*parse_for(t_tokl *lst);
t_tree				*parse_tree(t_lex *lst, t_cmd *prv, int flg_pipe);
t_for				*add_tree(t_tree *wood, t_for *lst);

void				tree_walker(t_tree *wood, t_env *env);
int					node_run(t_cmd *data, t_env *env);
t_cmd				*free_cmd(t_cmd *cmd);

#endif
