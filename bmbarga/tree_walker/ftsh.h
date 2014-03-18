/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftsh.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 15:41:51 by bmbarga           #+#    #+#             */
/*   Updated: 2014/03/12 13:24:31 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		FTSH_H
# define	FTSH_H

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

/* Decrit une commande intercalee sois par && sois || sois | */

// EX : ls -l file >> outfile 

typedef struct	s_cmd
{
	char			*prg; // ls
	char			**arg; // arg0 = ls ; arg1 = -l ; arg2 = file
	char			*ifile; // NULL
	char			*ofile; // outfile
	int				flg_app; // 1
	int				pipe_w; // 0
	int				pipe_r; // 0
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
	OR,
	VOID/* " || "*/
};

void		sig_handle(void);
void		prompt(char *str); /*Affiche le prompt avec str devant si str non NULL */
int			get_next_line(int const fd, char **line);

t_lex		*lexer(char *str); /*Le lexer...renvoi NULL si erreur*/
t_for		*parser(t_lex *lst); /* Liste d arbre */

int			parse_syn(t_lex *lst); /* verification syntaxique */
t_tokl		*parse_tok(t_lex *lst); /* cree une list de token */
t_for		*parse_for(t_tokl *lst);
t_tree		*parse_tree(t_lex *lst); /* cree la structure commande en meme tps que l'arbre */
t_for		*add_tree(t_tree *wood, t_for *lst);

void		tree_walker(t_tree *wood, t_env *env); /* Fonction de parcour d'arbre */
int			node_run(t_cmd *data, t_env *env); /* Fontion d execution de noeud */

#endif		/* !FTSH_H */
