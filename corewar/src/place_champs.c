/*
** place_champs.c for corewar in /home/pallua_j/rendu/Progelem/CPE_2014_corewar/corewar/src
** 
** Made by jules palluau
** Login   <pallua_j@epitech.net>
** 
** Started on  Mon Mar 23 19:20:11 2015 jules palluau
** Last update Fri Apr 10 16:51:41 2015 jules palluau
*/

#include "corewar.h"

/*
** Affichage de l'arène en hexadécimal.
*/

int	aff_arena(unsigned char *arena)
{
  int	x;

  x = 0;
  while (x < MEM_SIZE)
    {
      if ((x % 32) == 0 && x != 0)
	my_putchar('\n');
      if (arena[x] > 15)
	my_printf("%x ", arena[x]);
      else if (arena[x] == '\0')
	my_printf("00 ");
      else
	my_printf("0%x ", arena[x]);
      x++;
    }
  my_putchar('\n');
  return (0);
}

/*
** Fonction qui retourne le plus chiffre (numéro de champion)
** dans un tableu d'int, il met à 0 sa case avant de le retourner
** pour pas tomber plusieurs fois dessus.
*/

int	less_champ(t_vm *vm, int *order)
{
  int	x;
  int	y;

  x = 1;
  while (x < 5)
    {
      y = 0;
      while (y < vm->nb_player)
	{
	  if (order[x] != 0 && x == vm->c[y].player)
	    {
	      order[x] = 0;
	      return (y);
	    }
	  y++;
	}
      x++;
    }
  return (0);
}

/*
** Fonction qui place les champions en fonction de leurs adresses
** ou calcul la position du champion si vm->c[ch].add < 0.
*/

t_list	*place_champs(t_vm *vm, t_list *list)
{
  int	ch;
  int	*order;
  int	end;
  char	*s;

  order = init_order();
  end = 0;
  vm->cpt = 0;
  while (end < vm->nb_player)
    {
      ch = less_champ(vm, order);
      if ((s = malloc(sizeof(char) * vm->c[ch].head.prog_size)) == NULL)
	aff_error("Can't perform malloc\n");
      read(vm->c[ch].fd, s, vm->c[ch].head.prog_size);
      if (vm->c[ch].add >= 0)
	list = placement_with_add(vm, list, ch, s);
      else
	list = right_place(vm, list, ch, s);
      end++;
    }
  return (list);
}
