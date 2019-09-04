/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 15:18:24 by wtalea            #+#    #+#             */
/*   Updated: 2019/09/04 19:20:01 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASH_H
# define HASH_H

# include "libft.h"
# include "ft_vector.h"
# include "lib_wtalea.h"
# include "ft_string.h"
# include "ft_qsort.h"
# include "xfuncs.h"
# include <dirent.h>

# define HASH_LEN 200
# define HASH_USAGE "usage: hash [-r] [name ...]"
# define HASH_NAME "hash"

unsigned int				generate_hash(char *str, unsigned int len);
int							ft_intlen(int num);
int							ft_abs(int n);
void						ft_itoa_nm(int n, char *nb);

typedef struct				s_hash
{
	char					*name;
	char					*path;
	unsigned	char		hash_on;
	size_t					hash_count;
	unsigned int			hash;
	struct s_hash			*next;
	char					**flags_args;
}							t_hash;

void						null_hash(t_hash *table[HASH_LEN]);
char						*paste_path(char *str1, char *str2);
void						create_bin(char *str);
void						del_hash(void);
char						*get_bin(char *name);
void						fill_hash_table(void);
t_hash						*create_hash(char *name, char *path,
		unsigned int key);
void						add_force_builds(void);
void						create_arr_names(void);
t_hash						*get_hash_struct(char *name);

/*
**print_usage
*/
void						hash_usage(void);
void						hash_invalid_option(char c);
void						hash_empty(void);
void						print_number(int count, char num[13],
		char *str, int len);
void						hash_not_found(char *name);

/*
**start_hash
*/
void						hash_add_count(char *name);
void						hash_print(void);
int							hash_start_work(int flags, char **argv);
int							count_hash_on(void);
void						hash_print_new(int count, t_hash *table[count],
		int count_len);
void						find_and_del_hash(char *name);

/*
**Flags
*/
void						del_all_hash(void);

/*
**fill_flags
*/
void						add_flags_args(void);

char						**hash_get_flags(char *name);

#endif
