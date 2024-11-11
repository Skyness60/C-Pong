/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 01:07:22 by sperron           #+#    #+#             */
/*   Updated: 2024/11/11 01:15:29 by sperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pong.h"

void	handle_key_press(int keycode, t_data *data)
{
	if (keycode == 65362)
		data->paddle2_up = 1;
	if (keycode == 65364)
		data->paddle2_down = 1;
	if (keycode == 'z')
		data->paddle1_up = 1;
	if (keycode == 's')
		data->paddle1_down = 1;
}

int	key_press(int keycode, t_data *data)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		free(data);
		exit(0);
	}
	handle_key_press(keycode, data);
	return (0);
}

int	key_release(int keycode, t_data *data)
{
	if (keycode == 65362)
		data->paddle2_up = 0;
	if (keycode == 65364)
		data->paddle2_down = 0;
	if (keycode == 'z')
		data->paddle1_up = 0;
	if (keycode == 's')
		data->paddle1_down = 0;
	return (0);
}
