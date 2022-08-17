# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: talsaiaa <talsaiaa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/16 03:08:10 by talsaiaa          #+#    #+#              #
#    Updated: 2022/08/18 01:27:05 by talsaiaa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ------------------------------ Sources ------------------------------

# Files
SERVER		=	ft_server/ft_server.c

CLIENT		=	ft_client/ft_client.c

FT_PRINTF	=	cd ft_printf && make

LIB			=	ft_printf/libftprintf.a

# Sources and objects
SERVER_SRC	=	$(SERVER)

SERVER_OBJS	=	$(SERVER_SRC:.c=.o)

CLIENT_SRC	=	$(CLIENT)

CLIENT_OBJS	=	$(CLIENT_SRC:.c=.o)

OBJS		=	$(CLIENT_OBJS) \
				$(SERVER_OBJS)

# ------------------------------ Constant strings ------------------------------

GCC			=	gcc

FLAGS		=	-Wall -Wextra -Werror

INCLUDE		=	-I include

SERVER_NAME	=	server

CLIENT_NAME	=	client

NAME		=	minitalk

# ------------------------------ Rules ------------------------------

all: $(NAME)

$(NAME): comp_start ft_server ft_client

comp_start:
	@ $(FT_PRINTF)
	@ echo "Utilities are ready to be used"

ft_server: $(SERVER_OBJS)
	@ $(GCC) $(FLAGS) $(SERVER_OBJS) $(LIB) -o $(SERVER_NAME)
	@ echo "Server is ready"

ft_client: $(CLIENT_OBJS)
	@ $(GCC) $(FLAGS) $(CLIENT_OBJS) $(LIB) -o $(CLIENT_NAME)
	@ echo "Client is ready"

clean:
	@ rm -rf $(OBJS)
	@ cd ft_printf && make clean
	@ echo "Object files are now removed"

fclean: clean
	@ rm -rf $(SERVER_NAME) $(CLIENT_NAME)
	@ cd ft_printf && make fclean
	@ echo "Object files and executables are now removed"

.c.o:
	@${GCC} ${FLAGS} $(INCLUDE) -c $< -o ${<:.c=.o}

re:	fclean all
