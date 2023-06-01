/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   incs/cub3D.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggosse <ggosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 15:45:40 by ggosse            #+#    #+#             */
/*   Updated: 2023/06/01 16:02:32 by ggosse           ###   ########.fr       */
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
	char	**map_org;
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

//srcs/texture_part_utils.c
int		check_tx(t_game *game);
//srcs/main.c
int		build_map(t_game *game, int ite_start);
int		check_valid_chr_map(char *line);
int		ft_parsing(t_game *game, char **argv);
void	init_struct(t_game *game);
int		is_empty_line(char *line);
int		malloc_map(t_game *game, int ite_start);
//srcs/texture_part.c
int		check_ea(t_game *game, char *line);
int		check_no(t_game *game, char *line);
int		check_so(t_game *game, char *line);
int		check_we(t_game *game, char *line);
int		texture_part(t_game *game, char *line);
//srcs/valid_wall.c
int		ft_propagation(t_game *game);
int		ft_replace_around(t_game *game, int ite_big, int ite_lil);
int		ft_valid_wall(t_game *game);
//srcs/check_file.c
int		ft_check_env(char **envp);
int		ft_check_ext(char *filename, char one, char two, char three);
int		wrong_letter_tx(char *line);
//srcs/read_file.c
int		ft_buf_read(int fd, t_game *game);
int		ft_read_file(t_game *game, char *filename);
//srcs/floor_ceil_part.c
int		check_ceil(t_game *game, char *line);
int		check_floor(t_game *game, char *line);
int		floor_ceil_part(t_game *game, char *line);
//srcs/free_parsing.c
void	free_img(t_game *game);
void	ft_free_parsing(t_game *game, char *err);
void	ft_free_tab_str(char **tab_str);

#endif