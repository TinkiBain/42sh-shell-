/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bind.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 10:10:02 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/05 13:52:44 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bindings.h"

static t_string get_sequence2(int key)
{
	t_string	str;
	char		*seq;

	str_zero(&str);
	if (key == HOME)
		str = str_xcopy((seq = term_getstr("kh")) ? seq : "");
	else if (key == END)
		str = str_xcopy((seq = term_getstr("@7")) ? seq : "");
	else if (key == DELETE)
		str = str_xcopy((seq = term_getstr("kD")) ? seq : "");
	else if (key == INSERT)
		str = str_xcopy((seq = term_getstr("kI")) ? seq : "");
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
	char		*seq;

	str_zero(&str);
	if (key == ARROW_LEFT)
		str = str_xcopy((seq = term_getstr("kl")) ? seq : "\033[D");
	else if (key == ARROW_RIGHT)
		str = str_xcopy((seq = term_getstr("kr")) ? seq : "\033[C");
	else if (key == ARROW_UP)
		str = str_xcopy((seq = term_getstr("ku")) ? seq : "\033[A");
	else if (key == ARROW_DOWN)
		str = str_xcopy((seq = term_getstr("kd")) ? seq : "\033[B");
	else if (key == CTRL_LEFT)
		str = str_xcopy(CTRL_LEFT_SEQ);
	else if (key == CTRL_RIGHT)
		str = str_xcopy(CTRL_RIGHT_SEQ);
	else if (key == CTRL_UP)
		str = str_xcopy(CTRL_UP_SEQ);
	else if (key == CTRL_DOWN)
		str = str_xcopy(CTRL_DOWN_SEQ);
	else
		return (get_sequence2(key));
	return (str);
}

void	bind(t_vector *key_bindings, int key, t_action action)
{
	t_binding new;

	new.key = key;
	new.action = action;
	new.sequence = get_sequence(key);
	vec_xaddback(key_bindings, &new);
	/* todo: check for duplicates */
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

/*
**  key					termcap			terminfo		sequence
** --------------------------------------------------------------
** app_mode on			ks				smkx			\E[?1h\E=
** app_mode off			ke				rmkx			\E[?1l\E>
** 
** arrow_left			kl				kcub1			\EOD
** arrow_right			kr				kcuf1			\EOC
** arrow_up				ku				kcuu1			\EOA
** arrow_down			kd				kcud1			\EOB
**
** go_left				le				cub1			\b
** go_right				nd				cuf1			\E[C
** go_up				up				cuu1			\E[A
** go_down				do				cud1			\n
**
** delete				kD				kdch1			\E[3~
** insert				kI				kich1			\E[2~
** home					kh				khome			\EOH
** end					@7				kend			\EOF
**
** save cursor pos		sc				sc				\E7
** restore cursor pos	rc				rc				\E8	
*/
