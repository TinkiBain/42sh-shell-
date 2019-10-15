/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <dwisoky@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 22:02:51 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/10/14 21:03:19 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VARIABLES_H
# define VARIABLES_H

/*
**		Check that readonly variables consist current var
*/

int		check_readonly_var(const char *var, size_t name_len);

/*
**		Get var or var_value
*/

char	*ft_getenv(const char *name, char **env, size_t len);
char	*get_var_value(char *name);
char	*get_var_name(const char *var, size_t *name_len);
char	*get_str_function_var(const char *name, const char *value);

/*
**		Init global var
*/

int		fill_g_var_names(void);
int		init_g_var(void);
void	init_g_func_defs(void);

/*
**		Create variable
*/

int		add_new_var(const char *av, char ***env, int flag);
int		set_var(const char *var, char ***env, int change_readonly);
int		set_var_in_g_var(const char **av);
void	set_var_shellopts(void);
char	**create_copy_env(char **env);

/*
**		Change or remove variable
*/

int		remove_var(const char *av, char ***env);
int		replace_var(const char *var, char **env, size_t len, int flag);

/*
**		Print variables
*/

void	print_vars(int show_shell_vars);
int		print_var_names(void);

#endif
