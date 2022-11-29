# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apommier <apommier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/12 19:45:18 by apommier          #+#    #+#              #
#    Updated: 2022/11/29 15:29:09 by apommier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= my_tester
NAME2	= std_tester
SRCS	= tests/map_tester.cpp\
		tests/vector_tester.cpp\
		tests/stack_tester.cpp\
		tests/main.cpp

SRCS2	= tests/map_tester.cpp\
		tests/vector_tester.cpp\
		tests/stack_tester.cpp\
		tests/main_real.cpp

OBJS	= ${SRCS:.cpp=.o}
OBJS2	= ${SRCS2:.cpp=.o}
CC		= c++
CFLAGS	= -g -Wall -Wextra -Werror -std=c++98
RM		= rm -rf

.cpp.o:
		$(CC) ${CFLAGS} -c $< -o $(<:.cpp=.o)

${NAME}: ${OBJS} ${OBJS2}
		${CC} ${LIB} ${OBJS} -o ${NAME} 
		${CC} ${LIB} ${OBJS2} -o ${NAME2} 

all:	${NAME}

clean:
		@${RM} ${OBJS}
		@${RM} ${OBJS2}

fclean:	clean
		@${RM} ${NAME}
		@${RM} ${NAME2}

re: 	fclean all

.PHONY: all clean fclean re