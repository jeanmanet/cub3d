# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmanet <jmanet@student.42nice.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/29 11:31:39 by jmanet            #+#    #+#              #
#    Updated: 2023/09/01 16:32:04 by jmanet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

SRCS = ${wildcard srcs/*.c getnextline/*.c}

LIBS = -lmlx ${LIBFTPRINTF}

LIBFTPRINTF = libftprintf/libftprintf.a

INCLUDES = includes/

CC = gcc

FLAGS = -Wall -Werror -Wextra -framework Appkit -framework OpenGL

OBJS = ${SRCS:.c=.o}

OBJS_BONUS = ${SRCS_BONUS:.c=.o}

all : ${NAME}

${NAME} : ${OBJS} ${LIBFTPRINTF}
	${CC} ${SRCS} -I ${INCLUDES} ${LIBS} ${FLAGS} -o ${NAME}

bonus : ${OBJS_BONUS} ${LIBFTPRINTF}
	${CC} ${SRCS_BONUS} -I ${INCLUDES} ${LIBS} ${FLAGS} -o ${NAME}

${LIBFTPRINTF} :
	make -C libftprintf/

clean :
	rm -f ${OBJS}
	rm -f ${OBJS_BONUS}
	make fclean -C libftprintf/
fclean : clean
	rm -f ${NAME}
	rm -f ${LIBFTPRINT}
re : clean fclean all
