NAME = push_swap

SRCS =  $(wildcard helper/*c *.c)
OBJS = ${SRCS:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}
	@cc -Wall -Werror -Wextra ${OBJS} -o push_swap
.c.o:
	@cc -Wall -Werror -Wextra -c $< -o ${<:.c=.o}

clean:
	@rm -rf ${OBJS}

fclean: clean
	@rm -rf ${NAME}

re: fclean all
