/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmanet <jmanet@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 15:47:55 by jmanet            #+#    #+#             */
/*   Updated: 2023/09/05 16:29:24 by jmanet           ###   ########.fr       */
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

void draw_player(t_data *session, int x, int y)
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

int	draw_map(t_data *session)
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
	return (0);
}

void	trace_frame(t_data *session, int frame_height, int angle)
{
	int	i;
	int	j;
	int	startx;
	int	starty;
	int nbframe;

	i = 0;
	nbframe = (session->winwidth/100) * (PLAYER_FOV / 100);
	startx = angle * nbframe;
	starty = (session->winheight - frame_height) / 2;
	printf("nbframe = %i\n", nbframe);

	while (i < session->winheight)
	{
		j = 0;
		while (j < nbframe)
		{
			if (i < starty)
				mlx_pixel_put(session->mlx, session->win, startx + j, i, 0x00FF00);
			if (i >= starty && i < frame_height + starty)
				mlx_pixel_put(session->mlx, session->win, startx + j, i, 0xFF0000);
			if (i >= frame_height + starty)
				mlx_pixel_put(session->mlx, session->win, startx + j, i, 0x0000FF);
			j++;
		}
		i++;
	}
}


void	draw_walls(t_data *session, double ray_x, double ray_y, int angle)
{
	double delta_x = ray_x - session->player_x;
	double delta_y = ray_y - session->player_y;
	int frame_height = 0;


	double ray_length = sqrt(delta_x * delta_x + delta_y * delta_y);

	frame_height = session->winheight / ray_length;
	// printf("Longueur du rayon sur le degre %i: %f\n",angle, ray_length);
	// printf("Hauteur de la frame : %i\n", frame_height);
	trace_frame(session, frame_height, angle);


}

void draw_ray(t_data *session)
{
	double ray_direction_x;
	double ray_direction_y;
	int		i;

	session->x_ray = session->player_x * TILE_SIZE;
	session->y_ray = session->player_y * TILE_SIZE;
	i = 0;

	// ray_direction_x = cos(session->player_angle_view * M_PI / 180);
	// ray_direction_y = sin(session->player_angle_view * M_PI / 180);

	while (i <= PLAYER_FOV)
	{
		session->x_ray = session->player_x * TILE_SIZE;
		session->y_ray = session->player_y * TILE_SIZE;
		ray_direction_x = cos((session->player_angle_view + i) * M_PI / 180);
		ray_direction_y = sin((session->player_angle_view + i) * M_PI / 180);
		while (1)
		{
			// mlx_pixel_put(session->mlx, session->win, session->x_ray, session->y_ray, 0xFF0000);
			session->x_ray += ray_direction_x;
			session->y_ray += ray_direction_y;
			// printf("h : %i, w : %i\n", session->winheight, session->winwidth);
			// printf("xray : %f, yray : %f\n", session->x_ray, session->y_ray);
			// if (session->x_ray > session->winwidth || (int)session->x_ray < 0)
			if (map[(int)(session->y_ray/TILE_SIZE)][(int)(session->x_ray/TILE_SIZE)] == '1')
			{
				draw_walls(session, session->x_ray/TILE_SIZE, session->y_ray/TILE_SIZE, i );
				break ;
			}
		}
		i++;
	}
	//getchar();


}

int	ft_loop(t_data *session)
{
	// draw_map(session);
	// draw_player(session, session->player_x * TILE_SIZE, session->player_y * TILE_SIZE); // Couleur rouge pour le joueur (P)
	draw_ray(session);

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
}

int	ft_keypress(int key_input, t_data *session)
{
	(void)session;

	// printf("La touche enfoncee est : %i\n", key_input);
	if (key_input == 53)
		ft_exit(session);
	if (key_input == 123)
		session->player_angle_view -= 10;
	if (key_input == 124)
		session->player_angle_view += 10;
	ft_move_player(session, key_input);
	// printf("L'angle de vue du joureur est : %i\n", session->player_angle_view);
	return (0);
}

void	data_init(t_data *session)
{
	session->winheight = MAP_HEIGHT * TILE_SIZE;
	session->winwidth = MAP_WIDTH * TILE_SIZE;
	session->player_x = 2;
	session->player_y = 2;
	session->player_angle_view = 20;
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
	//draw_map(&session);
	// first_stream(&session);
	mlx_loop_hook(session.mlx, ft_loop, &session);
	mlx_loop(session.mlx);
	return (0);
}
