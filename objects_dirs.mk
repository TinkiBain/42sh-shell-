# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    objects_dirs.mk                                    :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/06 16:18:15 by ggwin-go          #+#    #+#              #
#    Updated: 2019/08/06 16:32:57 by ggwin-go         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CREATE_AST_SUBDIRS=$(addprefix $(OBJS_DIR)/$(AST_DIR)/, $(AST_SUBDIRS))
CREATE_READLINE_SUBDIRS=$(addprefix $(OBJS_DIR)/$(READLINE_DIR)/, $(READLINE_SUBDIRS))
CREATE_HASH_SUBDIRS=$(addprefix $(OBJS_DIR)/$(HASH_DIR)/, $(HASH_SUBDIRS))


$(OBJS_DIR):
	@echo "$(BLUE)Compiling $(NAME_CLEAN) objects files...$(NC)"
	@mkdir -p $(OBJS_DIR)/$(AST_DIR)
	@mkdir -p $(CREATE_AST_SUBDIRS)
	@mkdir -p $(OBJS_DIR)/$(BUILTIN_DIR)
	@mkdir -p $(OBJS_DIR)/$(CMD_HANDLE_DIR)
	@mkdir -p $(OBJS_DIR)/$(READLINE_DIR)
	@mkdir -p $(CREATE_READLINE_SUBDIRS)
	@mkdir -p $(OBJS_DIR)/$(HASH_DIR)
	@mkdir -p $(CREATE_HASH_SUBDIRS)
	@mkdir -p $(OBJS_DIR)/$(DIR_LIB_WTALEA)
