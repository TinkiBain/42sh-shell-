# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    builtins.mk                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/16 13:08:26 by gmelisan          #+#    #+#              #
#    Updated: 2019/10/15 17:17:05 by ggwin-go         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BUILTINS_CD_DIR=ft_cd
BUILTINS_FC_DIR=ft_fc
BUILTINS_TEST_DIR=ft_test

BUILTINS_INCLUDES=\
	builtins.h				ft_test.h				ft_fc.h

SRCS_BUILTINS_WITHOUT_DIR=\
	ft_alias.c				ft_bg.c\
	ft_echo.c				ft_exit.c\
	ft_export.c				ft_fg.c\
	ft_getopt_clear.c		ft_getopt_init.c\
	ft_hash.c				ft_history.c\
	ft_kill.c				ft_set.c\
	ft_source.c				ft_square_test.c\
	ft_type.c				ft_unalias.c\
	ft_unset.c

SRCS_BUILTIN_TEST=\
	ft_find_num.c			ft_isupper.c\
	ft_strtol.c				ft_test.c\
	ft_test_compare.c		ft_test_compare_int_eq_ne.c\
	ft_test_compare_str.c	ft_test_error.c\
	ft_test_exists.c		ft_test_exists_and_null.c\
	ft_test_find_flag.c		ft_test_int_compare_more_less.c\
	ft_test_type.c

SRCS_BUILTIN_FC=\
	ft_fc.c					ft_fc_build_vector.c\
	ft_fc_edit.c			ft_fc_edit_build_argv.c\
	ft_fc_edit_execute.c	ft_fc_edit_run_editor.c\
	ft_fc_find_arg.c		ft_fc_list.c\
	ft_fc_reexec.c

SRCS_BUILTIN_CD=\
	change_dir.c			ft_cd.c

BUILTINS_SUBDIRS=\
	$(BUILTINS_CD_DIR)\
	$(BUILTINS_FC_DIR)\
	$(BUILTINS_TEST_DIR)

SRCS_BUILTINS=\
	$(SRCS_BUILTINS_WITHOUT_DIR)\
	$(addprefix $(BUILTINS_CD_DIR)/, $(SRCS_BUILTIN_CD))\
	$(addprefix $(BUILTINS_FC_DIR)/, $(SRCS_BUILTIN_FC))\
	$(addprefix $(BUILTINS_TEST_DIR)/, $(SRCS_BUILTIN_TEST))
