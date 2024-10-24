/*
** my_fork.c for corewar in /home/toozs-_c/Prog_tests/corewar_tests/tests/ld_test
** 
** Made by cristopher toozs-hobson
** Login   <toozs-_c@epitech.net>
** 
** Started on  Mon Mar 30 16:04:34 2015 cristopher toozs-hobson
** Last update Sat Apr 11 15:35:41 2015 cristopher toozs-hobson
*/

#include "corewar.h"

void		my_fork(t_list *champ, t_vm *vm)
{
  int		new_pc;
  int		value;

  champ->wait = -1;
  value = convert(vm->arena, (champ->pc + 1) % MEM_SIZE, 11);
  new_pc = (champ->pc + (value % IDX_MOD)) % MEM_SIZE;
  champ = my_put_fork_list(champ, new_pc);
  champ->pc = (champ->pc + 3) % MEM_SIZE;
}

void		my_lfork(t_list *champ, t_vm *vm)
{
  int		new_pc;
  int		value;

  value = convert(vm->arena, (champ->pc + 1) % MEM_SIZE, 11);
  new_pc = (champ->pc + value) % MEM_SIZE;
  champ->wait = -1;
  champ = my_put_fork_list(champ, new_pc);
  champ->pc = (champ->pc + 3) % MEM_SIZE;
}
