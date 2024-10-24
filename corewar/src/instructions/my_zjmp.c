/*
** my_zjmp.c for corewar in /home/toozs-_c/Prog_tests/corewar_tests/tests/ld_test
** 
** Made by cristopher toozs-hobson
** Login   <toozs-_c@epitech.net>
** 
** Started on  Mon Mar 30 15:16:02 2015 cristopher toozs-hobson
** Last update Sat Apr 11 15:38:43 2015 cristopher toozs-hobson
*/

#include "corewar.h"

void		my_zjmp(t_list *pc, t_vm *vm)
{
  int		jump;
  int		val;

  if (pc->carry == 1)
    {
      jump = convert(vm->arena, (pc->pc + 1) % MEM_SIZE, 11);
      if ((val = (pc->pc + (jump % IDX_MOD)) % MEM_SIZE) < 0)
        pc->pc = MEM_SIZE + val;
      else
        pc->pc = val;
    }
  else
    pc->pc = (pc->pc + (3 % IDX_MOD)) % MEM_SIZE;
  pc->wait = -1;
}
