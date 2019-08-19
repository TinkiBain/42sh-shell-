# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    hash_table.mk                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/05 16:41:59 by ggwin-go          #+#    #+#              #
#    Updated: 2019/08/19 15:52:45 by wtalea           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HASH_HASH_DIR=hash
HASH_FOREST_DIR=forest

SRCS_HASH_HASH=\
	create_bin.c\
	create_hash.c\
	del_hash.c\
	fill_hash_table.c\
	get_bin.c\
	null_hash.c\
	paste_path.c\
	add_force.c\
	create_arr_names.c

SRCS_HASH_FOREST=\
	get_vec_prog.c

HASH_SUBDIRS=\
	$(HASH_HASH_DIR)\
	$(HASH_FOREST_DIR)

SRCS_HASH=\
	$(addprefix $(HASH_HASH_DIR)/, $(SRCS_HASH_HASH))\
	$(addprefix $(HASH_FOREST_DIR)/, $(SRCS_HASH_FOREST))
