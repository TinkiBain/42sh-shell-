# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/20 21:55:04 by ggwin-go          #+#    #+#              #
#    Updated: 2019/09/03 21:30:35 by ggwin-go         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a

CC=clang
FLAGS=-Wall -Wextra -Werror

RED=\033[0;31m
GREEN=\033[0;32m
BLUE=\033[1;34m
NC=\033[0m

include libft_dependences.mk

NAME_CLEAN=$(strip $(NAME))

LIBFT_OBJS_SUBDIRS=$(LIBFT_OBJS_DIR)\
	$(LIBFT_OBJS_DIR)/$(LIBFT_MEM_DIR)\
	$(LIBFT_OBJS_DIR)/$(LIBFT_STR_DIR)\
	$(LIBFT_OBJS_DIR)/$(LIBFT_OUTPUT_DIR)\
	$(LIBFT_OBJS_DIR)/$(FT_PRINTF_DIR)\
	$(LIBFT_OBJS_DIR)/$(FT_STRING_DIR)\
	$(LIBFT_OBJS_DIR)/$(FT_VECTOR_DIR)\
	$(LIBFT_OBJS_DIR)/$(LIBFT_LIST_DIR)\
	$(LIBFT_OBJS_DIR)/$(LIBFT_DLIST_DIR)

all: $(NAME)

$(NAME): $(LIBFT_OBJS_SUBDIRS) $(LIBFT_OBJS)
	@printf "$(BLUE)Compiling $(NAME) objects files...$(NC)\n"
	@ar rc $(NAME) $(LIBFT_OBJS)
	@ranlib $(NAME)
	@printf "$(GREEN)Bin $(NAME) is ready to use!$(NC)\n"

$(LIBFT_OBJS_SUBDIRS):
	@mkdir -p $@

$(LIBFT_OBJS_DIR)/%.o: $(LIBFT_SRCS_DIR)/%.c $(LIBFT_HEADERS)
	@$(CC) $(FLAGS) $(LIBFT_INCLUDES) -c $< -o $@

clean:
ifneq ($(LIBFT_OBJS_CLEAN),)
	@rm -rf $(LIBFT_OBJS_DIR)
	@printf "$(RED)$(NAME) objects files removed.$(NC)\n"
else
	@printf "$(RED)$(NAME) objects already cleaned$(NC)\n"
endif

fclean: clean
ifneq ($(NAME),)
	@rm -rf $(LIBFT_OBJS_DIR)
	@rm -rf $(NAME)
	@printf "$(RED)Bin $(NAME) removed.$(NC)\n"
else
	@printf "$(RED)Objects and bin $(NAME) already cleaned$(NC)\n"
endif

re: fclean all

.PHONY: all clean fclean re
