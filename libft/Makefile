# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/20 21:55:04 by ggwin-go          #+#    #+#              #
#    Updated: 2019/05/29 15:22:50 by ggwin-go         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a

FLAGS=-Wall -Wextra -Werror
INCLUDES=-I includes
HEADER=includes/libft.h

SRCS_DIR=sources/
OBJS_DIR=objects/

LIST=list/
MEM=memory/
STR=string/
OUTPUT=output/
OTHER=other/
VECTOR=vector/

SRCS_LIST=ft_lstdel.c	ft_lstdelone.c	ft_lstiter.c	ft_lst_push_front.c\
		ft_lstnew.c		ft_lstsize.c	ft_lst_push_back.c

SRCS_MEM=ft_bzero.c		ft_memalloc.c	ft_memccpy.c		ft_memchr.c\
		ft_memcmp.c		ft_memcpy.c		ft_memcpy_rev.c		ft_memdel.c\
		ft_memmove.c	ft_memset.c		ft_realloc.c		ft_swap.c\
		ft_xmalloc.c

SRCS_STR=ft_atoi.c			ft_isalnum.c			ft_isalpha.c\
	ft_isascii.c			ft_isdigit.c			ft_isprint.c\
	ft_itoa.c				ft_itoa_base.c			ft_itoa_base_unsigned.c\
	ft_is_whitespaces.c		ft_skip_whitespaces.c\
	ft_sort_strarray.c		ft_strcat.c				ft_strchr.c\
	ft_strclr.c				ft_strcmp.c				ft_strcpy.c\
	ft_strdel.c				ft_strdup.c				ft_strdup_len.c\
	ft_strdup_len_len.c		ft_strequ.c				ft_striter.c\
	ft_striteri.c			ft_strjoin.c			ft_strjoin_free.c\
	ft_strlcat.c			ft_strlen.c				ft_strnlen.c\
	ft_strlen_or_chr.c		ft_strmap.c				ft_strmapi.c\
	ft_strncat.c			ft_strncmp.c			ft_strncpy.c\
	ft_strnequ.c			ft_strnew.c				ft_strnstr.c\
	ft_strrchr.c			ft_strrev.c				ft_strsplit.c\
	ft_strstr.c				ft_strsub.c				ft_strtrim.c\
	ft_str_to_lower.c		ft_str_to_upper.c		ft_tolower.c\
	ft_toupper.c			ft_free_char_arr.c		ft_count_chr.c

SRCS_OUTPUT=ft_putchar.c		ft_putchar_fd.c		ft_putendl.c\
			ft_putendl_fd.c		ft_putnbr.c			ft_putnbr_fd.c\
			ft_putnbr_lli.c		ft_putnbr_lli_fd.c	ft_putstr.c\
			ft_putstr_fd.c		ft_putstr_len.c

SRCS_OTHER=ft_range.c

SRCS_VECTOR=ft_vector_add.c		ft_vector_remove.c

SOURCES=$(addprefix $(LIST), $(SRCS_LIST))\
	$(addprefix $(MEM), $(SRCS_MEM))\
	$(addprefix $(STR), $(SRCS_STR))\
	$(addprefix $(OUTPUT), $(SRCS_OUTPUT))\
	$(addprefix $(OTHER), $(SRCS_OTHER))\
	$(addprefix $(VECTOR), $(SRCS_VECTOR))

SRCS=$(addprefix $(SRCS_DIR), $(SOURCES))
OBJS=$(addprefix $(OBJS_DIR), $(SOURCES:.c=.o))
RED=\033[0;31m
GREEN=\033[0;32m
BLUE=\033[0;34m
NC=\033[0m
OBJS_CLEAN=$(strip $(foreach f,$(OBJS),$(wildcard $(f))))
NAME_CLEAN=$(strip $(NAME))

all: $(NAME)

$(OBJS_DIR):
	@echo "$(BLUE)Compiling $(NAME_CLEAN:.a=) objects files...$(NC)"
	@mkdir -p $(OBJS_DIR)$(LIST)
	@mkdir -p $(OBJS_DIR)$(MEM)
	@mkdir -p $(OBJS_DIR)$(STR)
	@mkdir -p $(OBJS_DIR)$(OUTPUT)
	@mkdir -p $(OBJS_DIR)$(OTHER)
	@mkdir -p $(OBJS_DIR)$(VECTOR)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c $(HEADER)
	@gcc $(FLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS_DIR) $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "$(GREEN)Bin $(NAME_CLEAN) is ready to use!$(NC)"

clean:
ifneq ($(OBJS_CLEAN),)
	@rm -rf $(OBJS_DIR)
	@echo "$(RED)$(NAME_CLEAN:.a=) objects files removed.$(NC)"
else
	@echo "$(RED)$(NAME_CLEAN:.a=) objects already cleaned$(NC)"
endif

fclean: clean
ifneq ($(NAME_CLEAN),)
	@rm -rf $(OBJS_DIR)
	@rm -rf $(NAME)
	@echo "$(RED)Bin $(NAME_CLEAN) removed.$(NC)"
else
	@echo "$(RED)Objects and bin $(NAME_CLEAN) already cleaned$(NC)"
endif

re: fclean all

.PHONY: all clean fclean re
