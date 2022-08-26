# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpaterno <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/26 18:20:36 by jpaterno          #+#    #+#              #
#    Updated: 2022/07/26 18:20:38 by jpaterno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

N_CLIENT = client
N_SERVER = server
N_LIBA = libft.a

SRC_CL = client_d/main.c \

SRC_SR = server_d/main.c \
			server_d/free.c \

OBJLIB = $(LIBFT:.c=.o)
OBJ_CL = $(SRC_CL:*.c=./.o)
OBJ_SR = $(SRC_SR:*.c=./.o)

all: $(N_CLIENT) $(N_SERVER)

$(N_CLIENT): $(OBJ_CL)
	make -C libft
	gcc -Wall -Werror -Wextra -c $(SRC_CL)
	gcc -Wall -Werror -Wextra -g $(OBJ_CL) libft/libft.a -o $(N_CLIENT)

$(N_SERVER): $(OBJ_SR)
	gcc -Wall -Werror -Wextra -c $(SRC_SR)
	gcc -Wall -Werror -Wextra -g $(OBJ_SR) libft/libft.a -o $(N_SERVER)

clean:
	rm -f *.o
	rm -f server_d/*.o
	rm -f client_d/*.o

fclean: clean
	rm -f ./$(N_CLIENT)
	rm -f ./$(N_SERVER)
	rm -rf *.dSYM
	make fclean -C libft

save1:
	rm -rf /Users/jpaterno/Documents/SAVE1/*
	cp -rf * /Users/jpaterno/Documents/SAVE1/
save2:
	rm -rf /Users/jpaterno/Documents/SAVE2/*
	cp -rf * /Users/jpaterno/Documents/SAVE2/

fspace:
	rm -rf ~/Library/**.42_cache_bak*; rm -rf ~/**.42_cache_bak; brew cleanup
	wipe


re: fclean all

