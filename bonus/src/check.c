/*
** init.c for corewar in /home/pallua_j/rendu/Progelem/CPE_2014_corewar/corewar/src
** 
** Made by jules palluau
** Login   <pallua_j@epitech.net>
** 
** Started on  Wed Mar 18 18:36:03 2015 jules palluau
** Last update Sun Apr 12 17:15:27 2015 cristopher toozs-hobson
*/

#include "corewar.h"

int	check_cor(char *str)
{
  int	x;

  if (str == NULL)
    aff_error("[ERROR]: can't find champ!\n");
  x = my_strlen(str);
  if (str[x - 4] != '.' || str[x - 3] != 'c'
      || str[x - 2] != 'o' || str[x - 1] != 'r')
    {
      my_printf("%s is not a corewar executable\n", str);
      exit(EXIT_FAILURE);
    }
  return (0);
}

int	sequel_parsing(char **av, int *x)
{
  if ((my_strcmp(av[*(x)], "-n")) == 0)
    {
      if (av[*(x) + 1] == NULL)
	aff_error("[ERROR]: Argument after -n is NULL!\n");
      if ((my_str_isnum(av[*(x) + 1])) == 0)
	{
	  my_printf("[ERROR]: %s is an invalid value!\n", av[*(x) + 1]);
	  exit(EXIT_FAILURE);
	}
      check_cor(av[*(x) + 2]);
      *(x) += 2;
    }
  else if ((my_strcmp(av[*(x)], "-a")) == 0)
    {
      if (av[*(x) + 1] == NULL)
	aff_error("[ERROR]: Argument after -a is NULL!\n");
      if ((my_str_isnum(av[*(x) + 1])) == 0)
	{
	  my_printf("[ERROR]: %s is an invalid value!\n", av[*(x) + 1]);
	  exit(EXIT_FAILURE);
	}
      check_cor(av[*(x) + 2]);
      *(x) += 2;
    }
  return (0);
}

void	parsing(char **av, t_vm *vm)
{
  int	x;

  x = 1;
  while (av[x])
    {
      if ((my_strcmp(av[x], "-dump")) == 0)
	{
	  if (av[x + 1] == NULL)
	    aff_error("[ERROR]: Argument after -dump is NULL!\n");
	  x += 2;
	}
      else if ((my_condition(av, x, vm)) == 1)
	{
	  if (av[x + 3] == NULL)
	    aff_error("[ERROR]: Argument after -a is NULL!\n");
	  check_cor(av[x + 4]);
	  x += 4;
	}
      else if ((my_condition(av, x, vm)) == 0)
	parse_multiple_option(av, &x);
      else
	sequel_parsing(av, &x);
      x++;
    }
}

/*
** Vérifie si les options sont existantes
** et appel la fonction my_header pour les intégrés à la vm.
*/

int	prog_number(char **av, t_vm *vm, int *x)
{
  if ((my_condition(av, *(x), vm)) == 1)
    {
      my_header(av[(*x) + 4], vm, my_getnbr(av[(*x) + 1]),
		my_getnbr(av[(*x) + 3]));
      (*x) += 4;
    }
  else if ((my_condition(av, *(x), vm)) == 0)
    {
      my_header(av[(*x) + 4], vm, my_getnbr(av[(*x) + 3]),
		my_getnbr(av[(*x) + 1]));
      (*x) += 4;
    }
  else if ((my_strcmp(av[(*x)], "-n")) == 0)
    {
      vm->n = 1;
      my_header(av[(*x) + 2], vm, my_getnbr(av[(*x) + 1]), -1);
      (*x) += 2;
    }
  else if ((my_strcmp(av[(*x)], "-a")) == 0)
    {
      my_header(av[(*x) + 2], vm, 42, my_getnbr(av[(*x) + 1]));
      (*x) += 2;
    }
  return (0);
}

void	check_option(char **av, t_vm *vm, int ac)
{
  int	x;

  x = 1;
  vm->dump = -1;
  vm->nb_player = 0;
  vm->c = NULL;
  vm->n = 0;
  parsing(av, vm);
  while (x < ac && av[x])
    {
      if ((my_strcmp(av[x], "-dump")) == 0)
	{
	  vm->dump = my_getnbr(av[x + 1]);
	  x += 1;
	}
      else if ((av[x][0] == '-' && av[x][1] == 'n') ||
	       (av[x][0] == '-' && av[x][1] == 'a'))
	prog_number(av, vm, &x);
      else
	if (av[x] != NULL)
	  my_header(av[x], vm, 42, -1);
      x++;
    }
  if (vm->nb_player > 4 || vm->nb_player == 0)
    aff_error("[ERROR]: Invalid number of champions!\n");
}
