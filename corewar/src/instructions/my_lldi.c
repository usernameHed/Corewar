/*
** my_ldi.c for corewar in /home/toozs-_c/Prog_tests/corewar_tests/tests/ld_test
** 
** Made by cristopher toozs-hobson
** Login   <toozs-_c@epitech.net>
** 
** Started on  Mon Mar 30 17:10:13 2015 cristopher toozs-hobson
** Last update Sat Apr 11 15:34:07 2015 cristopher toozs-hobson
*/

#include "corewar.h"

void		my_lldi(t_list *pc, t_vm *vm)
{
  int		st;
  int		p1;
  int		p2;
  int		jmp;

  pc->carry = 0;
  if ((p1 = calculate_first(pc, (*vm))) != -20349
      && (p2 = calculate_second(pc, (*vm))) != -20349)
    {
      jmp = set_jump(pc);
      st = (int)vm->arena[(pc->pc + (jmp - 1)) % MEM_SIZE];
      if (st > 0 && st <= 16)
	{
	  pc->r[st - 1] = convert(vm->arena, (pc->pc + (p1 + p2))
				  % MEM_SIZE, 10);
	  if (pc->r[st - 1] == 0)
	    pc->carry = 1;
	}
    }
  pc->wait = -1;
  pc->pc = (pc->pc + jmp) % MEM_SIZE;
}
