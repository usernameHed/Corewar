/*
** super_boucle.c for  in /home/belfio_u/rendu/CPE/CPE_2014_corewar/bonus3/src
**
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
**
** Started on  Sat Apr 11 03:38:07 2015 ugo belfiore
** Last update Mar 16 13:36:32 2016
*/

#include "mlx.h"
#include "mini.h"
#include "my.h"

/*
** 4 fu**ing thread qui marchent nichel !
*/

static void	frame_thread(t_data *d)
{
  int		z[2];

  if (d->ch.timer2 > 0)
    d->ch.timer2--;
  pthread_create(&d->threads[0], NULL, (void *)&particle_one, d);
  pthread_create(&d->threads[1], NULL, (void *)&particle_two, d);
  pthread_create(&d->threads[2], NULL, (void *)&particle_tree, d);
  pthread_create(&d->threads[3], NULL, (void *)&particle_four, d);
  pthread_join(d->threads[0], NULL);
  pthread_join(d->threads[1], NULL);
  pthread_join(d->threads[2], NULL);
  pthread_join(d->threads[3], NULL);
  d->ch.start++;
  if (d->ch.start > 3)
    d->ch.start = 3;
  if (d->ch.bla == 1)
    {
      z[0] = 20;
      z[1] = 20;
      aff_rec_bla(d, z, 1495, 970);
      d->ch.bla = 0;
    }
}

static void	frame_first_cycle_vm(t_data *d, int ret, int n)
{
  while (n < d->vm->nb_player)
    {
      d->vm->c[n].lived = 0;
      n++;
    }
  if (d->vm->nb_cycle == 0)
    {
      ret = check_live_champ(d->vm);
      check_live_process(d->list, *(d->vm));
      if (ret > 1)
	{
	  reset_champ_lives(d->vm);
	  d->vm->nb_cycle = d->vm->cycle_to_die;
	}
      else
	{
	  check_winner(*(d->vm), d);
	  return ;
	}
    }
  if (d->vm->lives <= 0)
    {
      d->vm->cycle_to_die -= CYCLE_DELTA;
      d->vm->lives = NBR_LIVE;
    }
}

static void	frame_game_vm(t_data *d, int i, int n)
{
  if (d->list)
    play(d->list, d->vm);
  d->vm->nb_cycle -= 1;
  d->vm->total_cycle += 1;
  i = 0;
  while (i < MEM_SIZE)
    {
      d->arene[i] = d->vm->graph[i] + '0';
      i++;
    }
  transpose_name(d);
  n = 0;
  while (n < d->vm->nb_player)
    {
      if (d->vm->c[n].lived != 0)
	d->ch.lived[n] = d->vm->c[n].lived * 10;
      n++;
    }
}

static void	frame_no_start(t_data *d, int ret, int n, int k)
{
  int		i;

  usleep(1000);
  if ((!(random() % d->ch.slow) || d->ch.slow < 0) && d->win == 0)
    {
      k = -1;
      while (++k < abs(d->ch.slow))
	{
	  if (d->ch.slow > 0)
	    k = abs(d->ch.slow);
	  frame_first_cycle_vm(d, ret, n);
	  i = 0;
	  frame_game_vm(d, i, n);
	  d->vmm.cycle = d->vm->nb_cycle;
	  d->vmm.cycle_to_die = d->vm->cycle_to_die;
	  d->vmm.total_cycle = d->vm->total_cycle;
	  d->vmm.process = list_len(d->list);
	  d->vmm.cycle = (d->vmm.cycle < 0) ? 0 : d->vmm.cycle;
	  d->vmm.cycle_to_die = (CYC < 0) ? 0 : CYC;
	}
    }
  frame_thread(d);
}

int		manage_frame(void *param)
{
  t_data	*d;
  int		ret;
  int		n;
  int		k;

  usleep(1000);
  d = (t_data *)param;
  (d->ch.pause == -1) ? MLX(d->mlx_ptr, d->win_ptr, d->pa.pp, 584, 455) : 1;
  if (d->ch.pause == -1)
    return (0);
  cible_move(d, 1, 0);
  nbr_of_champ(d);
  if (d->ch.start != 0)
    {
      (DUMP) ? dump(d->vm) : 1;
      ret = 0;
      n = 0;
      k = 0;
      frame_no_start(d, ret, n, k);
      mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->p.back2, 0, 0);
      aff_info(d);
    }
  else
    mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->p.back, 0, 0);
  return (0);
}
