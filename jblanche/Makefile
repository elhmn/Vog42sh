# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jblanche <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/09/25 12:42:57 by jblanche          #+#    #+#              #
#    Updated: 2014/03/18 13:24:02 by jblanche         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lexer
OBJDIR = ./
SRCDIR = srcs/
BINDIR = ./
SRCS = lexer.c lexer_aux.c lex_tools.c tools.c
FLAGS = -Wall -Wextra -Werror
LIBS =  -L./libft -lft -L./printf -lftprintf

OBJS = $(SRCS:.c=.o)
CSRCS = $(addprefix $(SRCDIR), $(SRCS))
COBJS = $(addprefix $(OBJDIR), $(OBJS))
CEXEC = $(addprefix $(BINDIR), $(NAME))

all: $(NAME)

$(NAME): $(CSRCS) ./includes/ ./libft/srcs ./printf/srcs
	@ make -C ./libft/
	@ make -C ./printf/
	@ gcc $(FLAGS) -I./includes/ $(LIBS) -o $(NAME) $(CSRCS)

debug: $(CSRCS) ./includes/
	@ make debug -C ./libft/
	@ make debug -C ./printf/
	@ gcc $(FLAGS) -g -I./includes $(LIBS) -o $(NAME) $(CSRCS)

clean:
	@ make clean -C ./libft/
	@ make clean -C ./printf/
	@ rm -f $(COBJS)

fclean: clean
	@ make fclean -C ./libft/
	@ make fclean -C ./printf/
	@ rm -f $(NAME)

re: fclean all
