# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fnovais- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/17 12:53:40 by fnovais-          #+#    #+#              #
#    Updated: 2022/11/17 13:02:50 by fnovais-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
CC = cc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

SRC = get_next_line.c get_next_line_utils.c

OBJ = $(SRC:.c=.o)

all:
	$(CC) $(CFLAGS) $(SRC)	

clean:
		$(RM) $(OBJ)

re: clean all

