/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otamrani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 13:09:47 by otamrani          #+#    #+#             */
/*   Updated: 2023/10/11 20:04:37 by otamrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H
#include <stdlib.h>
#include <unistd.h>
#include <mlx.h>
#include <math.h>
#include <stdio.h>
#include "parsing/file.h"
#if defined(__linux__)
    #define KEY_ESC 65307
    #define KEY_UP 5
    #define KEY_DOWN 5
    #define KEY_LEFT 65361
    #define KEY_RIGHT 65363
    #define KEY_W 119
    #define KEY_A 97
    #define KEY_S 115
    #define KEY_D 100
#elif defined(__APPLE__)
    #define KEY_ESC 53
    #define KEY_UP 126
    #define KEY_DOWN 125
    #define KEY_LEFT 123
    #define KEY_RIGHT 124
    #define KEY_W 13
    #define KEY_A 0
    #define KEY_S 1
    #define KEY_D 2
#endif
void    show_map();
typedef struct	s_data {
	double 	direction;
    double     fov;
    double    ray_x;
    double    ray_y;
    double    angle;
    double    ray_angle;
    double    wall_hit_x;
    double    wall_hit_y;
    double    distance;
    double    wall_height;
    double    wall_top;
    double    wall_bottom;
    double    wall_strip_height;
    double    step_x;
    double    step_y;
    double    next_touch_x;
    double    next_touch_y;
    double    x_to_check;
    double    y_to_check;
    double    x_intercept;
    double    y_intercept;
	double 	rotation_speed;
	void	*mlx;
	void	*mlx_win;
	void    *mlx_ptr;
	double	pos_x;
	double   pos_y;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
    t_all *all;
    t_textr *txt;
	int		endian;
}				t_data;

#endif