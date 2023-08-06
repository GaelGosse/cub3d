/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3D_2.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gael <gael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 11:38:30 by mael              #+#    #+#             */
/*   Updated: 2023/06/28 08:00:35 by gael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CUB3D_2_H
# define FT_CUB3D_2_H

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
// ---------------------------- end struct ---------------------------------- //

//libft/ft_isdigit.c
int		ft_isdigit(int c);
//libft/ft_isascii.c
int		ft_isascii(int c);
//libft/ft_lstlast_bonus.c
t_list *ft_lstlast(t_list *lst);
//libft/ft_strlcpy.c
size_t ft_strlcpy(char *dst, const char *src, size_t size);
//libft/ft_strchr.c
char	*ft_strchr(const char *str, int search);
//libft/ft_strrchr.c
char	*ft_strrchr(const char *str, int search);
//libft/ft_isalnum.c
int		ft_isalnum(int c);
//libft/ft_isalpha.c
int		ft_isalpha(int c);
//libft/ft_putnbr_fd.c
int		ft_putnbr_fd(int nbr, int fd);
//libft/ft_strtrim.c
char	*ft_strtrim(const char *str, const char *set);
//libft/ft_substr.c
char	*ft_substr(char const *s, unsigned int start, size_t len);
//libft/ft_putstr_fd.c
int		ft_putstr_fd(char *s, int fd);
//libft/ft_strncmp.c
int		ft_strncmp(const char *first, const char *second, size_t length);
//libft/ft_strlcat.c
size_t ft_strlcat(char *dst, const char *src, size_t size);
//libft/ft_memcpy.c
void	*ft_memcpy(void *destination, const void *source, size_t size);
//libft/ft_lstadd_back_bonus.c
void	ft_lstadd_back(t_list **lst, t_list *new);
//libft/ft_lstdelone_bonus.c
void	ft_lstdelone(t_list *lst, void (*del)(void *));
//libft/ft_putnbr_base_up.c
int		ft_putnbr_base_up(unsigned long long int nbr);
//libft/ft_tolower.c
int		ft_tolower(int chr);
//libft/ft_memset.c
void	*ft_memset(void *str, int value, size_t len);
//libft/ft_memcmp.c
int		ft_memcmp(const void *s1, const void *s2, size_t n);
//libft/ft_atoi.c
int		ft_atoi(const char *str);
//libft/ft_lstclear_bonus.c
void	ft_lstclear(t_list **lst, void (*del)(void *));
//libft/ft_gnl.c
char	*gnl(int fd);
//libft/ft_putchar_fd.c
int		ft_putchar_fd(char c, int fd);
//libft/ft_lstnew_bonus.c
t_list *ft_lstnew(void *content);
//libft/ft_tools.c
int		ft_putptr(unsigned long long int ptr);
void	ft_putptr_hexa(unsigned long long int ptr);
//libft/ft_strjoin.c
char	*ft_strjoin(char *s1, char const *s2);
char	*ft_strjoin_dfree(char *s1, char *s2);
char	*ft_strjoin_lfree(char *s1, char *s2);
char	*ft_strjoin_rfree(char *s1, char *s2);
//libft/ft_lstsize_bonus.c
int		ft_lstsize(t_list *lst);
//libft/ft_lstadd_front_bonus.c
void	ft_lstadd_front(t_list **lst, t_list *new);
//libft/ft_printf.c
int		ft_conv(const char *str, int i, va_list args);
int		ft_int(char chr, int var);
int		ft_printf(const char *str, ...);
int		ft_uns(char chr, unsigned long long int var);
//libft/ft_striteri.c
void	ft_striteri(char *str, void (*f)(unsigned int, char*));
//libft/ft_isprint.c
int		ft_isprint(int c);
//libft/ft_strlen.c
size_t ft_strlen(const char *str);
size_t ft_tablen(char **tab);
//libft/ft_bzero.c
void	ft_bzero(void *str, size_t n);
//libft/ft_itoa.c
char	*ft_itoa(int nbr);
//libft/ft_strmapi.c
char	*ft_strmapi(const char *str, char (*f)(unsigned int, char));
//libft/ft_split.c
char	**ft_split(const char *str, char sep);
//libft/ft_strnstr.c
char	*ft_strnstr(const char *big, const char *little, size_t len);
//libft/ft_lstiter_bonus.c
void	ft_lstiter(t_list *lst, void (*f)(void *));
//libft/ft_putendl_fd.c
void	ft_putendl_fd(char *s, int fd);
//libft/ft_putunbr.c
int		ft_putunbr(unsigned long long int nbr);
//libft/ft_lstmap_bonus.c
t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
//libft/ft_calloc.c
void	*ft_calloc(size_t nmemb, size_t size);
//libft/ft_toupper.c
int		ft_toupper(int chr);
//libft/ft_memmove.c
void	*ft_memmove(void *destination, const void *source, size_t n);
//libft/ft_memchr.c
void	*ft_memchr(const void *s, int c, size_t len);
//libft/ft_putnbr_base_low.c
int		ft_putnbr_base_low(unsigned long long int nbr);
//libft/ft_strdup.c
char	*ft_strdup(const char *src);
char	*ft_strdup_len(char *str, int start, int end);
//srcs/init_img.c
int		create_image_and_get_adrr(t_game *game);
int		init_img(t_game *game);
//srcs/start_3D.c
int		start_3D(t_game *game);
//srcs/main.c
int		build_map(t_game *game, char **argv);
int		ft_parsing(t_game *game, char **argv);
void	init_struct(t_game *game);
int		is_empty_line(char *line);
void	set_width(t_game *game);
//srcs/build_map.c
int		create_map(t_game *game, char *line, int fd);
int		tab_len(char **arr);
//srcs/draw_line.c
int		absolute_value(int nb);
void	draw_line(t_game *game, int i, int j);
int		init_line(t_game *game);
int		put_line_in_img(t_game *game);
//srcs/valid_wall.c
int		check_letters_map(t_game *game);
int		check_perso(t_game *game);
int		hole_in_wall(t_game *game);
//srcs/free_parsing.c
void	free_img(t_game *game);
void	free_parsing(t_game *game, char *err);
void	free_tab_str(char **tab_str);
//srcs/check_file.c
int		check_env(char **envp);
int		check_ext(char *filename, char one, char two, char three);
int		wrong_letter_tx(char *line);
//srcs/read_file.c
int		ft_buf_read(int fd, t_game *game);
int		ft_read_file(t_game *game, char *filename);
//srcs/texture_part_utils.c
int		check_tx(t_game *game);
void	print_word(char *new_w);
//srcs/floor_ceil_part.c
int		check_ceil(t_game *game, char *line);
int		check_floor(t_game *game, char *line);
int		floor_ceil_part(t_game *game, char *line);
//srcs/texture_part.c
int		check_ea(t_game *game, char *line);
int		check_no(t_game *game, char *line);
int		check_so(t_game *game, char *line);
int		check_we(t_game *game, char *line);
int		texture_part(t_game *game, char *line);
//buffer/put_square.c
int		create_square(t_game *game);
int		draw_square(t_game *game);
void	img_pix_put_2(t_game *game, int x, int y, int color);
int		init_square(t_game *game);
int		put_square_in_window(t_game *game);
void	set_pos_character(t_game *game);
//buffer/tab_img.c
void	color_image(t_game *game);
int		create_img(t_game *game);
void	fill_square(t_game *game, int color, int i, int j);
int		ft_event_listen(int key, t_game *game);
int		get_color(int red, int green, int blue);
void	img_pix_put(t_game *game, int x, int y, int color, int i, int j);
int		init_tab_img(t_game *game);
int		start_3d(t_game *game);
int		tab_img_to_window(t_game *game);

#endif