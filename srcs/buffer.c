/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gael <gael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 13:38:43 by gael              #+#    #+#             */
/*   Updated: 2023/07/25 16:20:28 by gael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



// ---------- BY WALL ----------

//void	fitter_blue(t_game *game)
// {
// 	int	i_fit;
// 	int	i_start;
// 	int	one;
// 	int	two;
// 	int	i_one;
// 	int	i_two;

// 	one = 0;
// 	two = 0;
// 	i_one = 0;
// 	i_two = 0;
// 	i_fit = game->fov->nbr_ray;
// 	i_start = 0;
// 	while (i_fit > game->fov->nbr_ray / 2)
// 	{
// 		if (i_fit > 0 && game->fov->wall[i_fit][0] == game->fov->wall[i_fit - 1][0])
// 		{
// 			i_start = i_fit;
// 			i_one = 0;
// 			i_two = 0;
// 			one = game->fov->toggle_vision[i_fit];
// 			while (i_fit > 0 && game->fov->wall[i_fit][0] == game->fov->wall[i_fit - 1][0])
// 			{
// 				if (game->fov->toggle_vision[i_fit] == one)
// 					i_one++;
// 				else
// 				{
// 					two = game->fov->toggle_vision[i_fit];
// 					i_two++;
// 				}
// 				i_fit--;
// 			}
// 			while (i_fit < i_start)
// 			{
// 				if (i_one > i_two)
// 					game->fov->toggle_vision[i_fit] = one;
// 				else
// 					game->fov->toggle_vision[i_fit] = two;
// 				i_fit++;
// 			}
// 			i_fit = i_start;
// 			while (i_fit > 0 && game->fov->wall[i_fit][0] == game->fov->wall[i_fit - 1][0])
// 				i_fit--;
// 		}
// 		else if (i_fit > 0 && game->fov->wall[i_fit][1] == game->fov->wall[i_fit - 1][1])
// 		{
// 			i_start = i_fit;
// 			i_one = 0;
// 			i_two = 0;
// 			one = game->fov->toggle_vision[i_fit];
// 			while (i_fit > 0 && game->fov->wall[i_fit][1] == game->fov->wall[i_fit - 1][1])
// 			{
// 				if (game->fov->toggle_vision[i_fit] == one)
// 					i_one++;
// 				else
// 				{
// 					two = game->fov->toggle_vision[i_fit];
// 					i_two++;
// 				}
// 				i_fit--;
// 			}
// 			while (i_fit < i_start)
// 			{
// 				if (i_one > i_two)
// 					game->fov->toggle_vision[i_fit] = one;
// 				else
// 					game->fov->toggle_vision[i_fit] = two;
// 				i_fit++;
// 			}
// 			i_fit = i_start;
// 			while (i_fit > 0 && game->fov->wall[i_fit][1] == game->fov->wall[i_fit - 1][1])
// 				i_fit--;
// 		}
// 		else
// 			i_fit--;
// 	}
// }

// void	fitter_red(t_game *game)
// {
// 	int	i_fit;
// 	int	i_start;
// 	int	one;
// 	int	two;
// 	int	i_one;
// 	int	i_two;

// 	one = 0;
// 	two = 0;
// 	i_one = 0;
// 	i_two = 0;
// 	i_fit = 0;
// 	i_start = 0;
// 	while (i_fit < game->fov->nbr_ray / 2)
// 	{
// 		if (i_fit < game->fov->nbr_ray / 2 && game->fov->wall[i_fit][0] == game->fov->wall[i_fit + 1][0])
// 		{
// 			i_start = i_fit;
// 			one = game->fov->toggle_vision[i_fit];
// 			i_one = 0;
// 			i_two = 0;
// 			while (i_fit < game->fov->nbr_ray / 2 && game->fov->wall[i_fit][0] == game->fov->wall[i_fit + 1][0])
// 			{
// 				if (game->fov->toggle_vision[i_fit] == one)
// 					i_one++;
// 				else
// 				{
// 					two = game->fov->toggle_vision[i_fit];
// 					i_two++;
// 				}
// 				i_fit++;
// 			}
// 			while (i_fit > i_start)
// 			{
// 				if (i_one > i_two)
// 					game->fov->toggle_vision[i_fit] = one;
// 				else
// 					game->fov->toggle_vision[i_fit] = two;
// 				i_fit--;
// 			}
// 			i_fit = i_start;
// 			while (i_fit < game->fov->nbr_ray / 2 && game->fov->wall[i_fit][0] == game->fov->wall[i_fit + 1][0])
// 				i_fit++;
// 		}
// 		else if (i_fit < game->fov->nbr_ray / 2 && game->fov->wall[i_fit][1] == game->fov->wall[i_fit + 1][1])
// 		{
// 			i_start = i_fit;
// 			one = game->fov->toggle_vision[i_fit];
// 			i_one = 0;
// 			i_two = 0;
// 			while (i_fit < game->fov->nbr_ray / 2 && game->fov->wall[i_fit][1] == game->fov->wall[i_fit + 1][1])
// 			{
// 				if (game->fov->toggle_vision[i_fit] == one)
// 					i_one++;
// 				else
// 				{
// 					two = game->fov->toggle_vision[i_fit];
// 					i_two++;
// 				}
// 				i_fit++;
// 			}
// 			while (i_fit > i_start)
// 			{
// 				if (i_one > i_two)
// 					game->fov->toggle_vision[i_fit] = one;
// 				else
// 					game->fov->toggle_vision[i_fit] = two;
// 				i_fit--;
// 			}
// 			i_fit = i_start;
// 			while (i_fit < game->fov->nbr_ray / 2 && game->fov->wall[i_fit][1] == game->fov->wall[i_fit + 1][1])
// 				i_fit++;
// 		}
// 		else
// 			i_fit++;
// 	}
// }

// ---------- BY CUB ----------

// void	fitter_blue(t_game *game)
// {
// 	int	i_fit;
// 	int	i_start;
// 	int	one;
// 	int	two;
// 	int	i_one;
// 	int	i_two;
// 	int	increase;

// 	increase = 0;
// 	one = 0;
// 	two = 0;
// 	i_one = 0;
// 	i_two = 0;
// 	i_fit = game->fov->nbr_ray;
// 	i_start = 0;
// 	while (i_fit > game->fov->nbr_ray / 2)
// 	{
// 		if (i_fit > 0 && game->fov->wall[i_fit][0] == game->fov->wall[i_fit - 1][0] && game->fov->wall[i_fit][1] == game->fov->wall[i_fit - 1][1])
// 		{
// 			i_one = 0;
// 			i_two = 0;
// 			i_start = i_fit;
// 			one = game->fov->toggle_vision[i_fit];
// 			increase = is_increase_blue(game, i_fit);
// 			while (i_fit > 0 &&
// 			game->fov->wall[i_fit][0] == game->fov->wall[i_fit - 1][0] &&
// 			game->fov->wall[i_fit][1] == game->fov->wall[i_fit - 1][1] &&
// 			is_increase_blue(game, i_fit) == increase)
// 			{
// 				// printf(BACK_GREEN"\t\t\t\t\t\t\t\t\taller"RST"\n");
// 				if (game->fov->toggle_vision[i_fit] == one)
// 					i_one++;
// 				else
// 				{
// 					two = game->fov->toggle_vision[i_fit];
// 					i_two++;
// 				}

// 				i_fit--;
// 			}
// 			while (i_fit < i_start)
// 			{
// 				// printf(BACK_RED"\t\t\t\t\t\t\t\t\tretour"RST"\n");
// 				if (i_one > i_two)
// 					game->fov->toggle_vision[i_fit] = one;
// 				else
// 					game->fov->toggle_vision[i_fit] = two;
// 				i_fit++;
// 			}
// 			i_fit = i_start;
// 			while (i_fit > 0 &&
// 			game->fov->wall[i_fit][0] == game->fov->wall[i_fit - 1][0] &&
// 			game->fov->wall[i_fit][1] == game->fov->wall[i_fit - 1][1] &&
// 			is_increase_blue(game, i_fit) == increase)
// 				i_fit--;
// 		}
// 		else
// 			i_fit--;
// 		// else if (i_fit > 0 && game->fov->wall[i_fit][1] == game->fov->wall[i_fit - 1][1])
// 		// {
// 		// 	i_start = i_fit;
// 		// 	one = game->fov->toggle_vision[i_fit];
// 		// 	while (i_fit > 0 && game->fov->wall[i_fit][1] == game->fov->wall[i_fit - 1][1])
// 		// 	{
// 		// 		if (game->fov->toggle_vision[i_fit] == one)
// 		// 			i_one++;
// 		// 		else
// 		// 		{
// 		// 			two = game->fov->toggle_vision[i_fit];
// 		// 			i_two++;
// 		// 		}
// 		// 		i_fit--;
// 		// 	}
// 		// 	while (i_fit < i_start)
// 		// 	{
// 		// 		if (i_one > i_two)
// 		// 			game->fov->toggle_vision[i_fit] = one;
// 		// 		else
// 		// 			game->fov->toggle_vision[i_fit] = two;
// 		// 		i_fit++;
// 		// 	}
// 		// 	i_fit = i_start;
// 		// 	while (i_fit > 0 && game->fov->wall[i_fit][1] == game->fov->wall[i_fit - 1][1])
// 		// 		i_fit--;
// 		// }

// 	}
// }

// int	is_increase_blue(t_game *game, int i_fit)
// {
// 	while (game->fov->lines_vision[i_fit - 1] &&
// 	game->fov->lines_vision[i_fit] == game->fov->lines_vision[i_fit - 1] &&
// 	game->fov->wall[i_fit][0] == game->fov->wall[i_fit - 1][0] &&
// 	game->fov->wall[i_fit][1] == game->fov->wall[i_fit - 1][1])
// 	{
// 		printf(BACK_RED"here"RST"\n");
// 		i_fit--;
// 	}
// 	if (game->fov->lines_vision[i_fit] > game->fov->lines_vision[i_fit - 1])
// 		return (FAIL);
// 	else
// 		return (SUCCESS);
// }

// void	fitter_red(t_game *game)
// {
// 	int	i_fit;
// 	int	i_start;
// 	int	one;
// 	int	two;
// 	int	i_one;
// 	int	i_two;
// 	int	increase;

// 	increase = 0;
// 	one = 0;
// 	two = 0;
// 	i_one = 0;
// 	i_two = 0;
// 	i_fit = 0;
// 	i_start = 0;
// 	while (i_fit < game->fov->nbr_ray / 2)
// 	{
// 		if (i_fit < game->fov->nbr_ray / 2 && game->fov->wall[i_fit][0] == game->fov->wall[i_fit + 1][0] && game->fov->wall[i_fit][1] == game->fov->wall[i_fit + 1][1])
// 		{
// 			i_one = 0;
// 			i_two = 0;
// 			i_start = i_fit;
// 			one = game->fov->toggle_vision[i_fit];
// 			increase = is_increase_red(game, i_fit);
// 			while (i_fit < game->fov->nbr_ray / 2 &&
// 			game->fov->wall[i_fit][0] == game->fov->wall[i_fit + 1][0] &&
// 			game->fov->wall[i_fit][1] == game->fov->wall[i_fit + 1][1] &&
// 			is_increase_red(game, i_fit) == increase)
// 			{
// 				// printf(BACK_GREEN"\t\t\t\t\t\t\t\t\taller"RST"\n");
// 				if (game->fov->toggle_vision[i_fit] == one)
// 					i_one++;
// 				else
// 				{
// 					two = game->fov->toggle_vision[i_fit];
// 					i_two++;
// 				}

// 				i_fit++;
// 			}
// 			while (i_fit > i_start)
// 			{
// 				// printf(BACK_RED"\t\t\t\t\t\t\t\t\tretour"RST"\n");
// 				if (i_one > i_two)
// 					game->fov->toggle_vision[i_fit] = one;
// 				else
// 					game->fov->toggle_vision[i_fit] = two;
// 				i_fit--;
// 			}
// 			i_fit = i_start;
// 			while (i_fit < game->fov->nbr_ray / 2 &&
// 			game->fov->wall[i_fit][0] == game->fov->wall[i_fit + 1][0] &&
// 			game->fov->wall[i_fit][1] == game->fov->wall[i_fit + 1][1] &&
// 			is_increase_red(game, i_fit) == increase)
// 				i_fit++;
// 		}
// 		else
// 			i_fit++;
// 	}
// }

// int	is_increase_red(t_game *game, int i_fit)
// {
// 	while (game->fov->lines_vision[i_fit + 1] &&
// 	game->fov->lines_vision[i_fit] == game->fov->lines_vision[i_fit + 1] &&
// 	game->fov->wall[i_fit][0] == game->fov->wall[i_fit + 1][0] &&
// 	game->fov->wall[i_fit][1] == game->fov->wall[i_fit + 1][1])
// 		i_fit--;
// 	if (game->fov->lines_vision[i_fit] > game->fov->lines_vision[i_fit + 1])
// 		return (FAIL);
// 	else
// 		return (SUCCESS);
// }
