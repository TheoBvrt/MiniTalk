NAME = minitalk
CLIENT = client
SERVER = server

OBJS_CLIENT = ${SRCS_CLIENT:.c=.o}
OBJS_SERVER = ${SRCS_SERVER:.c=.o}
CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

all: $(CLIENT) $(SERVER)

$(CLIENT) : client.c 
		${MAKE} bonus -C ./Libft 
		$(CC) client.c ./Libft/libft.a -o client
$(SERVER) : server.c
		${MAKE} bonus -C ./Libft 
		$(CC) server.c ./Libft/libft.a -o server


clean:
	${RM} ${OBJS_CLIENT}
	${RM} ${OBJS_SERVER}
	make fclean -C ./Libft

fclean: clean
	${RM} client
	${RM} server

re: fclean all
