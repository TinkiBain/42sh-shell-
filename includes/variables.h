/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 22:02:51 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/09/23 13:54:04 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VARIABLES_H
# define VARIABLES_H

int		add_new_var(const char *av, char ***env, int flag);
int		check_readonly_var(const char *var, size_t name_len);
char	**create_copy_env(char **env);
int		fill_g_var_names(void);
char	*ft_getenv(const char *name, char **env, size_t len);
char	*get_var_value(char *name);
char	*get_var_name(const char *var, size_t *name_len);
int		init_g_var(void);
int		remove_var(const char *av, char ***env);
int		replace_var(const char *var, char **env, size_t len, int flag);
void	print_vars(int show_shell_vars);
int		print_var_names(void);
void	set_result(void);
int		set_var(const char *var, char ***env, int change_readonly);
int		set_var_in_g_var(const char **av);
void	set_var_shellopts(void);

#endif
