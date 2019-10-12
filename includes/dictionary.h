/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 17:26:48 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/10/12 17:27:37 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DICTIONARY_H
# define DICTIONARY_H

# include <string.h>

/*
**	Dictionary (key/value)
*/

typedef struct		s_dict
{
	struct s_dict	*next;
	char			*key;
	char			*value;
	size_t			key_len;
	size_t			value_len;
}					t_dict;

void				ft_dict_del(t_dict **alst);
void				ft_dict_del_one(t_dict **dict);
void				ft_dict_remove_elem(t_dict **dict, t_dict *elem);
t_dict				*ft_init_dict(const char *key, const char *value);
void				ft_dict_push_back(t_dict **dict, t_dict *new_elem);
void				ft_dict_push_front(t_dict **dict, t_dict *new_elem);
void				ft_dict_remove_elem(t_dict **dict, t_dict *elem);
t_dict				*ft_get_dict(t_dict *dict, const char *key);
char				*ft_get_dict_value(t_dict *dict, const char *key);

#endif
