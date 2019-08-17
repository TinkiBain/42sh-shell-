/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan </var/spool/mail/vladimir>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 15:55:20 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/17 17:35:06 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYS_H
# define KEYS_H

# define KEY_OFFSET		27000
# define META			1000

/*
** Meta chars in range 1000-1127.
** Ex.: 1003 = M-C.
*/

enum e_key
{
	CTRL_A = 1,
	CTRL_B,
	CTRL_C,
	CTRL_D,
	CTRL_E,
	CTRL_F,
	CTRL_G,
	CTRL_H,
	CTRL_I,
	CTRL_J,
	CTRL_K,
	CTRL_L,
	CTRL_M,
	CTRL_N,
	CTRL_O,
	CTRL_P,
	CTRL_Q,
	CTRL_R,
	CTRL_S,
	CTRL_T,
	CTRL_U,
	CTRL_V,
	CTRL_W,
	CTRL_X,
	CTRL_Y,
	CTRL_Z,
	ESC,
	CTRL_US = 31,
	DEL = 127,
	ARROW_LEFT = KEY_OFFSET,
	ARROW_RIGHT,
	ARROW_UP,
	ARROW_DOWN,
	CTRL_LEFT,
	CTRL_RIGHT,
	CTRL_UP,
	CTRL_DOWN,
	INSERT,
	DELETE,
	HOME,
	END
};

# define BACKSPACE		CTRL_H
# define TAB			CTRL_I
# define NL				10
# define ENTER			10
# define CR				13

#endif
