/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael <mael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:27:05 by ggosse            #+#    #+#             */
/*   Updated: 2023/06/13 18:36:08 by mael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3D.h"

void	ft_free_tab_str(char **tab_str)
{
	int	ite_free_two;

	ite_free_two = -1;
	while (tab_str[++ite_free_two])
	{
		// printf("tab_str[ite_free_two]: %p\n", tab_str[ite_free_two]);
		free(tab_str[ite_free_two]);
		tab_str[ite_free_two] = NULL;
	}
	// printf("tab_str: %p\n", tab_str);
	free(tab_str);
	tab_str = NULL;
}

// int	ft_destroy_and_free(t_game *game, char *err)
// {
// 	if (err)
// 		ft_putstr_fd(err, 2);
// 	if (game->window)
// 		mlx_destroy_window(game->mlibx, game->window);
// 	if (game->window)
// 		mlx_destroy_display(game->mlibx);
// 	free(game->mlibx);
// 	ft_free_tab_str(game->map->map_tmp);
// 	ft_free_tab_str(game->map->tab_file);
// 	free(game->map);
// 	exit (1);
// }

// int	ft_destroy_and_free2(t_game *game)
// {
// 	if (game->window)
// 		mlx_destroy_window(game->mlibx, game->window);
// 	if (game->window)
// 		mlx_destroy_display(game->mlibx);
// 	free(game->mlibx);
// 	ft_free_tab_str(game->map->map_tmp);
// 	ft_free_tab_str(game->map->tab_file);
// 	free(game->map);
// 	exit (1);
// }

void	free_img(t_game *game)
{
	if (game->map->wall_no)
	{
		free(game->map->wall_no);
		game->map->wall_no = NULL;
	}
	if (game->map->wall_ea)
	{
		free(game->map->wall_ea);
		game->map->wall_ea = NULL;
	}
	if (game->map->wall_so)
	{
		free(game->map->wall_so);
		game->map->wall_so = NULL;
	}
	if (game->map->wall_we)
	{
		free(game->map->wall_we);
		game->map->wall_we = NULL;
	}
}

void	ft_free_parsing(t_game *game, char *err)
{
	if (err)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd(err, 2);
	}
	if (game->map->file_content)
	{
		free(game->map->file_content);
		game->map->file_content = NULL;
	}
	free_img(game);
	if (game->map->tab_file)
		ft_free_tab_str(game->map->tab_file);
	// printf("------------------------------\n");
	// if (game->map->map_tmp)
	// 	ft_free_tab_str(game->map->map_tmp);
	if (game->map)
	{
		free(game->map);
		game->map = NULL;
	}
}


