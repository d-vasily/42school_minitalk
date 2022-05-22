SRCS_S		= server.c
SRCS_B_S	= server_bonus.c

SRCS_C		= client.c
SRCS_B_C	= client_bonus.c

OBJ_DIR		= obj/

OBJS_S		= $(addprefix ${OBJ_DIR}, ${SRCS_S:.c=.o})
OBJS_S_D	= $(addprefix ${OBJ_DIR}, ${SRCS_S:.c=.d})
OBJS_C		= $(addprefix ${OBJ_DIR}, ${SRCS_C:.c=.o})
OBJS_C_D	= $(addprefix ${OBJ_DIR}, ${SRCS_C:.c=.d})

OBJS_B_S	= $(addprefix ${OBJ_DIR}, ${SRCS_B_S:.c=.o})
OBJS_B_S_D	= $(addprefix ${OBJ_DIR}, ${SRCS_B_S:.c=.d})
OBJS_B_C	= $(addprefix ${OBJ_DIR}, ${SRCS_B_C:.c=.o})
OBJS_B_C_D	= $(addprefix ${OBJ_DIR}, ${SRCS_B_C:.c=.d})

NAME		= mandatory

BONUS		= bonus

UTILS		= ./libft/libft.a

SERVER		= server

CLIENT		= client

HEADER		= minitalk.h
HEADER_B	= minitalk_bonus.h

CC			= gcc

FLAGS		= -Wall -Werror -Wextra -O2 -MMD

${OBJ_DIR}%.o : %.c
			${CC} ${FLAGS} -c $< -o $@

all:		${OBJ_DIR} ${NAME}

${OBJ_DIR}:
			@mkdir -p ${OBJ_DIR}		

${UTILS}:	FORCE
			@${MAKE} -C ./libft
			
${NAME}:	${OBJ_DIR} ${SERVER} ${CLIENT}

${BONUS}:	
			@make OBJS_S='${OBJS_B_S}' OBJS_C='${OBJS_B_C}' HEADER='${HEADER_B}' all 

${SERVER}:	${UTILS} ${OBJS_S} ${HEADER}
			${CC} ${FLAGS} ${OBJS_S} -lft -L./libft -o ${SERVER}

${CLIENT}:	${UTILS} ${OBJS_C} ${HEADER}
			${CC} ${FLAGS} ${OBJS_C} -lft -L./libft -o ${CLIENT}

FORCE:	;

clean:
			rm -rf ${OBJ_DIR}
			@${MAKE} clean -C ./libft

fclean:		clean
			rm -rf ${SERVER} ${CLIENT}
			@${MAKE} fclean -C ./libft
			
re:			fclean all

.PHONY:		all clean fclean re

-include	${OBJS_C_D} ${OBJS_S_D} ${OBJS_B_S_D} ${OBJS_B_C_D}
