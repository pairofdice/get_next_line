/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 17:17:40 by jsaarine          #+#    #+#             */
/*   Updated: 2022/02/12 14:51:03 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}	t_list;
typedef struct s_vec
{
	char			*memory;
	size_t			elem_size;
	size_t			alloc_size;
	size_t			len;
}	t_vec;
// PART 1
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memccpy(void *dst, const void *src, int c, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s1);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strncpy(char *dst, const char *src, size_t len);
char	*ft_strcat(char *s1, const char *s2);
char	*ft_strncat(char *s1, const char *s2, size_t n);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strstr(const char *a, const char *b);
char	*ft_strnstr(const char *hay, const char *needle, size_t len);
int		ft_strcmp(const char *a, const char *b);
int		ft_strncmp(const char *a, const char *b, size_t n);
int		ft_atoi(const char *str);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_tolower(int c);
int		ft_toupper(int c);
// PART 2
void	*ft_memalloc(size_t size);
void	ft_memdel(void **ap);
char	*ft_strnew(size_t size);
void	ft_strdel(char **as);
void	ft_strclr(char *s);
void	ft_striter(char *s, void (*f)(char *));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_strmap(char const *s, char (*f)(char));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strequ(char const *s1, char const *s2);
int		ft_strnequ(char const *s1, char const *s2, size_t n);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s);
char	**ft_strsplit(char const *s, char c);
char	*ft_itoa(int n);
void	ft_putchar(char c);
void	ft_putstr(char const *s);
void	ft_putendl(char const *s);
void	ft_putnbr(int n);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char const *s, int fd);
void	ft_putendl_fd(char const *s, int fd);
void	ft_putnbr_fd(int n, int fd);
// BONUS
t_list	*ft_lstnew(void const *content, size_t content_size);
void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void	ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void	ft_lstadd(t_list **alst, t_list *new);
void	ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
// personal
int		ft_iswhitespace(char c);
int		ft_islower(int c);
int		ft_isupper(int c);
int		ft_wordcount(char const *s, char c, int wordcount);
int		ft_min(int a, int b);
int		ft_max(int a, int b);
int		ft_abs(int a);
// vector
int		vec_new(t_vec *src, size_t init_len, size_t elem_size);
void	vec_free(t_vec *src);
int		vec_from(t_vec *dst, void *src, size_t len, size_t elem_size);
int		vec_resize(t_vec *src, size_t target_size);
//int		vec_clear(t_vec *src);
int		vec_push(t_vec *src, void *elem);
//int		vec_pop(void *dst, t_vec *src);
//int		vec_copy(t_vec *dst, t_vec *src);
//void	*vec_get(t_vec *src, size_t index);
//int		vec_insert(t_vec *dst, void *elem, size_t index);
//int		vec_remove(t_vec *src, size_t index);
int		vec_append(t_vec *dst, t_vec *src);
//int		vec_prepend(t_vec *dst, t_vec *src);
//void	vec_iter(t_vec *src, void (*f) (void *));
//void	*vec_find(t_vec *src, bool (*f) (void *));
//int		vec_map(t_vec *dst, t_vec *src, void (*f) (void *));
//int		vec_filter(t_vec *dst, t_vec *src, bool (*f) (void *));
//int		vec_reduce(void *dst, t_vec *src, void (*f) (void *, void *));
//void	vec_sort(t_vec *src, int (*f)(void *, void *));
int		vec_strapp(t_vec *vec, char *str);

#endif
