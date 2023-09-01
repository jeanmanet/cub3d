# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmanet <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/06 10:58:23 by jmanet            #+#    #+#              #
#    Updated: 2022/05/30 08:54:26 by jmanet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c ft_printf_utils.c ft_printhex.c ft_printptr.c ft_printunsigned.c

LIBFT = libft/libft.a

INCLUDES = includes/

CC = gcc

FLAGS = -Wall -Werror -Wextra

.c.o:
	${CC} -I ${INCLUDES} ${FLAGS} -c $< -o ${<:.c=.o}

OBJS = ${SRCS:.c=.o}


${NAME} : ${OBJS} ${LIBFT} 
	cp ${LIBFT} .
	mv libft.a ${NAME}
	ar rc ${NAME} ${OBJS}
	ranlib ${NAME}

${LIBFT} : 
	make -C libft/

all : ${NAME}


clean : 
	rm -f ${OBJS} 
	make fclean -C libft/
fclean : clean
	rm -f ${NAME}
	rm -f ${LIBFT}

re : fclean all
