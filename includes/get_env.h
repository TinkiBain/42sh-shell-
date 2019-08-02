/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 16:01:23 by wtalea            #+#    #+#             */
/*   Updated: 2019/08/01 17:32:55 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_ENV_H

#include "libft.h"
#include "lib_wtalea.h"

char			**create_env(char **env);
char			*search_bucks(char *str, char ***g_env);

#endif
