# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ymarcais <ymarcais@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/13 14:25:54 by ymarcais          #+#    #+#              #
#    Updated: 2023/04/28 16:04:19 by ymarcais         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# SETUP
NAME = pipex
CC = gcc -g
FLAGS = -Wall -Werror -Wextra -g3
RM = rm -rf

# FILES AND PATH
HEADER_SRCS = 	pipex.h
HEADER_DIR  =	includes/
HEADER		=	$(addprefix $(HEADER_DIR), $(HEADER_SRCS))

MPATH_SRCS	=  	utils.c \
				error.c \
				childs.c \
				../mini_libft.c \
				pipex.c
MPATH_DIR	=   mandatory/
MPATH       =   $(addprefix $(MPATH_DIR), $(MPATH_SRCS))
OBJ_M       =   $(MPATH:.c=.o)

BPATH_SRCS	=	../utils.c \
				../mini_libft.c \
				bonus.c
BPATH_DIR	=	bonus/
BPATH		=	$(addprefix $(BPATH_DIR), $(BPATH_SRCS))
OBJ_B		=	$(BPATH:.c=.o)

# COMMANDS
%.o:%.c $(HEADER) Makefile
							${CC} ${FLAGS} -c $< -o $@

$(NAME):		$(OBJ_M)
							$(CC) $(OBJ_M) -o$(NAME)
							@echo -e "$(GREEN)$(NAME) created!$(DEFAULT)"

all:			$(NAME)

clean:			
				$(RM) $(OBJ_M) $(OBJ_B)
				@echo -e "$(YELLOW)object files deleted!$(DEFAULT)"
                
fclean:			
				#$(RM) $(NAME)
				$(RM) $(OBJ_M) $(OBJ_B)
				@echo -e "$(RED)all deleted!$(DEFAULT)"
                           
re:				fclean all

bonus:			$(OBJ_B)
							$(CC) $(OBJ_B) -o$(NAME)
							@echo -e "$(GREEN)$(NAME) Pipex compiled with bonus!$(DEFAULT)"

.PHONY:			all clean fclean re bonus

#COLORS
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m             
