# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/20 21:55:04 by ggwin-go          #+#    #+#              #
#    Updated: 2019/09/02 16:50:16 by ggwin-go         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=$(LIBFT_NAME)

include libft_dependences.mk

$(LIBFT_OBJS_DIR):
	@printf "$(BLUE)Compiling $(NAME_CLEAN:.a=) objects files...$(NC)\n"
	@mkdir -p $(LIBFT_OBJS_DIR)/$(LIBFT_MEM_DIR)
	@mkdir -p $(LIBFT_OBJS_DIR)/$(LIBFT_STR_DIR)
	@mkdir -p $(LIBFT_OBJS_DIR)/$(LIBFT_OUTPUT_DIR)
	@mkdir -p $(LIBFT_OBJS_DIR)/$(FT_PRINTF_DIR)
	@mkdir -p $(LIBFT_OBJS_DIR)/$(FT_STRING_DIR)
	@mkdir -p $(LIBFT_OBJS_DIR)/$(FT_VECTOR_DIR)
	@mkdir -p $(LIBFT_OBJS_DIR)/$(LIBFT_LIST_DIR)
	@mkdir -p $(LIBFT_OBJS_DIR)/$(LIBFT_DLIST_DIR)

$(LIBFT_OBJS_DIR)/%.o: $(LIBFT_SRCS_DIR)/%.c $(LIBFT_HEADERS)
	@$(CC) $(FLAGS) $(LIBFT_INCLUDES) -c $< -o $@

$(NAME): $(LIBFT_OBJS_DIR) $(LIBFT_OBJS)
	@ar rc $(NAME) $(LIBFT_OBJS)
	@ranlib $(NAME)
	@printf "$(GREEN)Bin $(NAME_CLEAN) is ready to use!$(NC)\n"

all: $(NAME)

clean:
ifneq ($(OBJS_CLEAN),)
	@rm -rf $(LIBFT_OBJS_DIR)
	@printf "$(RED)$(NAME_CLEAN:.a=) objects files removed.$(NC)\n"
else
	@printf "$(RED)$(NAME_CLEAN:.a=) objects already cleaned$(NC)\n"
endif

fclean: clean
ifneq ($(NAME_CLEAN),)
	@rm -rf $(LIBFT_OBJS_DIR)
	@rm -rf $(NAME)
	@printf "$(RED)Bin $(NAME_CLEAN) removed.$(NC)\n"
else
	@printf "$(RED)Objects and bin $(NAME_CLEAN) already cleaned$(NC)\n"
endif

re: fclean all

.PHONY: all clean fclean re
