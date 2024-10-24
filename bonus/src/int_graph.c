/*
** int_graph.c for corewar in /home/pallua_j/rendu/Progelem/CPE_2014_corewar/graphique/corewar/src
** 
** Made by jules palluau
** Login   <pallua_j@epitech.net>
** 
** Started on  Sat Apr  4 10:44:55 2015 jules palluau
** Last update Wed Apr  8 17:44:07 2015 ugo belfiore
*/

#include "mini.h"

int	create_name(t_vm *vm)
{
  int	ch;

  ch = 0;
  while (ch < vm->nb_player)
    {
      if ((vm->c[ch].name = malloc(sizeof(char) * (3 + 1))) == NULL)
	aff_error("Can't perfor malloc\n");
      vm->c[ch].name[0] = vm->c[ch].head.prog_name[0];
      vm->c[ch].name[1] = vm->c[ch].head.prog_name[1];
      vm->c[ch].name[3] = '\0';
      ch++;
    }
  return (0);
}

int	transpose_name(t_data *d)
{
  int	ch;

  ch = 0;
  while (ch < d->vm->nb_player)
    {
      d->vmm.name[d->vm->c[ch].player - 1][0] = d->vm->c[ch].name[0];
      d->vmm.name[d->vm->c[ch].player - 1][1] = d->vm->c[ch].name[1];
      ch++;
    }
  return (0);
}
