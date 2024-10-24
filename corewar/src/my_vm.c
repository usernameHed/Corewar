/*
** my_vm.c for corewar in /home/toozs-_c/rendu/C_Prog_Elem/CPE_2014_corewar/corewar/src
** 
** Made by cristopher toozs-hobson
** Login   <toozs-_c@epitech.net>
** 
** Started on  Tue Apr  7 10:02:41 2015 cristopher toozs-hobson
** Last update Sun Apr 12 14:45:36 2015 cristopher toozs-hobson
*/

#include "corewar.h"

void		check_winner(t_vm vm)
{
  int		i;
  int		living;

  living = 0;
  i = -1;
  while (++i < vm.nb_player)
    {
      if (vm.c[i].live == 1)
	living++;
    }
  if (living > 1 || (living == 0 && vm.last != -1))
    my_printf("Player %d(%s) wins!\n", vm.c[vm.last].player,
	      vm.c[vm.last].head.prog_name);
  else if (living == 1)
    {
      i = -1;
      while (++i < vm.nb_player)
	{
	  if (vm.c[i].live == 1)
	    my_printf("Player %d(%s) wins!\n", vm.c[i].player,
		      vm.c[i].head.prog_name);
	}
    }
  else if (living == 0 && vm.last == -1)
    my_printf("No champions lived!\n");
}

int		my_vm(char **av, int ac)
{
  t_vm		*vm;
  t_list	*list;

  list = NULL;
  if ((vm = malloc(sizeof(*vm))) == NULL)
    aff_error("Can't perform malloc\n");
  init_arena(vm);
  check_option(av, vm, ac);
  list = place_champs(vm, list);
  game(list, vm);
  check_winner(*(vm));
  return (0);
}
