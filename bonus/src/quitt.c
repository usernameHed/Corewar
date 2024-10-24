/*
** quitt.c for  in /home/belfio_u/rendu/CPE/CPE_2014_corewar/bonus3/src
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Sat Apr 11 03:34:24 2015 ugo belfiore
** Last update Sat Apr 11 21:04:45 2015 ugo belfiore
*/

#include "mlx.h"
#include "mini.h"
#include "my.h"

/*
** fonction echap qui clean et free ce qu'il y a à free.
*/

void	quitt(t_data *d)
{
  FMOD_Sound_Release(d->sd.bonus1);
  FMOD_System_Close(d->sd.system);
  FMOD_System_Release(d->sd.system);
  mlx_destroy_window(d->mlx_ptr, d->win_ptr);
  free(d->ow[0].m.tab);
  free(d->ow[1].m.tab);
  free(d->ow[2].m.tab);
  free(d->ow[3].m.tab);
  exit(1);
}
