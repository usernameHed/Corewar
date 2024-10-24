/*
** aff_info_weird.c for  in /home/belfio_u/rendu/CPE/CPE_2014_corewar/bonus/src
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Sun Apr  5 16:36:55 2015 ugo belfiore
** Last update Sun Apr 12 13:38:43 2015 ugo belfiore
*/

#include "mlx.h"
#include "mini.h"
#include "my.h"

void	my_put_nbr_weird(t_data *d, int x, int y, int nb)
{
  int	result;
  int	diviseur;
  int	morx;

  morx = 0;
  if (nb < 0 || nb > 2000000)
    return;
  diviseur = 1;
  while ((nb / diviseur) >= 10)
    diviseur *= 10;
  while (diviseur > 0)
    {
      result = (nb / diviseur) % 10;
      put_charac(d, x + morx, y, (result % 10 + '0'));
      diviseur /= 10;
      morx += 20;
    }
}

static void	aff_rec_mem_normized(t_data *d, int total[4])
{
  int	z[2];

  z[0] = 1738;
  z[1] = 323;
  aff_rec_gre(d, z, 1758, 323 + total[2]);
  z[1] = 323 + total[2];
  aff_rec_bla(d, z, 1758, 656);
  z[0] = 1807;
  z[1] = 323;
  aff_rec_blu(d, z, 1827, 323 + total[3]);
  z[1] = 323 + total[3];
  aff_rec_bla(d, z, 1827, 656);
}

void	aff_rec_mem(t_data *d, int total[4])
{
  int	z[2];

  total[0] = ((total[0] * 333) / MEM_SIZE);
  total[1] = ((total[1] * 333) / MEM_SIZE);
  total[2] = ((total[2] * 333) / MEM_SIZE);
  total[3] = ((total[3] * 333) / MEM_SIZE);
  z[0] = 1589;
  z[1] = 323;
  aff_rec_red(d, z, 1609, 323 + total[0]);
  z[1] = 323 + total[0];
  aff_rec_bla(d, z, 1609, 656);
  z[0] = 1658;
  z[1] = 323;
  aff_rec_yel(d, z, 1678, 323 + total[1]);
  z[1] = 323 + total[1];
  aff_rec_bla(d, z, 1678, 656);
  aff_rec_mem_normized(d, total);
}

void	aff_rec_bla(t_data *d, int z[2], int x2, int y2)
{
  int	i;
  int	j;

  i = z[0];
  j = z[1];
  d->colo = COLOR_BLACK;
  while (i++ <= x2)
    {
      while (j++ <= y2)
	aff_pix_img_rec(d, i, j, d->p.bData2);
      j = z[1];
    }
}
