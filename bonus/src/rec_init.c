/*
** rec_init.c for  in /home/belfio_u/rendu/CPE/CPE_2014_corewar/bonus/src
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Sun Apr 12 13:53:41 2015 ugo belfiore
** Last update Sun Apr 12 14:32:35 2015 ugo belfiore
*/

#include "mlx.h"
#include "mini.h"
#include "my.h"

void	rec_init(t_data *d)
{
  int	z[2];

  if (d->ch.start != 2)
    return;
  z[0] = 1576;
  z[1] = 269;
  if (d->vmm.name[0][0] != '-' && d->vmm.name[0][1] != '-')
    aff_rec_red(d, z, 1620, 307);
  z[0] = 1645;
  if (d->vmm.name[1][0] != '-' && d->vmm.name[1][1] != '-')
    aff_rec_yel(d, z, 1689, 307);
  z[0] = 1725;
  if (d->vmm.name[2][0] != '-' && d->vmm.name[2][1] != '-')
    aff_rec_gre(d, z, 1769, 307);
  z[0] = 1794;
  if (d->vmm.name[3][0] != '-' && d->vmm.name[3][1] != '-')
    aff_rec_blu(d, z, 1838, 307);
}
