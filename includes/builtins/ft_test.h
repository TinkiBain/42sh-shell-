/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <wtalea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 16:16:22 by wtalea            #+#    #+#             */
/*   Updated: 2019/10/14 01:21:01 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TEST_H
# define FT_TEST_H

# include <errno.h>
# include "builtins.h"

long		ft_strtol(const char *nptr, char **endptr, register int base);
int			ft_find_num(char *str);
int			ft_isupper(int c);

/*
**test (return 0 if true, 1 if false, 2 if error)
*/
int			test_unary(char *src);
int			test_too_many(void);
int			test_find_flag(char **argv);
int			test_check_compare(char **argv);
int			test_integer_expression(char *src);

/*
**test_flags
*/
int			test_file_usual(char *str);
int			test_file_socket(char *str);
int			test_file_link(char *str);
int			test_file_dir(char *str);
int			test_file_symbol(char *str);
int			test_file_block(char *str);
int			test_file_exists(char *str);
int			test_file_set_group_id(char *str);
int			test_file_set_user_id(char *str);
int			test_file_pipe(char *str);
int			test_file_read(char *str);
int			test_file_exists_and_fat(char *str);
int			test_string_null(char *str);
int			test_file_exists_and_exec(char *str);
int			test_file_exists_and_write(char *str);

/*
**test_compare
*/
int			test_compare_str_equal(char *str, char *dobstr);
int			test_compare_str_not_equal(char *str, char *dobstr);
int			test_compare_int_not_equal(char *str, char *str2);
int			test_compare_int_equal(char *str, char *str2);
int			test_compare_int_less(char *str, char *str2);
int			test_compare_int_more(char *str, char *str2);
int			test_compare_int_less_or_equal(char *str, char *str2);
int			test_compare_int_more_or_equal(char *str, char *str2);

#endif
