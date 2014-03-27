#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: troussel <troussel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/26 16:08:30 by troussel          #+#    #+#              #
#    Updated: 2014/03/27 14:54:17 by troussel         ###   ########.fr        #
#                                                                              #
#******************************************************************************#
NAME =	42sh

SRCDIR = srcs/

CFILES =	addvenv.c builtin.c changedir.c chkaccess.c compute_path.c echo.c\
			echo_print.c env_tools.c envdup.c error.c execute.c free_env.c\
			free_for.c ft_env.c ft_puterror.c ft_setenv.c ft_unsetenv.c\
			ftcd.c ftexit.c get_next_line.c getarg.c gethomedir.c getinput.c\
			initenv.c lex_tools.c lexer.c lexer_aux.c main.c node_run.c\
			parse_for.c parse_syn.c parse_tok1.c parse_tok_tool.c\
			parse_tree.c parse_tree_tool1.c parse_tree_tool2.c run_bin.c\
			runcore.c seekbin.c setfd.c signal_handler.c syn_next_tools.c\
			syn_nxt.c tcmd_tool.c tild_replace.c tok_type.c tools.c\
			tree_walker.c tree_walker2.c ttree_tool.c updt.c

SRC = $(addprefix $(SRCDIR), $(CFILES))
GCC = gcc -Wall -Wextra -Werror -g
OBJ = $(SRC:.c=.o)
HDDIR = includes/

all: $(NAME)

$(NAME): $(OBJ)
		make -C libft/
		make -C printf/
		$(GCC) -o $(NAME) $(OBJ) libft/libft.a printf/libftprintf.a

%.o: %.c
	$(GCC) -c -o $@ $^  -I $(HDDIR)

clean:
		make -C libft/ clean
		make -C printf/ clean
		rm -f $(OBJ)

fclean: clean
		make -C libft/ fclean
		make -C printf/ fclean
		rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re
