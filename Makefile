# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/10 17:38:22 by ggwin-go          #+#    #+#              #
#    Updated: 2019/10/15 17:13:25 by ggwin-go         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=42sh

CC=clang
FLAGS=-Wall -Wextra -Werror -MMD
FLAGS+=-g

INCLUDES:=\
	-I includes\
	-I includes/readline\
	-I includes/builtins\
	-I libft/includes

SH_INCLUDES=\
	arifmetic.h		ast.h			defs.h			dictionary.h\
	error.h			expansion.h		hash.h			jobs.h\
	lexer.h			parser.h		redirect.h		sem.h\
	sh.h			variables.h		xfuncs.h

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
	execute_line.c			main.c\
	sem.c					shell_clear.c\
	shell_init.c

JOBS_DIR=jobs

SIG_DIR=signals

SRCS_JOBS=\
	fgbg_helper.c			ft_waitpid.c\
	jobs.c					jobs_helper.c\
	jobs_last_elem.c		jobs_list_counter.c\
	jobs_list_handler.c		jobs_list_sub.c\
	jobs_start_file.c

SRCS_SIG=\
	sig_kind_of_sig.c		sig_main_handler.c\
	sig_monitor.c			sig_pjobs_sig.c\
	sig_stop_kind.c

DICTIONARY_DIR=dictionary

SRCS_DICTIONARY=\
	ft_dict_del.c			ft_dict_del_one.c\
	ft_dict_push_back.c		ft_dict_push_front.c\
	ft_dict_remove_elem.c	ft_get_dict.c\
	ft_get_dict_value.c		ft_init_dict.c

XFUNCS_DIR=xfuncs

SRCS_XFUNCS=\
	ft_xstrdup.c			ft_xstrjoin.c\
	ft_xstrndup.c			ft_xstrrejoin.c\
	ft_xstrsplit.c			ft_xstrtrim.c\
	str_xaddback.c			str_xaddfront.c\
	str_xcopy.c				str_xcreate.c\
	str_xduplicate.c		str_xinsert.c\
	str_xncopy.c			str_xsubstring.c\
	vec_xfuncs.c			xmalloc.c

VAR_DIR=variables

SRCS_VAR=\
	add_new_var.c			check_readonly_var.c\
	create_copy_env.c		fill_g_var_names.c\
	ft_getenv.c				get_str_function_var.c\
	get_var_name.c			get_var_value.c\
	init_g_func_defs.c		init_g_var.c\
	print_var_names.c		print_vars.c\
	remove_var.c			replace_var.c\
	set_var.c				set_var_in_g_var.c\
	set_var_shellopts.c

ERROR_DIR=error

SRCS_ERROR=\
	print_error.c	fatal.c		check_file_errors.c

SOURCES=$(SRCS_WITHOUT_DIR)\
	$(addprefix $(AST_DIR)/, $(SRCS_AST))\
	$(addprefix $(JOBS_DIR)/, $(SRCS_JOBS))\
	$(addprefix $(HASH_DIR)/, $(SRCS_HASH))\
	$(addprefix $(READLINE_DIR)/, $(SRCS_READLINE))\
	$(addprefix $(VAR_DIR)/, $(SRCS_VAR))\
	$(addprefix $(ERROR_DIR)/, $(SRCS_ERROR))\
	$(addprefix $(BUILTINS_DIR)/, $(SRCS_BUILTINS))\
	$(addprefix $(SIG_DIR)/, $(SRCS_SIG))\
	$(addprefix $(DICTIONARY_DIR)/, $(SRCS_DICTIONARY))\
	$(addprefix $(XFUNCS_DIR)/, $(SRCS_XFUNCS))

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
	$(OBJS_DIR)/$(SIG_DIR)\
	$(OBJS_DIR)/$(ERROR_DIR)\
	$(OBJS_DIR)/$(BUILTINS_DIR)\
	$(CREATE_BUILTINS_SUBDIRS)\
	$(OBJS_DIR)/$(DICTIONARY_DIR)\
	$(OBJS_DIR)/$(XFUNCS_DIR)

.PHONY: all clean fclean re vg

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

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
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

vg:
	valgrind --leak-check=full --sigill-diagnostics=yes ./$(NAME) $(ARG)

re: fclean all
