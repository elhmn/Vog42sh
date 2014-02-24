# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jblanche <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/09/25 12:42:57 by jblanche          #+#    #+#              #
#    Updated: 2014/01/29 17:29:44 by jblanche         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 42sh
OBJDIR = ./
SRCDIR = srcs/
BINDIR = ./
SRCS = 42sh.c get_next_line.c ft_env.c ft_env_aux.c ft_error.c
FLAGS = -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)
CSRCS = $(addprefix $(SRCDIR), $(SRCS))
COBJS = $(addprefix $(OBJDIR), $(OBJS))
CEXEC = $(addprefix $(BINDIR), $(NAME))

all: $(NAME)

$(NAME): $(CSRCS) ./includes/
	make -C ./libs/printf/
	make -C ./libs/libft/
	gcc $(FLAGS) -I./includes/ -L./libs/libft -lft -L./libs/printf \
		-lftprintf	-o $(NAME) $(CSRCS)

debug: $(CSRCS) ./includes/
	make -C ./libs/printf/
	make debug -C ./libs/libft/
	gcc $(FLAGS) -g -I./includes/ -L./libs/libft -lft -L./libs/printf \
		-lftprintf	-o $(NAME) $(CSRCS)

clean:
	make clean -C ./libs/printf/
	make clean -C ./libs/libft/
	rm -rf $(COBJS) $(NAME).dSYM

fclean: clean
	make fclean -C ./libs/printf/
	make fclean -C ./libs/libft/
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re
