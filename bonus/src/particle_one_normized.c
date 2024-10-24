/*
** particle_one_normized.c for  in /home/belfio_u/rendu/CPE/CPE_2014_corewar/bonus3/src
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Thu Apr  9 11:35:12 2015 ugo belfiore
** Last update Sun Apr 12 15:57:07 2015 ugo belfiore
*/

#include "mlx.h"
#include "mini.h"
#include "my.h"

static void	blackos_one_normized(t_data *d, int j, int test)
{
  int	z[2];

  if (d->ow[0].m.tab[j].curs > 3 && d->ch.hidecurs == 1)
    test = d->ow[0].m.tab[j].curs;
  if (d->ow[0].m.tab[j].color_particle == 1 && d->ch.lived[0] > 2
      && d->ch.hidecurs == 1)
    test = d->ch.lived[0];
  if (d->ow[0].m.tab[j].color_particle == 2 && d->ch.lived[1] > 2
      && d->ch.hidecurs == 1)
    test = d->ch.lived[1];
  if (d->ow[0].m.tab[j].color_particle == 3 && d->ch.lived[2] > 2
      && d->ch.hidecurs == 1)
    test = d->ch.lived[2];
  if (d->ow[0].m.tab[j].color_particle == 4 && d->ch.lived[3] > 2
      && d->ch.hidecurs == 1)
    test = d->ch.lived[3];
  z[0] = d->ow[0].m.tab[j].tail_x[0];
  z[1] = d->ow[0].m.tab[j].tail_y[0];
  while (--test > 0)
    aff_circle_one(d, z, test, j);
}

void		blackos_one(t_data *d, int  j, int test, int cosy)
{
  t_list	*tmp;
  int		z[2];

  tmp = d->list;
  test = -1 + cosy;
  z[0] = d->ow[0].m.tab[j].tail_x[2];
  z[1] = d->ow[0].m.tab[j].tail_y[2];
  while (--test > 0)
    aff_circle_one(d, z, test, j);
  test = 1 + cosy;
  z[0] = d->ow[0].m.tab[j].tail_x[1];
  z[1] = d->ow[0].m.tab[j].tail_y[1];
  while (--test > 0)
    aff_circle_one(d, z, test, j);
  test = 2 + cosy;
  while (tmp && d->ch.hidecurs == 1)
    {
      if (tmp->pc == (MEM_SIZE_CUT * 0) + (j * 1))
        {
          d->ow[0].m.tab[j].curs = (d->ch.hidecurs == 1) ? 10 : 6;
          test = d->ow[0].m.tab[j].curs;
        }
      tmp = tmp->next;
    }
  blackos_one_normized(d, j, test);
}

void	tmp_a_one(t_data *d, int j, double tmp_a)
{
  if ((d->win == 0 || (d->win == d->ow[0].m.tab[j].color_particle)))
    {
      if (d->vm->n == 0)
	d->ow[0].m.tab[j].angl +=
	  MAX(MIN((((int)(tmp_a - d->ow[0].m.tab[j].angl + 540) % 360) - 180),
		  d->ow[0].m.tab[j].turn), -1 * d->ow[0].m.tab[j].turn);
      else if (d->vm->n != 0 && d->win == 0)
	d->ow[0].m.tab[j].angl +=
	  MAX(MIN((((int)(tmp_a - d->ow[0].m.tab[j].angl + 540) % 360) - 180),
		  d->ow[0].m.tab[j].turn), -1 * d->ow[0].m.tab[j].turn);
    }
  d->ow[0].m.tab[j].XVel = cos(d->ow[0].m.tab[j].angl / 180.0 * PI)
    * d->ow[0].m.tab[j].vel;
  d->ow[0].m.tab[j].YVel= - sin(d->ow[0].m.tab[j].angl / 180.0 * PI)
    * d->ow[0].m.tab[j].vel;
}

void	aff_one_tail_normized(t_data *d, int j, int test)
{
  int	z[2];

  z[0] = d->ow[0].m.tab[j].tail_x[3];
  z[1] = d->ow[0].m.tab[j].tail_y[3];
  aff_circle_one(d, z, test, j);
  z[0] = d->ow[0].m.tab[j].tail_x[2];
  z[1] = d->ow[0].m.tab[j].tail_y[2];
  aff_circle_one(d, z, test, j);
  z[0] = d->ow[0].m.tab[j].tail_x[1];
  z[1] = d->ow[0].m.tab[j].tail_y[1];
  aff_circle_one(d, z, test, j);
}
