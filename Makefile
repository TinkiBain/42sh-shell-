# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/10 17:38:22 by dmorgil           #+#    #+#              #
#    Updated: 2019/08/06 17:59:00 by ggwin-go         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=21sh

CC=clang
FLAGS=-Wall -Wextra -Werror
FLAGS+=-g

HEADER=includes/sh.h

INCLUDES:=-I includes -I includes/readline -I libft/includes

SRCS_DIR=sources
OBJS_DIR=objects

LIBFT_DIR=libft

AST_DIR=ast
include $(SRCS_DIR)/$(AST_DIR)/ast.mk

BUILTIN_DIR=builtin

HASH_DIR=hash_table
include $(SRCS_DIR)/$(HASH_DIR)/hash_table.mk

READLINE_DIR=readline
include $(SRCS_DIR)/$(READLINE_DIR)/readline.mk

# lib_wtalea need to remove
DIR_LIB_WTALEA=lib_wtalea
SRCS_LIB_WTALEA=die_log.c

SRCS_WITHOUT_DIR=\
	main.c

SRCS_BUILTIN=\
	ft_cd.c			ft_echo.c		ft_env.c		ft_hash.c\
	ft_setenv.c		ft_type.c		ft_unsetenv.c	ft_exit.c

SOURCES=$(SRCS_WITHOUT_DIR)\
	$(addprefix $(BUILTIN_DIR)/, $(SRCS_BUILTIN))\
	$(addprefix $(AST_DIR)/, $(SRCS_AST))\
	$(addprefix $(HASH_DIR)/, $(SRCS_HASH))\
	$(addprefix $(READLINE_DIR)/, $(SRCS_READLINE))\
	$(addprefix $(DIR_LIB_WTALEA)/, $(SRCS_LIB_WTALEA))

SRCS=$(addprefix $(SRCS_DIR)/, $(SOURCES))
OBJS=$(addprefix $(OBJS_DIR)/, $(SOURCES:.c=.o))

OBJS_CLEAN=$(strip $(foreach f,$(OBJS),$(wildcard $(f))))
NAME_CLEAN=$(strip $(NAME))

LIBFT_A=$(LIBFT_DIR)/libft.a

RED=\033[0;31m
GREEN=\033[0;32m
BLUE=\033[0;34m
NC=\033[0m

.PHONY: all clean fclean re

all: $(NAME)

include objects_dirs.mk

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(HEADER)
	@$(CC) $(INCLUDES) $(FLAGS) -o $@ -c $<

$(LIBFT_A):
	@make -C $(LIBFT_DIR)

$(NAME): $(LIBFT_A) $(OBJS_DIR) $(OBJS)
	@echo "$(BLUE)Compiling executable...$(NC)"
	@$(CC) $(OBJS) $(LIBFT_A) $(INCLUDES) $(FLAGS) -o $(NAME) -lcurses
	@echo "$(GREEN)Bin $(NAME) is ready to use!$(NC)"

clean:
ifneq ($(OBJS_CLEAN),)
	@make clean -C $(LIBFT_DIR)
	@rm -rf $(OBJS_DIR)
	@echo "$(RED)$(NAME_CLEAN) objects files removed.$(NC)"
else
	@echo "$(RED)$(NAME_CLEAN) objects already cleaned$(NC)"
endif

fclean: clean
ifneq ($(NAME_CLEAN),)
	@make fclean -C $(LIBFT_DIR)
	@rm -rf $(OBJS_DIR)
	@rm -rf $(NAME)
	@echo "$(RED)Bin $(NAME_CLEAN) removed.$(NC)"
else
	@echo "$(RED)Objects and bin $(NAME_CLEAN) already cleaned$(NC)"
endif

test:
	$(CC) $(FLAGS) -g $(SRCS) -o $(NAME) $(INCLUDES) $(LIBFT_A) -lcurses

sanitize:
	$(CC) $(FLAGS) -g -fsanitize=address $(SRCS) -o $(NAME) $(INCLUDES) $(LIBFT_A) -lcurses

re: fclean all
