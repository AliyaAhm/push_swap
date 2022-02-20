#NAME = push_swap

#SRCS = push_swap.c

#HEADER = push_swap.h

#OBJ = ${SRCS:%.c=%.o}

#LIB = libft/libft.a

#CC = clang -g

#FLAFS = -Wall -Wextra -Werror

#RM = rm -rf

#.PHONY: all clean fclean re bonus libft

#all: libft ${NAME}

#libft: 
#	${MAKE} -C libft/

#${NAME}: 	${OBJ}
#			${CC} ${FLAGS} ${OBJ} ${LIB} -o ${NAME}

#%.o : %.c ${HEADER}
#		${CC} ${FLAGS} -c $< -o  $@

#clean:
#		${RM} ${OBJ}
#		${MAKE} -C - libft/ clean

#fclean: clean
#		${MAKE} -C libft/ fclean
#		${RM} ${NAME}
	
#re:		fclean all
NAME		= push_swap
LIBFT_NAME	= libft.a
SRCS		= push_swap.c
LIBFT   	= libft.h
LIBFT_DIR	= ./libft/
PUSH_SWAP   = push_swap.h
PUSH_SWAP_DIR = ./
OBJ			= ${SRCS:%.c=%.o}
CC			= clang -g
CFLAGS		= -Wall -Wextra -Werror
.PHONY		: all clean fclean re
all			: ${NAME}
${NAME}		: ${LIBFT_NAME} ${OBJ} ${PUSH_SWAP_DIR}${PUSH_SWAP}
			${CC} ${OBJ} ${LIBFT_DIR}${LIBFT_NAME} -o ${NAME}

${LIBFT_NAME}:
			make all -C ${LIBFT_DIR}

%.o   		: %.c ${PUSH_SWAP_DIR}${PUSH_SWAP}
			${CC} ${CFLAGS} -I${LIBFT_DIR} -I${PUSH_SWAP_DIR} -c $< -o $@

clean		:
				rm -rf ${OBJ}
				make clean -C ${LIBFT_DIR}

fclean		:	clean				
				rm -f ${NAME}
				make clean -C ${LIBFT_DIR}

re			:	fclean all