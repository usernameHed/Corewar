/*
** my_ld.c for corewar in /home/toozs-_c/rendu/C_Prog_Elem/CPE_2014_corewar/corewar/src/instructions
** 
** Made by cristopher toozs-hobson
** Login   <toozs-_c@epitech.net>
** 
** Started on  Tue Apr  7 11:22:03 2015 cristopher toozs-hobson
** Last update Sun Apr 12 15:49:40 2015 cristopher toozs-hobson
*/

/*                                                                             
** Usage: if (champ->wait == -1)
**	    {
**	      if (arena[pc] == 2  || arena[pc] == 13)
**             {
**               set_ld(&champ, vm);
**             }
**	      etc...
**	    }
**	  else if (champ.wait == 0)
**	    {
**	      execute_instruction(&champ)
**     --------------------------------------------
**	      if (champ->instruction == 2)
**	 	  my_ld(champ, vm);
**	      else if (champ->instruction == 13)
**		  my_lld(champ, vm);
**     --------------------------------------------
**	    }
**	  else if (champ->wait > 0)
**	    {
**	      champ->wait -= 1;
**	    }
**	  
*/

#include "corewar.h"

void		my_ld(t_list *champ, t_vm *vm)
{
  int		val;
  int		store;

  store = -1;
  if (champ->cod == 208)
    {
      val = convert(vm->arena, (champ->pc + 2) % MEM_SIZE, 11);
      val = convert(vm->arena, (champ->pc + (val % IDX_MOD)) % MEM_SIZE, 10);
      store = (int)vm->arena[((champ->pc + 4) % MEM_SIZE)];
      champ->pc = (champ->pc + 4) % MEM_SIZE;
    }
  else if (champ->cod == 144)
    {
      val = convert(vm->arena, (champ->pc + 2) % MEM_SIZE, 10);
      store = (int)vm->arena[((champ->pc + 6) % MEM_SIZE)];
      champ->pc = (champ->pc + 6) % MEM_SIZE;
    }
  champ->carry = 0;
  if (store > 0 && store <= 16)
    {
      champ->r[store - 1] = val;
      champ->carry = (val == 0) ? 1 : champ->carry;
    }
  champ->pc = (champ->pc + 1) % MEM_SIZE;
  champ->wait = -1;
}

void		my_lld(t_list *champ, t_vm *vm)
{
  int		value;
  int		store;

  store = -1;
  if (champ->cod == 208)
    {
      value = convert(vm->arena, (champ->pc + 2) % MEM_SIZE, 11);
      value = convert(vm->arena, (champ->pc + value) % MEM_SIZE, 10);
      store = (int)vm->arena[((champ->pc + 4) % MEM_SIZE)];
      champ->pc = (champ->pc + 4) % MEM_SIZE;
    }
  else if (champ->cod == 144)
    {
      value = convert(vm->arena, (champ->pc + 2) % MEM_SIZE, 10);
      store = (int)vm->arena[((champ->pc + 6) % MEM_SIZE)];
      champ->pc = (champ->pc + 6) % MEM_SIZE;
    }
  champ->carry = 0;
  if (store > 0 && store <= 16)
    {
      champ->r[store - 1] = value;
      champ->carry = (value == 0) ? 1 : champ->carry;
    }
  champ->pc = (champ->pc + 1) % MEM_SIZE;
  champ->wait = -1;
}
