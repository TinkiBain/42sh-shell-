/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 22:02:51 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/08/22 17:34:41 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VARIABLES_H
# define VARIABLES_H

int		init_g_var(void);
int		set_var(const char *var, char ***env, int change_readonly);
int		set_var_in_g_var(const char **av);
int		add_new_var(const char *av, char ***env);
char	**create_copy_env(char **env);
int		fill_g_var_names(void);
char	*ft_getenv(const char *name, char **env, size_t len);
char	*get_value_from_all_vars(char *name);
char	*get_var_name(const char *var, size_t *name_len);
int		remove_var(const char *av, char ***env);
int		replace_var(const char *var, char **env, size_t len);
int		check_readonly_var(const char *var, size_t name_len);
void	print_all_vars(void);
int		print_var_names(void);
int		print_var_readonly(const char *var, size_t name_len);

#endif
