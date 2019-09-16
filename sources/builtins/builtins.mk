#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    builtins.mk                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/16 13:08:26 by gmelisan          #+#    #+#              #
#    Updated: 2019/09/16 15:39:04 by gmelisan         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

BUILTINS_TEST_DIR=ft_test
BUILTINS_FC_DIR=ft_fc

BUILTINS_INCLUDES=\
	builtins.h		ft_test.h	ft_fc.h

SRCS_BUILTINS_WITHOUT_DIR=\
	ft_getopt_init.c	ft_getopt_clear.c\
	cd.c				ft_echo.c	ft_exit.c	ft_hash.c		ft_set.c\
	ft_type.c			ft_unset.c	ft_env.c	ft_export.c		ft_kill.c\
	cd_change_dir.c		bg.c		fg.c		alias.c			unalias.c\

SRCS_BUILTIN_TEST=\
	ft_test.c\
	ft_find_num.c\
	ft_test_error.c\
	ft_test_exists.c\
	ft_test_exists_and_null.c\
	ft_test_find_flag.c\
	ft_test_type.c\
	ft_test_compare.c\
	ft_test_compare_int_eq_ne.c\
	ft_test_compare_str.c\
	ft_test_int_compare_more_less.c\
	ft_strtol.c\
	ft_isupper.c

SRCS_BUILTIN_FC=\
	ft_fc.c		ft_fc_list.c

BUILTINS_SUBDIRS=\
	$(BUILTINS_TEST_DIR)\
	$(BUILTINS_FC_DIR)\

SRCS_BUILTINS=\
	$(SRCS_BUILTINS_WITHOUT_DIR)\
	$(addprefix $(BUILTINS_TEST_DIR)/, $(SRCS_BUILTIN_TEST))\
	$(addprefix $(BUILTINS_FC_DIR)/, $(SRCS_BUILTIN_FC))
