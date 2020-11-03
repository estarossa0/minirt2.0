/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_mov.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 02:44:56 by arraji            #+#    #+#             */
/*   Updated: 2020/11/01 03:59:02 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	camera_tran(t_camera *cam, int key)
{
	if (key == SDLK_KP_8)
		cam->pos = vector_add(cam->pos, vector_mltp(cam->up, 5));
	else if (key == SDLK_KP_2)
		cam->pos = vector_add(cam->pos, vector_mltp(cam->up, -5));
	else if (key == SDLK_KP_4)
		cam->pos = vector_add(cam->pos, vector_mltp(cam->right, -5));
	else if (key == SDLK_KP_6)
		cam->pos = vector_add(cam->pos, vector_mltp(cam->right, 5));
	else if (key == SDLK_UP)
		cam->pos = vector_add(cam->pos, vector_mltp(cam->l_at, 5));
	else if (key == SDLK_DOWN)
		cam->pos = vector_add(cam->pos, vector_mltp(cam->l_at, -5));
	else if (key == SDLK_KP_9)
		cam->pos = vector_add(cam->pos, vector_add(
		vector_mltp(cam->up, 5), vector_mltp(cam->right, 5)));
	else if (key == SDLK_KP_7)
		cam->pos = vector_add(cam->pos, vector_add(
		vector_mltp(cam->up, 5), vector_mltp(cam->right, -5)));
	else if (key == SDLK_KP_1)
		cam->pos = vector_add(cam->pos, vector_add(
		vector_mltp(cam->up, -5), vector_mltp(cam->right, -5)));
	else if (key == SDLK_KP_3)
		cam->pos = vector_add(cam->pos, vector_add(
		vector_mltp(cam->up, -5), vector_mltp(cam->right, 5)));
}

void	camera_rot(t_camera *cam, int key)
{
	cam->l_at = vector_norm(cam->l_at);
	if (key == SDLK_KP_8)
		cam->l_at = rodrigues_rot(cam->l_at, cam->right, (-M_PI / 8));
	else if (key == SDLK_KP_2)
		cam->l_at = rodrigues_rot(cam->l_at, cam->right, (M_PI / 8));
	else if (key == SDLK_KP_4)
		cam->l_at = rodrigues_rot(cam->l_at, cam->up, -(M_PI / 8));
	else if (key == SDLK_KP_6)
		cam->l_at = rodrigues_rot(cam->l_at, cam->up, M_PI / 8);
	else if (key == SDLK_KP_3)
		cam->l_at = rodrigues_rot(cam->l_at,
		vector_add(cam->up, cam->right), M_PI / 8);
	else if (key == SDLK_KP_1)
		cam->l_at = rodrigues_rot(cam->l_at,
		vector_add(vector_mltp(cam->up, -1), cam->right), M_PI / 8);
	else if (key == SDLK_KP_9)
		cam->l_at = rodrigues_rot(cam->l_at,
		vector_add(cam->up, vector_mltp(cam->right, -1)), M_PI / 8);
	else if (key == SDLK_KP_7)
		cam->l_at = rodrigues_rot(cam->l_at, vector_add(
		vector_mltp(cam->up, -1), vector_mltp(cam->right, -1)), M_PI / 8);
	else if (key == SDLK_UP)
		cam->l_at = rodrigues_rot(cam->l_at, cam->up, M_PI);
}
