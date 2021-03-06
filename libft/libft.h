/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libft.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/03 10:35:07 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/19 11:47:59 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <wchar.h>
# include <inttypes.h>
# include <stdarg.h>
# include <inttypes.h>
# include <limits.h>
# include <stdlib.h>

# define FORMAT "-+ 0#123456789.hlLzjt*"
# define FLAGS "-+ 0#"
# define WIDTH "123456789*"
# define PRECIS '.'
# define LENGTH "hlzj"
# define TYPE "bsSpdDioOuUxXcC%"

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_format
{
	int				plus;
	int				minus;
	int				hash;
	int				space;
	int				zero;
	int				w;
	int				p;
	int				w_val;
	int				p_val;
	char			l;
	char			t;
	int				neg;
	char			mod;
}					t_format;


void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack, const char *needle,
					size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);

unsigned int		ft_atoui_base(char *str, char *base);
char				*ft_uitoa_base(uintmax_t n, int base);
long				ft_atol_base(char *str, char *base);
int					ft_nb_len(int nb);
int					ft_power(int nb, int pwr);
char				*ft_itoa_base(intmax_t n, int base);
int					ft_atoi_base(char *str, char *base);
int					ft_islower(int c);
int					ft_isupper(int c);
int					ft_iswhite(int c);
char				*ft_strrev(char *s);
int					ft_wordcount(const char *str, char c);
int					wchar_len(wchar_t c);
int					wstrlen(wchar_t *str);

void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
int					ft_putchar(char c);
int					ft_putwchar(wchar_t c);
int					ft_putwchar_fd(wchar_t c, int fd);
int					ft_putstr(char *s);
int					ft_putendl(char const *s);
int					ft_putnbr(int n);
int					ft_putchar_fd(char c, int fd);
int					ft_putstr_fd(const char *s, int fd);
int					ft_putendl_fd(char const *s, int fd);
int					ft_putnbr_fd(int n, int fd);

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

t_format			ft_parse(const char **str, va_list *va);
intmax_t			d_size(va_list *ap, t_format *fmt);
uintmax_t			u_size(va_list *ap, t_format *fmt);
void				ft_format_flags(const char **str, t_format *format);
void				ft_format_width(const char **str, t_format *format,
		va_list *va);
void				ft_format_precis(const char **str, t_format *format,
		va_list *va);
void				ft_format_length(const char **str, t_format *format);
void				ft_format_type(const char **str, t_format *format);
int					ft_printf(const char *format, ...);
void				ft_modify(t_format fmt, va_list *va, int *ret);
void				ft_type_di(t_format *fmt, va_list *va, int *ret);
void				ft_type_c(t_format *fmt, va_list *va, int *ret);
void				ft_type_s(t_format *fmt, va_list *va, int *ret);
void				ft_type_oub(t_format *fmt, va_list *va, int *ret);
void				ft_type_x(t_format *fmt, va_list *va, int *ret);
void				ft_type_p(t_format *fmt, va_list *va, int *ret);
void				ft_type_ws(t_format *fmt, va_list *va, int *ret);
void				ft_init_format(t_format *struc);
int					lenfinder(t_format *fmt, wchar_t *str);

#endif
