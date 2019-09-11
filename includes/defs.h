/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 10:15:13 by gmelisan          #+#    #+#             */
/*   Updated: 2019/09/11 16:38:06 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFS_H
# define DEFS_H

# define PROJECT_NAME			"42sh"

# define STDIN					0
# define STDOUT					1
# define STDERR					2

# define DEFAULT_HISTSIZE		"20"

extern char						*g_project_name;
extern int						g_res_exec;
extern char						*g_tty;
extern int						*g_open_fd;
extern char						*g_shell_path;

#endif
