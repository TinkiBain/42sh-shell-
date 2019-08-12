/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 22:02:51 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/08/12 16:12:39 by jterry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVIRONMENT_H
# define ENVIRONMENT_H

int					add_env(const char **av, char ***env);
char				**create_copy_env(char **env);
char				*ft_getenv(const char *name, char **env);
int					remove_env(const char **av, char ***env);

#endif
