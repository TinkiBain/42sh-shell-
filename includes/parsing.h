/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 11:14:21 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/06/19 11:36:10 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "sh.h"

typedef struct	s_redir
{

}				t_redir;

typedef struct	s_cmd_suf
{
	char				*text;
	struct s_redir		*redir;
	struct s_cmd_suf	*next;
}				t_cmd_suf;


typedef struct	s_cmd
{
	char			*text;
	struct s_cmd	*pipe;
	struct s_cmd	*sem;
	struct s_cmd	*
	t_cmd_suf		*cmd_suf;
	int				;
}               t_cmd;



#endif
