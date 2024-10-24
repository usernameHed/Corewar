/*
** aff_pix_img.c for  in /home/belfio_u/rendu/CPE/CPE_2014_corewar/bonus/src
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Fri Apr  3 21:14:39 2015 ugo belfiore
** Last update Mon Apr  6 00:28:43 2015 ugo belfiore
*/

#include "mlx.h"
#include "mlx_int.h"
#include "mini.h"
#include "my.h"

/*
** affiche un pixel à l'écran aux position x et y.
*/

void	aff_pix_img(t_data *d, int x, int y, char *img)
{
  int	i;

  if (x < 0 || x >= d->x_max + 100)
    return;
  if (y < 0 || y >= d->y_max)
    return;
  i = (d->p.size * y) + (x * (d->p.bpp / 8));
  img[i] = mlx_get_color_value(d->mlx_ptr, d->colo);
  img[i + 1] = mlx_get_color_value(d->mlx_ptr, d->colo >> 8);
  img[i + 2] = mlx_get_color_value(d->mlx_ptr, d->colo >> 16);
}

/*
** affiche un pixel à l'écran aux position x et y.
** utilisé par le thread 1
*/

void	aff_pix_img_one(t_data *d, int x, int y, int j)
{
  int	i;

  if (x < 27 || x >= d->x_max + 92)
    return;
  if (y < 27 || y >= d->y_max - 34)
    return;
  i = (d->p.size * y) + (x * (d->p.bpp / 8));
  d->p.bData2[i] = mlx_get_color_value(d->mlx_ptr, d->ow[0].m.tab[j].colo);
  d->p.bData2[i + 1] =
    mlx_get_color_value(d->mlx_ptr, d->ow[0].m.tab[j].colo >> 8);
  d->p.bData2[i + 2] =
    mlx_get_color_value(d->mlx_ptr, d->ow[0].m.tab[j].colo >> 16);
}

/*
** affiche un pixel à l'écran aux position x et y.
** utilisé par le thread 2
*/

void	aff_pix_img_two(t_data *d, int x, int y, int j)
{
  int	i;

  if (x < 27 || x >= d->x_max + 92)
    return;
  if (y < 27 || y >= d->y_max - 34)
    return;
  i = (d->p.size * y) + (x * (d->p.bpp / 8));
  d->p.bData2[i] = mlx_get_color_value(d->mlx_ptr, d->ow[1].m.tab[j].colo);
  d->p.bData2[i + 1] =
    mlx_get_color_value(d->mlx_ptr, d->ow[1].m.tab[j].colo >> 8);
  d->p.bData2[i + 2] =
    mlx_get_color_value(d->mlx_ptr, d->ow[1].m.tab[j].colo >> 16);
}

/*
** affiche un pixel à l'écran aux position x et y.
** utilisé par le thread 3
*/

void	aff_pix_img_tree(t_data *d, int x, int y, int j)
{
  int	i;

  if (x < 27 || x >= d->x_max + 92)
    return;
  if (y < 27 || y >= d->y_max - 34)
    return;
  i = (d->p.size * y) + (x * (d->p.bpp / 8));
  d->p.bData2[i] =
    mlx_get_color_value(d->mlx_ptr, d->ow[2].m.tab[j].colo);
  d->p.bData2[i + 1] =
    mlx_get_color_value(d->mlx_ptr, d->ow[2].m.tab[j].colo >> 8);
  d->p.bData2[i + 2] =
    mlx_get_color_value(d->mlx_ptr, d->ow[2].m.tab[j].colo >> 16);
}

/*
** affiche un pixel à l'écran aux position x et y.
** utilisé par le thread 4
*/

void	aff_pix_img_four(t_data *d, int x, int y, int j)
{
  int	i;

  if (x < 27 || x >= d->x_max + 92)
    return;
  if (y < 27 || y >= d->y_max - 34)
    return;
  i = (d->p.size * y) + (x * (d->p.bpp / 8));
  d->p.bData2[i] = mlx_get_color_value(d->mlx_ptr, d->ow[3].m.tab[j].colo);
  d->p.bData2[i + 1] =
    mlx_get_color_value(d->mlx_ptr, d->ow[3].m.tab[j].colo >> 8);
  d->p.bData2[i + 2] =
    mlx_get_color_value(d->mlx_ptr, d->ow[3].m.tab[j].colo >> 16);
}
