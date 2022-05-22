# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eelroy <eelroy@student.21-school.>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/11 12:19:25 by eelroy            #+#    #+#              #
#    Updated: 2022/03/06 16:42:15 by eelroy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    =   libft.a

HEADER_LIB = libft.h

SRC     =   ft_atoi.c       ft_bzero.c      ft_calloc.c     ft_isalnum.c \
			ft_isalpha.c    ft_isascii.c    ft_isdigit.c    ft_isprint.c \
			ft_itoa.c       ft_memchr.c \
			ft_memcmp.c     ft_memcpy.c     ft_memmove.c    ft_memset.c \
			ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c  ft_putstr_fd.c \
			ft_split.c      ft_strchr.c     ft_strdup.c     ft_striteri.c \
			ft_strjoin.c    ft_strlcat.c    ft_strlcpy.c    ft_strlen.c \
			ft_strmapi.c    ft_strncmp.c    ft_strnstr.c    ft_strrchr.c \
			ft_strtrim.c    ft_substr.c     ft_tolower.c    ft_toupper.c

BNS_SRC =   ft_lstnew_bonus.c         ft_lstsize_bonus.c        ft_lstlast_bonus.c \
			ft_lstadd_front_bonus.c   ft_lstdelone_bonus.c      ft_lstclear_bonus.c \
			ft_lstiter_bonus.c        ft_lstadd_back_bonus.c    ft_lstmap_bonus.c

OBJ_DIR =   obj/

OBJ     =   $(addprefix $(OBJ_DIR), $(SRC:.c=.o))
DEP     =   $(addprefix $(OBJ_DIR), $(SRC:.c=.d))

BNS_OBJ =   $(addprefix $(OBJ_DIR), $(BNS_SRC:.c=.o))
BNS_DEP =   $(addprefix $(OBJ_DIR), $(BNS_SRC:.c=.d))

CFLAGS  =    -MMD -Wall -Werror -Wextra

CC      =   gcc

.PHONY  :   all clean fclean re bonus

all     :  $(OBJ_DIR) $(NAME) $(HEADER_LIB)

$(OBJ_DIR) :
	mkdir -p $(OBJ_DIR)

$(NAME) :   $(OBJ)
	ar rcs $(NAME) $?

$(OBJ_DIR)%.o     :   %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean   :
	rm -rf $(OBJ_DIR)

fclean  :   clean
	rm -f $(NAME)

re      :   fclean all

bonus   :
	@make  OBJ='$(OBJ) $(BNS_OBJ)' all

norm	:
	norminette -R CheckDefine *.h
	norminette -R CheckForbiddenSourceHeader *.c

-include $(DEP) $(BNS_DEP)
