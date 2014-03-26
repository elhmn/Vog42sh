#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: troussel <troussel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/03/26 13:03:46 by troussel          #+#    #+#              #
#    Updated: 2014/03/26 13:41:57 by troussel         ###   ########.fr        #
#                                                                              #
#******************************************************************************#
NAME =	42sh

SRCDIR = srcs/

CFILES =	addvenv.c changedir.c chkaccess.c compute_path.c error.c execute.c\
			free_for.c ft_puterror.c ftcd.c ftexit.c get_next_line.c\
			gethomedir.c getinput.c initenv.c main.c node_run.c parse_for.c\
			parse_tok1.c parse_tok_tool.c parse_tree.c parse_tree_tool1.c\
			parse_tree_tool2.c run_bin.c runcore.c seekbin.c setfd.c\
			signal_handler.c tcmd_tool.c tild_replace.c ttree_tool.c updt.c

SRC = $(addprefix $(SRCDIR), $(CFILES))
GCC = gcc -Wall -Wextra -Werror
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
