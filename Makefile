# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcassu <tcassu@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/10 02:29:53 by tcassu            #+#    #+#              #
#    Updated: 2025/04/10 14:40:32 by tcassu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC			= push_swap.c sort.c sort_3.c sort_utils.c sort_utils_2.c utils.c commands/push.c commands/rotate.c commands/reverse_rotate.c commands/swap.c

SRCS 		= ${SRC}

OBJS		= ${SRCS:.c=.o}

INCLUDES	= ./includes

LIBFT		= libft

NAME		= push_swap

AR			= ar rc

RM			= rm -f

RANLIB		= ranlib

GCC			= gcc

CFLAGS		= -Wall -Werror -Wextra

all:		${NAME}

.c.o:
			${GCC} -c -I ${INCLUDES} $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			make -C $(LIBFT)
			cp libft/libft.a .
			mv libft.a $(NAME)
			${GCC} -o ${NAME} ${OBJS} -Llibft -lft


clean:
			rm -f ${OBJS}
			$(MAKE) -C libft clean

fclean:		clean
			rm -f ${NAME}
			$(MAKE) -C libft fclean

re:			fclean all
			
.PHONY:		all clean fclean re