NAME = $(cl) $(sr)

client = client.c

server = server.c

cl = client

utils = utils.c

SRC = $(client) $(server) $(utils)

sr = server

hd = minitalk.h

flags = -Wall -Wextra -Werror

all : $(NAME) 

$(NAME) : $(SRC) $(hd)
	gcc $(flags) $(client) $(utils) -o $(cl)
	gcc $(flags) $(server) $(utils) -o $(sr)


clean :
	rm -rf $(cl) $(sr)

fclean: clean

re : fclean	all