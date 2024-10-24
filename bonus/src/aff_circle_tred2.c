/*
** aff_circle_tred2.c for  in /home/belfio_u/rendu/CPE/CPE_2014_corewar/bonus/src
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Fri Apr  3 21:11:34 2015 ugo belfiore
** Last update Thu Apr  9 13:26:19 2015 ugo belfiore
*/

#include "mlx.h"
#include "mini.h"
#include "my.h"

/*
** extension d'affichage de cercle
*/

t_circle4	aff_circle_fourBIS(t_circle4 c)
{
  if (c.di >= (2 * c.x))
    {
      c.di = c.di - (2 * c.x) - 1;
      c.x++;
    }
  else if (c.di < 2 * (c.r - c.y))
    {
      c.di =  c.di + (2 * c.y) - 1;
      c.y--;
    }
  else
    {
      c.di = c.di + 2 * (c.y - c.x - 1);
      c.y = c.y - 1;
      c.x = c.x + 1;
    }
  return (c);
}

/*
** affichage de cercle pour le thread 4
*/

void		aff_circle_four(t_data *d, int z[2], int r, int j)
{
  t_circle4	c;

  aff_pix_img_four(d, z[0], z[1], j);
  c.x_mid = z[0];
  c.y_mid = z[1];
  c.x = 0;
  c.y = r;
  c.r = r;
  c.di = r - 1;
  while (c.y >= c.x)
    {
      aff_pix_img_four(d, c.x_mid + c.x, c.y_mid + c.y, j);
      aff_pix_img_four(d, c.x_mid + c.y, c.y_mid + c.x, j);
      aff_pix_img_four(d, c.x_mid - c.x, c.y_mid + c.y, j);
      aff_pix_img_four(d, c.x_mid - c.y, c.y_mid + c.x, j);
      aff_pix_img_four(d, c.x_mid + c.x, c.y_mid - c.y, j);
      aff_pix_img_four(d, c.x_mid + c.y, c.y_mid - c.x, j);
      aff_pix_img_four(d, c.x_mid - c.x, c.y_mid - c.y, j);
      aff_pix_img_four(d, c.x_mid - c.y, c.y_mid - c.x, j);
      c = aff_circle_fourBIS(c);
    }
}
