# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/27 17:52:53 by nsoares-          #+#    #+#              #
#    Updated: 2023/05/10 21:00:38 by nsoares-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = cc
CFLAGS = -Wall -Werror -Wextra -g0
LIBFT = ./libft/libft.a
RM = rm -rf
CPPFLAGS=-I/usr/local/opt/readline/include
LDFLAGS=-L/usr/local/opt/readline/lib

SRC = main.c \
			src/prompt.c \
			src/init.c \
			src/signal.c \
			src/utils.c \
			src/builtins/echo.c \
			src/builtins/builtins.c \
			src/builtins/clear.c \
			src/builtins/pwd.c \
			src/builtins/cd.c \
			src/builtins/exit.c \

			
OBJS_FILES = $(SRC:.c=.o)

# __________COLORS____________

BOLD_PURPLE	=	\033[1;35m
BOLD_CYAN	=	\033[1;36m
BOLD_YELLOW	=	\033[1;33m
NO_COLOR	=	\033[0m

# _________MESSAGE_____________

COMPILATION_START	=	echo "\n$(BOLD_YELLOW)Make: $(NO_COLOR)Compilation start...\n"

MINISHELL_READY  =   echo "\n$(BOLD_YELLOW)minishell ready! ✅ \n"

CLEANED		=	echo "\n$(BOLD_YELLOW)Clean: $(NO_COLOR)Removed all the \".o\" files \n"

FCLEANED	=	echo "\n$(BOLD_YELLOW)Fclean: $(NO_COLOR)Removed the executables \n"

RE          =   echo "\n$(BOLD_YELLOW)Re: $(NO_COLOR)Compilation restarted \n"

all: compilation_start $(NAME)

$(NAME): $(OBJS_FILES)
	@ $(MAKE) --no-print-directory -C ./libft
	$(CC) $(SRC) $(LIBFT) $(CFLAGS) $(LDFLAGS) $(CPPFLAGS) -o $(NAME) -lreadline
	@ $(MINISHELL_READY)

compilation_start:
	@ $(COMPILATION_START)

clean:
	@ $(RM) $(OBJS_FILES)
	@ cd libft && make clean
	@ $(CLEANED)
	
fclean: clean
	@ $(RM) $(NAME)
	@ cd libft && make fclean
	@ $(FCLEANED)
		
re:	fclean all
	@ $(RE)