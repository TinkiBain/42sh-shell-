# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/20 12:48:23 by gmelisan          #+#    #+#              #
#    Updated: 2019/07/28 21:46:17 by ggwin-go         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = clang
CFLAGS = -Wall -Wextra -Werror
CFLAGS += -g

OBJ = $(sort $(addprefix ./src/, \
ft_memset.o ft_bzero.o ft_memcpy.o ft_memccpy.o ft_memmove.o \
ft_memchr.o ft_memcmp.o ft_strlen.o ft_strdup.o ft_strcpy.o \
ft_strncpy.o ft_strcat.o ft_strncat.o ft_strlcat.o ft_strchr.o \
ft_strrchr.o ft_strstr.o ft_strnstr.o ft_strcmp.o ft_strncmp.o \
ft_isalpha.o ft_isdigit.o ft_isalnum.o ft_isascii.o ft_isprint.o \
ft_toupper.o ft_tolower.o ft_isspace.o ft_abs.o \
\
ft_memalloc.o ft_memdel.o ft_strnew.o ft_strdel.o ft_strclr.o \
ft_striter.o ft_striteri.o ft_strmap.o ft_strmapi.o ft_strequ.o \
ft_strnequ.o ft_strsub.o ft_strjoin.o ft_strtrim.o ft_strsplit.o \
ft_putchar.o ft_putstr.o ft_putendl.o ft_putnbr.o ft_putchar_fd.o \
ft_putstr_fd.o ft_putendl_fd.o ft_putnbr_fd.o \
\
ft_lstnew.o ft_lstdelone.o ft_lstdel.o ft_lstadd.o ft_lstiter.o \
ft_lstmap.o ft_dlstnew.o ft_dlstdelone.o ft_dlstdel.o ft_dlstadd.o \
ft_dlstiter.o ft_dlstaddback.o ft_dlstsize.o ft_dlstdelfront.o \
ft_dlstdelend.o ft_xmalloc.o ft_strndup.o\
\
ft_swap.o ft_range.o ft_power.o ft_realloc.o get_next_line.o \
get_lines.o ft_lstaddback.o ft_strarrdel.o get_lines.o ft_lstsize.o \
ft_atoi.o ft_itoa.o ft_qsort.o ft_strnjoin.o ft_cntdigits.o \
))

OBJ_FTPRINTF = $(sort $(addprefix ./src/ft_printf/, \
ft_printf.o ft_vprintf.o ft_fdprintf.o ft_vfdprintf.o \
get_conversion.o get_flags.o get_width.o get_precision.o get_length.o \
handle_conversion.o \
handle_unknown.o \
handle_char.o handle_string.o \
handle_wchar.o handle_wstring.o \
handle_integer.o convert_integer.o number_to_string.o \
handle_float.o convert_float.o \
number_to_string_f.o number_to_string_e.o \
get_color.o handle_color.o ))

OBJ_FTSTRING = $(sort $(addprefix ./src/ft_string/, \
str_create.o str_copy.o str_delete.o str_delete.o \
str_fixlen.o str_get.o str_compare.o str_duplicate.o \
str_substring.o str_addfront.o str_addback.o str_split.o \
str_delarr.o str_zero.o str_remove.o str_insert.o))

OBJ_FTVECTOR = $(sort $(addprefix ./src/ft_vector/, \
vec_create.o vec_duplicate.o vec_zero.o vec_delete.o vec_get.o \
vec_addback.o vec_addfront.o))

all: $(NAME)

$(NAME): $(OBJ) $(OBJ_FTPRINTF) $(OBJ_FTSTRING) $(OBJ_FTVECTOR)
	@ar rc $@ $^
	@ranlib $@
	@printf "\033[0;32mFile %s was successfully created.\033[0m\n" $@

$(OBJ): ./include/libft.h
get_next_line.o: ./include/get_next_line.h
ft_qsort.o: ./include/ft_qsort.h

$(OBJ_FTPRINTF): ./include/ft_printf.h ./include/libft.h
$(OBJ_FTSTRING): ./include/ft_string.h ./include/libft.h
$(OBJ_FTVECTOR): ./include/ft_vector.h ./include/libft.h

%.o : %.c
	@$(CC) $(CFLAGS) -I./include -c -o $@ $<
#	@echo "\033[34;1mCompiling ($(CFLAGS)) \033[0;36m$<\033[0m"
	@echo "Compiling ($(CFLAGS)) $<"

clean:
	@rm -f $(OBJ)
	@rm -f $(OBJ_FTPRINTF)
	@rm -f $(OBJ_FTSTRING)
	@rm -f $(OBJ_FTVECTOR)

fclean: clean
	@rm -f $(NAME)

re: fclean all
