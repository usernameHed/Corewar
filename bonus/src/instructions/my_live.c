/*
** my_live.c for corewar in /home/toozs-_c/Prog_tests/corewar_tests/tests/ld_test
** 
** Made by cristopher toozs-hobson
** Login   <toozs-_c@epitech.net>
** 
** Started on  Mon Mar 30 15:53:39 2015 cristopher toozs-hobson
** Last update Sun Apr 12 14:47:45 2015 cristopher toozs-hobson
*/

#include "corewar.h"

void		my_live(t_list *pc, t_vm *vm)
{
  int		nb;
  int		i;

  nb = convert(vm->arena, (pc->pc + 1) % MEM_SIZE, 10);
  i = -1;
  while (++i < vm->nb_player)
    {
      if (nb == vm->c[i].player)
	{
	  vm->c[i].live = 1;
	  my_printf("Player %d(%s) is alive\n", vm->c[i].player,
	  	    vm->c[i].head.prog_name);
	  vm->last = i;
	  vm->c[i].lived = 1;
	  vm->lives -= 1;
	  pc->wait = -1;
	  pc->live = 1;
	  pc->pc = (pc->pc + 5) % MEM_SIZE;
	  return ;
	}
    }
  pc->live = 1;
  vm->lives -= 1;
  pc->wait = -1;
  pc->pc = (pc->pc + 5) % MEM_SIZE;
}
