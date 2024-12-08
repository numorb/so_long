/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blnunez- <blnunez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 19:19:48 by blnunez-          #+#    #+#             */
/*   Updated: 2024/10/28 17:57:56 by blnunez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_list
{
	struct s_list	*next;
	void			*content;
}					t_list;

int					append_line(char **line, char *buffer);
int					ft_atoi(const char *nptr);
void				ft_bzero(void *s, size_t n);
void				*ft_calloc(size_t count, size_t size);
int					ft_fprintf(void *output_stream, const char *format, ...);
char				*ft_itoa(int n);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstnew(void *content);
int					ft_lstsize(t_list *lst);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memset(void *s, int c, size_t n);
int					ft_printf(const char *format, ...);
int					ft_printf_fd(int fd, const char *format, ...);
int					ft_printf_format(int fd, const char *format, va_list args);
void				ft_putchar(int c);
int					ft_putchar_count(char c, int fd);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_puthex(unsigned long x, int upcase);
int					ft_puthex_count(unsigned long x, int upcase, int fd);
void				ft_puthex_fd(unsigned long x, int upcase, int fd);
void				ft_putnbr(int x);
int					ft_putnbr_count(int x, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putpointer(void *p);
int					ft_putpointer_count(void *p, int fd);
void				ft_putpointer_fd(void *p, int fd);
void				ft_putstr(char *str);
int					ft_putstr_count(char *s, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putunsigned(unsigned int x);
int					ft_putunsigned_count(unsigned int x, int fd);
void				ft_putunsigned_fd(unsigned int x, int fd);
char				**ft_split(char const *s, char c);
char				*ft_strchr(const char *s, int c);
char				*ft_strdup(const char *s1);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *s);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strnstr(const char *big, const char *little,
						size_t len);
char				*ft_strrchr(const char *s, int c);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_substr(char const *s, unsigned int start, size_t len);
int					ft_tolower(int c);
int					ft_toupper(int c);
char				*get_next_line(int fd);
char				*get_one_line(char *buffer);
char				*handle_lines(char *line, char *old_line, char *remainder);
int					read_line(char *buffer, int fd, char **old_line);
void				rest_of_line(char *whatever_line);
int					specifiers(char format, va_list args, int fd);

#endif
