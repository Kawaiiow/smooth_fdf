CC = cc
CFLAG = -Wall -Werror -Wextra
LIBC = ar rcs
RM = rm -f

SRCS =	ft_printf.c	ft_itoa.c	ft_utoa.c \
		ft_itohex.c	ft_ptrtohex.c	formatter.c \
		util.c
NAME = ../libftprintf.a
OBJS = ${SRCS:.c=.o}

%.o: %.c ft_printf.h Makefile
	@${CC} ${CFLAG} -c $< -o $@

all: ${NAME}

${NAME}: ${OBJS}
	${LIBC} ${NAME} ${OBJS}
	
clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re

