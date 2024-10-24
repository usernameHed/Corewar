/*
** aff_pix_rec.c for  in /home/belfio_u/rendu/CPE/CPE_2014_corewar/bonus/src
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Mon Apr  6 02:00:49 2015 ugo belfiore
** Last update Fri Apr 10 16:25:26 2015 ugo belfiore
*/

#include "mlx.h"
#include "mini.h"
#include "my.h"

void	aff_pix_img_rec(t_data *d, int x, int y, char *img)
{
  int	i;

  if (x < 0 || x >= d->x_max + 500)
    return;
  if (y < 0 || y >= d->y_max)
    return;
  i = (d->p.size * y) + (x * (d->p.bpp / 8));
  img[i] = mlx_get_color_value(d->mlx_ptr, d->colo);
  img[i + 1] = mlx_get_color_value(d->mlx_ptr, d->colo >> 8);
  img[i + 2] = mlx_get_color_value(d->mlx_ptr, d->colo >> 16);
}

void	aff_rec_red(t_data *d, int z[2], int x2, int y2)
{
  int	i;
  int	j;

  i = z[0];
  j = z[1];
  while (i++ <= x2)
    {
      while (j++ <= y2)
	{
	  d->colo = COLOR_RED;
	  aff_pix_img_rec(d, i, j, d->p.bData2);
	}
      j = z[1];
    }
}

void	aff_rec_yel(t_data *d, int z[2], int x2, int y2)
{
  int	i;
  int	j;

  i = z[0];
  j = z[1];
  while (i++ <= x2)
    {
      while (j++ <= y2)
	{
	  d->colo = COLOR_YELLOW;
	  aff_pix_img_rec(d, i, j, d->p.bData2);
	}
      j = z[1];
    }
}

void	aff_rec_blu(t_data *d, int z[2], int x2, int y2)
{
  int	i;
  int	j;

  i = z[0];
  j = z[1];
  while (i++ <= x2)
    {
      while (j++ <= y2)
	{
	  d->colo = COLOR_BLUE;
	  aff_pix_img_rec(d, i, j, d->p.bData2);
	}
      j = z[1];
    }
}

void	aff_rec_gre(t_data *d, int z[2], int x2, int y2)
{
  int	i;
  int	j;

  i = z[0];
  j = z[1];
  while (i++ <= x2)
    {
      while (j++ <= y2)
	{
	  d->colo = COLOR_GREEN;
	  aff_pix_img_rec(d, i, j, d->p.bData2);
	}
      j = z[1];
    }
}
