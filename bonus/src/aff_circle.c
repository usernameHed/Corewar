/*
** aff_circle.c for  in /home/belfio_u/rendu/CPE/CPE_2014_corewar/bonus/src
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Fri Apr  3 21:05:07 2015 ugo belfiore
** Last update Thu Apr  9 13:29:07 2015 ugo belfiore
*/

#include "mlx.h"
#include "mini.h"
#include "my.h"

/*
** extension de l'affichage de cercle
*/

t_circle	aff_circleBIS(t_circle c)
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
** affichage de cercle (version normale).
*/

void		aff_circle(t_data *d, int z[2], int r, char *img)
{
  t_circle	c;

  aff_pix_img(d, z[0], z[1], img);
  c.x_mid = z[0];
  c.y_mid = z[1];
  c.x = 0;
  c.y = r;
  c.r = r;
  c.di = r - 1;
  while (c.y >= c.x)
    {
      aff_pix_img(d, c.x_mid + c.x, c.y_mid + c.y, img);
      aff_pix_img(d, c.x_mid + c.y, c.y_mid + c.x, img);
      aff_pix_img(d, c.x_mid - c.x, c.y_mid + c.y, img);
      aff_pix_img(d, c.x_mid - c.y, c.y_mid + c.x, img);
      aff_pix_img(d, c.x_mid + c.x, c.y_mid - c.y, img);
      aff_pix_img(d, c.x_mid + c.y, c.y_mid - c.x, img);
      aff_pix_img(d, c.x_mid - c.x, c.y_mid - c.y, img);
      aff_pix_img(d, c.x_mid - c.y, c.y_mid - c.x, img);
      c = aff_circleBIS(c);
    }
}

/*
** extension d'affichage de cercle.
*/

t_circle1	aff_circle_oneBIS(t_circle1 c)
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
** affichage de cercle du tred 1
*/

void		aff_circle_one(t_data *d, int z[2], int r, int j)
{
  t_circle1	c;

  aff_pix_img_one(d, z[0], z[1], j);
  c.x_mid = z[0];
  c.y_mid = z[1];
  c.x = 0;
  c.y = r;
  c.r = r;
  c.di = r - 1;
  while (c.y >= c.x)
    {
      aff_pix_img_one(d, c.x_mid + c.x, c.y_mid + c.y, j);
      aff_pix_img_one(d, c.x_mid + c.y, c.y_mid + c.x, j);
      aff_pix_img_one(d, c.x_mid - c.x, c.y_mid + c.y, j);
      aff_pix_img_one(d, c.x_mid - c.y, c.y_mid + c.x, j);
      aff_pix_img_one(d, c.x_mid + c.x, c.y_mid - c.y, j);
      aff_pix_img_one(d, c.x_mid + c.y, c.y_mid - c.x, j);
      aff_pix_img_one(d, c.x_mid - c.x, c.y_mid - c.y, j);
      aff_pix_img_one(d, c.x_mid - c.y, c.y_mid - c.x, j);
      c = aff_circle_oneBIS(c);
    }
}
