NAME		= push_swap

NAME_BONUS	=	checker

LIBFT_NAME	= libft.a

SRCS		= main.c           parser.c         for_instruct.c\
			  ft_process.c     function.c   	  instruct_check_1.c\
			  instruct_check.c instruct_r.c     instruct_s_p.c\
			  push_swap.c      sort.c           swap.c\
			  function_2.c

SRCS_BONUS	= 

LIBFT   	= libft.h

LIBFT_DIR	= ./libft/

PUSH_SWAP   = push_swap.h

PUSH_SWAP_DIR = ./

OBJ			= ${SRCS:%.c=%.o}

#OBJ_BONUS	= ${SRCS_BONUS:%.c=%.o}

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