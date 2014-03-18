/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftsh_env.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troussel <troussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 11:46:14 by troussel          #+#    #+#             */
/*   Updated: 2014/03/18 15:56:42 by troussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		FTSH_ENV_H
# define	FTSH_ENV_H

/*
** liste chainé (potentiellement NULL) des variable d'environnement.
** *var contient le nom de la variable et
** *val la valeur de la variable (potentiellement NULL)
*/

typedef struct	s_varenv
{
	char				*var;
	char				*val;
	struct s_varenv		*nxt;
}				t_venv;

/*
** liste chainé des path chargé au lancement du shell
** *dir contient un path terminé par un '/' (facilite l'utilisation 
** de strjoin pour le recherche de binaire)
*/

typedef struct	s_path
{
	char				*dir;
	struct s_path		*nxt;
}				t_path;

/*
** structure contenant l'intégralité des variables d'environnement
** nécessaire au fonctionnement des builtins
** structure initialisé aprés le chargement des path au lancement du shell
** on passe l'adresse de cette structure a tree_walker puis à node_run
** qui modifie si besoin l'environnement
** *var pointe vers le premier maillon de t_venv
** *path pointe vers le premier maillon de t_path
** **env est la liste chainé t_venv convertie en char** avant chq node_run
** last_ret contient la valeur de retour de la derniere execution (initialisé à 0 au lancement du shell)
** homedir est charge au demarrage du shell et permet a ft_cd de rejoindre la home dir si l'utilisateur
** balance un "cd"
*/

typedef struct	s_env
{
	struct s_varenv		*var;
	struct s_path		*path;
	char				**env;
	char				*homedir;
	int					last_ret;
}				t_env;

t_venv	*add_venv(char *var, char *val, t_venv *lst);
t_venv	*pop_venv(char *var, t_venv *lst);
t_venv	*mod_venv(char *var, char *val, t_venv *lst);

t_path	*add_path(char *dir, t_path *lst);

t_env	init_env(t_venv *lst_venv, t_path *lst_path);

#endif		/* !FTSH_ENV_H */
