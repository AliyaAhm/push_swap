#NAME = push_swap

#NAME = checker

#SRCS = push_swap.c

#SRCS_B = checker.c

#HEADER = push_swap.h

#OBJ = ${SRCS:%.c=%.o}

#OBJ_B = ${SRCS:%.c=%.o}

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

NAME_BONUS	=	checker

LIBFT_NAME	= libft.a

SRCS		= main.c           parser.c         for_instruct.c\
			  ft_process.c     function.c   	  instruct_check_1.c\
			  instruct_check.c instruct_r.c     instruct_s_p.c\
			  push_swap.c      sort.c           swap.c\
			  function_2.c

SRCS_BONUS	= checker.c        parser.c         for_instruct.c\
			  ft_process.c     function.c   	instruct_check_1.c\
			  instruct_check.c instruct_r.c     instruct_s_p.c\
			  push_swap.c      sort.c           swap.c\
			  function_2.c

LIBFT   	= libft.h

LIBFT_DIR	= ./libft/

PUSH_SWAP   = push_swap.h

PUSH_SWAP_DIR = ./

OBJ			= ${SRCS:%.c=%.o}

OBJ_BONUS	= ${SRCS_BONUS:%.c=%.o}

CC			= clang -g

CFLAGS		= -Wall -Wextra -Werror

.PHONY		: all clean fclean re

all			: ${NAME}

bonus		:	$(NAME_BONUS)

${NAME}		: ${LIBFT_NAME} ${OBJ} ${PUSH_SWAP_DIR}${PUSH_SWAP}
			${CC} ${OBJ} ${LIBFT_DIR}${LIBFT_NAME} -o ${NAME}

$(NAME_BONUS)	:	${LIBFT_NAME} ${OBJ_BONUS} ${PUSH_SWAP_DIR}${PUSH_SWAP} ${LIBFT_DIR}${LIBFT_NAME}
					${CC} ${OBJ_BONUS} ${LIBFT_DIR}${LIBFT_NAME} -o ${NAME_BONUS}

${LIBFT_NAME}:
			make all -C ${LIBFT_DIR}

%.o   		: %.c ${PUSH_SWAP_DIR}${PUSH_SWAP}
			${CC} ${CFLAGS} -I${LIBFT_DIR} -I${PUSH_SWAP_DIR} -c $< -o $@

clean		:
				rm -rf ${OBJ}
				rm -rf ${OBJ_BONUS}
				make clean -C ${LIBFT_DIR}

fclean		:	clean				
				rm -f ${NAME}
				rm -f ${NAME_BONUS}
				make clean -C ${LIBFT_DIR}

re			:	fclean all