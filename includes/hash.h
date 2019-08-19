/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 15:18:24 by wtalea            #+#    #+#             */
/*   Updated: 2019/08/19 16:37:08 by wtalea           ###   ########.fr       */
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

unsigned int		generate_hash(char *str, unsigned int len);

typedef struct		s_hash
{
	char			*name;
	char			*path;
	unsigned int	hash;
	struct s_hash	*next;
}					t_hash;

void				null_hash(t_hash *table[HASH_LEN]);
char				*paste_path(char *str1, char *str2);
void				create_bin(char *str);
void				del_hash(void);
char				*get_bin(char *name);
void				fill_hash_table(void);
t_hash				*create_hash(char *name, char *path, unsigned int key);
void				add_force_builds(void);
void				create_arr_names(void);

t_vector			get_vec_prog(t_string query);

#endif
