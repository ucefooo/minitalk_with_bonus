NAME = $(cl) $(sr)

client = client_bonus.c

server = server_bonus.c

cl = client

utils = utils_bonus.c

SRC = $(client) $(server) $(utils)

sr = server

hd = minitalk_bonus.h

flags = -Wall -Wextra -Werror

all : $(NAME) 

$(NAME) : $(SRC) $(hd)
	gcc $(flags) $(client) $(utils) -o $(cl)
	gcc $(flags) $(server) $(utils) -o $(sr)


clean :
	rm -rf $(cl) $(sr)

fclean: clean

re : fclean	all