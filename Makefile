# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/10 17:38:22 by dmorgil           #+#    #+#              #
#    Updated: 2019/08/15 22:46:18 by ggwin-go         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=21sh

CC=clang
FLAGS=-Wall -Wextra -Werror
FLAGS+=-g

INCLUDES:=-I includes -I includes/readline -I libft/includes

SH_INCLUDES=\
	ast.h		cmd.h		defs.h			variables.h		exec.h\
	hash.h		lexer.h		lib_wtalea.h	parser.h		sh.h

HEADER=\
	$(addprefix includes/, $(SH_INCLUDES))\
	$(addprefix includes/readline/, $(READLINE_INCLUDES))

SRCS_DIR=sources
OBJS_DIR=objects

LIBFT_DIR=libft

AST_DIR=ast
include $(SRCS_DIR)/$(AST_DIR)/ast.mk

HASH_DIR=hash_table
include $(SRCS_DIR)/$(HASH_DIR)/hash_table.mk

READLINE_DIR=readline
include $(SRCS_DIR)/$(READLINE_DIR)/readline.mk

# lib_wtalea need to remove
DIR_LIB_WTALEA=lib_wtalea
SRCS_LIB_WTALEA=die_log.c

SRCS_WITHOUT_DIR=\
	main.c

BUILTIN_DIR=builtin

SRCS_BUILTIN=\
	ft_cd.c			ft_echo.c		ft_exit.c		ft_hash.c\
	ft_setenv.c		ft_type.c		ft_unsetenv.c

VAR_DIR=variables

SRCS_VAR=\
	add_var.c				create_copy_env.c\
	ft_getenv.c				remove_var.c\
	replace_var.c			check_is_var_readonly.c\
	print_var_readonly.c

SOURCES=$(SRCS_WITHOUT_DIR)\
	$(addprefix $(BUILTIN_DIR)/, $(SRCS_BUILTIN))\
	$(addprefix $(AST_DIR)/, $(SRCS_AST))\
	$(addprefix $(HASH_DIR)/, $(SRCS_HASH))\
	$(addprefix $(READLINE_DIR)/, $(SRCS_READLINE))\
	$(addprefix $(VAR_DIR)/, $(SRCS_VAR))\
	$(addprefix $(DIR_LIB_WTALEA)/, $(SRCS_LIB_WTALEA))

SRCS=$(addprefix $(SRCS_DIR)/, $(SOURCES))
OBJS=$(addprefix $(OBJS_DIR)/, $(SOURCES:.c=.o))

OBJS_CLEAN=$(strip $(foreach f,$(OBJS),$(wildcard $(f))))
NAME_CLEAN=$(strip $(NAME))

LIBFT_A=$(LIBFT_DIR)/libft.a

RED=\033[0;31m
GREEN=\033[0;32m
BLUE=\033[1;34m
NC=\033[0m

CREATE_AST_SUBDIRS=$(addprefix $(OBJS_DIR)/$(AST_DIR)/, $(AST_SUBDIRS))
CREATE_READLINE_SUBDIRS=\
	$(addprefix $(OBJS_DIR)/$(READLINE_DIR)/, $(READLINE_SUBDIRS))
CREATE_HASH_SUBDIRS=$(addprefix $(OBJS_DIR)/$(HASH_DIR)/, $(HASH_SUBDIRS))

OBJS_SUBDIRS=$(OBJS_DIR)\
	$(OBJS_DIR)/$(AST_DIR)\
	$(CREATE_AST_SUBDIRS)\
	$(OBJS_DIR)/$(BUILTIN_DIR)\
	$(OBJS_DIR)/$(CMD_HANDLE_DIR)\
	$(OBJS_DIR)/$(READLINE_DIR)\
	$(CREATE_READLINE_SUBDIRS)\
	$(OBJS_DIR)/$(HASH_DIR)\
	$(CREATE_HASH_SUBDIRS)\
	$(OBJS_DIR)/$(VAR_DIR)\
	$(OBJS_DIR)/$(DIR_LIB_WTALEA)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIBFT_A) $(OBJS_SUBDIRS) $(OBJS)
	@printf "$(BLUE)Compiling executable...$(NC)\n"
	@$(CC) $(OBJS) $(LIBFT_A) $(INCLUDES) $(FLAGS) -o $(NAME) -lcurses
	@printf "$(GREEN)Bin $(NAME) is ready to use!$(NC)\n"

$(LIBFT_A):
	@make -C $(LIBFT_DIR)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(HEADER)
	@$(CC) $(INCLUDES) $(FLAGS) -o $@ -c $<

$(OBJS_SUBDIRS):
	@printf "$(BLUE)Compiling $(NAME_CLEAN) objects files...$(NC)\n"
	@mkdir -p $(OBJS_DIR)/$(AST_DIR)
	@mkdir -p $(CREATE_AST_SUBDIRS)
	@mkdir -p $(OBJS_DIR)/$(BUILTIN_DIR)
	@mkdir -p $(OBJS_DIR)/$(CMD_HANDLE_DIR)
	@mkdir -p $(OBJS_DIR)/$(READLINE_DIR)
	@mkdir -p $(CREATE_READLINE_SUBDIRS)
	@mkdir -p $(OBJS_DIR)/$(HASH_DIR)
	@mkdir -p $(CREATE_HASH_SUBDIRS)
	@mkdir -p $(OBJS_DIR)/$(VAR_DIR)
	@mkdir -p $(OBJS_DIR)/$(DIR_LIB_WTALEA)

clean:
ifneq ($(OBJS_CLEAN),)
	@make clean -C $(LIBFT_DIR)
	@rm -rf $(OBJS_DIR)
	@printf "$(RED)$(NAME_CLEAN) objects files removed.$(NC)\n"
else
	@printf "$(RED)$(NAME_CLEAN) objects already cleaned$(NC)\n"
endif

fclean: clean
ifneq ($(NAME_CLEAN),)
	@make fclean -C $(LIBFT_DIR)
	@rm -rf $(OBJS_DIR)
	@rm -rf $(NAME)
	@printf "$(RED)Bin $(NAME_CLEAN) removed.$(NC)\n"
else
	@printf "$(RED)Objects and bin $(NAME_CLEAN) already cleaned$(NC)\n"
endif

test:
	$(CC) $(FLAGS) -g $(SRCS) -o $(NAME) $(INCLUDES) $(LIBFT_A) -lcurses

sanitize:
	$(CC) $(FLAGS) -g -fsanitize=address $(SRCS) -o $(NAME) $(INCLUDES)	$(LIBFT_A) -lcurses

re: fclean all
