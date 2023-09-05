/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmanet <jmanet@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 16:33:48 by jmanet            #+#    #+#             */
/*   Updated: 2023/09/05 17:55:17 by jmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>

# define MAP_WIDTH 10 // Largeur de la carte
# define MAP_HEIGHT 10 // Hauteur de la carte
# define TILE_SIZE 50 // Taille d'une case (en pixels)
# define PLAYER_FOV 100 // Champ de vision du joueur

extern char *map[];

typedef struct s_data
{
	char 		**map;
	void		*mlx;
	void		*win;
	int			winwidth;
	int			winheight;
	double		player_x;
	double		player_y;
	double		player_direction_x;
	double		player_direction_y;
	int			player_angle_view;
	double		ray_direction_x;
	double		ray_direction_y;
	double		x_ray;
	double		y_ray;


}	t_data;

void	mlx_rectangle(t_data *session,
			int x1, int y1, int x2, int y2, int color);

void	ft_move_player(t_data *session, int key_input);
void	ft_move_forward(t_data *session);
void	ft_move_backward(t_data *session);
void	ft_move_left(t_data *session);
void	ft_move_right(t_data *session);

#endif
