// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   fitter.c                                           :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: mael <mael@student.42.fr>                  +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2023/07/18 17:05:42 by mael              #+#    #+#             */
// /*   Updated: 2023/07/19 13:49:18 by mael             ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "cub3D.h"

void	print_tab_wall(t_game *game)
{
	int i;

	i = game->fov->nbr_ray;
	while (i > game->fov->nbr_ray / 2)
	{
		// printf(BLUE"game->fov->wall[%i][0]: %i\n"RST, i, game->fov->wall[i][0]);//, (int)round((game->fov->wall[i][0] / game->img_size)));
		// printf(BLUE"game->fov->wall[%i][1]: %i\n\n"RST, i, game->fov->wall[i][1]);//, (int)round((game->fov->wall[i][1] / game->img_size)));
		i--;
	}
	i = 0;
	while (i <= game->fov->nbr_ray / 2)
	{
		// printf(RED"game->fov->wall[%i][0]: %i\n"RST, i, game->fov->wall[i][0]);//, (int)round((game->fov->wall[i][0] / game->img_size)));
		// printf(RED"game->fov->wall[%i][1]: %i\n\n"RST, i, game->fov->wall[i][1]);//, (int)round((game->fov->wall[i][1] / game->img_size)));
		i++;
	}

}

// ---------- BY CORNER ----------

void	fitter_blue(t_game *game)
{
	int	i_fit;
	int	i_start;
	int	one;
	int	two;
	int	i_one;
	int	i_two;
	int	increase;

	increase = 0;
	one = 0;
	two = 0;
	i_one = 0;
	i_two = 0;
	i_fit = game->fov->nbr_ray / 2;
	i_start = 0;
	while (i_fit < game->fov->nbr_ray)
	{
		if (i_fit < game->fov->nbr_ray &&
		game->fov->wall[i_fit][0] == game->fov->wall[i_fit - 1][0] &&
		game->fov->wall[i_fit][1] == game->fov->wall[i_fit - 1][1] &&
		is_increase_blue(game, i_fit) == SUCCESS)
		{
			i_one = 0;
			i_two = 0;
			i_start = i_fit;
			// increase = is_increase_blue(game, i_fit);
			one = game->fov->toggle_vision[i_fit];
			while (i_fit < game->fov->nbr_ray &&
			game->fov->wall[i_fit][0] == game->fov->wall[i_fit - 1][0] &&
			game->fov->wall[i_fit][1] == game->fov->wall[i_fit - 1][1] &&
			is_increase_blue(game, i_fit) == SUCCESS)
			{
				// printf(BACK_GREEN"\t\t\t\t\t\t\t\t\taller"RST"\n");
				if (game->fov->toggle_vision[i_fit] == one)
					i_one++;
				else
				{
					two = game->fov->toggle_vision[i_fit];
					i_two++;
				}
				i_fit++;
			}
			while (i_fit > i_start)
			{
				// printf(BACK_RED"\t\t\t\t\t\t\t\t\tretour"RST"\n");
				if (i_one > i_two)
					game->fov->toggle_vision[i_fit] = one;
				else
					game->fov->toggle_vision[i_fit] = two;
				i_fit--;
			}
			if (i_one > 0 || i_two > 0)
				i_fit = i_start;
			while (i_fit < game->fov->nbr_ray &&
			game->fov->wall[i_fit][0] == game->fov->wall[i_fit - 1][0] &&
			game->fov->wall[i_fit][1] == game->fov->wall[i_fit - 1][1] &&
			is_increase_blue(game, i_fit) == SUCCESS)
			{
				// printf(BACK_BLUE"\t\t\t\t\t\t\t\t\tgo _back"RST"\n");
				i_fit++;
			}
		}
		else
			i_fit++;
	}
	(void)increase;
}

int	is_increase_blue(t_game *game, int i_fit)
{

	// while (game->fov->lines_vision[i_fit - 1] &&
	// game->fov->lines_vision[i_fit] == game->fov->lines_vision[i_fit - 1] &&
	// game->fov->wall[i_fit][0] == game->fov->wall[i_fit - 1][0] &&
	// game->fov->wall[i_fit][1] == game->fov->wall[i_fit - 1][1])
	// {
	// 	i_fit--;

	// printf(GREEN"game->fov->wall_witch[%i][1] %% game->img_size: %i"RST"\n", i_fit, ((int)game->fov->wall_witch[i_fit][1]) % game->img_size);
	// printf(GREEN"game->fov->wall_witch[%i][0] %% game->img_size: %i"RST"\n\n", i_fit, ((int)game->fov->wall_witch[i_fit][0]) % game->img_size);
	// printf(BOLD_GREEN"game->fov->wall_witch[%i][1] %% game->img_size: %i"RST"\n", i_fit, ((int)game->fov->wall_witch[i_fit][1]) % game->img_size == 0);
	// printf(BOLD_GREEN"game->fov->wall_witch[%i][0] %% game->img_size: %i"RST"\n\n", i_fit, ((int)game->fov->wall_witch[i_fit][0]) % game->img_size == 0);
	int	i = 0;
	// printf("A\n");
	if (((int)(game->fov->wall_witch[i_fit][0]) % game->img_size == 0 \
	&& (int)(game->fov->wall_witch[i_fit][1]) % game->img_size == 0))
	{
		//printf(BACK_RED" hit end "RST"\n");
		// img_pix_put(game, round(game->fov->wall_witch[i_fit][0]), round(game->fov->wall_witch[i_fit][1]), get_color(255, 0, 255));
		cross(game, i_fit, 0, 0);
		return (FAIL);
	}
	else if (((int)(game->fov->wall_witch[i_fit + 1][0]) % game->img_size != 0 \
	|| (int)(game->fov->wall_witch[i_fit + 1][1]) % game->img_size != 0))
	{
		if (((int)(game->fov->wall_witch[i_fit][0]) == (int)(game->fov->wall_witch[i_fit + 1][0])))
		{
			//printf(YELLOW"vertical"RESET"\n");
			if (game->fov->angle >= 180 && game->fov->angle < 360)
			{
				i = 0;
				while (i <= 20)
				{
					// printf(UNDER_BLUE"x: %i", (int)(game->fov->wall_witch[i_fit][0]) - 1);
					// printf("\tx: %i", (int)(game->fov->wall_witch[i_fit][0]));
					// printf("\tx: %i\t", (int)(game->fov->wall_witch[i_fit][0]) + 1);
					// printf(BLUE" y: %i"RESET"\t", (int)(game->fov->wall_witch[i_fit][1] + i));

					// printf(BACK_BLUE"(%i, ", ((int)(game->fov->wall_witch[i_fit][0])) % game->img_size);
					// printf("%i)"RESET"\n", ((int)(game->fov->wall_witch[i_fit][1]) + i) % game->img_size);

					if ((((int)(game->fov->wall_witch[i_fit][0])) % game->img_size == 0
					|| ((int)(game->fov->wall_witch[i_fit][0]) - 1) % game->img_size == 0
					|| ((int)(game->fov->wall_witch[i_fit][0]) + 1) % game->img_size == 0)
					&& ((int)(game->fov->wall_witch[i_fit][1]) + i) % game->img_size == 0)
					{
						img_pix_put(game, round(game->fov->wall_witch[i_fit][0]) , round(game->fov->wall_witch[i_fit][1]) + i, get_color(0, 255, 0));
						//printf(BACK_RED" hit "RESET"\n");
						i = 0;
						while (i <= 20)
						{
							printf("x   0 : %i\n", ((int)(game->fov->wall_witch[i_fit + 1][0])) % game->img_size);
							printf("x - 1): %i\n", ((int)(game->fov->wall_witch[i_fit + 1][0]) - 1) % game->img_size);
							printf("x + 1): %i\n", ((int)(game->fov->wall_witch[i_fit + 1][0]) + 1) % game->img_size);
							printf("y + i): %i\n", ((int)(game->fov->wall_witch[i_fit + 1][1]) + i) % game->img_size);
							printf("\n");
							if ((((int)(game->fov->wall_witch[i_fit + 1][0])) % game->img_size == 0
							  || ((int)(game->fov->wall_witch[i_fit + 1][0]) - 1) % game->img_size == 0
							  || ((int)(game->fov->wall_witch[i_fit + 1][0]) + 1) % game->img_size == 0)
							  && ((int)(game->fov->wall_witch[i_fit + 1][1]) - i) % game->img_size == 0)
							{
								cross(game, i_fit + 1, 0, -i);
								return (FAIL);
							}
							i++;
						}
						printf("------------------------------\n");
					}
					i++;
				}
				// printf("------------------------------\n");
			}
			else if (game->fov->angle >= 0 && game ->fov->angle < 180)
			{
				i = 0;
				while (i <= 20)
				{
					// printf(BOLD_BLUE"x: %i", (int)(game->fov->wall_witch[i_fit][0]) - 1);
					// printf("\tx: %i", (int)(game->fov->wall_witch[i_fit][0]));
					// printf("\tx: %i\t", (int)(game->fov->wall_witch[i_fit][0]) + 1);
					// printf(BLUE" y: %i"RESET"\t", (int)(game->fov->wall_witch[i_fit][1] - i));

					// printf(BOLD_BLUE"(%i, ", ((int)(game->fov->wall_witch[i_fit][0])) % game->img_size);
					// printf("%i)"RESET"\n", ((int)(game->fov->wall_witch[i_fit][1]) - i) % game->img_size);

					// img_pix_put(game, round(game->fov->wall_witch[i_fit][0]) + 1, round(game->fov->wall_witch[i_fit][1]) + i, get_color(255, 255, 0));
					if ((((int)(game->fov->wall_witch[i_fit][0])) % game->img_size == 0
					|| ((int)(game->fov->wall_witch[i_fit][0])) - 1 % game->img_size == 0
					|| ((int)(game->fov->wall_witch[i_fit][0])) + 1 % game->img_size == 0)
					&& ((int)(game->fov->wall_witch[i_fit][1]) - i) % game->img_size == 0)
					{
						i = 0;
						while (i <= 20)
						{
							if ((((int)(game->fov->wall_witch[i_fit + 1][0])) % game->img_size == 0
							|| ((int)(game->fov->wall_witch[i_fit + 1][0])) - 1 % game->img_size == 0
							|| ((int)(game->fov->wall_witch[i_fit + 1][0]) + 1) % game->img_size == 0)
							&& ((int)(game->fov->wall_witch[i_fit + 1][1]) + i) % game->img_size == 0)
							{
								cross(game, i_fit + 1, 0, i);
								return (FAIL);
							}
							i++;
						}
					}
						// printf(BACK_RED" hit "RESET"\n");
						// cross(game, i_fit, 0, -i);
						// return (FAIL);
					i++;
				}
				// printf("------------------------------\n");
			}
		}
		else if ((int)(game->fov->wall_witch[i_fit][1]) == (int)(game->fov->wall_witch[i_fit + 1][1]))
		{
			//printf(GREEN"hrz"RESET"\n");
			if ((game->fov->angle > 270 && game->fov->angle < 360) || (game->fov->angle >= 0 && game->fov->angle < 90))
			{
				i = -1;
				// if ((int)(game->fov->wall_witch[i_fit][1]) < 160)
				// {
				// 	printf(GREEN"x: %i\t"BOLD_WHITE, (int)(game->fov->wall_witch[i_fit][0]) + i);
				// 	printf(" y: %i", (int)(game->fov->wall_witch[i_fit][1]) - 1);
				// 	printf(" y: %i", (int)(game->fov->wall_witch[i_fit][1]));
				// 	printf(" y: %i"RESET"\t", (int)(game->fov->wall_witch[i_fit][1]) + 1);

				// 	printf(GREEN"(%i, ", ((int)(game->fov->wall_witch[i_fit][0]) + i) % game->img_size);
				// 	printf("%i)"RESET" ", ((int)(game->fov->wall_witch[i_fit][1]) - 1) % game->img_size);
				// 	printf("%i)"RESET" ", ((int)(game->fov->wall_witch[i_fit][1])) % game->img_size);
				// 	printf("%i)"RESET"\n", ((int)(game->fov->wall_witch[i_fit][1]) + 1) % game->img_size);
				// }
				// img_pix_put(game, round(game->fov->wall_witch[i_fit][0]) - i, round(game->fov->wall_witch[i_fit][1]) + 1, get_color(255, 0, 255));
				while (i <= 20)
				{
					if (((int)(game->fov->wall_witch[i_fit][0]) - i) % game->img_size == 0
					&& (((int)(game->fov->wall_witch[i_fit][1])) % game->img_size == 0
					|| ((int)(game->fov->wall_witch[i_fit][1]) - 1) % game->img_size == 0
					|| ((int)(game->fov->wall_witch[i_fit][1]) + 1) % game->img_size == 0))
					{
						// cross(game, i_fit, -i, 0);
						i = -1;
						while (i <= 20)
						{

							if ((((int)(game->fov->wall_witch[i_fit + 1][1]) % game->img_size == 0)
							|| (((int)(game->fov->wall_witch[i_fit + 1][1]) - 1) % game->img_size == 0)
							|| (((int)(game->fov->wall_witch[i_fit + 1][1]) + 1) % game->img_size == 0))
							&& ((int)(game->fov->wall_witch[i_fit + 1][0]) + i) % game->img_size == 0)
							{
								cross(game, i_fit + 1, i, 0);
								return (FAIL);
							}
							i++;
						}
					}
						// if ((int)(game->fov->wall_witch[i_fit][1]) < 160)
						// 	printf("------------------------------\n");
						// printf(BACK_RED" hit "RESET"\n");
						// cross(game, i_fit, -i, 0);
						// return (FAIL);
					i++;
				}

				// printf("------------------------------\n");
			}
			else if (game->fov->angle >= 90 && game ->fov->angle <= 270)
			{
				i = -1;
				while (i <= 20)
				{
					// printf(UNDER_GREEN"x: %i\t"GREEN, (int)(game->fov->wall_witch[i_fit][0]) + i);
					// printf(" y: %i", (int)(game->fov->wall_witch[i_fit][1]) - 1);
					// printf(" y: %i", (int)(game->fov->wall_witch[i_fit][1]) + 1);
					// printf(" y: %i"RESET"\t", (int)(game->fov->wall_witch[i_fit][1]));
					// printf(UNDER_GREEN"(%i, ", ((int)(game->fov->wall_witch[i_fit][0]) + i) % game->img_size);
					// printf("%i)"RESET"\n", ((int)(game->fov->wall_witch[i_fit][1])) % game->img_size);
					// img_pix_put(game, round(game->fov->wall_witch[i_fit + 1][0]) + i, round(game->fov->wall_witch[i_fit + 1][1]) + 1, get_color(75, 75, 75));
					if (((int)(game->fov->wall_witch[i_fit][0]) + i) % game->img_size == 0
					&& (((int)(game->fov->wall_witch[i_fit][1])) % game->img_size == 0
					|| ((int)(game->fov->wall_witch[i_fit][1]) - 1) % game->img_size == 0
					|| ((int)(game->fov->wall_witch[i_fit][1]) + 1) % game->img_size == 0))
					{
						// cross(game, i_fit, i, 0);
						// return (FAIL);
						i = -1;
						while (i <= 20)
						{
							img_pix_put(game, round(game->fov->wall_witch[i_fit + 1][0]) - i, round(game->fov->wall_witch[i_fit + 1][1]) + 1, get_color(0, 0, 0));
							if ((((int)(game->fov->wall_witch[i_fit + 1][1]) % game->img_size == 0)
							|| (((int)(game->fov->wall_witch[i_fit + 1][1]) - 1) % game->img_size == 0)
							|| (((int)(game->fov->wall_witch[i_fit + 1][1]) + 1) % game->img_size == 0))
							&& ((int)(game->fov->wall_witch[i_fit + 1][0]) - i) % game->img_size == 0)
							{
								cross(game, i_fit + 1, -i, 0);
								return (FAIL);
							}
							i++;
						}
					}
					i++;
						// printf(BACK_RED" hit "RESET"\n");
						// cross(game, i_fit, i, 0);
						// return (FAIL);
				}
				i++;

				// printf("------------------------------\n");
			}
		}
		// printf("D\n");
		return (SUCCESS);
	}
	else
		return (SUCCESS);
	// else
	// {
	// 	printf(BLUE"game->fov->wall_witch[%i][1] %% game->img_size: %i"RESET"\n", i_fit, ((int)game->fov->wall_witch[i_fit][1]) % game->img_size);
	// 	printf(BLUE"game->fov->wall_witch[%i][0] %% game->img_size: %i"RESET"\n\n", i_fit, ((int)game->fov->wall_witch[i_fit][0]) % game->img_size);
	// }
	//i_fit--;
	// if (game->fov->lines_vision[i_fit] > game->fov->lines_vision[i_fit - 1])
	// 	return (FAIL);
	// else
	// 	return (SUCCESS);
}

void	fitter_red(t_game *game)
{
	int	i_fit;
	int	i_start;
	int	one;
	int	two;
	int	i_one;
	int	i_two;
	int	increase;

	increase = 0;
	one = 0;
	two = 0;
	i_one = 0;
	i_two = 0;
	i_fit = 0;
	i_start = 0;
	while (i_fit < game->fov->nbr_ray / 2)
	{
		if (i_fit < game->fov->nbr_ray / 2 && game->fov->wall[i_fit][0] == game->fov->wall[i_fit + 1][0] && game->fov->wall[i_fit][1] == game->fov->wall[i_fit + 1][1])
		{
			i_one = 0;
			i_two = 0;
			i_start = i_fit;
			one = game->fov->toggle_vision[i_fit];
			increase = is_increase_red(game, i_fit);
			while (i_fit < game->fov->nbr_ray / 2 &&
			game->fov->wall[i_fit][0] == game->fov->wall[i_fit + 1][0] &&
			game->fov->wall[i_fit][1] == game->fov->wall[i_fit + 1][1] &&
			is_increase_red(game, i_fit) == increase)
			{
				// printf(BACK_GREEN"\t\t\t\t\t\t\t\t\taller"RST"\n");
				if (game->fov->toggle_vision[i_fit] == one)
					i_one++;
				else
				{
					two = game->fov->toggle_vision[i_fit];
					i_two++;
				}

				int	i = 0;

				// printf(BACK_PURPLE"game->fov->wall_witch[i_fit][0]: %f"RST"\n", game->fov->wall_witch[i_fit][0]);
				if (((int)(game->fov->wall_witch[i_fit][0] + 2) % game->img_size == 0 \
				&& (int)(game->fov->wall_witch[i_fit][1] + 2) % game->img_size == 0)

				|| ((int)(game->fov->wall_witch[i_fit][0] + 1) % game->img_size == 0 \
				&& (int)(game->fov->wall_witch[i_fit][1] + 2) % game->img_size == 0)

				|| ((int)(game->fov->wall_witch[i_fit][0] + 2) % game->img_size == 0 \
				&& (int)(game->fov->wall_witch[i_fit][1] + 1) % game->img_size == 0)

				|| ((int)(game->fov->wall_witch[i_fit][0] + 1) % game->img_size == 0 \
				&& (int)(game->fov->wall_witch[i_fit][1] + 1) % game->img_size == 0)

				|| ((int)(game->fov->wall_witch[i_fit][0]) % game->img_size == 0 \
				&& (int)(game->fov->wall_witch[i_fit][1] + 1) % game->img_size == 0)

				|| ((int)(game->fov->wall_witch[i_fit][0] + 1) % game->img_size == 0 \
				&& (int)(game->fov->wall_witch[i_fit][1]) % game->img_size == 0)

				|| ((int)(game->fov->wall_witch[i_fit][0]) % game->img_size == 0 \
				&& (int)(game->fov->wall_witch[i_fit][1]) % game->img_size == 0)

				|| ((int)(game->fov->wall_witch[i_fit][0]) % game->img_size == 0 \
				&& (int)(game->fov->wall_witch[i_fit][1] - 1) % game->img_size == 0)

				|| ((int)(game->fov->wall_witch[i_fit][0] - 1) % game->img_size == 0 \
				&& (int)(game->fov->wall_witch[i_fit][1]) % game->img_size == 0)

				|| ((int)(game->fov->wall_witch[i_fit][0] - 1) % game->img_size == 0 \
				&& (int)(game->fov->wall_witch[i_fit][1] - 1) % game->img_size == 0)

				|| ((int)(game->fov->wall_witch[i_fit][0] - 1) % game->img_size == 0 \
				&& (int)(game->fov->wall_witch[i_fit][1] - 2) % game->img_size == 0)

				|| ((int)(game->fov->wall_witch[i_fit][0] - 2) % game->img_size == 0 \
				&& (int)(game->fov->wall_witch[i_fit][1] - 1) % game->img_size == 0)

				|| ((int)(game->fov->wall_witch[i_fit][0] - 2) % game->img_size == 0 \
				&& (int)(game->fov->wall_witch[i_fit][1] - 2) % game->img_size == 0))

				{
					// printf(GREEN"game->fov->wall_witch[%i][1] %% game->img_size: %i"RST"\n", i_fit, ((int)game->fov->wall_witch[i_fit][1]) % game->img_size);
					// printf(GREEN"game->fov->wall_witch[%i][0] %% game->img_size: %i"RST"\n\n", i_fit, ((int)game->fov->wall_witch[i_fit][0]) % game->img_size);
					// printf(BOLD_GREEN"game->fov->wall_witch[%i][1] %% game->img_size: %i"RST"\n", i_fit, ((int)game->fov->wall_witch[i_fit][1]) % game->img_size == 0);
					// printf(BOLD_GREEN"game->fov->wall_witch[%i][0] %% game->img_size: %i"RST"\n\n", i_fit, ((int)game->fov->wall_witch[i_fit][0]) % game->img_size == 0);
					i = -1;
					while (++i < 5)
						img_pix_put(game, round(game->fov->wall_witch[i_fit][0]), round(game->fov->wall_witch[i_fit][1]) + i, get_color(255, 0, 0));
					i = -1;
					while (++i < 5)
						img_pix_put(game, round(game->fov->wall_witch[i_fit][0]), round(game->fov->wall_witch[i_fit][1]) - i, get_color(255, 0, 0));
					i = -1;
					while (++i < 5)
						img_pix_put(game, round(game->fov->wall_witch[i_fit][0]) + i, round(game->fov->wall_witch[i_fit][1]), get_color(255, 0, 0));
					i = -1;
					while (++i < 5)
						img_pix_put(game, round(game->fov->wall_witch[i_fit][0]) - i, round(game->fov->wall_witch[i_fit][1]), get_color(255, 0, 0));
				}
				// else
				// {
				// 	printf(RED"game->fov->wall_witch[%i][1] %% game->img_size: %i"RST"\n", i_fit, (int)game->fov->wall_witch[i_fit][1] % game->img_size);
				// 	printf(RED"game->fov->wall_witch[%i][0] %% game->img_size: %i"RST"\n\n", i_fit, (int)game->fov->wall_witch[i_fit][0] % game->img_size);
				// }
				i_fit++;
			}
			while (i_fit > i_start)
			{
				// printf(BACK_RED"\t\t\t\t\t\t\t\t\tretour"RST"\n");
				if (i_one > i_two)
					game->fov->toggle_vision[i_fit] = one;
				else
					game->fov->toggle_vision[i_fit] = two;
				i_fit--;
			}
			i_fit = i_start;
			while (i_fit < game->fov->nbr_ray / 2 &&
			game->fov->wall[i_fit][0] == game->fov->wall[i_fit + 1][0] &&
			game->fov->wall[i_fit][1] == game->fov->wall[i_fit + 1][1] &&
			is_increase_red(game, i_fit) == increase)
				i_fit++;
		}
		else
			i_fit++;
	}
}

int	is_increase_red(t_game *game, int i_fit)
{
	while (game->fov->lines_vision[i_fit + 1] &&
	game->fov->lines_vision[i_fit] == game->fov->lines_vision[i_fit + 1] &&
	game->fov->wall[i_fit][0] == game->fov->wall[i_fit + 1][0] &&
	game->fov->wall[i_fit][1] == game->fov->wall[i_fit + 1][1])
		i_fit--;
	if (game->fov->lines_vision[i_fit] > game->fov->lines_vision[i_fit + 1])
		return (FAIL);
	else
		return (SUCCESS);
}

void	cross(t_game *game, int i_fit, int x_plus, int y_plus)
{
	int z;

	z = -1;
	while (++z < 5)
		img_pix_put(game, round(game->fov->wall_witch[i_fit][0]) + x_plus, round(game->fov->wall_witch[i_fit][1]) + y_plus + z, get_color(255, 0, 0));
	z = -1;
	while (++z < 5)
		img_pix_put(game, round(game->fov->wall_witch[i_fit][0]) + x_plus, round(game->fov->wall_witch[i_fit][1]) + y_plus - z, get_color(255, 0, 0));
	z = -1;
	while (++z < 5)
		img_pix_put(game, round(game->fov->wall_witch[i_fit][0]) + x_plus + z, round(game->fov->wall_witch[i_fit][1]) + y_plus, get_color(255, 0, 0));
	z = -1;
	while (++z < 5)
		img_pix_put(game, round(game->fov->wall_witch[i_fit][0]) + x_plus - z, round(game->fov->wall_witch[i_fit][1]) + y_plus, get_color(255, 0, 0));
}
