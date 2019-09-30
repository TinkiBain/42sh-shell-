# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/10 17:38:22 by ggwin-go          #+#    #+#              #
#    Updated: 2019/09/30 22:30:55 by ggwin-go         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=42sh

CC=clang
FLAGS=-Wall -Wextra -Werror -MMD
FLAGS+=-g

INCLUDES:=\
	-I includes \
	-I includes/readline \
	-I includes/builtins \
	-I libft/includes

SH_INCLUDES=\
	ast.h		defs.h			variables.h		exec.h\
	hash.h		lexer.h			parser.h		sh.h\
	xfuncs.h	lib_wtalea.h	error.h			sem.h

# HEADER=\
# 	$(addprefix includes/, $(SH_INCLUDES))\
# 	$(addprefix includes/readline/, $(READLINE_INCLUDES))\
# 	$(addprefix includes/builtins/, $(BUILTINS_INCLUDES))\

SRCS_DIR=sources
OBJS_DIR=objects

LIBFT_DIR=libft

include $(LIBFT_DIR)/libft_dependences.mk

AST_DIR=ast
include $(SRCS_DIR)/$(AST_DIR)/ast.mk

HASH_DIR=hash_table
include $(SRCS_DIR)/$(HASH_DIR)/hash_table.mk

READLINE_DIR=readline
include $(SRCS_DIR)/$(READLINE_DIR)/readline.mk

BUILTINS_DIR=builtins
include $(SRCS_DIR)/$(BUILTINS_DIR)/builtins.mk

SRCS_WITHOUT_DIR=\
	main.c\
	shell_init.c\
	shell_clear.c\
	execute_line.c\
	signal_monitor.c\
	sem.c

JOBS_DIR=jobs

SRCS_JOBS=\
	jobs.c					jobs_helper.c\
	jobs_list_hendler.c		jobs_list_sub.c\
	jobs_sig_hendler.c		fgbg_helper.c\
	jobs_last_elem.c		jobs_list_counter.c\
	jobs_start_file.c		ft_waitpid.c

VAR_DIR=variables

SRCS_VAR=\
	add_new_var.c				create_copy_env.c\
	ft_getenv.c					remove_var.c\
	replace_var.c				check_readonly_var.c\
	set_var_shellopts.c			set_var.c\
	get_var_name.c				init_g_var.c\
	fill_g_var_names.c			print_var_names.c\
	get_var_value.c				print_vars.c\
	set_var_in_g_var.c			set_result.c

XFUNCS_DIR=xfuncs

SRCS_XFUNCS=\
	ft_xstrdup.c	 ft_xstrjoin.c		ft_xstrsplit.c		str_xfuncs1.c\
	str_xfuncs2.c	 vec_xfuncs.c		xmalloc.c			ft_xstrtrim.c

ERROR_DIR=error

SRCS_ERROR=\
	print_error.c	fatal.c		check_file_errors.c

SOURCES=$(SRCS_WITHOUT_DIR)\
	$(addprefix $(AST_DIR)/, $(SRCS_AST))\
	$(addprefix $(JOBS_DIR)/, $(SRCS_JOBS))\
	$(addprefix $(HASH_DIR)/, $(SRCS_HASH))\
	$(addprefix $(READLINE_DIR)/, $(SRCS_READLINE))\
	$(addprefix $(VAR_DIR)/, $(SRCS_VAR))\
	$(addprefix $(XFUNCS_DIR)/, $(SRCS_XFUNCS))\
	$(addprefix $(ERROR_DIR)/, $(SRCS_ERROR))\
	$(addprefix $(BUILTINS_DIR)/, $(SRCS_BUILTINS))\

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
CREATE_BUILTINS_SUBDIRS=$(addprefix $(OBJS_DIR)/$(BUILTINS_DIR)/, $(BUILTINS_SUBDIRS))

OBJS_SUBDIRS=$(OBJS_DIR)\
	$(OBJS_DIR)/$(AST_DIR)\
	$(CREATE_AST_SUBDIRS)\
	$(OBJS_DIR)/$(READLINE_DIR)\
	$(CREATE_READLINE_SUBDIRS)\
	$(OBJS_DIR)/$(HASH_DIR)\
	$(CREATE_HASH_SUBDIRS)\
	$(OBJS_DIR)/$(VAR_DIR)\
	$(OBJS_DIR)/$(JOBS_DIR)\
	$(OBJS_DIR)/$(XFUNCS_DIR)\
	$(OBJS_DIR)/$(ERROR_DIR)\
	$(OBJS_DIR)/$(BUILTINS_DIR)\
	$(CREATE_BUILTINS_SUBDIRS)\

.PHONY: all clean fclean re

LIBFT_OBJS_DEPENDS=$(addprefix $(LIBFT_DIR)/, $(LIBFT_OBJS))

all: $(NAME)

$(NAME): $(LIBFT_A) $(LIBFT_OBJS_DEPENDS) $(OBJS_SUBDIRS) $(OBJS)
	@printf "$(BLUE)Compiling $(NAME_CLEAN)...$(NC)\n"
	@$(CC) $(OBJS) $(LIBFT_A) $(INCLUDES) $(FLAGS) -o $(NAME) -lcurses
	@printf "$(GREEN)Bin $(NAME) is ready to use!$(NC)\n"

$(LIBFT_A):
	@make -C $(LIBFT_DIR)

$(LIBFT_DIR)/$(LIBFT_OBJS_DIR)/%.o: $(LIBFT_DIR)/$(LIBFT_SRCS_DIR)/%.c
	@make -C $(LIBFT_DIR)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c# $(HEADER)
	@$(CC) $(INCLUDES) $(FLAGS) -o $@ -c $<

$(OBJS_SUBDIRS):
	@mkdir -p $@

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
	@rm -rf ~/21sh
	@rm -rf ~/.21sh.history
	@rm -rf ~/.21sh.log
	@rm -rf ~/.42sh.history
	@rm -rf ~/.42sh.log
	@printf "$(RED)Bin $(NAME_CLEAN) removed.$(NC)\n"
else
	@printf "$(RED)Objects and bin $(NAME_CLEAN) already cleaned$(NC)\n"
endif

test: $(LIBFT_A)
	$(CC) $(FLAGS) -g $(SRCS) -o $(NAME) $(INCLUDES) $(LIBFT_A) -lcurses

sanitize:
	$(CC) $(FLAGS) -g -fsanitize=address $(SRCS) -o $(NAME) $(INCLUDES)	$(LIBFT_A) -lcurses

vg:
	valgrind --leak-check=full --sigill-diagnostics=yes ./$(NAME) $(ARG)

re: fclean all
