/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggosse <ggosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:27:05 by ggosse            #+#    #+#             */
/*   Updated: 2023/05/24 18:07:47 by ggosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_free_tab_str(char **tab_str)
{
	int	ite_free_two;

	ite_free_two = -1;
	while (tab_str[++ite_free_two])
	{
		free(tab_str[ite_free_two]);
		tab_str[ite_free_two] = NULL;
	}
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
// 	ft_free_tab_str(game->map->map_chck);
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
// 	ft_free_tab_str(game->map->map_chck);
// 	ft_free_tab_str(game->map->tab_file);
// 	free(game->map);
// 	exit (1);
// }

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
	if (game->map->tab_file)
		ft_free_tab_str(game->map->tab_file);
	if (game->map->map_chck)
		ft_free_tab_str(game->map->map_chck);
	if (game->map)
	{
		free(game->map);
		game->map = NULL;
	}
}


