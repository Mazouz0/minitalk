# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/02 18:31:43 by mohmazou          #+#    #+#              #
#    Updated: 2024/06/07 10:42:35 by mohmazou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT_C = client.c utilis.c

SERVER_C = server.c utilis.c

CLIENT_O = $(CLIENT_C:.c=.o)
SERVER_O = $(SERVER_C:.c=.o)

NAME_CLIENT = client
NAME_SERVER = server

%.o : %.c minitalk.h
	cc -Wall -Wextra -Werror -c $< -o $@

all : $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT) : $(CLIENT_O)
	cc -Wall -Werror -Wextra $(CLIENT_O) -o client

$(NAME_SERVER) : $(SERVER_O)
	cc -Wall -Werror -Wextra $(SERVER_O) -o server

clean :
	rm -f $(SERVER_O) $(CLIENT_O)

fclean : clean
	rm -f $(NAME_CLIENT) $(NAME_SERVER)

re : fclean all

.PHONY : clean