/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_we_go.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 15:50:24 by arraji            #+#    #+#             */
/*   Updated: 2020/11/01 04:53:36 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		init_wind(t_all all)
{
	if ((SDL_Init( SDL_INIT_VIDEO )) < 0)
		ft_exit(E_SDL);
	if (all.save == 0)
	{
		if (!(all.wind->wind_p = SDL_CreateWindow( "Minirt2.0",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, all.wind->wind_x,
		all.wind->wind_y, SDL_WINDOW_RESIZABLE )))
			ft_exit(E_SDL);
		all.wind->wind_s = SDL_GetWindowSurface( all.wind->wind_p );
	}
}

void		init_image(t_all all)
{
	if (all.save == 0)
		all.wind->wind_s = SDL_GetWindowSurface( all.wind->wind_p );
	if (!(all.wind->img_p = SDL_CreateRGBSurface(0, all.wind->wind_x,
	all.wind->wind_y, 32, 0, 0, 0, 0)))
		ft_exit(E_SDL);
}

void		render(t_all all, t_camera camera, t_color *color, t_cord v_ray)
{
	int			pos;
	double		t;
	t_obj		*obj;

	*color = (t_color){ 0, 0, 0};
	t = FAR;
	camera.v_ray = v_ray;
	all.a_camera = &camera;
	if ((pos = inters(all.a_obj, camera, &t)) >= 0)
	{
		obj = all.a_obj;
		while (pos--)
			obj = obj->next;
		ft_phong(all, *obj, color, t);
	}
}

void		put_image(t_all *all)
{
	if (all->save == 0)
	{
		SDL_BlitSurface( all->wind->img_p, NULL, all->wind->wind_s, NULL );
		SDL_UpdateWindowSurface(all->wind->wind_p);
	}
	else
	{
		save_bitmap(*all->wind, (int *)all->wind->img_p->pixels);
		exit(0);
	}
}

void		here_we_go(t_all *all)
{
	g_all = all;
	init_image(*all);
	init_camera(all->a_camera, *all);
	if (all->str != 0)
		stereoscopy_render(all);
	else
	{
		threads_parent();
		all->filter == 1 ? filter(all->wind->img_data) : 1;
	}
}
