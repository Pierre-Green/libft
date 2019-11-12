/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 11:39:29 by pguthaus          #+#    #+#             */
/*   Updated: 2019/11/12 20:06:33 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

typedef enum		e_bool
{
	false = 0,
	true = 42
}					t_bool;

/*
** Memory manipulation
*/
void				*ft_memset(void *b, int c, size_t len);

void				ft_bzero(void *s, size_t n);

void				*ft_memcpy(void *dst, const void *src, size_t n);

void				*ft_memccpy(void *dst, const void *src, int c, size_t n);

void				*ft_memmove(void *dst, const void *src, size_t len);

void				*ft_memchr(const void *s, int c, size_t n);

int					ft_memcmp(const void *s1, const void *s2, size_t n);

void				*ft_calloc(size_t count, size_t size);

/*
** Strings manipulation
*/

size_t				ft_strlen(const char *s);

char				*ft_strchr(const char *s, int c);

char				*ft_strrchr(const char *s, int c);

int					ft_strncmp(const char *s1, const char *s2, size_t n);

size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);

size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);

char				*ft_strnstr(const char *haystack, const char *needle,
	size_t len);

char				*ft_strdup(const char *s1);

char				*ft_substr(char const *s, unsigned int start, size_t len);

char				*ft_strjoin(char const *s1, char const *s2);

char				*ft_strtrim(char const *s1, char const *set);

char				**ft_split(char const *s, char c);

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/*
** I/O
*/
typedef struct		s_buff
{
	char			buff[BUFFER_SIZE];
	size_t			len;
	char			eol;
	char			eof;
	struct s_buff	*next;
}					t_buff;

void				ft_putchar_fd(char c, int fd);

void				ft_putstr_fd(char *s, int fd);

void				ft_putendl_fd(char *s, int fd);

void				ft_putnbr_fd(int n, int fd);

int					get_next_line(int fd, char **line);

int					flush_to_eol(t_buff **buff, char **line);

t_buff				*clear_buff_next(t_buff *buff);

void				trim_buff(t_buff *buff, unsigned int nl);

/*
** Other helpers
*/

int					ft_atoi(const char *str);

char				*ft_itoa(int n);

int					ft_isalpha(int c);

int					ft_isdigit(int c);

int					ft_isalnum(int c);

int					ft_isascii(int c);

int					ft_isprint(int c);

int					ft_toupper(int c);

int					ft_tolower(int c);

/*
** Maths
*/
typedef struct		s_vec3d
{
	double			x;
	double			y;
	double			z;
}					t_vec3d;

size_t				ft_pow(int n, int power);

size_t				ft_idkpow(int n, int powa);

size_t				ft_count_uint_base(uint64_t n, uint32_t base);

/*
** Lists
*/
typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void *content);

void				ft_lstadd_front(t_list **alst, t_list *new);

int					ft_lstsize(t_list *lst);

t_list				*ft_lstlast(t_list *lst);

void				ft_lstadd_back(t_list **alst, t_list *new);

void				ft_lstdelone(t_list *lst, void (*del)(void *));

void				ft_lstclear(t_list **lst, void (*del)(void *));

void				ft_lstiter(t_list *lst, void (*f)(void *));

t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
	void (*del)(void *));

/*
** Args
*/
typedef struct		s_arg
{
	char			*value;
	struct s_arg	*next;
}					t_arg;
typedef struct		s_args
{
	size_t			count;
	t_arg			*args;
}					t_args;
t_args				*ft_args_start(int argc, char **argv);
t_args				*ft_args_end(t_args **args);

/*
** Colors
*/
typedef uint32_t	t_color;

#endif
