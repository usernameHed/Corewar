/*
** check_winner.c for  in /home/belfio_u/rendu/CPE/CPE_2014_corewar/bonus3/src
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Thu Apr  9 11:59:03 2015 ugo belfiore
** Last update Sun Apr 12 14:49:41 2015 cristopher toozs-hobson
*/

#include "mlx.h"
#include "mini.h"
#include "my.h"

static void	check_winner_draw(t_vm vm, t_data *d)
{
  int		rdi;

  rdi = 0;
  my_printf("No champions lived!\n");
  rdi = 1 + random() % vm.nb_player;
  my_printf("Player %d(%s) wins!\n", rdi, vm.c[rdi - 1].head.prog_name);
  d->win = rdi;
  d->ch.style = 1;
  d->ch.timer2 = 140;
}

static void	check_one_living(t_vm vm, t_data *d)
{
  int		i;

  i = -1;
  while (++i < vm.nb_player)
    {
      if (vm.c[i].live == 1)
	{
	  my_printf("Player %d(%s)wins!\n", vm.c[i].player,
		    vm.c[i].head.prog_name);
	  d->win = i + 1;
	  d->ch.style = 1;
	  d->ch.timer2 = 140;
	}
    }
}

void		check_winner(t_vm vm, t_data *d)
{
  int		i;
  int		living;

  living = 0;
  i = -1;
  while (++i < vm.nb_player)
    {
      if (vm.c[i].live == 1)
        living++;
    }
  if (living > 1 || (living == 0 && vm.last != -1))
    {
      my_printf("Player %d(%s) wins!\n", vm.c[vm.last].player,
		vm.c[vm.last].head.prog_name);
      d->win = vm.last + 1;
      d->ch.style = 1;
      d->ch.timer2 = 140;
    }
  else if (living == 1)
    check_one_living(vm, d);
  else if (living == 0 && vm.last == -1)
    check_winner_draw(vm, d);
}
