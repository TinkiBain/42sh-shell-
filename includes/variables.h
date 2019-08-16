/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 22:02:51 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/08/16 22:09:37 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VARIABLES_H
# define VARIABLES_H

int		init_g_var(void);
int		set_var(const char *var, char ***env, int change_readonly);
int		add_new_var(const char *av, char ***env);
char	**create_copy_env(char **env);
char	*ft_getenv(const char *name, char **env);
char	*get_var_name(const char *var, size_t *name_len);
int		remove_var(const char *av, char ***env);
int		replace_var(const char *name, const char *var, char **env, size_t len);
int		is_var_readonly(const char *name);
int		print_var_readonly(const char *var);

#endif
