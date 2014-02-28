/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   42sh.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troussel <troussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 11:46:14 by troussel          #+#    #+#             */
/*   Updated: 2014/02/28 13:34:38 by troussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef		42SH_H
# define	42SH_H
/*
typedef struct	s_env
{
	char			*var;
	char			*val;
	struct s_env	*nxt;
}				t_env;
*/

typedef struct	s_lex
{
	char			*elm;
	int				tok;
	struct s_lex	*nxt;
}				t_lex;

typedef struct	s_cmd
{
	char			*prg;
	char			**arg;
	char			*ifile;
	char			*ofile;
	int				flg_app;
	int				pipe_w;
	int				pipe_r;
	struct s_cmd	*nxt;
}				t_cmd;

typedef struct	s_tree
{
	struct s_cmd	*data;
	struct s_tree	*left;
	struct s_tree	*right;
}				t_tree;

typedef struct	s_forest
{
	struct s_tree	*wood;
	struct s_forest	*nxt;
}				t_for;

typedef struct	s_toklst
{
	struct s_lex		*lst;
	struct s_toklst		*nxt;
}				t_tokl;

enum	e_tok
{
	CMD,
	ARG,
	FIL,
	OUT, /* " > "*/
	IN,  /* " < "*/
	APP, /* double chevron */
	PIPE,
	SEMIC, /* point virgule*/
	AND, /* " && " */
	OR /* " || "*/
};

void		sig_handle(void);
void		prompt(char *str); /*Affiche le prompt avec str devant si str non NULL */
int			get_next_line(int const fd, char **line);

t_lex		*lexer(char *str); /*Le lexer...renvoi NULL si erreur*/
t_for		*parser(t_lex *lst);

int			parse_syn(t_lex *lst);
t_tokl		*parse_tok(t_lex *lst);
t_tree		*parse_tree(t_lex *lst); /*cree la structure commande en meme tps que l'arbre*/
t_for		*add_tree(t_tree *wood, t_for *lst);

void		tree_walker(t_tree *wood);
int			node_run(t_cmd *data);

#endif		/* !42SH_H */
