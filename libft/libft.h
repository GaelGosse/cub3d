/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gael <gael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 19:28:51 by ggosse            #+#    #+#             */
/*   Updated: 2023/06/01 11:47:41 by gael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <dirent.h>
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <pthread.h>
# include <sys/types.h>
# include <sys/time.h>
# include <sys/resource.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <sys/ioctl.h>
# include <signal.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <termios.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>

// ------------------------------ include ----------------------------------- //
// ---------------------------- end include --------------------------------- //

// ------------------------------ define ------------------------------------ //
// ---------------------------- end define ---------------------------------- //

// ------------------------------ struct ------------------------------------ //

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;
// ---------------------------- end struct ---------------------------------- //

//ft_bzero.c
void	ft_bzero(void *str, size_t n);
//ft_toupper.c
int		ft_toupper(int chr);
//ft_substr.c
char	*ft_substr(char const *s, unsigned int start, size_t len);
//ft_calloc.c
void	*ft_calloc(size_t nmemb, size_t size);
//ft_printf.c
int		ft_conv(const char *str, int i, va_list args);
int		ft_int(char chr, int var);
int		ft_printf(const char *str, ...);
int		ft_uns(char chr, unsigned long long int var);
//ft_putnbr_fd.c
int		ft_putnbr_fd(int nbr, int fd);
//ft_lstnew_bonus.c
t_list	*ft_lstnew(void *content);
//ft_strnstr.c
char	*ft_strnstr(const char *big, const char *little, size_t len);
//ft_atoi.c
int		ft_atoi(const char *str);
//ft_lstadd_front_bonus.c
void	ft_lstadd_front(t_list **lst, t_list *new);
//ft_memchr.c
void	*ft_memchr(const void *s, int c, size_t len);
//ft_lstmap_bonus.c
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
//ft_putchar_fd.c
int		ft_putchar_fd(char c, int fd);
//ft_strlen.c
size_t ft_strlen(const char *str);
size_t ft_tablen(char **tab);
//ft_lstclear_bonus.c
void	ft_lstclear(t_list **lst, void (*del)(void *));
//ft_lstdelone_bonus.c
void	ft_lstdelone(t_list *lst, void (*del)(void *));
//ft_lstlast_bonus.c
t_list	*ft_lstlast(t_list *lst);
//ft_lstsize_bonus.c
int		ft_lstsize(t_list *lst);
//ft_split.c
char	**ft_split(const char *str, char sep);
//ft_isalpha.c
int		ft_isalpha(int c);
//ft_strjoin.c
char	*ft_strjoin(char *s1, char const *s2);
char	*ft_strjoin_dfree(char *s1, char *s2);
char	*ft_strjoin_lfree(char *s1, char *s2);
char	*ft_strjoin_rfree(char *s1, char *s2);
//ft_isdigit.c
int		ft_isdigit(int c);
//ft_strncmp.c
int		ft_strncmp(const char *first, const char *second, size_t length);
//ft_isascii.c
int		ft_isascii(int c);
//ft_strlcpy.c
size_t ft_strlcpy(char *dst, const char *src, size_t size);
//ft_putstr_fd.c
int		ft_putstr_fd(char *s, int fd);
//ft_putunbr.c
int		ft_putunbr(unsigned long long int nbr);
//ft_strdup.c
char	*ft_strdup(const char *src);
char	*ft_strdup_len(char *str, int start, int end);
//ft_memmove.c
void	*ft_memmove(void *destination, const void *source, size_t n);
//ft_strrchr.c
char	*ft_strrchr(const char *str, int search);
//ft_memcmp.c
int		ft_memcmp(const void *s1, const void *s2, size_t n);
//ft_tolower.c
int		ft_tolower(int chr);
//ft_isprint.c
int		ft_isprint(int c);
//ft_itoa.c
char	*ft_itoa(int nbr);
//ft_strchr.c
char	*ft_strchr(const char *str, int search);
//ft_strtrim.c
char	*ft_strtrim(const char *str, const char *set);
//ft_putendl_fd.c
void	ft_putendl_fd(char *s, int fd);
//ft_memcpy.c
void	*ft_memcpy(void *destination, const void *source, size_t size);
//ft_isalnum.c
int		ft_isalnum(int c);
//ft_putnbr_base_low.c
int		ft_putnbr_base_low(unsigned long long int nbr);
//ft_memset.c
void	*ft_memset(void *str, int value, size_t len);
//ft_lstadd_back_bonus.c
void	ft_lstadd_back(t_list **lst, t_list *new);
//ft_tools.c
int		ft_putptr(unsigned long long int ptr);
void	ft_putptr_hexa(unsigned long long int ptr);
//ft_striteri.c
void	ft_striteri(char *str, void (*f)(unsigned int, char*));
//ft_lstiter_bonus.c
void	ft_lstiter(t_list *lst, void (*f)(void *));
//ft_putnbr_base_up.c
int		ft_putnbr_base_up(unsigned long long int nbr);
//ft_strlcat.c
size_t ft_strlcat(char *dst, const char *src, size_t size);
//ft_strmapi.c
char	*ft_strmapi(const char *str, char (*f)(unsigned int, char));

#endif