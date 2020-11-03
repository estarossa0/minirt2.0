/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 01:56:48 by arraji            #+#    #+#             */
/*   Updated: 2020/11/01 05:17:34 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		apply_texture(t_all all)
{
	t_obj	*obj;

	obj = all.a_obj;
	while (obj)
	{
		if (obj->type == UV_SPHERE)
			load_texture(all, obj->texture);
		obj = obj->next;
	}
}

void		load_texture(t_all all, t_texture *texture)
{
	int imgFlags;

	(void )all;
	imgFlags = IMG_INIT_PNG;
	if( !( IMG_Init( imgFlags ) & imgFlags ) )
		ft_exit(E_SDL);
	if (!(texture->img_s = IMG_Load(texture->file)))
		ft_exit(E_SDL);
	texture->hight = texture->img_s->h;
	texture->width = texture->img_s->w;
	texture->img_s = SDL_ConvertSurface( texture->img_s, all.wind->wind_s->format, 0 );
	texture->image = (int *)texture->img_s->pixels;
}

t_color		get_pixel_at(t_texture *texture, double x, double y)
{
	t_color		color;

	y = 1 - y;
	x = x * (texture->width - 1);
	y = y * (texture->hight - 1);
	x = round(x);
	y = round(y);
	color = get_color(texture->image[((int)y * texture->width) + (int)x]);
	return (color);
}
