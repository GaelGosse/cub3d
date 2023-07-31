/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   incs/cub3D.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gael <gael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 15:45:40 by ggosse            #+#    #+#             */
/*   Updated: 2023/07/31 17:08:17 by gael             ###   ########.fr       */
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
	int		no_width_height;
	int		no_tab_start;
	char	*ea_file_content;
	char	*ea_file_map;
	char	**ea_tab_file;
	int		**ea_colors;
	int		ea_width_height;
	int		ea_tab_start;
	char	*we_file_content;
	char	*we_file_map;
	char	**we_tab_file;
	int		**we_colors;
	int		we_width_height;
	int		we_tab_start;
	char	*so_file_content;
	char	*so_file_map;
	char	**so_tab_file;
	int		**so_colors;
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

//srcs/xpm_no_open.c
void	xpm_no_hex_to_dec(t_game *g, int i_color, int i_tab_file);
char	*xpm_no_keep_metadata(char **tmp, int i_tmp);
int		xpm_no_letter_color(t_game *game, int i_color, int i_tab_file);
int		xpm_no_set_color(t_game *game, int i_color, char *tmp);
//srcs/xpm_so_parse.c
int		xpm_so_get_content_xpm(t_game *game, int fd, int ret, char *buf);
int		xpm_so_parse(t_game *game);
int		xpm_so_read(t_game *game, char *filename);
int		xpm_so_split_buf(int fd, t_game *game);
//srcs/draw_xpm_ud.c
int		draw_xpm_down_blue(t_game *game, int i_midline);
int		draw_xpm_down_red(t_game *game, int i_midline);
int		draw_xpm_up_blue(t_game *game, int i_midline);
int		draw_xpm_up_red(t_game *game, int i_midline);
//srcs/free_xpm_no.c
void	free_xpm(t_game *game);
void	free_xpm_ea(t_game *game);
void	free_xpm_no(t_game *game);
void	free_xpm_so(t_game *game);
void	free_xpm_we(t_game *game);
//srcs/main.c
int		ft_parsing(t_game *game, char **argv);
void	init_struct(t_game *game);
int		open_fd(t_game *game, int *fd, char **argv);
void	print_map(char **arr);
//srcs/pixel_and_color.c
int		get_color(int red, int green, int blue);
void	img_pix_put(t_game *game, int x, int y, int color);
void	img_pix_put_2(t_game *game, int x, int y, int color);
//srcs/xpm_we_correction.c
int		xpm_we_copy_tab(t_game *game, char **tmp);
void	xpm_we_correct(t_game *g);
int		xpm_we_read_1line(t_game *game);
int		xpm_we_set_len_n_color(t_game *g, char **line);
void	xpm_we_wo_comm(t_game *g, int n_comm);
//srcs/start_3D.c
void	color_image(t_game *game);
void	do_quad(t_game *game, int i, int j);
void	fill_void(t_game *game, int i, int j);
void	fill_wall(t_game *game, int i, int j);
int		first_time(t_game *game);
void	reset_img(t_game *game);
int		start_3D(t_game *game);
//srcs/draw_xpm_down_ea.c
void	draw_xpm_down_ea(t_game *game, int i_midline);
int		draw_xpm_ea_color(t_game *game, int x, int y);
//srcs/draw_line.c
double	abs_dble(double nb);
double	abs_flt(double nb);
int		absolute_value(int nb);
int		draw_line_vision(t_game *game, int color);
int		draw_pixel(t_game *game, int toggle, int x_check, int y_check, int color);
int		init_line(t_game *game);
//srcs/free_parsing.c
int		destroy_and_free(t_game *game, char *err);
int		destroy_and_free2(t_game *game);
void	free_img(t_game *game);
void	free_parsing(t_game *game, char *err);
void	free_tab_str(char **tab_str);
//srcs/display_3d_up.c
int		display_3d_up(t_game *game);
void	fill_ceil_floor(t_game *game);
int		init_3d_line(t_game *game);
//srcs/free_all.c
int		free_all(t_game *game);
int		free_ceil_floor(t_game *game);
void	free_fov(t_game *game);
//srcs/xpm_so_correction.c
int		xpm_so_copy_tab(t_game *game, char **tmp);
void	xpm_so_correct(t_game *g);
int		xpm_so_read_1line(t_game *game);
int		xpm_so_set_len_n_color(t_game *g, char **line);
void	xpm_so_wo_comm(t_game *g, int n_comm);
//srcs/display_all_reverse.c
int		display_all_reverse_a(t_game *game, int key, int len_side);
int		display_all_reverse_d(t_game *g, int k, int l);
//srcs/flooding.c
int		end_propa(t_game *game, int i_row, int i_col);
int		flooding(t_game *game);
int		is_propa_finished(t_game *game);
int		propagation(t_game *game, int row, int col, int count);
//srcs/texture_part_utils.c
int		check_tx(t_game *game);
void	print_word(char *new_w);
//srcs/valid_wall.c
int		check_letters_map(t_game *game);
int		check_perso(t_game *game);
int		hole_in_wall(t_game *game);
int		is_fault(t_game *game, int row, int col);
//srcs/convert.c
double	deg_to_radian(double deg);
int		hex_to_dec(char *hexa);
//srcs/rotate.c
void	t(void);
//srcs/build_map.c
void	build_content(t_game *game, char **line, int fd);
int		build_map(t_game *game, char **argv);
int		create_map(t_game *game, char *line, int fd);
void	realloc_lines(t_game *game);
void	skip_empty_line(char **line, int fd);
//srcs/read_file.c
int		ft_buf_read(int fd, t_game *game);
int		ft_read_file(t_game *game, char *filename);
//srcs/display_3d_down.c
int		display_3d_down(t_game *game);
void	draw_line_temp(t_game *game, int flag_1, int flag_2, int flag_3, int flag_4);
int		init_temp(t_game *game);
//srcs/fov.c
int		calcul_opposite_side(t_game *game, double angle);
int		first_calcul(t_game *game, double angle);
int		init_fov(t_game *game);
int		init_fov_wall(t_game *game);
int		init_fov_wall_witch(t_game *game);
void	init_position(t_game *game);
int		second_calcul(t_game *game, double angle);
//srcs/draw_xpm_down_we.c
void	draw_xpm_down_we(t_game *game, int i_midline);
int		draw_xpm_we_color(t_game *game, int x, int y);
//srcs/xpm_we_open.c
void	xpm_we_hex_to_dec(t_game *g, int i_color, int i_tab_file);
char	*xpm_we_keep_metadata(char **tmp, int i_tmp);
int		xpm_we_letter_color(t_game *game, int i_color, int i_tab_file);
int		xpm_we_set_color(t_game *game, int i_color, char *tmp);
//srcs/build_map_utils.c
int		check_nbr(char *str);
int		is_empty_line(char *line);
void	set_width(t_game *game);
int		tab_len(char **arr);
//srcs/texture_part.c
int		check_ea(t_game *game, char *line);
int		check_no(t_game *game, char *line);
int		check_so(t_game *game, char *line);
int		check_we(t_game *game, char *line);
int		texture_part(t_game *game, char *line);
//srcs/draw_xpm_up_ea.c
void	draw_xpm_up_ea(t_game *game, int i_midline);
int		draw_xpm_up_ea_color(t_game *game, int x, int y);
//srcs/display_all.c
int		display_all(t_game *game, int key);
int		is_impur(t_game *game);
void	set_dest_e(t_game *game, int key, int len_side);
void	set_dest_n(t_game *game, int key, int len_side);
void	set_dest_s(t_game *game, int key, int len_side);
void	set_dest_w(t_game *game, int key, int len_side);
//srcs/display_all_utils.c
int		init_display_all(t_game *game, int key, int *len_side);
void	move_straight(t_game *game);
void	rotate_new(t_game *game);
//srcs/player.c
void	draw_player(t_game *game);
int		ft_event_listen(int key, t_game *game);
void	set_pos_character(t_game *game);
//srcs/toggle.c
void	change_toggle_a(t_game *game);
void	change_toggle_d(t_game *game);
//srcs/xpm_common.c
int		init_xpm(t_game *game);
int		xpm_parse(t_game *game);
//srcs/xpm_ea_parse.c
int		xpm_ea_get_content_xpm(t_game *game, int fd, int ret, char *buf);
int		xpm_ea_parse(t_game *game);
int		xpm_ea_read(t_game *game, char *filename);
int		xpm_ea_split_buf(int fd, t_game *game);
//srcs/draw_xpm_up_we.c
void	draw_xpm_up_we(t_game *game, int i_midline);
int		draw_xpm_up_we_color(t_game *game, int x, int y);
//srcs/draw_xpm_down_so.c
void	draw_xpm_down_so(t_game *game, int i_midline);
int		draw_xpm_so_color(t_game *game, int x, int y);
//srcs/xpm_no_correction.c
int		xpm_no_copy_tab(t_game *game, char **tmp);
void	xpm_no_correct(t_game *g);
int		xpm_no_read_1line(t_game *game);
int		xpm_no_set_len_n_color(t_game *g, char **line);
void	xpm_no_wo_comm(t_game *g, int n_comm);
//srcs/draw_xpm_down_no.c
void	draw_xpm_down_no(t_game *game, int i_midline);
int		draw_xpm_no_color(t_game *game, int x, int y);
//srcs/fitter_2.c
int		fitter_2_blue(t_game *game);
int		fitter_2_red(t_game *game);
void	fitter_of_fitter_blue(t_game *game);
//srcs/xpm_so_open.c
void	xpm_so_hex_to_dec(t_game *g, int i_color, int i_tab_file);
char	*xpm_so_keep_metadata(char **tmp, int i_tmp);
int		xpm_so_letter_color(t_game *game, int i_color, int i_tab_file);
int		xpm_so_set_color(t_game *game, int i_color, char *tmp);
//srcs/draw_xpm_up_no.c
void	draw_xpm_up_no(t_game *game, int i_midline);
int		draw_xpm_up_no_color(t_game *game, int x, int y);
//srcs/xpm_no_parse.c
int		xpm_no_get_content_xpm(t_game *game, int fd, int ret, char *buf);
int		xpm_no_parse(t_game *game);
int		xpm_no_read(t_game *game, char *filename);
int		xpm_no_split_buf(int fd, t_game *game);
//srcs/check_file.c
int		check_env(char **envp);
int		check_ext(char *filename, char one, char two, char three);
int		wrong_letter_tx(char *line);
//srcs/init_img.c
int		create_image_and_get_adrr(t_game *game);
int		init_img(t_game *game);
//srcs/move_w_s.c
int		calcul_corr_for_step(t_game *game);
void	init_direction_for_s(t_game *game);
void	init_direction_for_s_2(t_game *game);
void	move_s(t_game *game);
void	move_w(t_game *game);
//srcs/floor_ceil_part.c
int		check_ceil(t_game *game, char *line, char *color);
int		check_ceil_content(t_game *game, char **color);
int		check_floor(t_game *game, char *line, char *color);
int		check_floor_content(t_game *game, char **color);
int		floor_ceil_part(t_game *game, char *line);
//srcs/xpm_we_parse.c
int		xpm_we_get_content_xpm(t_game *game, int fd, int ret, char *buf);
int		xpm_we_parse(t_game *game);
int		xpm_we_read(t_game *game, char *filename);
int		xpm_we_split_buf(int fd, t_game *game);
//srcs/check_format.c
void	check_corner(t_game *game);
//srcs/draw_xpm_up_so.c
void	draw_xpm_up_so(t_game *game, int i_midline);
int		draw_xpm_up_so_color(t_game *game, int x, int y);
//srcs/xpm_ea_open.c
void	xpm_ea_hex_to_dec(t_game *g, int i_color, int i_tab_file);
char	*xpm_ea_keep_metadata(char **tmp, int i_tmp);
int		xpm_ea_letter_color(t_game *game, int i_color, int i_tab_file);
int		xpm_ea_set_color(t_game *game, int i_color, char *tmp);
//srcs/xpm_ea_correction.c
int		xpm_ea_copy_tab(t_game *game, char **tmp);
void	xpm_ea_correct(t_game *g);
int		xpm_ea_read_1line(t_game *game);
int		xpm_ea_set_len_n_color(t_game *g, char **line);
void	xpm_ea_wo_comm(t_game *g, int n_comm);
//srcs/fitter.c
void	cross(t_game *game, int i_fit, int x_plus, int y_plus);
void	fitter_blue(t_game *game);
void	fitter_red(t_game *game);
int		is_increase_blue(t_game *game, int i_fit);
int		is_increase_red(t_game *game, int i_fit);
void	print_tab_wall(t_game *game);
//test.c
float rounded(float flt);

#endif