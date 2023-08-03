/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   incs/cub3D.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael <mael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 15:45:40 by ggosse            #+#    #+#             */
/*   Updated: 2023/08/03 16:15:32 by mael             ###   ########.fr       */
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

typedef struct s_xpm
{
	char	*no_file_content;
	char	*no_file_map;
	char	**no_tab_file;
	int		**no_colors;
	int		*no_metadata;
	int		no_width_height;
	int		no_tab_start;
	char	*ea_file_content;
	char	*ea_file_map;
	char	**ea_tab_file;
	int		**ea_colors;
	int		*ea_metadata;
	int		ea_width_height;
	int		ea_tab_start;
	char	*we_file_content;
	char	*we_file_map;
	char	**we_tab_file;
	int		**we_colors;
	int		*we_metadata;
	int		we_width_height;
	int		we_tab_start;
	char	*so_file_content;
	char	*so_file_map;
	char	**so_tab_file;
	int		**so_colors;
	int		*so_metadata;
	int		so_width_height;
	int		so_tab_start;
}	t_xpm;

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
	double	xite;
	double	yite;
	double	corr_x;
	double	corr_y;
	int		x_src;
	int		y_src;
	int		x_dest;
	int		y_dest;
	int		x_dest_prev;
	int		y_dest_prev;
	int		check_x;
	int		check_y;
	int		new_x;
	int		new_y;
}	t_line;

typedef struct s_temp
{
	int		dx;
	int		dy;
	int		steps;
	double	xite;
	double	yite;
	double	corr_x;
	double	corr_y;
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
	double	xite;
	double	yite;
	double	corr_x;
	double	corr_y;
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
	int		north;
	int		south;
	int		east;
	int		west;
}			t_map;

typedef struct s_fov
{
	double	**wall_witch;
	int		**wall;
	int		*lines_vision;
	int		*toggle_vision;
	int		angle;
	int		nbr_ray;
	int		proj_plane;
	double	deg;
	char	toggle;
}			t_fov;

typedef struct s_game
{
	int			display_all_save_src_x;
	int			display_all_save_src_y;
	int			display_all_save_x;
	int			display_all_save_y;
	double		display_all_angle;
	double		display_all_angle_2;
	int			display_all_i_rotate;
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
	t_xpm		*xpm;
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
//srcs/draw_xpm_ud.c
int		draw_xpm_down_blue(t_game *game, int i_midline);
int		draw_xpm_down_red(t_game *game, int i_midline);
int		draw_xpm_up_blue(t_game *game, int i_midline);
int		draw_xpm_up_red(t_game *game, int i_midline);
//srcs/init_img.c
int		create_image_and_get_adrr(t_game *game);
int		init_img(t_game *game);
//srcs/player.c
int		ft_event_listen(int key, t_game *game);
void	set_pos_character(t_game *game);
//srcs/start_3D.c
int		first_time(t_game *game);
void	reset_img(t_game *game);
int		start_3d(t_game *game);
//srcs/tools.c
double abs_dble(double nb);
double abs_flt(double nb);
int		absolute_value(int nb);
double deg_to_radian(double deg);
int		hex_to_dec(char *hexa);
//srcs/main.c
int		ft_parsing(t_game *game, char **argv);
void	init_struct(t_game *game);
int		open_fd(t_game *game, int *fd, char **argv);
//srcs/build_map.c
void	build_content(t_game *game, char **line, int fd);
int		build_map(t_game *game, char **argv, int count, int fd);
int		create_map(t_game *game, char *line, int fd);
void	realloc_lines(t_game *game);
void	skip_empty_line(char **line, int fd);
//srcs/draw_line.c
int		check_lines_hit_wall(t_game *game, int x_check, int y_check, int toggle);
int		draw_line_vision(t_game *game);
int		draw_pixel(t_game *game, int toggle);
int		init_line(t_game *game);
//srcs/display_3d_up.c
void	display_3d_up(t_game *game);
void	display_3d_up_red(t_game *game, int i_main);
void	fill_ceil_floor(t_game *game);
void	fill_ceil_floor_2(t_game *game);
int		init_3d_line(t_game *game);
//srcs/xpm_we_parse.c
int		xpm_we_get_content_xpm(t_game *game, int fd, int ret, char *buf);
int		xpm_we_parse(t_game *game);
int		xpm_we_read(t_game *game, char *filename);
int		xpm_we_split_buf(int fd, t_game *game);
//srcs/xpm_no_parse.c
int		xpm_no_get_content_xpm(t_game *game, int fd, int ret, char *buf);
int		xpm_no_parse(t_game *game);
int		xpm_no_read(t_game *game, char *filename);
int		xpm_no_split_buf(int fd, t_game *game);
//srcs/pixel_and_color.c
int		get_color(int red, int green, int blue);
void	img_pix_put(t_game *game, int x, int y, int color);
//srcs/draw_xpm_up_no.c
void	draw_xpm_up_no(t_game *g, int i_midline);
int		draw_xpm_up_no_color(t_game *game, int x, int y);
//srcs/draw_xpm_down_so.c
void	draw_xpm_down_so(t_game *game, int i_midline);
int		draw_xpm_so_color(t_game *game, int x, int y);
//srcs/key_tools.c
int		calcul_step_for_key_a(t_game *game);
int		calcul_step_for_key_d(t_game *game);
void	check_for_wall_a(t_game *game);
void	check_for_wall_d(t_game *game);
//srcs/draw_xpm_up_ea.c
void	draw_xpm_up_ea(t_game *game, int i_midline);
int		draw_xpm_up_ea_color(t_game *game, int x, int y);
//srcs/check_format.c
void	check_corner(t_game *game);
void	check_wall_in_map_1(t_game *game, int i_big, int i_lil);
void	check_wall_in_map_2(t_game *game, int i_big, int i_lil);
//srcs/xpm_so_parse.c
int		xpm_so_get_content_xpm(t_game *game, int fd, int ret, char *buf);
int		xpm_so_parse(t_game *game);
int		xpm_so_read(t_game *game, char *filename);
int		xpm_so_split_buf(int fd, t_game *game);
//srcs/xpm_no_colors.c
int		xpm_no_check_line_color(t_game *g, int *i_chr, int i_tab_file, int i_color);
int		xpm_no_hex_to_dec(t_game *g, int i_color, int i_tab_file, int i_chr);
int		xpm_no_letter_color(t_game *game, int i_color, int i_tab_file);
int		xpm_no_set_color(t_game *game, int i_color, char *tmp);
int		xpm_no_set_len_n_color(t_game *g, char **line);
//srcs/xpm_we_utils.c
int		xpm_we_check_wh(t_game *game);
void	xpm_we_fill_metadata(t_game *game, char **line);
int		xpm_we_init_color(t_game *g);
char	*xpm_we_keep_metadata(char **tmp, int i_tmp);
//srcs/draw_xpm_up_so.c
void	draw_xpm_up_so(t_game *g, int i_midline);
int		draw_xpm_up_so_color(t_game *game, int x, int y);
//srcs/valid_wall.c
int		check_letters_map(t_game *game);
int		check_perso(t_game *game);
int		hole_in_wall(t_game *game);
int		is_fault(t_game *game, int row, int col);
//srcs/draw_xpm_ud_utils.c
void	adjust_line_3d(t_game *game);
void	draw_xpm_if_blue(t_game *game, int i);
void	draw_xpm_if_red(t_game *game, int i);
//srcs/free_parsing.c
int		destroy_and_free(t_game *game, char *err);
int		destroy_and_free2(t_game *game);
void	free_parsing(t_game *game, char *err);
void	free_tab_str(char **tab_str);
void	free_wall(t_game *game);
//srcs/xpm_we_colors.c
int		xpm_we_check_line_color(t_game *g, int *i_chr, int i_tab_file, int i_color);
int		xpm_we_hex_to_dec(t_game *g, int i_color, int i_tab_file, int i_chr);
int		xpm_we_letter_color(t_game *game, int i_color, int i_tab_file);
int		xpm_we_set_color(t_game *game, int i_color, char *tmp);
int		xpm_we_set_len_n_color(t_game *g, char **line);
//srcs/xpm_ea_correction.c
int		xpm_ea_copy_tab(t_game *game, char **tmp);
int		xpm_ea_correct(t_game *g);
int		xpm_ea_read_1line(t_game *game);
int		xpm_ea_wo_comm(t_game *g, int n_comm);
//srcs/display_all_blue.c
void	display_all_blue(t_game *g, int i_rotate, int len_vision);
void	display_all_blue_first(t_game *game, int i_rotate, int len_vision);
void	display_all_blue_second(t_game *game, int i_rotate, int len_vision);
//srcs/key_move.c
int		key_is_a(t_game *game, int key);
int		key_is_d(t_game *game, int key);
void	key_is_s(t_game *game, int key);
void	key_is_w(t_game *g, int key);
//srcs/display_all.c
int		display_all(t_game *g, int key);
void	last_correct_toggle(t_game *game);
void	mid_display_all(t_game *game, int i_rotate, int len_vision);
void	set_toggle(t_game *g, int i_rotate);
//srcs/check_file.c
int		check_env(char **envp);
int		check_ext(char *filename, char one, char two, char three);
int		wrong_letter_tx(char *line);
//srcs/xpm_no_utils.c
int		xpm_no_check_wh(t_game *game);
void	xpm_no_fill_metadata(t_game *game, char **line);
int		xpm_no_init_color(t_game *game, char **line);
char	*xpm_no_keep_metadata(char **tmp, int i_tmp);
//srcs/xpm_we_correction.c
int		xpm_we_copy_tab(t_game *game, char **tmp);
int		xpm_we_correct(t_game *g);
int		xpm_we_read_1line(t_game *game);
int		xpm_we_wo_comm(t_game *g, int n_comm);
//srcs/move_w_s.c
int		calcul_corr_for_step(t_game *game);
void	init_direction_for_s(t_game *game);
void	init_direction_for_s_2(t_game *game);
void	move_s(t_game *game);
void	move_w(t_game *game);
//srcs/key_rotate.c
void	key_rotate_left(t_game *game, int key);
void	key_rotate_right(t_game *game, int key);
//srcs/xpm_common.c
void	init_second_xpm(t_game *game);
int		init_xpm(t_game *game);
int		is_space(char chr);
int		xpm_check_width(t_game *game);
int		xpm_parse(t_game *game);
//srcs/xpm_so_colors.c
int		xpm_so_check_line_color(t_game *g, int *i_chr, int i_tab_file, int i_color);
int		xpm_so_hex_to_dec(t_game *g, int i_color, int i_tab_file, int i_chr);
int		xpm_so_letter_color(t_game *game, int i_color, int i_tab_file);
int		xpm_so_set_color(t_game *game, int i_color, char *tmp);
int		xpm_so_set_len_n_color(t_game *g, char **line);
//srcs/read_file.c
int		ft_buf_read(int fd, t_game *game);
int		ft_read_file(t_game *game, char *filename);
//srcs/free_xpm_2.c
void	free_tab_colors_ea(t_game *game, int i);
void	free_tab_colors_no(t_game *game, int i);
void	free_tab_colors_so(t_game *game, int i);
void	free_tab_colors_we(t_game *game, int i);
//srcs/draw_xpm_down_no.c
void	draw_xpm_down_no(t_game *game, int i_midline);
int		draw_xpm_no_color(t_game *game, int x, int y);
//srcs/draw_xpm_up_we.c
void	draw_xpm_up_we(t_game *g, int i_midline);
int		draw_xpm_up_we_color(t_game *game, int x, int y);
//srcs/texture_part_utils.c
int		check_tx(t_game *game);
//srcs/display_3d_up_utils.c
void	draw_line_3d_up(t_game *game, int i_main, int i_midline);
void	i_draw_up_blue(t_game *game, int i_midline);
void	i_draw_up_red(t_game *game, int i_midline);
//srcs/draw_xpm_down_we.c
void	draw_xpm_down_we(t_game *game, int i_midline);
int		draw_xpm_we_color(t_game *game, int x, int y);
//srcs/display_3d_down_utils.c
void	draw_line_3d_down(t_game *game, int i_main, int i_midline);
void	i_draw_blue(t_game *game, int i_midline);
void	i_draw_red(t_game *game, int i_midline);
//srcs/display_all_red.c
void	display_all_red(t_game *game, int i_rotate, int len_vision);
void	display_all_red_first(t_game *game, int i_rotate, int len_vision);
void	display_all_red_second(t_game *game, int i_rotate, int len_vision);
void	display_all_red_third(t_game *game, int i_rotate, int len_vision);
//srcs/floor_ceil_part.c
int		check_ceil(t_game *game, char *line, char *color);
int		check_ceil_content(t_game *game, char **color);
int		check_floor(t_game *game, char *line, char *color);
int		check_floor_content(t_game *g, char **color);
int		floor_ceil_part(t_game *game, char *line);
//srcs/texture_part.c
int		check_ea(t_game *game, char *line);
int		check_no(t_game *game, char *line);
int		check_so(t_game *game, char *line);
int		check_we(t_game *game, char *line);
int		texture_part(t_game *game, char *line);
//srcs/xpm_ea_utils.c
int		xpm_ea_check_wh(t_game *game);
void	xpm_ea_fill_metadata(t_game *game, char **line);
int		xpm_ea_init_color(t_game *game, char **line);
char	*xpm_ea_keep_metadata(char **tmp, int i_tmp);
//srcs/flooding.c
int		flooding(t_game *game);
int		is_propa_finished(t_game *game);
int		propagation(t_game *game, int row, int col, int count);
//srcs/xpm_so_utils.c
int		xpm_so_check_wh(t_game *game);
void	xpm_so_fill_metadata(t_game *game, char **line);
int		xpm_so_init_color(t_game *game, char **line);
char	*xpm_so_keep_metadata(char **tmp, int i_tmp);
//srcs/fov.c
int		init_fov(t_game *game);
int		init_fov_wall(t_game *game);
int		init_fov_wall_witch(t_game *game);
void	init_position(t_game *game);
//srcs/free_xpm.c
void	free_xpm(t_game *game);
void	free_xpm_ea(t_game *game, int i);
void	free_xpm_no(t_game *game, int i);
void	free_xpm_so(t_game *game, int i);
void	free_xpm_we(t_game *game, int i);
//srcs/xpm_no_correction.c
int		xpm_no_copy_tab(t_game *game, char **tmp);
int		xpm_no_correct(t_game *g);
int		xpm_no_read_1line(t_game *game);
int		xpm_no_wo_comm(t_game *g, int n_comm);
//srcs/free_all.c
int		free_all(t_game *game);
int		free_ceil_floor(t_game *game);
void	free_fov(t_game *game);
//srcs/xpm_so_correction.c
int		xpm_so_copy_tab(t_game *game, char **tmp);
int		xpm_so_correct(t_game *g);
int		xpm_so_read_1line(t_game *game);
int		xpm_so_wo_comm(t_game *g, int n_comm);
//srcs/draw_xpm_down_ea.c
void	draw_xpm_down_ea(t_game *game, int i_midline);
int		draw_xpm_ea_color(t_game *game, int x, int y);
//srcs/xpm_ea_colors.c
int		xpm_ea_check_line_color(t_game *g, int *i_chr, int i_tab_file, int i_color);
int		xpm_ea_hex_to_dec(t_game *g, int i_color, int i_tab_file, int i_chr);
int		xpm_ea_letter_color(t_game *game, int i_color, int i_tab_file);
int		xpm_ea_set_color(t_game *game, int i_color, char *tmp);
int		xpm_ea_set_len_n_color(t_game *g, char **line);
//srcs/build_map_utils.c
int		check_nbr(char *str);
int		is_empty_line(char *line);
void	set_width(t_game *game);
int		tab_len(char **arr);
//srcs/display_3d_down.c
void	display_3d(t_game *game);
void	display_3d_down(t_game *game);
void	display_3d_down_red(t_game *game, int i_main);
//srcs/xpm_ea_parse.c
int		xpm_ea_get_content_xpm(t_game *game, int fd, int ret, char *buf);
int		xpm_ea_parse(t_game *game);
int		xpm_ea_read(t_game *game, char *filename);
int		xpm_ea_split_buf(int fd, t_game *game);
//srcs/angle_len.c
void	angle_1(t_game *game, double angle_2, int len_vision);
void	angle_3(t_game *game, double angle_2, int len_vision);
void	angle_4(t_game *game, double angle_2, int len_vision);
//srcs/display_all_utils.c
int		init_display_all(t_game *game, int key, int *len_side);
void	move_straight(t_game *game);
void	rotate_new(t_game *game);

#endif