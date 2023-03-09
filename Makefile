NAME = minitalk
CLIENT = client
SERVER = server

LIB_DIR = ./Libft
LIBTF = -L ${LIB_DIR} -lft

SRCS_CLIENT = client.c
SRCS_SERVER = server.c
OBJS_CLIENT = ${SRCS_CLIENT:.c=.o}
OBJS_SERVER = ${SRCS_SERVER:.c=.o}
CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

all: $(CLIENT) $(SERVER)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

#libft : 
#	make all -C ./Libft

$(CLIENT) : ${OBJS_CLIENT}
		@make all -sC ${LIB_DIR}
		$(CC) $(CFLAGS) ${OBJS_CLIENT} ${LIBTF} -o client

$(SERVER) : ${OBJS_SERVER}
		@make all -sC ${LIB_DIR}
		$(CC) $(CFLAGS) ${OBJS_SERVER} ${LIBTF} -o server

clean:
	${RM} ${OBJS_CLIENT}
	${RM} ${OBJS_SERVER}
	make clean -C ./Libft

fclean: clean
	${RM} client
	${RM} server
	make fclean -C ./Libft

re: fclean all
