/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 23:13:55 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/08/04 15:49:47 by ggwin-go         ###   ########.fr       */
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
# include <stdio.h>

typedef unsigned char			t_uchar;
typedef unsigned int			t_uint;
typedef unsigned long int		t_ulint;
typedef long long int			t_llint;
typedef unsigned long long int	t_ullint;

void				ft_bzero(void *s, size_t n);
void				*ft_memalloc(size_t size);
void				*ft_memcpy_rev(void *dst, const void *src, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				ft_memdel(void **ap);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_realloc(void **ptr, size_t oldsize, size_t newsize);
void				ft_swap(void *a, void *b);
void				*ft_xmalloc(size_t size);

int					ft_atoi(const char *str);
int					ft_gnl(const int fd, char **line);
void				ft_free_double_ptr_arr(void ***arr);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_isspace(char c);
char				*ft_itoa(int n);
char				*ft_itoa_base(long long int value, int base);
char				**ft_sort_str_array(char **arr, int rewrite);
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
char				*ft_strndup(const char *src, int j);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strjoin_free(char const *s1, char const *s2,
						int numstr_to_free);
size_t				ft_strlen(const char *s);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strnew(size_t size);
char				**ft_strsplit(char const *s, char c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack, const char *needle,
						size_t len);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);

int					ft_tolower(int c);
int					ft_toupper(int c);

void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr(char const *str);
void				ft_putstr_fd(char const *s, int fd);

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lstaddback(t_list **alst, t_list *new);
size_t				ft_lstsize(t_list *lst);

typedef struct		s_dlist
{
	void			*content;
	size_t			content_size;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}					t_dlist;

int					get_next_line(const int fd, char **line);
int					get_lines(int fd, char ***lines, int n);

t_dlist				*ft_dlstnew(void const *content, size_t content_size);
void				ft_dlstdelone(t_dlist **alst, void (*del)(void *, size_t));
void				ft_dlstdel(t_dlist **alst, void (*del)(void *, size_t));
void				ft_dlstdelfront(t_dlist **alst, void (*del)(void *, size_t));
void				ft_dlstdelend(t_dlist **alst, void (*del)(void *, size_t));
void				ft_dlstadd(t_dlist **alst, t_dlist *new);
void				ft_dlstiter(t_dlist *lst, void (*f)(t_dlist *elem));
void				ft_dlstaddback(t_dlist **alst, t_dlist *new);
size_t				ft_dlstsize(t_dlist *lst);

int					ft_printf(const char *format, ...);
int					ft_vprintf(const char *format, va_list ap);
int					ft_fdprintf(int fd, const char *format, ...);
int					ft_vfdprintf(int fd, const char *format, va_list ap);

#endif
