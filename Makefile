# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adchebbi <adchebbi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/25 12:26:18 by adchebbi          #+#    #+#              #
#    Updated: 2026/03/26 11:25:43 by adchebbi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# **************** PROGRAM **************** #
#											#
NAME        = pipex
#											#
# ***************************************** #


# **************** COMPILER *************** #
#											#
CC          = cc							#
CFLAGS      = -Wall -Wextra -Werror			#
RM          = rm -f							#
#											#
# ***************************************** #


# ************* DIRECTORIES *************** #
#											#
SRCS_DIR    = srcs
LIBFT_DIR   = libft
#											#
# ***************************************** #


# **************** FILES ****************** #
#											#
SRCS        = $(SRCS_DIR)/main.c \
              $(SRCS_DIR)/path.c \
              $(SRCS_DIR)/pipex.c \
              $(SRCS_DIR)/utils.c
#											#
OBJS        = $(SRCS:.c=.o)					#
#											#
LIBFT       = $(LIBFT_DIR)/libft.a			#
#											#
# ***************************************** #


# **************** COLORS ***************** #
#											#
GREEN       = \033[0;32m
YELLOW      = \033[0;33m
RED         = \033[0;31m
BLUE        = \033[0;34m
RESET       = \033[0m
#											#
# ***************************************** #


# ************* FILES CREATED ************* #
#											#
FILES = infile \
		infile_*\
		outfile \
		outfile_*\
#											#
# ***************************************** #


# **************** RULES ****************** #
#											#
all: $(LIBFT) $(NAME)
#											#
$(LIBFT):
	@printf "$(YELLOW)📚 Compiling libft...$(RESET)\n"
	@make -C $(LIBFT_DIR) --silent
	@printf "$(GREEN)✅ Libft ready$(RESET)\n"
#											#
$(NAME): $(OBJS) $(LIBFT)
	@printf "$(BLUE)🔧 Linking $(NAME)...$(RESET)\n"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@printf "$(GREEN)✅ $(NAME) compiled successfully$(RESET)\n"
#											#
%.o: %.c
	@printf "$(YELLOW)🔨 Compiling $<$(RESET)\n"
	@$(CC) $(CFLAGS) -I includes -c $< -o $@
#											#
clean:
	@printf "$(RED)🧹 Cleaning object files$(RESET)\n"
	@make clean -C $(LIBFT_DIR) --silent
	@$(RM) $(OBJS)
#											#
fclean: clean
	@printf "$(RED)🧼 Full clean$(RESET)\n"
	@make fclean -C $(LIBFT_DIR) --silent
	@$(RM) $(NAME) $(FILES)
	@sleep 1
	@clear
#											#
re: fclean all
#											#
.PHONY: all clean fclean re
#											#
# ***************************************** #
