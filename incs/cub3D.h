/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   incs/cub3D.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gael <gael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 15:45:40 by ggosse            #+#    #+#             */
/*   Updated: 2023/07/26 10:21:52 by gael             ###   ########.fr       */
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
	char	*file_content;
	char	*file_map;
	char	**tab_file;
	int		*lenth_n_color;
	int		**colors;
	int		tab_start;
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
	float	**wall_witch;
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
	t_xpm		*xpm;
	t_line		*line;
	t_fov		*fov;
	t_line_3d	*line_3d;
	t_temp		*temp;
}			t_game;
// ---------------------------- end struct ---------------------------------- //

//srcs/main.c
int		ft_parsing(t_game *game, char **argv);
void	init_struct(t_game *game);
int		open_fd(t_game *game, int *fd, char **argv);
void	print_map(char **arr);
//srcs/pixel_and_color.c
int		get_color(int red, int green, int blue);
void	img_pix_put(t_game *game, int x, int y, int color);
void	img_pix_put_2(t_game *game, int x, int y, int color);
//srcs/start_3D.c
void	color_image(t_game *game);
void	do_quad(t_game *game, int i, int j);
void	fill_void(t_game *game, int i, int j);
void	fill_wall(t_game *game, int i, int j);
int		first_time(t_game *game);
void	reset_img(t_game *game);
int		start_3D(t_game *game);
//srcs/draw_line.c
double	abs_dble(double nb);
float abs_flt(float nb);
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
//srcs/xpm_first.c
char	*keep_metadata_xpm(char **tmp, int i_tmp);
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
//srcs/xpm_parse.c
int		buf_split_xpm(int fd, t_game *game);
int		get_content_xpm(t_game *game, int fd, int ret, char *buf);
int		init_xpm(t_game *game);
int		read_xpm(t_game *game, char *filename);
int		xpm_parse(t_game *game);
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
int		check_ceil(t_game *game, char *line);
int		check_ceil_content(t_game *game, char **color);
int		check_floor(t_game *game, char *line);
int		check_floor_content(t_game *game, char **color);
int		floor_ceil_part(t_game *game, char *line);
//srcs/check_format.c
void	check_corner(t_game *game);
//srcs/xpm_correction.c
int		copy_tab_xpm(t_game *game, char **tmp);
int		read_first_line_xpm(t_game *game);
int		set_color(t_game *game, int i_color, char *tmp);
int		set_color_when_no_digit(t_game *game, int i_color, int i_tab_file);
int		set_lenth_n_color(t_game *game, char **line);
void	xpm_correct(t_game *g);
void	xpm_wo_comm(t_game *g, int n_comm);
//srcs/fitter.c
void	cross(t_game *game, int i_fit, int x_plus, int y_plus);
void	fitter_blue(t_game *game);
void	fitter_red(t_game *game);
int		is_increase_blue(t_game *game, int i_fit);
int		is_increase_red(t_game *game, int i_fit);
void	print_tab_wall(t_game *game);
//test.c

#endif