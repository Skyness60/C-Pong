/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 01:03:48 by sperron           #+#    #+#             */
/*   Updated: 2024/11/11 01:19:57 by sperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pong.h"

void	draw_rect(t_data *data, t_rect rect)
{
	int	i;
	int	j;

	i = -1;
	while (++i < rect.width)
	{
		j = -1;
		while (++j < rect.height)
			mlx_pixel_put(data->mlx, data->win, rect.x + i, rect.y + j, \
			0xFFFFFF);
	}
}

void	draw_center_lines(t_data *data)
{
	int		x;
	int		y;
	int		height;
	t_rect	rect;

	x = WIN_WIDTH / 2 - 5;
	y = 0;
	height = WIN_HEIGHT;
	while (y < height)
	{
		rect.x = x;
		rect.y = y;
		rect.width = 5;
		rect.height = 10;
		draw_rect(data, rect);
		y += 20;
	}
}

void	draw_score(t_data *data)
{
	char	score1_str[10];
	char	score2_str[10];
	int		score1_x;
	int		score2_x;
	int		score_y;

	snprintf(score1_str, sizeof(score1_str), "%d", data->score1);
	snprintf(score2_str, sizeof(score2_str), "%d", data->score2);
	score1_x = WIN_WIDTH / 2 - 100;
	score2_x = WIN_WIDTH / 2 + 80;
	score_y = 50;
	mlx_string_put(data->mlx, data->win, score1_x, score_y, \
	0xFFFFFF, score1_str);
	mlx_string_put(data->mlx, data->win, score2_x, score_y, \
	0xFFFFFF, score2_str);
}
