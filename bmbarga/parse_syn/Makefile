## ########################################################################## ##
##                                                                            ##
##                                                        :::      ::::::::   ##
##   Makefile                                           :+:      :+:    :+:   ##
##                                                    +:+ +:+         +:+     ##
##   By: elhmn <marvin@42.fr>                       +#+  +:+       +#+        ##
##                                                +#+#+#+#+#+   +#+           ##
##   Created: 2014/02/26 05:07:28 by elhmn             #+#    #+#             ##
##   Updated: 2014/02/26 05:07:28 by elhmn            ###   ########.fr       ##
##                                                                            ##
## ########################################################################## ##

NAME = ft_minishell1
CC = gcc
FLAGS = -Wall -Werror -Wextra
INCLUDES = -I ./includes/
LIBS = -L ./libft/ -lft
SRCS =  main.c
OBJS = $(SRCS:.c=.o)

all: $(OBJS)
	$(CC) $(FLAGS) $(INCLUDES) $(OBJS) $(LIBS) -o $(NAME) 

$(OBJS): $(SRCS)
	make -C ./libft/
	$(CC) $(FLAGS) $(INCLUDES) -c $(SRCS)

lib:
	make -C ./libft/

debug: $(OBJS)
	$(CC) $(FLAGS) -g $(INCLUDES) $(OBJS) $(LIBS) -o $(NAME) 

clean:
	make clean -C ./libft/
	rm -f $(OBJS)

fclean: clean
	make fclean -C ./libft/
	rm -f $(NAME)
re: fclean all
