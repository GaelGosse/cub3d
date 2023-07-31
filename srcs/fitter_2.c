/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fitter_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gael <gael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 13:09:00 by mael              #+#    #+#             */
/*   Updated: 2023/07/31 17:28:33 by gael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	fitter_2_blue(t_game *game)
{
	int i;

	i = 151;
	while (i < game->fov->nbr_ray )
	{
		if (game->fov->angle >= 0 && game->fov->angle < 180)
		{
			if ((((int)(game->fov->wall_witch[i][0]) % game->img_size == 0)
			&& ((int)(game->fov->wall_witch[i + 1][0]) % game->img_size == 0))
			&& (((int)(game->fov->wall_witch[i][1]) % game->img_size != 0)
			&& ((int)(game->fov->wall_witch[i + 1][1]) % game->img_size != 0)))
			{
				game->fov->toggle_vision[i] = 'W';
				if (game->fov->toggle_vision[i - 1] != game->fov->toggle_vision[i]
				&& game->fov->toggle_vision[i + 1] != game->fov->toggle_vision[i])
				{
					// printf("here blue WEST\n");
					// printf(BACK_BLUE"game->fov->toggle[%i]: %c"RST"\n", i, game->fov->toggle_vision[i]);
					game->fov->toggle_vision[i] = game->fov->toggle_vision[i + 1];
				}
				if (game->fov->toggle_vision[i - 1] != game->fov->toggle_vision[i]
				&& game->fov->toggle_vision[i + 1] != game->fov->toggle_vision[i])
				{
					// printf(BACK_YELLOW"toggle_vision[i - 1]: %c"RST"\n", game->fov->toggle_vision[i - 1]);
					// printf(BACK_YELLOW"toggle_vision[i]: %c"RST"\n", game->fov->toggle_vision[i]);
					// printf(BACK_YELLOW"toggle_vision[i + 1]: %c"RST"\n", game->fov->toggle_vision[i + 1]);
					// printf("\n\n");
				}
				// if (game->fov->toggle_vision[i - 1] != game->fov->toggle_vision[i]
				// && game->fov->toggle_vision[i + 1] != game->fov->toggle_vision[i])
				// {
					// printf(BACK_YELLOW"toggle_vision[i_midline - 1]: %c"RST"\n", game->fov->toggle_vision[i_midline - 1]);
					// printf(BACK_YELLOW"toggle_vision[i_midline]: %c"RST"\n", game->fov->toggle_vision[i_midline]);
					// printf(BACK_YELLOW"toggle_vision[i_midline + 1]: %c"RST"\n", game->fov->toggle_vision[i_midline + 1]);
					// printf("\n\n");
				// }
			// if (game->fov->toggle_vision[i] != 'W')
				// {
					// printf("[i][0]: %d\t", (int)(game->fov->wall_witch[i][0]));
					// printf("[i][1]: %d\n", (int)(game->fov->wall_witch[i][1]));
					// printf("[i + 1][0]: %d\t", (int)(game->fov->wall_witch[i + 1][0]));
					// printf("[i + 1][1]: %d\n", (int)(game->fov->wall_witch[i + 1][1]));
					// printf(BACK_YELLOW"toggle_vision[i - 1]: %c"RST"\n", game->fov->toggle_vision[i - 1]);
					// printf(BACK_YELLOW"toggle_vision[i]: %c"RST"\n", game->fov->toggle_vision[i]);
					// printf(BACK_YELLOW"toggle_vision[i + 1]: %c"RST"\n", game->fov->toggle_vision[i + 1]);
					// printf("\n");
				// }
			}
		}
		if ((game->fov->angle >= 270 && game->fov->angle < 360) || (game->fov->angle >= 0 && game->fov->angle < 90))
		{
			if ((((int)(game->fov->wall_witch[i][0]) % game->img_size != 0)
			&& ((int)(game->fov->wall_witch[i + 1][0]) % game->img_size != 0))
			&& (((int)(game->fov->wall_witch[i][1]) % game->img_size == 0)
			&& ((int)(game->fov->wall_witch[i + 1][1]) % game->img_size == 0)))
			{
				game->fov->toggle_vision[i] = 'S';
				if (game->fov->toggle_vision[i - 1] != game->fov->toggle_vision[i]
				&& game->fov->toggle_vision[i + 1] != game->fov->toggle_vision[i])
				{
					// printf("here SOUTH\n");
					game->fov->toggle_vision[i] = game->fov->toggle_vision[i + 1];
				}
				// if (game->fov->toggle_vision[i] != 'W')
				// {
					// printf("[i][0]: %d\t", (int)(game->fov->wall_witch[i][0]));
					// printf("[i][1]: %d\n", (int)(game->fov->wall_witch[i][1]));
					// printf("[i + 1][0]: %d\t", (int)(game->fov->wall_witch[i + 1][0]));
					// printf("[i + 1][1]: %d\n", (int)(game->fov->wall_witch[i + 1][1]));
					// printf(BACK_YELLOW"toggle_vision[i - 1]: %c"RST"\n", game->fov->toggle_vision[i - 1]);
					// printf(BACK_YELLOW"toggle_vision[i]: %c"RST"\n", game->fov->toggle_vision[i]);
					// printf(BACK_YELLOW"toggle_vision[i + 1]: %c"RST"\n", game->fov->toggle_vision[i + 1]);
					// printf("\n");
				// }
			}
		}
		if (game->fov->angle >= 180 && game->fov->angle < 360)
		{
			if ((((int)(game->fov->wall_witch[i][0]) % game->img_size == 0)
			&& ((int)(game->fov->wall_witch[i + 1][0]) % game->img_size == 0))
			&& (((int)(game->fov->wall_witch[i][1]) % game->img_size != 0)
			&& ((int)(game->fov->wall_witch[i + 1][1]) % game->img_size != 0)))
			{
				game->fov->toggle_vision[i] = 'E';
				if (game->fov->toggle_vision[i - 1] != game->fov->toggle_vision[i]
				&& game->fov->toggle_vision[i + 1] != game->fov->toggle_vision[i])
				{
					// printf("here EAST\n");
					game->fov->toggle_vision[i] = game->fov->toggle_vision[i + 1];
				}
					// printf(BACK_YELLOW"toggle_vision[i - 1]: %c"RST"\n", game->fov->toggle_vision[i - 1]);
					// printf(BACK_YELLOW"toggle_vision[i]: %c"RST"\n", game->fov->toggle_vision[i]);
					// printf(BACK_YELLOW"toggle_vision[i + 1]: %c"RST"\n", game->fov->toggle_vision[i + 1]);
					// printf("\n\n");
				// if (game->fov->toggle_vision[i] != 'W')
				// {
					// printf("[i][0]: %d\t", (int)(game->fov->wall_witch[i][0]));
					// printf("[i][1]: %d\n", (int)(game->fov->wall_witch[i][1]));
					// printf("[i + 1][0]: %d\t", (int)(game->fov->wall_witch[i + 1][0]));
					// printf("[i + 1][1]: %d\n", (int)(game->fov->wall_witch[i + 1][1]));
					// printf(BACK_YELLOW"toggle_vision[i - 1]: %c"RST"\n", game->fov->toggle_vision[i - 1]);
					// printf(BACK_YELLOW"toggle_vision[i]: %c"RST"\n", game->fov->toggle_vision[i]);
					// printf(BACK_YELLOW"toggle_vision[i + 1]: %c"RST"\n", game->fov->toggle_vision[i + 1]);
					// printf("\n");
				// }
			}
		}
		if ((game->fov->angle >= 90 && game->fov->angle < 270))
		{
			if ((((int)(game->fov->wall_witch[i][0]) % game->img_size != 0)
			&& ((int)(game->fov->wall_witch[i + 1][0]) % game->img_size != 0))
			&& (((int)(game->fov->wall_witch[i][1]) % game->img_size == 0)
			&& ((int)(game->fov->wall_witch[i + 1][1]) % game->img_size == 0)))
			{
				game->fov->toggle_vision[i] = 'N';
				if (game->fov->toggle_vision[i - 1] != game->fov->toggle_vision[i]
				&& game->fov->toggle_vision[i + 1] != game->fov->toggle_vision[i])
				{
					// printf("here NORTH\n");
					game->fov->toggle_vision[i] = game->fov->toggle_vision[i + 1];
				}
				// if (game->fov->toggle_vision[i] != 'W')
				// {
					// printf("[i][0]: %d\t", (int)(game->fov->wall_witch[i][0]));
					// printf("[i][1]: %d\n", (int)(game->fov->wall_witch[i][1]));
					// printf("[i + 1][0]: %d\t", (int)(game->fov->wall_witch[i + 1][0]));
					// printf("[i + 1][1]: %d\n", (int)(game->fov->wall_witch[i + 1][1]));
					// printf(BACK_YELLOW"toggle_vision[i - 1]: %c"RST"\n", game->fov->toggle_vision[i - 1]);
					// printf(BACK_YELLOW"toggle_vision[i]: %c"RST"\n", game->fov->toggle_vision[i]);
					// printf(BACK_YELLOW"toggle_vision[i + 1]: %c"RST"\n", game->fov->toggle_vision[i + 1]);
				// printf("\n");
				// }
			}
		}

		// else
		// {
		// 	if (round(game->fov->wall_witch[i][0]) == round(game->fov->wall_witch[i + 1][0]))
		// 		game->fov->toggle_vision[i] = 'W';
		// }
		i++;
	}
	return (SUCCESS);
}

int	fitter_2_red(t_game *game)
{
	int i;

	i = 0;
	while (i < game->fov->nbr_ray / 2)
	{
		if (game->fov->angle >= 0 && game->fov->angle < 180)
		{
			if ((((int)(game->fov->wall_witch[i][0]) % game->img_size == 0)
			&& ((int)(game->fov->wall_witch[i + 1][0]) % game->img_size == 0))
			&& (((int)(game->fov->wall_witch[i][1]) % game->img_size != 0)
			&& ((int)(game->fov->wall_witch[i + 1][1]) % game->img_size != 0)))
			{
				game->fov->toggle_vision[i] = 'W';
				if (i > 0 && game->fov->toggle_vision[i - 1] != game->fov->toggle_vision[i]
				&& game->fov->toggle_vision[i + 1] != game->fov->toggle_vision[i])
				{
					// printf("here red WEST\n");
					// printf(BACK_RED"game->fov->toggle[%i]: %c"RST"\n", i, game->fov->toggle_vision[i]);
					// printf(BACK_RED"game->fov->toggle[%i + %i]: %c"RST"\n", i, 1, game->fov->toggle_vision[i + 1]);
					game->fov->toggle_vision[i] = game->fov->toggle_vision[i + 1];
					// printf(BACK_RED"game->fov->toggle[%i] apres verif: %c"RST"\n", i, game->fov->toggle_vision[i]);
				}
				if (i > 0 && game->fov->toggle_vision[i - 1] != game->fov->toggle_vision[i]
				&& game->fov->toggle_vision[i + 1] != game->fov->toggle_vision[i])
				{
					// printf(BACK_YELLOW"toggle_vision[i - 1]: %c"RST"\n", game->fov->toggle_vision[i - 1]);
					// printf(BACK_YELLOW"toggle_vision[i]: %c"RST"\n", game->fov->toggle_vision[i]);
					// printf(BACK_YELLOW"toggle_vision[i + 1]: %c"RST"\n", game->fov->toggle_vision[i + 1]);
					// printf("\n\n");
				}
				// if (game->fov->toggle_vision[i - 1] != game->fov->toggle_vision[i]
				// && game->fov->toggle_vision[i + 1] != game->fov->toggle_vision[i])
				// {
					// printf(BACK_YELLOW"toggle_vision[i_midline - 1]: %c"RST"\n", game->fov->toggle_vision[i_midline - 1]);
					// printf(BACK_YELLOW"toggle_vision[i_midline]: %c"RST"\n", game->fov->toggle_vision[i_midline]);
					// printf(BACK_YELLOW"toggle_vision[i_midline + 1]: %c"RST"\n", game->fov->toggle_vision[i_midline + 1]);
					// printf("\n\n");
				// }
			// if (game->fov->toggle_vision[i] != 'W')
				// {
					// printf("[i][0]: %d\t", (int)(game->fov->wall_witch[i][0]));
					// printf("[i][1]: %d\n", (int)(game->fov->wall_witch[i][1]));
					// printf("[i + 1][0]: %d\t", (int)(game->fov->wall_witch[i + 1][0]));
					// printf("[i + 1][1]: %d\n", (int)(game->fov->wall_witch[i + 1][1]));
					// printf(BACK_YELLOW"toggle_vision[i - 1]: %c"RST"\n", game->fov->toggle_vision[i - 1]);
					// printf(BACK_YELLOW"toggle_vision[i]: %c"RST"\n", game->fov->toggle_vision[i]);
					// printf(BACK_YELLOW"toggle_vision[i + 1]: %c"RST"\n", game->fov->toggle_vision[i + 1]);
					// printf("\n");
				// }
			}
		}
		if ((game->fov->angle >= 270 && game->fov->angle < 360) || (game->fov->angle >= 0 && game->fov->angle < 90))
		{
			if ((((int)(game->fov->wall_witch[i][0]) % game->img_size != 0)
			&& ((int)(game->fov->wall_witch[i + 1][0]) % game->img_size != 0))
			&& (((int)(game->fov->wall_witch[i][1]) % game->img_size == 0)
			&& ((int)(game->fov->wall_witch[i + 1][1]) % game->img_size == 0)))
			{
				game->fov->toggle_vision[i] = 'S';
				if (game->fov->toggle_vision[i - 1] != game->fov->toggle_vision[i]
				&& game->fov->toggle_vision[i + 1] != game->fov->toggle_vision[i])
				{
					// printf("here SOUTH\n");
					game->fov->toggle_vision[i] = game->fov->toggle_vision[i + 1];
				}
				// if (game->fov->toggle_vision[i] != 'W')
				// {
					// printf("[i][0]: %d\t", (int)(game->fov->wall_witch[i][0]));
					// printf("[i][1]: %d\n", (int)(game->fov->wall_witch[i][1]));
					// printf("[i + 1][0]: %d\t", (int)(game->fov->wall_witch[i + 1][0]));
					// printf("[i + 1][1]: %d\n", (int)(game->fov->wall_witch[i + 1][1]));
					// printf(BACK_YELLOW"toggle_vision[i - 1]: %c"RST"\n", game->fov->toggle_vision[i - 1]);
					// printf(BACK_YELLOW"toggle_vision[i]: %c"RST"\n", game->fov->toggle_vision[i]);
					// printf(BACK_YELLOW"toggle_vision[i + 1]: %c"RST"\n", game->fov->toggle_vision[i + 1]);
					// printf("\n");
				// }
			}
		}
		if (game->fov->angle >= 180 && game->fov->angle < 360)
		{
			if ((((int)(game->fov->wall_witch[i][0]) % game->img_size == 0)
			&& ((int)(game->fov->wall_witch[i + 1][0]) % game->img_size == 0))
			&& (((int)(game->fov->wall_witch[i][1]) % game->img_size != 0)
			&& ((int)(game->fov->wall_witch[i + 1][1]) % game->img_size != 0)))
			{
				game->fov->toggle_vision[i] = 'E';
				if (game->fov->toggle_vision[i - 1] != game->fov->toggle_vision[i]
				&& game->fov->toggle_vision[i + 1] != game->fov->toggle_vision[i])
				{
					// printf("here EAST\n");
					game->fov->toggle_vision[i] = game->fov->toggle_vision[i + 1];
				}
					// printf(BACK_YELLOW"toggle_vision[i - 1]: %c"RST"\n", game->fov->toggle_vision[i - 1]);
					// printf(BACK_YELLOW"toggle_vision[i]: %c"RST"\n", game->fov->toggle_vision[i]);
					// printf(BACK_YELLOW"toggle_vision[i + 1]: %c"RST"\n", game->fov->toggle_vision[i + 1]);
					// printf("\n\n");
				// if (game->fov->toggle_vision[i] != 'W')
				// {
					// printf("[i][0]: %d\t", (int)(game->fov->wall_witch[i][0]));
					// printf("[i][1]: %d\n", (int)(game->fov->wall_witch[i][1]));
					// printf("[i + 1][0]: %d\t", (int)(game->fov->wall_witch[i + 1][0]));
					// printf("[i + 1][1]: %d\n", (int)(game->fov->wall_witch[i + 1][1]));
					// printf(BACK_YELLOW"toggle_vision[i - 1]: %c"RST"\n", game->fov->toggle_vision[i - 1]);
					// printf(BACK_YELLOW"toggle_vision[i]: %c"RST"\n", game->fov->toggle_vision[i]);
					// printf(BACK_YELLOW"toggle_vision[i + 1]: %c"RST"\n", game->fov->toggle_vision[i + 1]);
					// printf("\n");
				// }
			}
		}
		if ((game->fov->angle >= 90 && game->fov->angle < 270))
		{
			if ((((int)(game->fov->wall_witch[i][0]) % game->img_size != 0)
			&& ((int)(game->fov->wall_witch[i + 1][0]) % game->img_size != 0))
			&& (((int)(game->fov->wall_witch[i][1]) % game->img_size == 0)
			&& ((int)(game->fov->wall_witch[i + 1][1]) % game->img_size == 0)))
			{
				game->fov->toggle_vision[i] = 'N';
				if (game->fov->toggle_vision[i - 1] != game->fov->toggle_vision[i]
				&& game->fov->toggle_vision[i + 1] != game->fov->toggle_vision[i])
				{
					// printf("here NORTH\n");
					game->fov->toggle_vision[i] = game->fov->toggle_vision[i + 1];
				}
				// if (game->fov->toggle_vision[i] != 'W')
				// {
					// printf("[i][0]: %d\t", (int)(game->fov->wall_witch[i][0]));
					// printf("[i][1]: %d\n", (int)(game->fov->wall_witch[i][1]));
					// printf("[i + 1][0]: %d\t", (int)(game->fov->wall_witch[i + 1][0]));
					// printf("[i + 1][1]: %d\n", (int)(game->fov->wall_witch[i + 1][1]));
					// printf(BACK_YELLOW"toggle_vision[i - 1]: %c"RST"\n", game->fov->toggle_vision[i - 1]);
					// printf(BACK_YELLOW"toggle_vision[i]: %c"RST"\n", game->fov->toggle_vision[i]);
					// printf(BACK_YELLOW"toggle_vision[i + 1]: %c"RST"\n", game->fov->toggle_vision[i + 1]);
				// printf("\n");
				// }
			}
		}

		// else
		// {
		// 	if (round(game->fov->wall_witch[i][0]) == round(game->fov->wall_witch[i + 1][0]))
		// 		game->fov->toggle_vision[i] = 'W';
		// }
		i++;
	}
	return (SUCCESS);
}

