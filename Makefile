NAME = fdf
OBJ_DIR	=	obj
SRC_DIR	=	src

SOURCES = 	main \
			get_next_line \
			get_next_line_utils\
			draw\
			parcer\
			utils
			
OBJ = ${addprefix $(SRC_DIR)/,$(SOURCES:=.o)}

CC = gcc
CFLAGS = -Wall -Wextra #-Werror#'-Dmalloc(__size)=memset(malloc(__size), 0, __size)'
OBJFLAGS = -I/usr/include -Imlx_linux -O3
LASTFLAGS = -Lmlx_linux minilibx-linux/libmlx_Linux.a -L/usr/lib -Imlx_linux ft_printf/libftprintf.a -lXext -lX11 -lm -lz

%.o: %.c
	${CC} ${OBJFLAGS} -c $< -o $@

$(NAME): ${OBJ}
	${CC} ${OBJ} ${LASTFLAGS} -o ${NAME}

all: 	$(NAME)

clean:
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all bonus clean fclean re