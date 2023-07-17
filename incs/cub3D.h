/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   incs/cub3D.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael <mael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 15:45:40 by ggosse            #+#    #+#             */
/*   Updated: 2023/07/17 15:09:38 by mael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <dirent.h>
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <math.h>
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
#include <math.h>
#include "../minilibx/mlx.h"
#include <X11/keysym.h>
#include <X11/X.h>
// ---------------------------- end include --------------------------------- //

// ------------------------------ define ------------------------------------ //
# define SUCCESS 1
# define FAIL -1
// ---------------------------- end define ---------------------------------- //

// ------------------------------ struct ------------------------------------ //

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_line
{
	int		dx;
	int		dy;
	int		steps;
	float	xite;
	float	yite;
	float	corr_x;
	float	corr_y;
	int		x_src;
	int		y_src;
	int		x_dest;
	int		y_dest;
	int		x_dest_prev;
	int		y_dest_prev;
}	t_line;

typedef struct s_temp
{
	int		dx;
	int		dy;
	int		steps;
	float	xite;
	float	yite;
	float	corr_x;
	float	corr_y;
	int		x_src;
	int		y_src;
	int		x_dest;
	int		y_dest;
	int		x_dest_prev;
	int		y_dest_prev;
}	t_temp;

typedef struct s_line_3d
{
	int		dx;
	int		dy;
	int		steps;
	float	xite;
	float	yite;
	float	corr_x;
	float	corr_y;
	int		x_src;
	int		y_src;
	int		x_dest;
	int		y_dest;
	int		x_dest_prev;
	int		y_dest_prev;
}	t_line_3d;

typedef struct s_map
{
	char	*file_content;
	char	*file_map;
	char	**tab_file;
	char	**map_tmp;
	char	**map_org;
	char	*wall_no;
	char	*wall_ea;
	char	*wall_so;
	char	*wall_we;
	int		*floor;
	int		*ceil;
	int		height;
	int		width;
	int		pos_y;
	int		pos_x;
	int		count_step;
	int		fd_map;
}			t_map;

typedef struct s_fov
{
	int		**wall;
	int		*lines_vision;
	int		*toggle_vision;
	int		angle;
	int		nbr_ray;
	int		proj_plane;
	float	deg;
	char	toggle;
}			t_fov;

typedef struct s_game
{
	int			flag;
	int			view_angle;
	int			img_size;
	char		perso;
	void		*mlibx;
	void		*window;
	int			win_height;
	int			win_width;
	t_map		*map;
	t_img		*img;
	t_line		*line;
	t_fov		*fov;
	t_line_3d	*line_3d;
	t_temp		*temp;
}			t_game;
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
char	*ft_str_replace(char *src, char search, char replace);
char	*ft_strdup(const char *src);
char	*ft_strdup_len(char *str, int start, int end);
char	*ft_strdup_pad(char *src, int len, char pad);
//srcs/init_img.c
int		create_image_and_get_adrr(t_game *game);
int		init_img(t_game *game);
//srcs/player.c
void	draw_player(t_game *game);
int		ft_event_listen(int key, t_game *game);
void	set_pos_character(t_game *game);
//srcs/toggle.c
void	change_toggle_a(t_game *game);
void	change_toggle_d(t_game *game);
//srcs/start_3D.c
void	color_image(t_game *game);
void	do_quad(t_game *game, int i, int j);
void	fill_void(t_game *game, int i, int j);
void	fill_wall(t_game *game, int i, int j);
int		first_time(t_game *game);
void	reset_img(t_game *game);
int		start_3D(t_game *game);
//srcs/main.c
int		ft_parsing(t_game *game, char **argv);
void	init_struct(t_game *game);
int		open_fd(t_game *game, int *fd, char **argv);
void	print_map(char **arr);
//srcs/build_map.c
void	build_content(t_game *game, char **line, int fd);
int		build_map(t_game *game, char **argv);
int		create_map(t_game *game, char *line, int fd);
void	realloc_lines(t_game *game);
void	skip_empty_line(char **line, int fd);
//srcs/draw_line.c
double abs_dble(double nb);
float abs_flt(float nb);
int		absolute_value(int nb);
int		draw_line_vision(t_game *game, int color);
int		draw_pixel(t_game *game, int toggle, int x_check, int y_check, int color);
int		init_line(t_game *game);
//srcs/display_3d_up.c
int		display_3d_up(t_game *game);
void	fill_ceil_floor(t_game *game);
int		init_3d_line(t_game *game);
//srcs/pixel_and_color.c
int		get_color(int red, int green, int blue);
void	img_pix_put(t_game *game, int x, int y, int color);
void	img_pix_put_2(t_game *game, int x, int y, int color);
//srcs/check_format.c
void	check_corner(t_game *game);
//srcs/display_all_reverse.c
int		display_all_reverse_a(t_game *game, int key, int len_side);
int		display_all_reverse_d(t_game *g, int k, int l);
//srcs/valid_wall.c
int		check_letters_map(t_game *game);
int		check_perso(t_game *game);
int		hole_in_wall(t_game *game);
int		is_fault(t_game *game, int row, int col);
//srcs/free_parsing.c
int		destroy_and_free(t_game *game, char *err);
int		destroy_and_free2(t_game *game);
void	free_img(t_game *game);
void	free_parsing(t_game *game, char *err);
void	free_tab_str(char **tab_str);
//srcs/display_all.c
int		display_all(t_game *game, int key);
void	set_dest_e(t_game *game, int key, int len_side);
void	set_dest_n(t_game *game, int key, int len_side);
void	set_dest_s(t_game *game, int key, int len_side);
void	set_dest_w(t_game *game, int key, int len_side);
//srcs/check_file.c
int		check_env(char **envp);
int		check_ext(char *filename, char one, char two, char three);
int		wrong_letter_tx(char *line);
//srcs/move_w_s.c
int		calcul_corr_for_step(t_game *game);
void	init_direction_for_s(t_game *game);
void	init_direction_for_s_2(t_game *game);
void	move_s(t_game *game);
void	move_w(t_game *game);
//srcs/rotate.c
void	t(void);
//srcs/read_file.c
int		ft_buf_read(int fd, t_game *game);
int		ft_read_file(t_game *game, char *filename);
//srcs/texture_part_utils.c
int		check_tx(t_game *game);
void	print_word(char *new_w);
//srcs/convert.c
double deg_to_radian(double deg);
//srcs/floor_ceil_part.c
int		check_ceil(t_game *game, char *line);
int		check_ceil_content(t_game *game, char **color);
int		check_floor(t_game *game, char *line);
int		check_floor_content(t_game *game, char **color);
int		floor_ceil_part(t_game *game, char *line);
//srcs/texture_part.c
int		check_ea(t_game *game, char *line);
int		check_no(t_game *game, char *line);
int		check_so(t_game *game, char *line);
int		check_we(t_game *game, char *line);
int		texture_part(t_game *game, char *line);
//srcs/flooding.c
int		end_propa(t_game *game, int i_row, int i_col);
int		flooding(t_game *game);
int		is_propa_finished(t_game *game);
int		propagation(t_game *game, int row, int col, int count);
//srcs/fov.c
int		calcul_opposite_side(t_game *game, double angle);
int		first_calcul(t_game *game, double angle);
int		init_fov(t_game *game);
int		init_fov_wall(t_game *game);
void	init_position(t_game *game);
int		second_calcul(t_game *game, double angle);
//srcs/build_map_utils.c
int		check_nbr(char *str);
int		is_empty_line(char *line);
void	set_width(t_game *game);
int		tab_len(char **arr);
//srcs/display_3d_down.c
int		display_3d_down(t_game *game);
void	draw_line_temp(t_game *game, int flag_1, int flag_2, int flag_3, int flag_4);
int		init_temp(t_game *game);
//srcs/display_all_utils.c
int		init_display_all(t_game *game, int key, int *len_side);
void	move_straight(t_game *game);
//test.c

#endif