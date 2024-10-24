/*
** dump.c for corewar in /home/pallua_j/rendu/Progelem/CPE_2014_corewar/corewar/src
** 
** Made by jules palluau
** Login   <pallua_j@epitech.net>
** 
** Started on  Sat Apr 11 00:04:25 2015 jules palluau
** Last update Sat Apr 11 00:05:45 2015 jules palluau
*/

#include "corewar.h"

int	dump(t_vm *vm)
{
  aff_arena(vm->arena);
  exit(EXIT_SUCCESS);
  return (0);
}
