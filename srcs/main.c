/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmanet <jmanet@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 15:47:55 by jmanet            #+#    #+#             */
/*   Updated: 2023/09/01 18:43:59 by jmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/cub3d.h"



char *map[] = {
    "1111111111",
    "1000000001",
    "1000000001",
    "1001111001",
    "1000000001",
    "1000000001",
    "1000000001",
    "1000000001",
    "1000000001",
    "1111111111"
};

void mlx_player(t_data *session, int x, int y)
{
	int	size;
	int	i;
	int	j;

	size = TILE_SIZE/2;
	i = -size;
	j = -size;
	while (j < size)
	{
		while (i < size)
		{
			mlx_pixel_put(session->mlx, session->win, x + i, y + j, 0xFF0000);
			i++;
		}
		j++;
		i = -size;
	}
}

int draw_map(t_data *session)
{
	int	x;
	int	y;

	for (y = 0; y < MAP_HEIGHT; y++)
	{
		for (x = 0; x < MAP_WIDTH; x++)
		{
			if (map[y][x] == '1')
			{
				mlx_rectangle(session, x * TILE_SIZE, y * TILE_SIZE,
								(x + 1) * TILE_SIZE, (y + 1) * TILE_SIZE, 0xFFFFFF); // Couleur blanche pour les murs
			}
			else if (map[y][x] == '0')
			{
				mlx_rectangle(session, x * TILE_SIZE, y * TILE_SIZE,
								(x + 1) * TILE_SIZE, (y + 1) * TILE_SIZE, 0x000000); // Couleur noire pour les espaces vides
			}

		}
	}
	mlx_player(session, session->player_x * TILE_SIZE, session->player_y * TILE_SIZE); // Couleur rouge pour le joueur (P)
	return (0);
}



void mlx_rectangle(t_data *session, int x1, int y1, int x2, int y2, int color)
{
	int x, y;

	for (x = x1; x < x2; x++)
	{
		for (y = y1; y < y2; y++)
		{
			mlx_pixel_put(session->mlx, session->win, x, y, color);
		}
	}
}
int	ft_exit(t_data *session)
{
	(void)session;
	exit (0);
}

void ft_move_player(t_data *session, int key_input)
{
	int x = 0;
	int y = 0;



	if (key_input == 0)
	{
		x = (int)(session->player_x - 0.1);
		y = (int)(session->player_y);
		printf("x = %i, y = %i\n", x, y);
		printf("map[%i][%i] = %c\n", x, y, map[x][y]);
		if (map[y][x] != '1')
			session->player_x -= 0.1;
	}
	if (key_input == 2)
	{
		x = (int)(session->player_x + 0.1);
		y = (int)(session->player_y);
		if (map[y][x] != '1')
			session->player_x += 0.1;
	}
	if (key_input == 1)
	{
		x = (int)(session->player_x);
		y = (int)(session->player_y + 0.1);
		if (map[y][x] != '1')
			session->player_y += 0.1;
	}
	if (key_input == 13)
	{
		x = (int)(session->player_x);
		y = (int)(session->player_y - 0.1);
		if (map[y][x] != '1')
			session->player_y -= 0.1;
	}

	printf("position du joueur : x=%f , y=%f\n", session->player_x, session->player_y);
}

int	ft_keypress(int key_input, t_data *session)
{
	(void)session;

	printf("La touche enfoncee est : %i\n", key_input);
	if (key_input == 53)
		ft_exit(session);
	ft_move_player(session, key_input);
	return (0);
}

void	data_init(t_data *session)
{
	session->winheight = MAP_HEIGHT;
	session->winwidth = MAP_WIDTH;
	session->player_x = 2;
	session->player_y = 2;
}
int	main(int argc, char **argv)
{
	t_data	session;

	(void)argc;
	(void)argv;

	//if (argc != 2)
	//	ft_exit_maperror(8, &session);
	//session.mapfile = argv[1];
	//check_map_name(&session);
	//session.map = ft_importmap(&session);
	data_init(&session);
	//check_map(&session);
	session.mlx = mlx_init();
	session.win = mlx_new_window(session.mlx, MAP_WIDTH * TILE_SIZE, MAP_HEIGHT * TILE_SIZE, "Map Viewer");
	mlx_hook(session.win, 2, 1L << 0, ft_keypress, &session);
	mlx_hook(session.win, 17, 0L, ft_exit, &session);
	draw_map(&session);
	// first_stream(&session);
	mlx_loop_hook(session.mlx, draw_map, &session);
	mlx_loop(session.mlx);
	return (0);
}
