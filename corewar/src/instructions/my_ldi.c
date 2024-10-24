/*
** my_ldi.c for corewar in /home/toozs-_c/Prog_tests/corewar_tests/tests/ld_test
** 
** Made by cristopher toozs-hobson
** Login   <toozs-_c@epitech.net>
** 
** Started on  Mon Mar 30 17:10:13 2015 cristopher toozs-hobson
** Last update Sat Apr 11 20:30:29 2015 cristopher toozs-hobson
*/

#include "corewar.h"

int		calculate_first(t_list *pc, t_vm vm)
{
  int		p1;
  int		val;

  p1 = -20349;
  if (pc->cod == 228 || pc->cod == 212)
    {
      p1 = convert(vm.arena, (pc->pc + 2) % MEM_SIZE, 11);
      p1 = convert(vm.arena, (pc->pc + (p1 % IDX_MOD)) % MEM_SIZE, 11);
    }
  else if (pc->cod == 84 || pc->cod == 100)
    {
      val = (int)vm.arena[(pc->pc + 2) % MEM_SIZE];
      if (val > 0 && val <= 16)
	p1 = pc->r[val - 1];
    }
  else if (pc->cod == 164 || pc->cod == 148)
    p1 = convert(vm.arena, (pc->pc + 2) % MEM_SIZE, 11);
  return (p1);
}

int		calculate_second(t_list *pc, t_vm vm)
{
  int		p2;
  int		val;

  p2 = -20349;
  if (pc->cod == 84 || pc->cod == 148 || pc->cod == 212)
    {
      if (pc->cod == 84)
	  val = (int)vm.arena[(pc->pc + 3) % MEM_SIZE];
      else if (pc->cod == 148 || pc->cod == 212)
	  val = (int)vm.arena[(pc->pc + 4) % MEM_SIZE];
      if (val > 0 && val <= 16)
	p2 = pc->r[val - 1];
    }
  else if (pc->cod == 228 || pc->cod == 100 || pc->cod == 164)
    {
      if (pc->cod == 100)
	p2 = convert(vm.arena, (pc->pc + 3) % MEM_SIZE, 11);
      else if (pc->cod == 228 || pc->cod == 164)
	p2 = convert(vm.arena, (pc->pc + 4) % MEM_SIZE, 11);
    }
  return (p2);
}

int		set_jump(t_list *pc)
{
  int		jmp;

  jmp = 1;
  if (pc->cod == 100 || pc->cod == 212 || pc->cod == 148)
    jmp = 6;
  else if (pc->cod == 164 || pc->cod == 228)
    jmp = 7;
  else if (pc->cod == 84)
    jmp = 5;
  return (jmp);
}

void		my_ldi(t_list *pc, t_vm *vm)
{
  int		st;
  int		p1;
  int		p2;
  int		jmp;

  pc->carry = 0;
  p1 = -20349;
  p2 = -20349;
  if ((p1 = calculate_first(pc, (*vm))) != -20349
      && (p2 = calculate_second(pc, (*vm))) != -20349)
    {
      jmp = set_jump(pc);
      st = (int)vm->arena[(pc->pc + (jmp - 1)) % MEM_SIZE];
      if (st > 0 && st <= 16)
	{
	  pc->r[st - 1] = convert(vm->arena, (pc->pc + ((p1 + p2) % IDX_MOD))
				  % MEM_SIZE, 10);
	  if (pc->r[st - 1] == 0)
	    pc->carry = 1;
	}
    }
  pc->wait = -1;
  pc->pc = (pc->pc + jmp) % MEM_SIZE;
}
