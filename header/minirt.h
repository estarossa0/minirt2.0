/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 22:35:13 by arraji            #+#    #+#             */
/*   Updated: 2020/11/01 04:48:23 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINIRT_H
# define FT_MINIRT_H
# define FAR 1e30
# define NEAR 1e-6
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include <errno.h>
# include <fcntl.h>
# include <pthread.h>
# include "SDL.h"
# include "SDL_image.h"
# include "libft.h"
# include "struct.h"
# include "vector_op.h"
# include "camera.h"
# include "colors.h"
# include "error.h"
# include "parsing.h"
# include "inters.h"
# include "shitting_math.h"
# include "light_shitting.h"
# include "shadows.h"
# include "hook.h"
# include "save.h"
# include "thread.h"
# include "filter.h"
# include "stereoscopy.h"
# include "texture.h"

void		load_texture(t_all all, t_texture *texture);
t_color		get_pixel_at(t_texture *texture, double x, double y);
void		render(t_all all, t_camera s_camera, t_color *color, t_cord v_ray);
void		here_we_go(t_all *all);
void		get_all_rays(t_cord *v_rays, double x, double y);
void		render_all_ray(t_color *colors, t_cord *v_rays);
void		get_pixel(int *indexs, int *img);
void		init_wind(t_all all);
void		init_image(t_all all);
double		smallest_double(double *tab, int size);
void		put_image(t_all *all);
void		refresh(t_all *all);
t_all		*g_all;
#endif
