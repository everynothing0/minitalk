# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cde-voog <cde-voog@student.42lehavre.fr>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/13 16:56:56 by cde-voog          #+#    #+#              #
#    Updated: 2023/07/13 17:26:03 by cde-voog         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = program

SERVER = server

CLIENT = client

UTILS = utils

CC = gcc

// LIB = ./minitalk.h

CFLAGS = -Wall -Werror -Wextra

all: $(SERVER) $(CLIENT)

$(NAME): all

$(SERVER):
	$(CC) $(CFLAGS) server.c $(LIB) -o $(SERVER)
$(CLIENT):
	$(CC) $(CFLAGS) client.c $(LIB) -o $(CLIENT)
$(UTILS):
	$(CC) $(CFLAGS) minitalk_utils.c $(LIB) -o $(CLIENT)

clean:
	rm -rf $(SERVER) $(CLIENT) $(UTILS)
fclean: clean
re: fclean all

.PHONY: all fclean clean re
