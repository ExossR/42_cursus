/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:37:59 by jbranche          #+#    #+#             */
/*   Updated: 2023/02/17 11:21:15 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

//GNL
char			*get_next_line(int fd);
char			*ft_split_line(char *line);
char			*ft_read_buffer(int fd, char *stock);
char			*ft_substr_wcheck(char const *s,
					unsigned int start, size_t len);
int				ft_is_in(char *str, char c);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 512

# endif

//libft
int				ft_atoi(const char *string);
void			ft_bzero(void *s, unsigned int n);
void			*ft_calloc(unsigned int element_count,
					unsigned int element_size);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
char			*ft_itoa(int n);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstadd_front(t_list **lst, t_list *new);
t_list			*ft_lstlast(t_list *lst);
t_list			*ft_lstnew(void *content);
int				ft_lstsize(t_list *lst);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			*ft_memchr(const void *memory, int searchedChar,
					unsigned int size);
int				ft_memcmp(const void *first, const void *second,
					unsigned int n);
void			*ft_memcpy(void *dest, const void *src, unsigned int n);
void			*ft_memmove(void *dest, const void *src, unsigned int n);
void			*ft_memset(void *pointer, int value, unsigned int count);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr_fd(char *s, int fd);
char			**ft_split(char*s, char c);
char			*ft_strndup(char *s, unsigned int size);
char			*ft_strchr(const char *string, int searched_char);
char			*ft_strdup(const char *src);
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strjoin(char const *s1, char const *s2);
unsigned int	ft_strlcat(char *dst, const char *src, unsigned int size);
unsigned int	ft_strlcpy(char *dst, const char *src, unsigned int size);
unsigned int	ft_strlen(const char *s);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strncmp(const char *first, const char *second,
					unsigned int length);
char			*ft_strnstr(const char *big, const char *little,
					unsigned int n);
char			*ft_strrchr(const char *string, int searched_char);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_substr(char const *s, unsigned int start, unsigned int len);
int				ft_tolower(int c);
int				ft_toupper(int c);
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));

#endif
