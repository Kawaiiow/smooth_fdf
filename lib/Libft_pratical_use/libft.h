/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibasri <pibasri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 22:02:23 by kawaii            #+#    #+#             */
/*   Updated: 2024/11/21 21:16:16 by pibasri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int		in(char c, char	*set);

t_list	*ft_lstnew(void *content);

t_list	*ft_lstlast(t_list *target);
int		ft_lstsize(t_list *target);
void	ft_lstiter(t_list *target, void (*f)(void *));

void	ft_lstadd_front(t_list **target, t_list *new);
void	ft_lstadd_back(t_list **target, t_list *new);
void	ft_lstdelone(t_list *target, void (*del)(void *));
void	ft_lstclear(t_list **target, void (*del)(void *));
t_list	*ft_lstmap(t_list *target, void *(*f)(void *), void (*del)(void *));

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_tolower(int c);
int		ft_toupper(int c);

void	ft_putchar_fd(char c, int fildes);
void	ft_putstr_fd(char *str, int fildes);
void	ft_putendl_fd(char *str, int fildes);
void	ft_putnbr_fd(int n, int fildes);

int		ft_strlen(char const *str);
int		ft_strncmp(char const *s1, char const *s2, size_t n);
int		ft_strlcpy(char *dest, char const *src, size_t size);
int		ft_strlcat(char *dest, char const *src, size_t size);
char	*ft_strnstr(char const *str, char const *to_find, size_t n);
char	*ft_strchr(char const *str, int c);
char	*ft_strrchr(char const *str, int c);

char	*ft_strdup(char const *str);
char	**ft_split(char const *str, char c);
char	**split_clear(char **split_str);
char	*ft_strtrim(char const *str, char const *set);
char	*ft_strjoin(char const *str1, char const *str2);
char	*ft_substr(char const *str, unsigned int start, size_t len);
char	*ft_strmapi(char const *str, char (*f)(unsigned int, char));
void	ft_striteri(char *str, void (*f)(unsigned int, char*));

int		ft_atoi(char const *str);
long	ft_atol(char const *str);
int		ft_atoi_base(char *str, char *base);
char	*ft_itoa(int num);

void	ft_bzero(void *set, size_t n);
void	*ft_calloc(size_t n, size_t size);

void	*ft_memset(void *s, int c, size_t n);
void	*ft_memmove(void *dest, void const *src, size_t n);
void	*ft_memchr(void const *src, int c, size_t n);
void	*ft_memcpy(void *dest, void const *src, size_t n);
int		ft_memcmp(void const *s1, void const *s2, size_t n);

char	*map_up(char *str);

#endif
