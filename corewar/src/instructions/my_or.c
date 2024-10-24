/*
** my_and.c for corewar in /home/toozs-_c/Prog_tests/corewar_tests/tests/ld_test
** 
** Made by cristopher toozs-hobson
** Login   <toozs-_c@epitech.net>
** 
** Started on  Mon Mar 30 10:19:52 2015 cristopher toozs-hobson
** Last update Sat Apr 11 15:37:15 2015 cristopher toozs-hobson
*/

#include "corewar.h"

void		my_or(t_list *pc, t_vm *vm)
{
  int		p1;
  int		p2;
  int		p3;
  int		st;
  int		jmp;

  pc->carry = 0;
  if (((p1 = calcul_first(pc, (*vm))) != -20349)
      && ((p2 = calcul_second(pc, (*vm))) != -20349)
      && ((p3 = calculate_jmp(pc, 3)) != 0))
    {
      st = (int)vm->arena[(pc->pc + p3) % MEM_SIZE] - 1;
      if (st >= 0 && st < 16)
	{
	  pc->r[st] = p1 | p2;
	  if (pc->r[st] == 0)
	    pc->carry = 1;
	}
    }
  jmp = calculate_jmp(pc, 4);
  if (jmp > 1)
    pc->pc = (pc->pc + jmp) % MEM_SIZE;
  else
    pc->pc = (pc->pc + 1) % MEM_SIZE;
  pc->wait = -1;
}
