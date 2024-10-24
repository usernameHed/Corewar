/*
** play.c for corewar in /home/toozs-_c/rendu/C_Prog_Elem/CPE_2014_corewar/corewar/src
** 
** Made by cristopher toozs-hobson
** Login   <toozs-_c@epitech.net>
** 
** Started on  Tue Apr  7 17:46:25 2015 cristopher toozs-hobson
** Last update Sat Apr 11 22:52:01 2015 cristopher toozs-hobson
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

void		game(t_vm *vm)
{
  vm->nb_cycle = CYCLE_TO_DIE;
  vm->cycle_to_die = CYCLE_TO_DIE;
  vm->total_cycle = 0;
  vm->lived = 0;
  vm->last = -1;
  vm->lives = NBR_LIVE;
}
