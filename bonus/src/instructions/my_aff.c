/*
** my_aff.c for corewar in /home/toozs-_c/Prog_tests/corewar_tests/tests/ld_test
** 
** Made by cristopher toozs-hobson
** Login   <toozs-_c@epitech.net>
** 
** Started on  Mon Mar 30 15:37:44 2015 cristopher toozs-hobson
** Last update Sat Apr 11 15:34:37 2015 cristopher toozs-hobson
*/

#include "corewar.h"

void		my_aff(t_list *champ, t_vm *vm)
{
  int		val;
  int		reg;

  reg = (int)vm->arena[(champ->pc + 2) % MEM_SIZE] - 1;
  if (reg >= 0 && reg < 16)
    {
      val = champ->r[reg];
      val = val % 256;
      my_printf("%c\n", val);
    }
  champ->wait = -1;
  champ->pc = ((champ->pc + 3) % MEM_SIZE);
}
