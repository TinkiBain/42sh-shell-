/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 19:57:15 by wtalea            #+#    #+#             */
/*   Updated: 2019/08/03 19:03:54 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASH_H
# define HASH_H

# include "libft.h"
# include "lib_wtalea.h"
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
void				create_bin(char *str, t_hash ***table);
void				del_hash(t_hash ***table);
char				*get_bin(char *name, t_hash **table);
void				fill_hash_table(void);

#endif
