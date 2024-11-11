/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pong.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 00:58:03 by sperron           #+#    #+#             */
/*   Updated: 2024/11/11 01:22:06 by sperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pong.h"

void	reset_ball(t_data *data, int player)
{
	data->ball_speed = BALL_SPEED;
	data->ball_x = WIN_WIDTH / 2 - BALL_SIZE / 2;
	data->ball_y = WIN_HEIGHT / 2 - BALL_SIZE / 2;
	data->ball_dx = data->ball_speed;
	data->ball_dy = data->ball_speed;
	if (player == 1)
		data->score1++;
	else
		data->score2++;
}

void	move_paddles(t_data *data)
{
	if (data->paddle1_up && data->paddle1_y > 0)
		data->paddle1_y -= PADDLE_SPEED;
	if (data->paddle1_down && data->paddle1_y < WIN_HEIGHT - PADDLE_HEIGHT)
		data->paddle1_y += PADDLE_SPEED;
	if (data->paddle2_up && data->paddle2_y > 0)
		data->paddle2_y -= PADDLE_SPEED;
	if (data->paddle2_down && data->paddle2_y < WIN_HEIGHT - PADDLE_HEIGHT)
		data->paddle2_y += PADDLE_SPEED;
}

int	render_next_frame(t_data *data)
{
	t_rect	paddle1;
	t_rect	paddle2;
	t_rect	ball;

	mlx_clear_window(data->mlx, data->win);
	paddle1 = (t_rect){50, data->paddle1_y, PADDLE_WIDTH, PADDLE_HEIGHT};
	paddle2 = (t_rect){WIN_WIDTH - 50 - PADDLE_WIDTH, data->paddle2_y, \
	PADDLE_WIDTH, PADDLE_HEIGHT};
	ball = (t_rect){data->ball_x, data->ball_y, BALL_SIZE, BALL_SIZE};
	draw_rect(data, paddle1);
	draw_rect(data, paddle2);
	draw_rect(data, ball);
	draw_center_lines(data);
	draw_score(data);
	data->ball_x += data->ball_dx;
	data->ball_y += data->ball_dy;
	check_collision(data);
	move_paddles(data);
	usleep(10000);
	return (0);
}

void	initialize_game(t_data *data)
{
	mlx_hook(data->win, 2, 1L << 0, key_press, data);
	mlx_hook(data->win, 3, 1L << 1, key_release, data);
	data->paddle1_y = WIN_HEIGHT / 2 - PADDLE_HEIGHT / 2;
	data->paddle2_y = WIN_HEIGHT / 2 - PADDLE_HEIGHT / 2;
	data->ball_x = WIN_WIDTH / 2 - BALL_SIZE / 2;
	data->ball_y = WIN_HEIGHT / 2 - BALL_SIZE / 2;
	data->ball_dx = BALL_SPEED;
	data->ball_dy = BALL_SPEED;
	data->ball_speed = BALL_SPEED;
	data->paddle1_up = 0;
	data->paddle1_down = 0;
	data->paddle2_up = 0;
	data->paddle2_down = 0;
	data->score1 = 0;
	data->score2 = 0;
}

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac >= 2)
		return (1);
	(void)av;
	data = malloc(sizeof(t_data));
	if (!data)
		return (1);
	data->mlx = mlx_init();
	if (!data->mlx)
		return (free(data), 1);
	data->win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "Pong");
	if (!data->win)
		return (free(data), free(data->mlx), 1);
	return (initialize_game(data), mlx_loop_hook(data->mlx, \
	render_next_frame, data), mlx_loop(data->mlx), \
	mlx_destroy_window(data->mlx, data->win), \
	mlx_destroy_display(data->mlx), free(data->mlx), \
	free(data), 0);
}
