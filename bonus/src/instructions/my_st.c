/*
** my_st.c for corewar in /home/toozs-_c/rendu/C_Prog_Elem/CPE_2014_corewar/corewar/src/instructions
** 
** Made by cristopher toozs-hobson
** Login   <toozs-_c@epitech.net>
** 
** Started on  Mon Apr  6 19:32:46 2015 cristopher toozs-hobson
** Last update Sat Apr 11 15:37:24 2015 cristopher toozs-hobson
*/

#include "corewar.h"

void		stock(t_list *pc, t_vm *vm, int loc, int val)
{
  int		first;
  int		second;
  int		third;
  int		fourth;
  int		player;

  player = vm->graph[pc->pc % MEM_SIZE];
  if ((first = (pc->pc + (loc % IDX_MOD)) % MEM_SIZE) < 0)
    first = MEM_SIZE + first;
  if ((second = (pc->pc + ((loc + 1) % IDX_MOD)) % MEM_SIZE) < 0)
    second = MEM_SIZE + second;
  if ((third = (pc->pc + ((loc + 2) % IDX_MOD)) % MEM_SIZE) < 0)
    third = MEM_SIZE + third;
  if ((fourth = (pc->pc + ((loc + 3) % IDX_MOD)) % MEM_SIZE) < 0)
    fourth = MEM_SIZE + fourth;
  vm->arena[first] = (val >> 24) & 0xFF;
  vm->arena[second] = (val >> 16) & 0xFF;
  vm->arena[third] = (val >> 8) & 0xFF;
  vm->arena[fourth] = val & 0xFF;
  vm->graph[first] = player;
  vm->graph[second] = player;
  vm->graph[third] = player;
  vm->graph[fourth] = player;
}

void		my_st(t_list *pc, t_vm *vm)
{
  int		v;
  int		s;

  if (pc->cod == 80)
    {
      if (((v = (int)vm->arena[((pc->pc + 2) % MEM_SIZE)]) > 0 && v <= 16)
	  && ((s = (int)vm->arena[((pc->pc + 3) % MEM_SIZE)]) > 0 && s <= 16))
	pc->r[s - 1] = pc->r[v - 1];
      pc->pc = (pc->pc + 4) % MEM_SIZE;
    }
  else if (pc->cod == 112)
    {
      v = convert(vm->arena, (pc->pc + 3) % MEM_SIZE, 11);
      if ((s = (int)vm->arena[((pc->pc + 2) % MEM_SIZE)] - 1) >= 0 && s < 16)
	{
	  stock(pc, vm, v, pc->r[s]);
	}
      pc->pc = (pc->pc + 5) % MEM_SIZE;
    }
  pc->wait = -1;
}
