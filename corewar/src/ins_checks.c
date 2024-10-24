/*
** ins_checks.c for corewar in /home/toozs-_c/rendu/C_Prog_Elem/CPE_2014_corewar/corewar/src
** 
** Made by cristopher toozs-hobson
** Login   <toozs-_c@epitech.net>
** 
** Started on  Sat Apr 11 18:30:34 2015 cristopher toozs-hobson
** Last update Sat Apr 11 18:32:09 2015 cristopher toozs-hobson
*/

#include "corewar.h"
#include "instruction_tab.h"

void		set_ins(t_list *champ, t_vm vm, int i)
{
  champ->instruction = gl_set[i].ins;
  champ->wait = gl_set[i].wait;
  if (gl_set[i].cod == 1)
    champ->cod = vm.arena[(champ->pc + 1) % MEM_SIZE];
  else
    champ->cod = 0;
}

int		check_for_instruction(t_list *champ, t_vm vm)
{
  int		i;

  i = 0;
  champ->instruction = 0;
  while (vm.arena[champ->pc % MEM_SIZE] != gl_set[i].ins
         && gl_set[i].ins != 0)
    i++;
  if (gl_set[i].ins == 0)
    return (0);
  else
    {
      set_ins(champ, vm, i);
      return (1);
    }
}

void		execute_instruction(t_list *champ, t_vm *vm)
{
  int		i;

  i = 0;
  while (champ->instruction != gl_ins[i].instruction
         && gl_ins[i].ptr != NULL)
    i++;
  if (gl_ins[i].ptr != NULL)
    gl_ins[i].ptr(champ, vm);
}
