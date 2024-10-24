/*
** sequel_check.c for corewar in /home/pallua_j/rendu/Progelem/CPE_2014_corewar/corewar/src
** 
** Made by jules palluau
** Login   <pallua_j@epitech.net>
** 
** Started on  Sun Apr 12 13:23:02 2015 jules palluau
** Last update Sun Apr 12 15:13:46 2015 jules palluau
*/

#include "corewar.h"

int	my_condition(char **av, int x, t_vm *vm)
{
  if ((my_strcmp(av[x], "-a")) == 0 && (my_strcmp(av[x + 2], "-n"))
      == 0)
    {
      vm->n = 1;
      return (0);
    }
  else if ((my_strcmp(av[x], "-n")) == 0 && (my_strcmp(av[x + 2], "-a"))
	   == 0)
    {
      vm->n = 1;
      return (1);
    }
  return (-1);
}

int	parse_multiple_option(char **av, int *x)
{
  if (av[*(x) + 3] == NULL)
    aff_error("[ERROR]: Argument after -a is NULL!\n");
  check_cor(av[*(x) + 4]);
  *(x) += 4;
  return (0);
}
