/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   incs/cub3D.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gael <gael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 15:45:40 by ggosse            #+#    #+#             */
/*   Updated: 2023/05/26 07:52:02 by gael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

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
#include "../libft/libft.h"
#include "color.h"
// ---------------------------- end include --------------------------------- //

// ------------------------------ define ------------------------------------ //
# define SUCCESS 1
# define FAIL -1
// ---------------------------- end define ---------------------------------- //

// ------------------------------ struct ------------------------------------ //

typedef struct s_map
{
	char	*file_content;
	char	**tab_file;
	char	**map_chck;
	char	*wall_no;
	char	*wall_ea;
	char	*wall_so;
	char	*wall_we;
	char	*floor;
	char	*ceil;
	int		h;
	int		w;
	int		p_y;
	int		p_x;
	int		count_step;
	int		fd_map;
}				t_map;

typedef struct s_game
{
	int		img_size;
	void	*mlibx;
	void	*window;
	t_map	*map;
}			t_game;
// ---------------------------- end struct ---------------------------------- //

//libft/ft_bzero.c
void	ft_bzero(void *str, size_t n);
//libft/ft_toupper.c
int		ft_toupper(int chr);
//libft/ft_substr.c
char	*ft_substr(char const *s, unsigned int start, size_t len);
//libft/ft_calloc.c
void	*ft_calloc(size_t nmemb, size_t size);
//libft/ft_printf.c
int		ft_conv(const char *str, int i, va_list args);
int		ft_int(char chr, int var);
int		ft_printf(const char *str, ...);
int		ft_uns(char chr, unsigned long long int var);
//libft/ft_putnbr_fd.c
int		ft_putnbr_fd(int nbr, int fd);
//libft/ft_lstnew_bonus.c
t_list *ft_lstnew(void *content);
//libft/ft_strnstr.c
char	*ft_strnstr(const char *big, const char *little, size_t len);
//libft/ft_atoi.c
int		ft_atoi(const char *str);
//libft/ft_lstadd_front_bonus.c
void	ft_lstadd_front(t_list **lst, t_list *new);
//libft/ft_memchr.c
void	*ft_memchr(const void *s, int c, size_t len);
//libft/ft_lstmap_bonus.c
t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
//libft/ft_putchar_fd.c
int		ft_putchar_fd(char c, int fd);
//libft/ft_strlen.c
size_t ft_strlen(const char *str);
//libft/ft_lstclear_bonus.c
void	ft_lstclear(t_list **lst, void (*del)(void *));
//libft/ft_lstdelone_bonus.c
void	ft_lstdelone(t_list *lst, void (*del)(void *));
//libft/ft_lstlast_bonus.c
t_list *ft_lstlast(t_list *lst);
//libft/ft_lstsize_bonus.c
int		ft_lstsize(t_list *lst);
//libft/ft_split.c
char	**ft_split(const char *str, char sep);
//libft/ft_isalpha.c
int		ft_isalpha(int c);
//libft/ft_strjoin.c
char	*ft_strjoin(char *s1, char const *s2);
char	*ft_strjoin_dfree(char *s1, char *s2);
char	*ft_strjoin_lfree(char *s1, char *s2);
char	*ft_strjoin_rfree(char *s1, char *s2);
//libft/ft_isdigit.c
int		ft_isdigit(int c);
//libft/ft_strncmp.c
int		ft_strncmp(const char *first, const char *second, size_t length);
//libft/ft_isascii.c
int		ft_isascii(int c);
//libft/ft_strlcpy.c
size_t ft_strlcpy(char *dst, const char *src, size_t size);
//libft/ft_putstr_fd.c
int		ft_putstr_fd(char *s, int fd);
//libft/ft_putunbr.c
int		ft_putunbr(unsigned long long int nbr);
//libft/ft_strdup.c
char	*ft_strdup(const char *src);
char	*ft_strdup_len(char *str, int start, int end);
//libft/ft_memmove.c
void	*ft_memmove(void *destination, const void *source, size_t n);
//libft/ft_strrchr.c
char	*ft_strrchr(const char *str, int search);
//libft/ft_memcmp.c
int		ft_memcmp(const void *s1, const void *s2, size_t n);
//libft/ft_tolower.c
int		ft_tolower(int chr);
//libft/ft_isprint.c
int		ft_isprint(int c);
//libft/ft_itoa.c
char	*ft_itoa(int nbr);
//libft/ft_strchr.c
char	*ft_strchr(const char *str, int search);
//libft/ft_strtrim.c
char	*ft_strtrim(const char *str, const char *set);
//libft/ft_putendl_fd.c
void	ft_putendl_fd(char *s, int fd);
//libft/ft_memcpy.c
void	*ft_memcpy(void *destination, const void *source, size_t size);
//libft/ft_isalnum.c
int		ft_isalnum(int c);
//libft/ft_putnbr_base_low.c
int		ft_putnbr_base_low(unsigned long long int nbr);
//libft/ft_memset.c
void	*ft_memset(void *str, int value, size_t len);
//libft/ft_lstadd_back_bonus.c
void	ft_lstadd_back(t_list **lst, t_list *new);
//libft/ft_tools.c
int		ft_putptr(unsigned long long int ptr);
void	ft_putptr_hexa(unsigned long long int ptr);
//libft/ft_striteri.c
void	ft_striteri(char *str, void (*f)(unsigned int, char*));
//libft/ft_lstiter_bonus.c
void	ft_lstiter(t_list *lst, void (*f)(void *));
//libft/ft_putnbr_base_up.c
int		ft_putnbr_base_up(unsigned long long int nbr);
//libft/ft_strlcat.c
size_t ft_strlcat(char *dst, const char *src, size_t size);
//libft/ft_strmapi.c
char	*ft_strmapi(const char *str, char (*f)(unsigned int, char));
//srcs/main.c
int		ft_parsing(t_game *game, char **argv);
void	init_struct(t_game *game);
int		is_empty_line(char *line);
//srcs/free_parsing.c
void	free_img(t_game *game);
void	ft_free_parsing(t_game *game, char *err);
void	ft_free_tab_str(char **tab_str);
//srcs/texture_part_utils.c
int		check_tx(t_game *game);
//srcs/valid_wall.c
int		ft_propagation(t_game *game);
int		ft_replace_around(t_game *game, int ite_big, int ite_lil);
int		ft_valid_wall(t_game *game);
//srcs/read_file.c
int		ft_buf_read(int fd, t_game *game);
int		ft_read_file(t_game *game, char *filename);
//srcs/texture_part.c
int		check_ea(t_game *game, char *line);
int		check_no(t_game *game, char *line);
int		check_so(t_game *game, char *line);
int		check_we(t_game *game, char *line);
int		texture_part(t_game *game, char *line);
//srcs/check_file.c
int		ft_check_env(char **envp);
int		ft_check_ext(char *filename, char one, char two, char three);
int		wrong_letter_tx(char *line);
//srcs/floor_ceil_part.c
int		check_ceil(t_game *game, char *line);
int		check_floor(t_game *game, char *line);
int		floor_ceil_part(t_game *game, char *line);

#endif