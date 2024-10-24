/*
** my_sub.c for corewar in /home/toozs-_c/Prog_tests/corewar_tests/instructions
** 
** Made by cristopher toozs-hobson
** Login   <toozs-_c@epitech.net>
** 
** Started on  Mon Mar 30 09:36:43 2015 cristopher toozs-hobson
** Last update Sat Apr 11 15:38:08 2015 cristopher toozs-hobson
*/

/*
** Usage: if (arena[pc] == 5 **0x05 instruction number**)
**        {
**          my_sub(&champ, vm)
**        }
*/

#include "corewar.h"

void		my_sub(t_list *champ, t_vm *vm)
{
  int		one;
  int		two;
  int		store;

  one = (int)vm->arena[(champ->pc + 2) % MEM_SIZE];
  two = (int)vm->arena[(champ->pc + 3) % MEM_SIZE];
  store = (int)vm->arena[(champ->pc + 4) % MEM_SIZE];
  champ->carry = 0;
  if ((store > 0 && store <= 16) && (one > 0 && one <= 16)
      && (two > 0 && two <= 16))
    {
      champ->r[store - 1] = champ->r[one - 1] - champ->r[two - 1];
      if (champ->r[store - 1] == 0)
	champ->carry = 1;
    }
  champ->pc = (champ->pc + 5) % MEM_SIZE;
  champ->wait = -1;
}
