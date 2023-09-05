/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmanet <jmanet@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:45:53 by jmanet            #+#    #+#             */
/*   Updated: 2023/09/05 18:02:50 by jmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_move_forward(t_data *session)
{
	int		x;
	int		y;
	double	direction_x;
	double	direction_y;

	direction_x = cos((session->player_angle_view) * M_PI / 180);
	direction_y = sin((session->player_angle_view) * M_PI / 180);
	x = (int)(session->player_x + (direction_x / 2));
	y = (int)(session->player_y + (direction_y / 2));
	if (map[y][x] != '1')
	{
		session->player_x += (direction_x / 2);
		session->player_y += (direction_y / 2);
	}
}

void	ft_move_backward(t_data *session)
{
	int		x;
	int		y;
	double	direction_x;
	double	direction_y;

	direction_x = cos((session->player_angle_view) * M_PI / 180);
	direction_y = sin((session->player_angle_view) * M_PI / 180);
	x = (int)(session->player_x - (direction_x / 2));
	y = (int)(session->player_y - (direction_y / 2));
	if (map[y][x] != '1')
	{
		session->player_x -= (direction_x / 2);
		session->player_y -= (direction_y / 2);
	}
}

void	ft_move_left(t_data *session)
{
	int		x;
	int		y;
	double	direction_x;
	double	direction_y;

	direction_x = cos((session->player_angle_view - 90) * M_PI / 180);
	direction_y = sin((session->player_angle_view - 90) * M_PI / 180);
	x = (int)(session->player_x + (direction_x / 2));
	y = (int)(session->player_y + (direction_y / 2));
	if (map[y][x] != '1')
	{
		session->player_x += (direction_x / 2);
		session->player_y += (direction_y / 2);
	}
}

void	ft_move_right(t_data *session)
{
	int		x;
	int		y;
	double	direction_x;
	double	direction_y;

	direction_x = cos((session->player_angle_view + 90) * M_PI / 180);
	direction_y = sin((session->player_angle_view + 90) * M_PI / 180);
	x = (int)(session->player_x + (direction_x / 2));
	y = (int)(session->player_y + (direction_y / 2));
	if (map[y][x] != '1')
	{
		session->player_x += (direction_x / 2);
		session->player_y += (direction_y / 2);
	}
}

void	ft_move_player(t_data *session, int key_input)
{

	if (key_input == 13)
		ft_move_forward(session);
	if (key_input == 1)
	{
		ft_move_backward(session);
	}
	if (key_input == 0)
	{
		ft_move_left(session);
	}
		if (key_input == 2)
	{
		ft_move_right(session);
	}

}
