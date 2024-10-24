/*
** my_sti.c for corewar in /home/toozs-_c/rendu/C_Prog_Elem/CPE_2014_corewar/corewar/src/instructions
** 
** Made by cristopher toozs-hobson
** Login   <toozs-_c@epitech.net>
** 
** Started on  Tue Apr  7 14:26:50 2015 cristopher toozs-hobson
** Last update Sat Apr 11 16:15:22 2015 cristopher toozs-hobson
*/

#include "corewar.h"

int		check_jmp(t_list *pc)
{
  int		jmp;

  jmp = 1;
  if (pc->cod == 84)
    jmp = 5;
  else if (pc->cod == 88 || pc->cod == 116 || pc->cod == 100)
    jmp = 6;
  else if (pc->cod == 104 || pc->cod == 120)
    jmp = 7;
  return (jmp);
}

void		sti_reg(t_list *pc, t_vm *vm)
{
  int		v;
  int		p2;
  int		p3;
  int		jmp;

  p2 = -20349;
  p3 = -20349;
  if (pc->cod == 84)
    {
      if ((v = (int)vm->arena[(pc->pc + 3) % MEM_SIZE]) > 0 && v <= 16)
      	p2 = pc->r[v - 1];
      if ((v = (int)vm->arena[(pc->pc + 4) % MEM_SIZE]) > 0 && v <= 16)
      	p3 = pc->r[v - 1];
    }
  else if (pc->cod == 88)
    {
      if ((v = (int)vm->arena[(pc->pc + 3) % MEM_SIZE]) > 0 && v <= 16)
      	p2 = pc->r[v - 1];
      p3 = convert(vm->arena, (pc->pc + 4) % MEM_SIZE, 11);
    }
  jmp = check_jmp(pc);
  if (((v = (int)vm->arena[(pc->pc + 2) % MEM_SIZE] - 1) >= 0 && v < 16)
      && p2 != -20349 && p3 != -20349)
    stock(pc, vm, p2 + p3, pc->r[v]);
  pc->pc = (pc->pc + jmp) % MEM_SIZE;
}

void		sti_ind(t_list *pc, t_vm *vm)
{
  int		v;
  int		p2;
  int		p3;
  int		jmp;

  p2 = -20349;
  p3 = -20349;
  if (pc->cod == 116)
    {
      p2 = convert(vm->arena, (pc->pc + 3) % MEM_SIZE, 11);
      p2 = convert(vm->arena, (pc->pc + (p2 % IDX_MOD)) % MEM_SIZE, 11);
      if ((v = (int)vm->arena[(pc->pc + 5) % MEM_SIZE]) > 0 && v <= 16)
      	p2 = pc->r[v - 1];
    }
  else if (pc->cod == 120)
    {
      p2 = convert(vm->arena, (pc->pc + 3) % MEM_SIZE, 11);
      p2 = convert(vm->arena, (pc->pc + (p2 % IDX_MOD)) % MEM_SIZE, 11);
      p3 = convert(vm->arena, (pc->pc + 5) % MEM_SIZE, 11);
    }
  jmp = check_jmp(pc);
  if (((v = (int)vm->arena[(pc->pc + 2) % MEM_SIZE] - 1) >= 0 && v < 16)
      && p2 != -20349 && p3 != -20349)
    stock(pc, vm, p2 + p3, pc->r[v]);
  pc->pc = (pc->pc + jmp) % MEM_SIZE;
}

void		sti_dir(t_list *pc, t_vm *vm)
{
  int		p2;
  int		p3;
  int		v;
  int		jmp;

  p2 = -20349;
  p3 = -20349;
  if (pc->cod == 100)
    {
      p2 = convert(vm->arena, (pc->pc + 3) % MEM_SIZE, 11);
      if ((v = (int)vm->arena[(pc->pc + 5) % MEM_SIZE]) > 0 && v <= 16)
	p3 = pc->r[v - 1];
    }
  else if (pc->cod == 104)
    {
      p2 = convert(vm->arena, (pc->pc + 3) % MEM_SIZE, 11);
      p3 = convert(vm->arena, (pc->pc + 5) % MEM_SIZE, 11);
    }
  jmp = check_jmp(pc);
  if (((v = (int)vm->arena[(pc->pc + 2) % MEM_SIZE] - 1) >= 0 && v < 16)
      && p2 != -20349 && p3 != -20349)
    stock(pc, vm, p2 + p3, pc->r[v]);
  pc->pc = (pc->pc + jmp) % MEM_SIZE;
}

void		my_sti(t_list *pc, t_vm *vm)
{
  if (pc->wait == 0)
    {
      if (pc->cod == 84 || pc->cod == 88)
        {
          sti_reg(pc, vm);
        }
      else if (pc->cod == 116 || pc->cod == 120)
        {
          sti_ind(pc, vm);
        }
      else if (pc->cod == 100 || pc->cod == 104)
        {
          sti_dir(pc, vm);
        }
      pc->wait = -1;
    }
}
