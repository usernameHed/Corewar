/*
** my_and.c for corewar in /home/toozs-_c/Prog_tests/corewar_tests/tests/ld_test
** 
** Made by cristopher toozs-hobson
** Login   <toozs-_c@epitech.net>
** 
** Started on  Mon Mar 30 10:19:52 2015 cristopher toozs-hobson
** Last update Sat Apr 11 15:35:22 2015 cristopher toozs-hobson
*/

#include "corewar.h"

int		calcul_first(t_list *pc, t_vm vm)
{
  int		p1;
  int		val;

  p1 = -20349;
  if (pc->cod == 180 || pc->cod == 164 || pc->cod == 148)
    p1 = convert(vm.arena, (pc->pc + 2) % MEM_SIZE, 10);
  else if (pc->cod == 244 || pc->cod == 228 || pc->cod == 212)
    {
      p1 = convert(vm.arena, (pc->pc + 2) % MEM_SIZE, 11);
      p1 = convert(vm.arena, (pc->pc + (p1 % IDX_MOD)) % MEM_SIZE, 10);
    }
  else if (pc->cod == 84 || pc->cod == 116 || pc->cod == 100)
    {
      val = (int)vm.arena[(pc->pc + 2) % MEM_SIZE] - 1;
      if (val >= 0 && val < 16)
	p1 = pc->r[val];
    }
  return (p1);
}

int		calcul_second(t_list *pc, t_vm vm)
{
  int		p2;
  int		jmp;
  int		val;

  jmp = 0;
  p2 = -20349;
  jmp = calculate_jmp(pc, 2);
  if (jmp != 0)
    {
      if (pc->cod == 164 || pc->cod == 228 || pc->cod == 100)
	p2 = convert(vm.arena, (pc->pc + jmp) % MEM_SIZE, 10);
      else if (pc->cod == 180 || pc->cod == 244 || pc->cod == 166)
	{
	  p2 = convert(vm.arena, (pc->pc + jmp) % MEM_SIZE, 11);
	  p2 = convert(vm.arena, (pc->pc + (p2 % IDX_MOD))
		       % MEM_SIZE, 10);
	}
      else if (pc->cod == 148 || pc->cod == 212 || pc->cod == 84)
	{
	  val = (int)vm.arena[(pc->pc + jmp) % MEM_SIZE] - 1;
	  if (val >= 0 && val < 16)
	    p2 = pc->r[val];
	}
    }
  return (p2);
}

int		calculate_jmp(t_list *pc, int param)
{
  int		jmp;

  jmp = 0;
  if (param == 2)
    {
      if (pc->cod == 180 || pc->cod == 164 || pc->cod == 148)
	jmp = 6;
      else if (pc->cod == 244 || pc->cod == 228 || pc->cod == 212)
	jmp = 4;
      else if (pc->cod == 84 || pc->cod == 116 || pc->cod == 100)
	jmp = 3;
    }
  else if (param == 3 || param == 4)
    {
      jmp = (pc->cod == 148 || pc->cod == 100) ? 7 : jmp;
      jmp = (pc->cod == 180 || pc->cod == 228) ? 8 : jmp;
      jmp = (pc->cod == 212 || pc->cod == 116) ? 5 : jmp;
      jmp = (pc->cod == 164) ? 10 : jmp;
      jmp = (pc->cod == 244) ? 6 : jmp;
      jmp = (pc->cod == 84) ? 4 : jmp;
    }
  jmp += (param == 4) ? 1 : 0;
  return (jmp);
}

void		my_and(t_list *pc, t_vm *vm)
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
	  pc->r[st] = p1 & p2;
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
