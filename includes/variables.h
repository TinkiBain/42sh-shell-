/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 22:02:51 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/08/15 22:48:58 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VARIABLES_H
# define VARIABLES_H

int		add_var(const char *av, char ***env);
char	**create_copy_env(char **env);
char	*ft_getenv(const char *name, char **env);
int		remove_var(const char *av, char ***env);
int		replace_var(const char *name, const char *var, char **env, size_t len);
int		check_is_var_readonly(const char *name);
int		print_var_readonly(const char *var);

#endif
