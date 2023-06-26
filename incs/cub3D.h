/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   incs/cub3D.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gael <gael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 15:45:40 by ggosse            #+#    #+#             */
/*   Updated: 2023/06/25 12:45:28 by gael             ###   ########.fr       */
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
}	t_line;

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
}				t_map;

typedef struct s_game
{
	int		img_size;
	char	perso;
	void	*mlibx;
	void	*window;
	t_map	*map;
	//t_img	***tab_img;
	//t_img	*square;
	t_img	*img;
	t_line	*line;
}			t_game;
// ---------------------------- end struct ---------------------------------- //

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
int		init_tab_img(t_game *game);
int		start_3d(t_game *game);
int		tab_img_to_window(t_game *game);
//srcs/main.c
int		ft_parsing(t_game *game, char **argv);
void	init_struct(t_game *game);
int		open_fd(t_game *game, int *fd);
void	print_map(char **arr);
//srcs/pixel_and_color.c
void	img_pix_put(t_game *game, int x, int y, int color);
void	img_pix_put_2(t_game *game, int x, int y, int color);
//srcs/start_3D.c
void	color_image(t_game *game);
int		display_all(t_game *game);
void	do_quad(t_game *game, int i, int j);
void	fill_void(t_game *game, int i, int j);
void	fill_wall(t_game *game, int i, int j);
void	reset_img(t_game *game);
int		start_3D(t_game *game);
//srcs/draw_line.c
int		absolute_value(int nb);
void	draw_line_vision(t_game *game);
int		init_line(t_game *game);
//srcs/free_parsing.c
void	free_img(t_game *game);
void	ft_free_parsing(t_game *game, char *err);
void	ft_free_tab_str(char **tab_str);
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
//srcs/build_map.c
void	build_content(t_game *game, char **line, int fd);
int		build_map(t_game *game);
int		create_map(t_game *game, char *line, int fd);
void	realloc_lines(t_game *game);
void	skip_empty_line(char **line, int fd);
//srcs/read_file.c
int		ft_buf_read(int fd, t_game *game);
int		ft_read_file(t_game *game, char *filename);
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
//srcs/player.c
void	draw_player(t_game *game);
int		ft_event_listen(int key, t_game *game);
void	set_pos_character(t_game *game);
//srcs/check_file.c
int		ft_check_env(char **envp);
int		ft_check_ext(char *filename, char one, char two, char three);
int		wrong_letter_tx(char *line);
//srcs/init_img.c
int		create_image_and_get_adrr(t_game *game);
int		init_img(t_game *game);
//srcs/floor_ceil_part.c
int		check_ceil(t_game *game, char *line);
int		check_ceil_content(t_game *game, char **color);
int		check_floor(t_game *game, char *line);
int		check_floor_content(t_game *game, char **color);
int		floor_ceil_part(t_game *game, char *line);

#endif