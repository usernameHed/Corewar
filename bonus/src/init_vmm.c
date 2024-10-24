/*
** init_vmm.c for  in /home/belfio_u/rendu/CPE/CPE_2014_corewar/bonus3/src
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Sat Apr 11 01:49:26 2015 ugo belfiore
** Last update Sun Apr 12 15:25:52 2015 ugo belfiore
*/

#include "mlx.h"
#include "mini.h"
#include "my.h"

/*
** initialise la vm/graphique
*/

static void	vmm_init(t_data *d)
{
  d->vmm.name[0][0] = '-';
  d->vmm.name[0][1] = '-';
  d->vmm.name[1][0] = '-';
  d->vmm.name[1][1] = '-';
  d->vmm.name[2][0] = '-';
  d->vmm.name[2][1] = '-';
  d->vmm.name[3][0] = '-';
  d->vmm.name[3][1] = '-';
  d->vmm.cycle = 0;
  d->vmm.cycle_to_die = 0;
  d->vmm.total_cycle = 0;
  d->vmm.process = 0;
  d->ch.pc[0] = -1;
  d->ch.pc[1] = -1;
  d->ch.pc[2] = -1;
  d->ch.pc[3] = -1;
  d->ch.lived[0] = 0;
  d->ch.lived[1] = 0;
  d->ch.lived[2] = 0;
  d->ch.lived[3] = 0;
  d->ch.testali[0] = 0;
  d->ch.testali[1] = 0;
  d->ch.testali[2] = 0;
  d->ch.testali[3] = 0;
  d->ch.pause = 1;
}

void	vmm_super_init(t_data *d)
{
  d->x_max = 1400;
  d->y_max = 1000;
  d->ch.start = 0;
  sound_init(d);
  cible_init(d);
  vmm_init(d);
  if (d->vm->n == 1)
    {
      d->ch.timer2 = 76;
      d->ch.style = -1;
    }
}
