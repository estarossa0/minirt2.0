/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 18:53:59 by arraji            #+#    #+#             */
/*   Updated: 2020/11/01 04:50:19 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		die(void)
{
	exit(0);
	return (0);
}

int		is_pressed(int button)
{
	if (button == SDLK_KP_8 || button == SDLK_KP_2 || button == SDLK_KP_4 ||
	button == SDLK_KP_6 || button == SDLK_UP || button == SDLK_DOWN ||
	button == SDLK_KP_9 || button == SDLK_KP_7
	|| button == SDLK_KP_1|| button == SDLK_KP_3 || button == SDLK_r)
		return (1);
	return (0);
}

void	hooks_midleware(int button, t_all *all)
{
	if (button == SDLK_r)
	{
		mouse_move();
		return ;
	}
	if (all->cam)
		all->rot == 0 ? camera_tran(all->a_camera, button)
		: camera_rot(all->a_camera, button);
	else
	{
		all->rot == 0 ? object_trans_midleware(all->a_obj,
		*all->a_camera, all->pos, button)
		: object_rot_midleware(all->a_obj, *all->a_camera, all->pos, button);
	}
}

int		control(int button, t_all *all)
{
	if (button == SDLK_p || button == SDLK_n)
	{
		all->a_camera = button == KEY_P ? all->a_camera->previous
		: all->a_camera->next;
		refresh(all);
	}
	else if (button == SDLK_ESCAPE)
		die();
	else if (button == SDLK_SPACE)
		all->rot = all->rot == 1 ? 0 : 1;
	else if (is_pressed(button))
	{
		hooks_midleware(button, all);
		refresh(all);
	}
	return (0);
}

void	hook(t_all all)
{
	SDL_Event e;

	if (all.save == 0)
	{
		while (1)
		{
			while (SDL_PollEvent(&e))
			{
				if( e.type == SDL_QUIT)
					die();
				else if (e.type == SDL_MOUSEBUTTONUP)
					get_obj(e.button.button, e.button.x, e.button.y, &all);
				else if (e.type == SDL_KEYDOWN)
					control(e.key.keysym.sym, &all);
				else if (e.type == SDL_WINDOWEVENT)
					if (e.window.event == SDL_WINDOWEVENT_SIZE_CHANGED)
						{
							all.wind->wind_x = e.window.data1;
							all.wind->wind_y = e.window.data2;
							refresh(&all);
						}
			}
		}
	}
}
