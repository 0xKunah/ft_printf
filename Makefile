# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/16 13:34:19 by dbiguene          #+#    #+#              #
#    Updated: 2022/11/21 17:03:39 by dbiguene         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #


# ******** VARIABLES ******** #

# ---- Final Executable --- #

NAME			=	libftprintf.a

COMP_NAME		= 	output

# ---- Directories ---- #

DIR_OBJS		=	bin/

DIR_SRCS		=	src/

DIR_HEADERS		=	include/

# ---- Files ---- #

HEADERS_LIST	=	ft_printf.h		ft_utils.h		\
					ft_printers.h

SRCS_LIST		=	ft_printf.c		ft_utils.c		\
					ft_utils2.c						\
					ft_printers.c	ft_printers2.c	

HEADERS			=	${HEADERS_LIST:%.h=${DIR_HEADERS}%.h}

OBJS			=	${SRCS_LIST:%.c=${DIR_OBJS}%.o}

# ---- Compilation ---- #

CC				=	cc

CFLAGS			=	-Wall -Wextra -Werror

# ---- Commands ---- #

RM				=	rm -rf

MKDIR			=	mkdir -p

AR				=	ar rcs

# ********* RULES ******** #

all				:	${NAME}

# ---- Variables Rules ---- #

${NAME}			:	${OBJS} Makefile ${HEADERS}
					@echo "\n\033[0;32m ✔️ Binaries compiled from \033[1;36m${DIR_SRCS} \033[0;32mto \033[1;36m${DIR_OBJS} !"		
					${AR} ${NAME} ${OBJS}
					@echo "\n\033[0;32m ✔️ Lib successfully built !"

${COMP_NAME}	:	${OBJS} Makefile ${HEADERS}
					${CC} ${CFLAGS} -I ${DIR_HEADERS}. ${OBJS} ${OBJS_OUTPUT} -o ${COMP_NAME}

# ---- Compiled Rules ---- #

${OBJS}			:	| ${DIR_OBJS}

${DIR_OBJS}%.o	:	${DIR_SRCS}%.c ${HEADERS} Makefile
					${CC} ${CFLAGS} -I ${DIR_HEADERS}. -c $< -o $@

${DIR_OBJS}		:
					${MKDIR} ${DIR_OBJS}
					@echo "\n\033[0;32m ✔️ Successfully created binaries directory \033[1;36m${DIR_OBJS} !"

# ---- Usual Rules ---- #

clean			:
					${RM} ${OBJS}
					@echo "\n\033[0;31m ✔️ Successfully deleted binaries from directory \033[1;36m${DIR_OBJS} !"

fclean			:	clean
					${RM} ${NAME}
					@echo "\n\033[0;31m ✔️ Successfully deleted \033[1;36m${NAME} !"

re				:	fclean all
					@echo "\n\033[0;32m ✔️ Successfully re-compiled binaries and lib \033[0;36m${NAME} !"

test			:
					${CC} -I ${DIR_HEADERS}. src/test.c ${SRCS_LIST:%.c=${DIR_SRCS}%.c} -o ${COMP_NAME}
					@echo "\n\033[0;32m ✔️ Successfully built test program to \033[0;36m${COMP_NAME} !"
					@echo "\n\033[1;36mProgram output : \033[0;37m" && ./${COMP_NAME}
					
debug			:
					${CC} -I ${DIR_HEADERS}. src/test.c ${SRCS_LIST:%.c=${DIR_SRCS}%.c} -g -o ${COMP_NAME}
					@echo "\n\033[0;32m ✔️ Successfully built debug program to \033[0;36m${COMP_NAME} !"

check_leaks		:	test
					@echo "\n\n\033[0;32m✔️ Program leaks: \033[0;36m"
					leaks --atExit -- ./${COMP_NAME} > leaks.txt
					cat leaks.txt | grep "leaks for"
					rm -f leaks.txt
					
.PHONY:	all clean fclean re test
.SILENT:
