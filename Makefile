CC				= cc
CFLAGS			= -Wall -Werror -Wextra -Ofast
NAME			= fdf

INCLD			= -I ./include -I ${MLX42_PATH}/include
MLX42_PATH		= ./lib/MLX42
LIBS			= ${MLX42_PATH}/build/libmlx42.a -ldl -lglfw -pthread -lm

LIBFT_PATH		= ./lib/Libft_pratical_use
FT_PRINTF_PATH	= ./lib/ft_printf
GNL_PATH		= ./lib/get_next_line

LIBFT_A			= ./lib/libft.a
FT_PRINTF_A		= ./lib/libftprintf.a
GNL_A			= ./lib/get_next_line.a

DOT_A			= libft.a	libftprintf.a	get_next_line.a
ALL_A			= ${addprefix lib/, ${DOT_A}}

C_FILES		= fdf.c drawing.c color.c color2.c gradient.c map_projection.c matrix_ops.c \
					offset.c parser.c hook.c parser_queue.c parser_vector.c render.c

SRCS			= ${addprefix src/, ${C_FILES}}
OBJS			= ${SRCS:.c=.o}

all: libmlx ${NAME}

%.o: %.c
	@${CC} ${CFLAGS} -c $< -o $@ ${INCLD}

ifeq ($((BONUS_STAT)), 1)
${NAME}: ${OBJS} include/fdf.h Makefile
	@${MAKE} libft
	$(CC) $(CFLAGS) ${OBJS} -L. ${LIBS} ${ALL_A} ${INCLD} -o ${NAME}
else
${NAME}: ${OBJS} include/fdf.h Makefile
	# @rm -f ${OBJS}
	@BONUS_STAT=0
	@${MAKE} libft
	$(CC) $(CFLAGS) ${OBJS} -L. ${LIBS} ${ALL_A}  ${INCLD} -o ${NAME}
endif

libmlx:
	@cmake ${MLX42_PATH} -B ${MLX42_PATH}/build && make -C ${MLX42_PATH}/build -j4

libft:
	@make -C ${LIBFT_PATH}
	@make -C ${GNL_PATH}
	@make -C ${FT_PRINTF_PATH}

bonus:
	@BONUS_STAT=1 make --no-print-directory

clean:
	@make clean -C ${LIBFT_PATH}
	@make clean -C ${GNL_PATH}
	@make clean -C ${FT_PRINTF_PATH}
	@rm -f ${T_OBJS}
	rm -f ${OBJS}
	rm -rf ${MLX42_PATH}/build

fclean: clean
	@make fclean -C ${LIBFT_PATH}
	@make fclean -C ${GNL_PATH}
	@make fclean -C ${FT_PRINTF_PATH}
	@rm -f ${TEST_NAME}
	rm -rf ${NAME}

re: fclean all

.PHONY: all clean fclean re libmlx libft
