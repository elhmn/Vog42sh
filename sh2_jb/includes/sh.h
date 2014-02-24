/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   42sh.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblanche <jblanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 14:46:34 by jblanche          #+#    #+#             */
/*   Updated: 2013/12/29 20:01:31 by jblanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_H
# define SH_H
# include <signal.h>
# include <unistd.h>
# include "get_next_line.h"
# include "../libs/libft/includes/libft.h"
int		ft_printf(const char *str, ...)__attribute__((format(printf, 1, 2)));
int		ft_env_main(char **str, char **enviro);
void	ft_sig(int	sig);
void	ft_error(int code, char *str);
void	ft_chg_str_in_tab(char **tab, char *str);
#endif /* !SH_H */
