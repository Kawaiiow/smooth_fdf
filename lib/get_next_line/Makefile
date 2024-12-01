CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBC = ar rcs
RM = rm -f

SRCS = get_next_line.c	get_next_line_utils.c
OBJS = ${SRCS:.c=.o}
NAME = ../get_next_line.a

all: ${NAME}

%.o: %.c Makefile get_next_line.h
	@${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJS}
	${LIBC} ${NAME} ${OBJS} 

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY : all bonus clean fclean re
