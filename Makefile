NAME = minitalk
SRCS_CLIENT = client.c
SRCS_SERVER = server.c

OBJS_CLIENT = ${SRCS_CLIENT:.c=.o}
OBJS_SERVER = ${SRCS_SERVER:.c=.o}
CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

all : ${OBJS_CLIENT} ${OBJS_SERVER} ${NAME}

%.o : %.c
	$(CC) -c $< -o $@

${NAME} :
	${MAKE} bonus -C ./Libft 
	$(CC) $(OBJS_CLIENT) $(CFLAGS) ./Libft/libft.a -o client
	$(CC) $(OBJS_SERVER) $(CFLAGS) ./Libft/libft.a -o server

clean:
	${RM} ${OBJS_CLIENT}
	${RM} ${OBJS_SERVER}
	make fclean -C ./Libft

fclean: clean
	${RM} client
	${RM} server

re: fclean all
