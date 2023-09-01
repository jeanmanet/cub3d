/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmanet <jmanet@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 16:33:48 by jmanet            #+#    #+#             */
/*   Updated: 2023/09/01 17:59:25 by jmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>

# define MAP_WIDTH 10 // Largeur de la carte
# define MAP_HEIGHT 10 // Hauteur de la carte
# define TILE_SIZE 32 // Taille d'une case (en pixels)

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		winwidth;
	int		winheight;
	float		player_x;
	float		player_y;
}	t_data;

void	mlx_rectangle(t_data *session,
			int x1, int y1, int x2, int y2, int color);

#endif
