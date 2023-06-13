/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael <mael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 15:45:40 by ggosse            #+#    #+#             */
/*   Updated: 2023/06/13 17:42:17 by mael             ###   ########.fr       */
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

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

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
	t_img	***tab_img;
}			t_game;
// ---------------------------- end struct ---------------------------------- //

//srcs/main.c
int		build_map(t_game *game, char **argv);
int		ft_parsing(t_game *game, char **argv);
void	init_struct(t_game *game);
int		is_empty_line(char *line);
//srcs/free_parsing.c
void	free_img(t_game *game);
void	ft_free_parsing(t_game *game, char *err);
void	ft_free_tab_str(char **tab_str);
//srcs/texture_part_utils.c
int		check_tx(t_game *game);
void	print_word(char *new_w);
//srcs/valid_wall.c
int		check_letters_map(t_game *game);
int		check_perso(t_game *game);
int		hole_in_wall(t_game *game);
//srcs/build_map.c
int		create_map(t_game *game, char *line, int fd);
int		tab_len(char **arr);
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


int	start_3d(t_game *game);
int	init_tab_img(t_game *game);
int	create_img(t_game *game);
void	img_pix_put(t_game *game, int x, int y, int color, int i, int j);
int	get_color(int red, int green, int blue);
void	fill_square(t_game *game, int color, int i, int j);
void	color_image(t_game *game);
int	tab_img_to_window(t_game *game);


#endif