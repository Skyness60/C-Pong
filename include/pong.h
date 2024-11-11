/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pong.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 17:42:36 by sperron           #+#    #+#             */
/*   Updated: 2024/11/11 01:24:17 by sperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PONG_H
# define PONG_H
# include <stdlib.h>
# include <unistd.h>
# include "../mlx/mlx.h"
# include <stdio.h>
# define WIN_WIDTH 800
# define WIN_HEIGHT 600
# define PADDLE_WIDTH 10
# define PADDLE_HEIGHT 100
# define BALL_SIZE 10
# define PADDLE_SPEED 10
# define BALL_SPEED 1
# define MAX_BALL_SPEED 10

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		paddle1_y;
	int		paddle2_y;
	int		ball_x;
	int		ball_y;
	int		ball_dx;
	int		ball_dy;
	int		paddle1_up;
	int		paddle1_down;
	int		paddle2_up;
	int		paddle2_down;
	int		score1;
	int		score2;
	int		ball_speed;
	int		game_time;
}				t_data;

typedef struct s_rect
{
	int		x;
	int		y;
	int		width;
	int		height;
}				t_rect;

void	draw_rect(t_data *data, t_rect rect);
void	draw_center_lines(t_data *data);
void	draw_score(t_data *data);
void	check_paddle1_collision(t_data *data);
void	check_paddle_collision(t_data *data);
void	check_collision(t_data *data);
void	handle_key_press(int keycode, t_data *data);
int		key_press(int keycode, t_data *data);
int		key_release(int keycode, t_data *data);
void	reset_ball(t_data *data, int player);
#endif // !PONG_H