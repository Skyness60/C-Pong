/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 01:05:10 by sperron           #+#    #+#             */
/*   Updated: 2024/11/11 01:15:06 by sperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pong.h"

void	check_paddle1_collision(t_data *data)
{
	if (data->ball_dx < 0 && data->ball_x > 0 && data->ball_x <= 50 + \
			PADDLE_WIDTH && data->ball_y + BALL_SIZE >= data->paddle1_y && \
		data->ball_y <= data->paddle1_y + PADDLE_HEIGHT)
	{
		if (data->ball_x + BALL_SIZE > 50)
		{
			data->ball_dx = -data->ball_dx;
			if (data->ball_speed != 10)
				data->ball_speed += 1;
			if (data->ball_dx > 0)
				data->ball_dx = data->ball_speed;
			else
				data->ball_dx = -data->ball_speed;
			if (data->ball_dy > 0)
				data->ball_dy = data->ball_speed;
			else
				data->ball_dy = -data->ball_speed;
		}
	}
}

void	check_paddle_collision(t_data *data)
{
	check_paddle1_collision(data);
	if (data->ball_dx > 0 && data->ball_x < WIN_WIDTH - BALL_SIZE && \
		data->ball_x >= WIN_WIDTH - 50 - PADDLE_WIDTH - BALL_SIZE && \
		data->ball_y + BALL_SIZE >= data->paddle2_y && \
		data->ball_y <= data->paddle2_y + PADDLE_HEIGHT)
	{
		if (data->ball_x < WIN_WIDTH - 50)
		{
			data->ball_dx = -data->ball_dx;
			if (data->ball_speed != 10)
				data->ball_speed += 1;
			if (data->ball_dx > 0)
				data->ball_dx = data->ball_speed;
			else
				data->ball_dx = -data->ball_speed;
			if (data->ball_dy > 0)
				data->ball_dy = data->ball_speed;
			else
				data->ball_dy = -data->ball_speed;
		}
	}
}

void	check_collision(t_data *data)
{
	if (data->ball_x < 0)
		reset_ball(data, 2);
	if (data->ball_x > WIN_WIDTH - BALL_SIZE)
		reset_ball(data, 1);
	if (data->ball_y <= 0 || data->ball_y >= WIN_HEIGHT - BALL_SIZE)
		data->ball_dy = -data->ball_dy;
	check_paddle_collision(data);
}
