/*
** right_place.c for corewar in /home/pallua_j/rendu/Progelem/CPE_2014_corewar/corewar/src
** 
** Made by jules palluau
** Login   <pallua_j@epitech.net>
** 
** Started on  Thu Apr  2 10:12:10 2015 jules palluau
** Last update Sat Apr 11 20:07:59 2015 cristopher toozs-hobson
*/

#include "corewar.h"

/*
** Calcul la taille total des champions additionnés.
*/

int	my_total(t_vm *vm)
{
  int	total;
  int	x;

  x = 0;
  total = 0;
  while (x < vm->nb_player)
    {
      total += vm->c[x].head.prog_size;
      x++;
    }
  total = MEM_SIZE - total;
  total /= vm->nb_player;
  if (total > MEM_SIZE)
    aff_error("[ERROR]: Champions too big for memory!\n");
  return (total);
}

/*
** Place un champion avec une adresse valide
** si la case n'est pas déjà écrite.
*/

t_list	*placement_with_add(t_vm *vm, t_list *list, int ch, char *champ)
{
  int	x;

  x = 0;
  if (vm->c[ch].head.prog_size > (MEM_SIZE / 4))
    aff_error("[ERROR]: Champion too big!\n");
  vm->cpt = vm->c[ch].add;
  while (x < vm->c[ch].head.prog_size)
    {
      if (vm->arena[vm->cpt % MEM_SIZE] != '\0')
	aff_error("[ERROR]: Bad champion's address!\n");
      vm->arena[vm->cpt++ % MEM_SIZE] = champ[x++];
    }
  free(champ);
  close(vm->c[ch].fd);
  list = my_put_end_list(list, vm->c[ch].add, vm->c[ch].player);
  return (list);
}

/*
** Calcul la position d'un champion sans addresse
** et le place dans la mémoire.
*/

t_list		*right_place(t_vm *vm, t_list *list, int ch, char *champ)
{
  static int	total = 0;
  int		x;

  x = 0;
  if (vm->c[ch].head.prog_size > (MEM_SIZE / 4))
    aff_error("[ERROR]: Champion too big!\n");
  if (total == 0)
    total = my_total(vm);
  if (vm->cpt != 0)
    vm->cpt = (vm->cpt + total) % MEM_SIZE;
  list = my_put_end_list(list, vm->cpt, vm->c[ch].player);
  while (x < vm->c[ch].head.prog_size)
    {
      if (vm->arena[vm->cpt % MEM_SIZE] != '\0')
	aff_error("[ERROR]: Bad campion's address!\n");
      vm->arena[vm->cpt % MEM_SIZE] = champ[x];
      vm->cpt++;
      x++;
    }
  close(vm->c[ch].fd);
  free(champ);
  return (list);
}
