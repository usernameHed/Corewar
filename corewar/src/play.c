/*
** play.c for corewar in /home/toozs-_c/rendu/C_Prog_Elem/CPE_2014_corewar/corewar/src
** 
** Made by cristopher toozs-hobson
** Login   <toozs-_c@epitech.net>
** 
** Started on  Tue Apr  7 17:46:25 2015 cristopher toozs-hobson
** Last update Sat Apr 11 18:32:37 2015 cristopher toozs-hobson
*/

#include "corewar.h"

void		play(t_list *champ, t_vm *vm)
{
  t_list	*tmp;

  tmp = champ;
  while (champ != NULL)
    {
      if (champ->wait > 0)
	champ->wait -= 1;
      else if (champ->wait == 0)
	execute_instruction(champ, vm);
      else if (champ->wait == -1)
	{
	  if (check_for_instruction(champ, *(vm)) == 0)
	    champ->pc += 1;
	}
      champ = champ->next;
    }
  champ = tmp;
}

void		init_game(t_vm *vm)
{
  vm->nb_cycle = CYCLE_TO_DIE;
  vm->cycle_to_die = CYCLE_TO_DIE;
  vm->total_cycle = 0;
  vm->lives = NBR_LIVE;
  vm->last = -1;
}

void		check_ctd(t_vm *vm)
{
  if (vm->lives <= 0)
    {
      vm->cycle_to_die -= CYCLE_DELTA;
      vm->lives = NBR_LIVE;
    }
}

void		game(t_list *champ, t_vm *vm)
{
  int		ret;

  init_game(vm);
  while (vm->nb_cycle >= 0 && vm->cycle_to_die > 1)
    {
      if (vm->dump != 0 && vm->total_cycle == vm->dump)
	dump(vm);
      if (vm->nb_cycle == 0)
	{
	  ret = check_live_champ(vm);
	  check_live_process(champ, *(vm));
	  if (ret > 1)
	    {
	      reset_champ_lives(vm);
	      vm->nb_cycle = vm->cycle_to_die;
	    }
	  else
	    return ;
	}
      check_ctd(vm);
      if (champ)
	play(champ, vm);
      vm->nb_cycle -= 1;
      vm->total_cycle += 1;
    }
}
