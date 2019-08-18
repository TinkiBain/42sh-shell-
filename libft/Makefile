# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/20 21:55:04 by ggwin-go          #+#    #+#              #
#    Updated: 2019/08/18 17:19:06 by ggwin-go         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a

CC=clang
FLAGS=-Wall -Wextra -Werror
INCLUDES=-I includes

H_FILES=\
	ft_printf.h\
	ft_string.h\
	ft_vector.h\
	get_next_line.h\
	ft_qsort.h\
	libft.h

HEADER=$(addprefix includes/, $(H_FILES))

SRCS_DIR=sources/
OBJS_DIR=objects/

MEM_DIR=memory/
STR_DIR=string/
OUTPUT_DIR=output/
FT_PRINTF_DIR=ft_printf/
FT_STRING_DIR=ft_string/
FT_VECTOR_DIR=ft_vector/
LIST_DIR=list/
DLIST_DIR=dlist/

SRCS_WITHOUT_DIR=get_next_line.c ft_qsort.c

SRCS_MEM=ft_bzero.c			ft_memalloc.c				ft_memccpy.c\
		ft_memchr.c			ft_memcmp.c					ft_memcpy.c\
		ft_memcpy_rev.c		ft_memdel.c					ft_memmove.c\
		ft_memset.c			ft_realloc.c				ft_swap.c\
		ft_xmalloc.c		ft_free_double_ptr_arr.c

SRCS_STR=ft_atoi.c			ft_isalnum.c			ft_isalpha.c\
	ft_isascii.c			ft_isdigit.c			ft_isprint.c\
	ft_isspace.c			ft_itoa.c				ft_itoa_base.c\
	ft_sort_str_array.c		ft_strcat.c				ft_strchr.c\
	ft_strclr.c				ft_strcmp.c				ft_strcpy.c\
	ft_strdel.c				ft_strdup.c				ft_strndup.c\
	ft_strequ.c				ft_striter.c\
	ft_striteri.c			ft_strjoin.c			ft_strrejoin.c\
	ft_strlcat.c			ft_strlen.c\
	ft_strmap.c				ft_strmapi.c\
	ft_strncat.c			ft_strncmp.c			ft_strncpy.c\
	ft_strnequ.c			ft_strnew.c				ft_strnstr.c\
	ft_strrchr.c			ft_strsplit.c\
	ft_strstr.c				ft_strsub.c				ft_strtrim.c\
	ft_tolower.c			ft_toupper.c\
	ft_strrejoin.c

SRCS_OUTPUT=ft_putchar.c		ft_putchar_fd.c		ft_putendl.c\
			ft_putendl_fd.c		ft_putnbr.c			ft_putnbr_fd.c\
			ft_putstr.c			ft_putstr_fd.c		ft_putstr_len.c

SRCS_FT_PRINTF=convert_float.c	convert_integer.c		ft_fdprintf.c\
	ft_printf.c					ft_vfdprintf.c			ft_vprintf.c\
	get_color.c					get_conversion.c		get_flags.c\
	get_length.c				get_precision.c			get_width.c\
	handle_char.c				handle_color.c			handle_conversion.c\
	handle_float.c				handle_integer.c		handle_string.c\
	handle_unknown.c			handle_wchar.c			handle_wstring.c\
	number_to_string.c			number_to_string_e.c	number_to_string_f.c

SRCS_FT_STRING=str_addback.c	str_addfront.c			str_compare.c\
	str_copy.c					str_create.c			str_delarr.c\
	str_delete.c				str_duplicate.c			str_fixlen.c\
	str_get.c					str_insert.c			str_remove.c\
	str_split.c					str_substring.c			str_zero.c\
	str_ncopy.c

SRCS_FT_VECTOR=vec_addback.c	vec_addfront.c			vec_create.c\
	vec_delete.c				vec_duplicate.c			vec_get.c\
	vec_zero.c

SRCS_LIST=ft_lstadd.c			ft_lstaddback.c			ft_lstdel.c\
	ft_lstdelone.c				ft_lstiter.c			ft_lstmap.c\
	ft_lstnew.c					ft_lstsize.c

SRCS_DLIST=ft_dlstadd.c			ft_dlstaddback.c		ft_dlstdel.c\
	ft_dlstdelend.c				ft_dlstdelfront.c		ft_dlstdelone.c\
	ft_dlstiter.c				ft_dlstnew.c			ft_dlstsize.c

SOURCES=$(SRCS_WITHOUT_DIR)\
	$(addprefix $(MEM_DIR), $(SRCS_MEM))\
	$(addprefix $(STR_DIR), $(SRCS_STR))\
	$(addprefix $(OUTPUT_DIR), $(SRCS_OUTPUT))\
	$(addprefix $(FT_PRINTF_DIR), $(SRCS_FT_PRINTF))\
	$(addprefix $(FT_STRING_DIR), $(SRCS_FT_STRING))\
	$(addprefix $(FT_VECTOR_DIR), $(SRCS_FT_VECTOR))\
	$(addprefix $(LIST_DIR), $(SRCS_LIST))\
	$(addprefix $(DLIST_DIR), $(SRCS_DLIST))

RED=\033[0;31m
GREEN=\033[0;32m
BLUE=\033[1;34m
NC=\033[0m

SRCS=$(addprefix $(SRCS_DIR), $(SOURCES))
OBJS=$(addprefix $(OBJS_DIR), $(SOURCES:%.c=%.o))

OBJS_CLEAN=$(strip $(foreach f,$(OBJS),$(wildcard $(f))))
NAME_CLEAN=$(strip $(NAME))

all: $(NAME)

$(OBJS_DIR):
	@printf "$(BLUE)Compiling $(NAME_CLEAN:.a=) objects files...$(NC)\n"
	@mkdir -p $(OBJS_DIR)$(MEM_DIR)
	@mkdir -p $(OBJS_DIR)$(STR_DIR)
	@mkdir -p $(OBJS_DIR)$(OUTPUT_DIR)
	@mkdir -p $(OBJS_DIR)$(FT_PRINTF_DIR)
	@mkdir -p $(OBJS_DIR)$(FT_STRING_DIR)
	@mkdir -p $(OBJS_DIR)$(FT_VECTOR_DIR)
	@mkdir -p $(OBJS_DIR)$(LIST_DIR)
	@mkdir -p $(OBJS_DIR)$(DLIST_DIR)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c $(HEADER)
	@$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS_DIR) $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@printf "$(GREEN)Bin $(NAME_CLEAN) is ready to use!$(NC)\n"

clean:
ifneq ($(OBJS_CLEAN),)
	@rm -rf $(OBJS_DIR)
	@printf "$(RED)$(NAME_CLEAN:.a=) objects files removed.$(NC)\n"
else
	@printf "$(RED)$(NAME_CLEAN:.a=) objects already cleaned$(NC)\n"
endif

fclean: clean
ifneq ($(NAME_CLEAN),)
	@rm -rf $(OBJS_DIR)
	@rm -rf $(NAME)
	@printf "$(RED)Bin $(NAME_CLEAN) removed.$(NC)\n"
else
	@printf "$(RED)Objects and bin $(NAME_CLEAN) already cleaned$(NC)\n"
endif

re: fclean all

.PHONY: all clean fclean re
