/*
** aff_circle_tred1.c for  in /home/belfio_u/rendu/CPE/CPE_2014_corewar/bonus/src
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Fri Apr  3 21:09:33 2015 ugo belfiore
** Last update Thu Apr  9 13:27:12 2015 ugo belfiore
*/

#include "mlx.h"
#include "mini.h"
#include "my.h"

/*
** extension d'affichage de cercle
*/

t_circle2	aff_circle_twoBIS(t_circle2 c)
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
** affichage de cercle pour les thread 2
*/

void		aff_circle_two(t_data *d, int z[2], int r, int j)
{
  t_circle2	c;

  aff_pix_img_two(d, z[0], z[1], j);
  c.x_mid = z[0];
  c.y_mid = z[1];
  c.x = 0;
  c.y = r;
  c.r = r;
  c.di = r - 1;
  while (c.y >= c.x)
    {
      aff_pix_img_two(d, c.x_mid + c.x, c.y_mid + c.y, j);
      aff_pix_img_two(d, c.x_mid + c.y, c.y_mid + c.x, j);
      aff_pix_img_two(d, c.x_mid - c.x, c.y_mid + c.y, j);
      aff_pix_img_two(d, c.x_mid - c.y, c.y_mid + c.x, j);
      aff_pix_img_two(d, c.x_mid + c.x, c.y_mid - c.y, j);
      aff_pix_img_two(d, c.x_mid + c.y, c.y_mid - c.x, j);
      aff_pix_img_two(d, c.x_mid - c.x, c.y_mid - c.y, j);
      aff_pix_img_two(d, c.x_mid - c.y, c.y_mid - c.x, j);
      c = aff_circle_twoBIS(c);
    }
}

/*
** extension d'affichage de cercle
*/

t_circle3	aff_circle_treeBIS(t_circle3 c)
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
** affichage de cercle pour le thread 3
*/

void		aff_circle_tree(t_data *d, int z[2], int r, int j)
{
  t_circle3	c;

  aff_pix_img_tree(d, z[0], z[1], j);
  c.x_mid = z[0];
  c.y_mid = z[1];
  c.x = 0;
  c.y = r;
  c.r = r;
  c.di = r - 1;
  while (c.y >= c.x)
    {
      aff_pix_img_tree(d, c.x_mid + c.x, c.y_mid + c.y, j);
      aff_pix_img_tree(d, c.x_mid + c.y, c.y_mid + c.x, j);
      aff_pix_img_tree(d, c.x_mid - c.x, c.y_mid + c.y, j);
      aff_pix_img_tree(d, c.x_mid - c.y, c.y_mid + c.x, j);
      aff_pix_img_tree(d, c.x_mid + c.x, c.y_mid - c.y, j);
      aff_pix_img_tree(d, c.x_mid + c.y, c.y_mid - c.x, j);
      aff_pix_img_tree(d, c.x_mid - c.x, c.y_mid - c.y, j);
      aff_pix_img_tree(d, c.x_mid - c.y, c.y_mid - c.x, j);
      c = aff_circle_treeBIS(c);
    }
}
