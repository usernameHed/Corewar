/*
** main.c for corewar in /home/pallua_j/rendu/Progelem/CPE_2014_corewar/corewar/src
** 
** Made by jules palluau
** Login   <pallua_j@epitech.net>
** 
** Started on  Tue Mar 17 21:36:24 2015 jules palluau
** Last update Sun Apr 12 11:33:10 2015 cristopher toozs-hobson
*/

#include "corewar.h"

int	main(int ac, char **av)
{
  if (ac <= 1)
    {
      my_printf("\033[31m");
      my_printf("Usage : ./corewar [-dump nbr_cycle] [[-n prog_number]");
      my_printf(" [-a load_address] prog_name] ... \n");
      my_printf("\033[0m");
      return (1);
    }
  else
    my_vm(av, ac);
  return (0);
}
