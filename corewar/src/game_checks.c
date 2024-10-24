/*
** game_checks.c for corewar in /home/toozs-_c/rendu/C_Prog_Elem/CPE_2014_corewar/corewar/src
** 
** Made by cristopher toozs-hobson
** Login   <toozs-_c@epitech.net>
** 
** Started on  Sat Apr 11 18:22:15 2015 cristopher toozs-hobson
** Last update Sat Apr 11 19:29:21 2015 cristopher toozs-hobson
*/

#include "corewar.h"

int		check_live_champ(t_vm *vm)
{
  int		count;
  int		i;

  count = 0;
  i = 0;
  while (i < vm->nb_player)
    {
      if (vm->c[i].live == 1)
        {
          count++;
        }
      i++;
    }
  return (count);
}

void		reset_champ_lives(t_vm *vm)
{
  int		i;

  i = 0;
  while (i < vm->nb_player)
    {
      if (vm->c[i].live == 1)
        {
          vm->c[i].live = 0;
        }
      i++;
    }
}

int		dead_champ(t_list *champ, t_vm vm)
{
  int		i;

  i = 0;
  while (i < vm.nb_player)
    {
      if (champ->r[0] == vm.c[i].player)
        {
          if (vm.c[i].live == 0)
            return (1);
        }
      i++;
    }
  return (0);
}

void		check_live_process(t_list *pc, t_vm vm)
{
  while (pc != NULL)
    {
      if (pc->live != 1 || dead_champ(pc, vm) == 1)
        {
          delete_node(&pc);
        }
      else
        pc->live = 0;
      if (pc)
        pc = pc->next;
    }
}
