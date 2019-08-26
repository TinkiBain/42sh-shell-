# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    hash_table.mk                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/05 16:41:59 by ggwin-go          #+#    #+#              #
#    Updated: 2019/08/26 17:54:24 by wtalea           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HASH_HASH_DIR=hash

SRCS_HASH_HASH=\
	../ft_abs.c\
	../ft_itoa_nm.c\
	../ft_intlen.c\
	create_bin.c\
	create_hash.c\
	del_hash.c\
	fill_hash_table.c\
	get_bin.c\
	null_hash.c\
	paste_path.c\
	add_force.c\
	create_arr_names.c\
	count_hash_on.c\
	hash_print.c\
	hash_print_use.c\
	print_lib.c\
	print_usage.c\
	start_built_hash.c\
	find_and_del.c\
	hash_flag_r.c

HASH_SUBDIRS=\
	$(HASH_HASH_DIR)\

SRCS_HASH=\
	$(addprefix $(HASH_HASH_DIR)/, $(SRCS_HASH_HASH))\
