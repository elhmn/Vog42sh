/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   42sh.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblanche <jblanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 14:42:28 by jblanche          #+#    #+#             */
/*   Updated: 2014/01/04 11:59:10 by jblanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

extern char		**environ;
pid_t			pid;

static char		**ft_get_paths(char **enviro)
{
	char	**path;
	int		i;

	i = 0;
	while (enviro[i])
		i++;
	path = (char **)malloc(sizeof(path) * (i + 1));
	path[i + 1] = NULL;
	i = 0;
	while (ft_strncmp(enviro[i], "PATH=", 5) != 0)
		i++;
	environ[i] = ft_strnclr(environ[i], 5);
	path = ft_strsplit(enviro[i], ':');
	i = 0;
	while (path[i])
	{
		ft_realloc(path[i], 2);
		path[i][ft_strlen(path[i])] = '/';
		i++;
	}
	return (path);
}

static void		process_flags(char **str)
{
	int		ret_excve;
	int		i;
	char	*fpath;
	char	**path;
	char	**enviro;

	i = 0;
	ret_excve = -1;
	enviro = ft_tabcpy(environ);
	path = ft_get_paths(enviro);
	if (ft_env_main(str, enviro) == 1)
	{
		while (ret_excve == -1 && path[i])
		{
			fpath = (str[0][0] == '/' ? str[0] : ft_strjoin(path[i], str[0]));
			if (access(fpath, F_OK) == 0 && access(fpath, X_OK) == -1)
				ft_error(8, fpath);
			else
				ret_excve = execve(fpath, str, enviro);
			i++;
		}
		if (ret_excve == -1)
			ft_error(0, str[0]);
	}
	exit(0);
}

void			ft_sig(int sig)
{
	if (sig == SIGUSR1 || sig == SIGUSR2)
	{
		if (sig == SIGUSR1 && pid <= 256)
			ft_printf("exit\n");
		exit(0);
	}
	else if (sig == SIGINFO && pid == 0)
		ft_printf("$> ");
	else if (sig == SIGINT)
	{
		ft_printf("\n");
		if (pid <= 256)
			ft_printf("$> ");
	}
	else if (sig == SIGSEGV || sig == SIGBUS)
	{
		ft_puterror("unhandled error, please retry.\n");
		exit(-1);
	}
	else if (pid == 0)
	{
		signal(sig, ft_sig);
		ft_printf("\n$> ");
	}
}

static void		ft_signals(void)
{
	signal(SIGINT, ft_sig);
	signal(SIGINFO, ft_sig);
	signal(SIGUSR1, ft_sig);
	signal(SIGUSR2, ft_sig);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGSEGV, ft_sig);
	signal(SIGBUS, ft_sig);
	signal(SIGTSTP, SIG_IGN);
}

int				main(void)
{
	char	*line;
	char	**str;

	ft_signals();
	while (1)
	{
		ft_printf("$> ");
		if (get_next_line(0, &line) != 2)
		{
			if (line[0])
			{
				line = ft_strtrim(line);
				str = ft_strsplit(line, ' ');
			}
			if (line[0] && ft_strcmp(str[0], "exit") == 0)
				kill(0, SIGUSR1);
			pid = fork();
			if (pid == 0 && line[0])
				process_flags(str);
			else if (pid > 0)
				wait(&pid);
		}
	}
	return (0);
}
