/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects_mov.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 23:49:44 by arraji            #+#    #+#             */
/*   Updated: 2020/11/01 04:07:47 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	mouse_move(void)
{
	int		x;
	int		y;

	SDL_GetMouseState(&x, &y);
	g_all->a_camera->l_at =
	get_ray(*g_all->a_camera, g_all->a_camera->bot, x, g_all->wind->wind_y - y);
}

int		get_obj(int button, int x, int y, t_all *all)
{
	double	t;

	t = FAR;
	if (button == 1)
	{
		all->a_camera->v_ray =
		get_ray(*all->a_camera, all->a_camera->bot, x, all->wind->wind_y - y);
		if ((all->pos = inters(all->a_obj, *all->a_camera, &t)) >= 0)
			all->cam = 0;
		else
			all->cam = 1;
	}
	if (button == 3)
		all->cam = 1;
	return (0);
}

void	object_rot_midleware(t_obj *obj, t_camera cam, int pos, int key)
{
	while (pos-- > 0)
		obj = obj->next;
	if (key == SDLK_KP_8)
		object_rot(obj, cam.right);
	else if (key == SDLK_KP_2)
		object_rot(obj, vector_mltp(cam.right, -1));
	else if (key == SDLK_KP_4)
		object_rot(obj, cam.l_at);
	else if (key == SDLK_KP_6)
		object_rot(obj, vector_mltp(cam.l_at, -1));
	else if (key == SDLK_UP)
		object_rot(obj, cam.up);
	else if (key == SDLK_DOWN)
		object_rot(obj, vector_mltp(cam.up, -1));
}

void	object_trans_midleware(t_obj *obj, t_camera camera, int pos, int button)
{
	while (pos-- > 0)
		obj = obj->next;
	if (button == SDLK_KP_8)
		object_trans(obj, camera.up);
	else if (button == SDLK_KP_2)
		object_trans(obj, vector_mltp(camera.up, -1));
	else if (button == SDLK_KP_4)
		object_trans(obj, vector_mltp(camera.right, -1));
	else if (button == SDLK_KP_6)
		object_trans(obj, camera.right);
	else if (button == SDLK_UP)
		object_trans(obj, camera.l_at);
	else if (button == SDLK_DOWN)
		object_trans(obj, vector_mltp(camera.l_at, -1));
}
