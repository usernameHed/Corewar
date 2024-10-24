/*
** header.c for corewar in /home/pallua_j/rendu/Progelem/CPE_2014_corewar/corewar/src
** 
** Made by jules palluau
** Login   <pallua_j@epitech.net>
** 
** Started on  Wed Mar 18 11:36:07 2015 jules palluau
** Last update Sat Apr 11 19:46:40 2015 cristopher toozs-hobson
*/

#include "corewar.h"

int		reverse_endian(int x)
{
  int		en;

  en = ((x << 8) & 0xFF00FF00) | ((x >> 8) & 0x00FF00FF);
  return ((en << 16) | ((en >> 16) & 0xFFFF));
}

/*
** Vérifie si le champion est en big ou en little endian.
*/

int		check_magic(t_champ *c, char *name)
{
  if (c->head.magic == COREWAR_EXEC_MAGIC)
    c->endian = 0;
  else if (reverse_endian(c->head.magic) == COREWAR_EXEC_MAGIC)
    c->endian = 1;
  else
    {
      my_printf("[ERROR]: %s is an invalid .cor file\n", name);
      exit(EXIT_FAILURE);
    }
  return (0);
}

/*
** Donne au champion le numéro de joueur le plus petit si il n'a pas été
** précisé.
*/

int		*my_order2(t_vm *vm, int *test, int v)
{
  int		y;
  int		less;

  y = 0;
  less = 5;
  while (y < 5)
    {
      if (test[y] > 0 && test[y] < less)
	{
	  less = test[y];
	}
      y++;
    }
  test[less] = 0;
  vm->c[v].player = less;
  return (test);
}

/*
** Vérifie si le numéro du joueur est précisé
** et si il est disponible.
*/

void		my_order(t_vm * vm, int x, int v)
{
  static int	*test;

  if (v == 0)
    test = init_order();
  if (x == 42)
    test = my_order2(vm, test, v);
  else if ((x > 0 || x < 5) && (test[x] == x))
    {
      test[x] = 0;
      vm->c[v].player = x;
    }
  else if (test[x] == 0 && x > 0 && x < 5)
    {
      my_printf("prog_number %d already used\n", x);
      exit(-1);
    }
  else
    aff_error("[ERROR]: Invalid prog_number!\n");
}

/*
** Récupération du header du champion
** et de toutes ces caractéristiques...
*/

int		my_header(char *av, t_vm *vm, int y, int add)
{
  static int	x = 0;

  if (av == NULL)
    aff_error("Corewar executable missing\n");
  if ((vm->c = realloc(vm->c, sizeof(vm->c[0]) * (x + 1))) == NULL)
    aff_error("Can't perform malloc\n");
  if ((vm->c[x].fd = open(av, O_RDONLY)) == -1)
    {
      my_printf("%s is not a corewar executable\n", av);
      exit(-1);
    }
  read(vm->c[x].fd, &vm->c[x].head, sizeof(header_t));
  check_magic(&vm->c[x], av);
  if (vm->c[x].endian == 1)
    vm->c[x].head.prog_size = reverse_endian(vm->c[x].head.prog_size);
  my_order(vm, y, x);
  if (add >= 0 && add < MEM_SIZE)
    vm->c[x].add = add % MEM_SIZE;
  else if (add >= MEM_SIZE)
    aff_error("[ERROR]: address bigger than MEM_SIZE!\n");
  else
    vm->c[x].add = -1;
  vm->c[x++].live = 0;
  vm->nb_player += 1;
  return (0);
}
