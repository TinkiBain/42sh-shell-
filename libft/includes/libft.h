/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 23:13:55 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/06/03 17:07:52 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>

# define GNL_BUFF_SIZE 1024
# define GNL_MAX_FD 3

typedef struct		s_list
{
	char			*name;
	char			*path;
	size_t			name_len;
	size_t			path_len;
	struct s_list	*next;
}					t_list;

void				ft_bzero(void *s, size_t n);
int					ft_count_chr(const char *s, char c);
void				*ft_memalloc(size_t size);
void				*ft_memcpy_rev(void *dst, const void *src, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				ft_memdel(void **ap);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_realloc(void *ptr, size_t size);
void				ft_swap(void *a, void *b);
void				*ft_xmalloc(size_t size);

void				ft_lst_push_back(t_list **alst, t_list *lst_new);
void				ft_lst_push_front(t_list **alst, t_list *lst_new);
void				ft_lstdelone(t_list **alst);
void				ft_lstdel(t_list **alst);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstnew(const char *name, const char *path);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
size_t				ft_lstsize(t_list *lst);

int					ft_atoi(const char *str);
int					ft_gnl(const int fd, char **line);
void				ft_free_char_arr(char ***arr);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_is_whitespaces(char c);
char				*ft_itoa(int n);
char				*ft_itoa_base(long long int value, int base);
char				*ft_itoa_base_unsigned(unsigned long long int value,
																int base);
char				*ft_skip_whitespaces(char *s);
char				**ft_sort_strarray(char **arr, int rewrite);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
void				ft_strclr(char *s);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
void				ft_strdel(char **as);
char				*ft_strdup(const char *src);
char				*ft_strdup_len(const char *src, size_t *len);
char				*ft_strdup_len_len(const char *src, size_t *len,
													size_t *printable_len);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strjoin_free(char const *s1, char const *s2,
						int numstr_to_free);
size_t				ft_strlen(const char *s);
size_t				ft_strnlen(const char *s, size_t maxlen);
size_t				ft_strlen_or_chr(char const *str, char c);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strnew(size_t size);
char				*ft_strrev(char *src, int need_to_free);
char				**ft_strsplit(char const *s, char c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack, const char *needle,
						size_t len);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);
char				*ft_str_to_lower(char *dst, int need_to_free);
char				*ft_str_to_upper(char *dst, int need_to_free);

int					ft_tolower(int c);
int					ft_toupper(int c);

void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putnbr_lli(long long int n);
void				ft_putnbr_lli_fd(long long int n, int fd);
void				ft_putstr(char const *str);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putstr_len(char const *str, size_t len);

int					*ft_range(int min, int max);

#endif
