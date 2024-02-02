# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shoudek <shoudek@student.42prague.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/02 12:43:00 by shoudek           #+#    #+#              #
#    Updated: 2024/02/02 13:30:06 by shoudek          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BOLD =	\033[1m
BCYAN =	\033[96m
GREEN =	\033[32m
RED =	\033[31m

# name
NAME_CLIENT =	client
NAME_SERVER =	server

# compiler
CC =		cc
CFLAGS =	-Wall -Wextra -Werror

# libft
LIBFT_PATH =	libft/
LIBFT_NAME =	libft.a
LIBFT =		$(LIBFT_PATH)$(LIBFT_NAME)

# includes
INC =	-I ./libft

# sources
SRCCLIENT =	src/client.c
SRCSERVER =	src/server.c
SRC_PATH =	src/

OBJCLIENT =	obj/client.o
OBJSERVER =	obj/server.o

all: $(LIBFT) $(NAME_CLIENT) $(NAME_SERVER)

$(OBJ_PATH)%.o : $(SRC_PATH)%.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(LIBFT):
	@echo "$(BOLD)$(BCYAN)[ Making libft... ]"
	@make -sC $(LIBFT_PATH)

$(NAME_CLIENT): $(OBJCLIENT)
	@echo "$(BOLD)$(BCYAN)[ Compiling client... ]"
	@$(CC) $(CFLAGS) -o $(NAME_CLIENT) $(OBJCLIENT) $(LIBFT) $(INC)
	@echo "$(BOLD)$(GREEN)[ Client program ready! ]"

$(NAME_SERVER): $(OBJSERVER)
	@echo "$(BOLD)$(BCYAN)[ Compiling server... ]"
	@$(CC) $(CFLAGS) -o $(NAME_SERVER) $(OBJSERVER) $(LIBFT) $(INC)
	@echo "$(BOLD)$(GREEN)[ Server program ready! ]"

$(OBJCLIENT): $(SRCCLIENT)
	@echo "$(BOLD)$(BCYAN)[ Compiling client objects... ]"
	@$(CC) $(CFLAGS) -c $(SRCCLIENT) -o $(OBJCLIENT) $(INC)

$(OBJSERVER): $(SRCSERVER)
	@echo "$(BOLD)$(BCYAN)[ Compiling server objects... ]"
	@$(CC) $(CFLAGS) -c $(SRCSERVER) -o $(OBJSERVER) $(INC)

clean:
	@rm -f $(OBJCLIENT) $(OBJSERVER)
	@make clean -sC $(LIBFT_PATH)
	@echo "$(BOLD)$(RED)[ Object files deleted ]"

fclean: clean
	@rm -f $(NAME_CLIENT) $(NAME_SERVER)
	@rm -f $(LIBFT_PATH)$(LIBFT_NAME)
	@echo "$(BOLD)$(RED)[ Programs deleted ]"

re: fclean all

.PHONY: all re clean fclean
