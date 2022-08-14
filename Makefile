# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: talsaiaa <talsaiaa@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/16 03:08:10 by talsaiaa          #+#    #+#              #
#    Updated: 2022/08/14 16:10:03 by talsaiaa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Minitalk

SRCS = server.c client.c

OBJS = ${SRCS}

OBJSBONUS = ${BONUS}

CC		= gcc
RM		= rm -f

CFLAGS = -Wall -Wextra -Werror

$(NAME): ${OBJS}
		${CC} ${CFLAGS} server.c -o server
		${CC} ${CFLAGS} client.c -o client

all:	${NAME}

clean:
		${RM} server client

fclean:	clean
		${RM} ${NAME}

re:		fclean all
