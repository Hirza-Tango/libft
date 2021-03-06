/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrove@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 12:02:56 by dslogrov          #+#    #+#             */
/*   Updated: 2019/09/09 13:52:53 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# ifdef __linux__
#  include <inttypes.h>
# endif

void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *s1);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *s1, const char *s2, size_t n);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strnstr(
	const char *haystack, const char *needle, size_t len);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_atoi(const char *str);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);

void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);
char			*ft_itoa(intmax_t n);
void			ft_putchar(char c);
void			ft_putstr(char const *s);
void			ft_putendl(char const *s);
void			ft_putnbr(intmax_t n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(intmax_t n, int fd);

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *elem);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

typedef struct	s_d_list
{
	void			*content;
	size_t			content_size;
	struct s_d_list	*next;
	struct s_d_list *prev;
}				t_d_list;

t_d_list		*ft_dlstnew(void const *content, size_t content_size);
void			ft_dlstdelone(t_d_list **alst, void (*del)(void*, size_t));
void			ft_dlstdel(t_d_list **alst, void (*del)(void*, size_t));
void			ft_dlstadd(t_d_list **alst, t_d_list *elem);
void			ft_dlstiter(t_d_list *lst, void (*f)(t_d_list *elem));
t_d_list		*ft_dlstmap(t_d_list *lst, t_d_list *(*f)(t_d_list *elem));

# define CHECK_RETURN(c, r) if(c) return (r);
# define MIN(X,Y) (X > Y ? Y : X)
# define MAX(X,Y) (X < Y ? Y : X)
# define ABS(X) (X > 0 ? X : -X)
# define PASS (void)0

void			*ft_memrchr(const void *s, int c, size_t n);
int				ft_isupper(int c);
int				ft_islower(int c);
int				ft_isspace(int c);
char			*ft_itoa_base(intmax_t value, int base);
char			*ft_strndup(const char *s1, size_t n);
void			ft_swapnfree(void **var, void *new_val);
size_t			ft_atou_base(const char *value, unsigned char base);
char			*ft_appendwchar(wchar_t wc, char *str);
char			*ft_utoa_base(uintmax_t value, int base);
void			ft_lstswap(t_list *a, t_list *b);
t_list			**ft_lstsort(t_list **lst,
	long (*f)(const void *, const void *));
void			ft_lstappend(t_list **alst, t_list *elem);
char			*ft_strmjoin(size_t count, ...);
char			**ft_strqotsplit(char const *str);
char			*ft_strlit(char *str, size_t n);
char			**ft_tabdup(char **tab);
void			ft_tabfree(char **tab);
void			ft_lstrev(t_list **lst);
size_t			ft_declen(uintmax_t d);
size_t			ft_lstlen(t_list *list);
void			ft_lstrm(t_list **list, size_t index,
	void (*del)(void *, size_t));
void			ft_putptr_fd(void *ptr, int fd);
void			ft_putptr(void *ptr);
void			ft_put_uintmax_base_fd(uintmax_t n, int fd, int base);
void			ft_put_uintmax_base(uintmax_t n, int base);
void			ft_hexdump(void *region, size_t size, off_t offset,
	unsigned char pointer_size);

#endif
