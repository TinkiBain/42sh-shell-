/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bind.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 10:10:02 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/17 05:36:01 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bindings.h"

static t_string get_sequence_2(int key)
{
	t_string	str;

	str_zero(&str);
	if (key == HOME)
		str = str_xcopy(g_cap.key_home);
	else if (key == END)
		str = str_xcopy(g_cap.key_end);
	else if (key == DELETE)
		str = str_xcopy(g_cap.key_delete);
	else if (key == INSERT)
		str = str_xcopy(g_cap.key_insert);
	else if (key >= META && key <= META + 127)
	{
		str = str_xcreate(2);
		str.s[0] = ESC;
		str.s[1] = (char)(key - META);
	}
	else if (key)
	{
		str = str_xcreate(1);
		str.s[0] = (char)key;
	}
	return (str);
}

static t_string get_sequence(int key)
{
	t_string	str;

	str_zero(&str);
	if (key == ARROW_LEFT)
		str = str_xcopy(g_cap.key_left);
	else if (key == ARROW_RIGHT)
		str = str_xcopy(g_cap.key_right);
	else if (key == ARROW_UP)
		str = str_xcopy(g_cap.key_up);
	else if (key == ARROW_DOWN)
		str = str_xcopy(g_cap.key_down);
	else if (key == CTRL_LEFT)
		str = str_xcopy(g_cap.key_ctrl_left);
	else if (key == CTRL_RIGHT)
		str = str_xcopy(g_cap.key_ctrl_right);
	else if (key == CTRL_UP)
		str = str_xcopy(g_cap.key_ctrl_up);
	else if (key == CTRL_DOWN)
		str = str_xcopy(g_cap.key_ctrl_down);
	else
		return (get_sequence_2(key));
	return (str);
}

void	bind(t_vector *key_bindings, int key, t_action action)
{
	t_binding new;

	new.key = key;
	new.action = action;
	new.sequence = get_sequence(key);
	vec_xaddback(key_bindings, &new);
}

t_binding	*find_binding(t_vector *key_bindings, char *buf)
{
	int			i;
	t_binding	*b;

	i = 0;
	while (i < (int)key_bindings->len)
	{
		b = (t_binding *)vec_get(*key_bindings, i);
		if (ft_strequ(b->sequence.s, buf))
			return (b);
		i++;
	}
	return (NULL);
}
