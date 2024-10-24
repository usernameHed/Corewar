/*
** main.c for  in /home/msa_m/Epitech/C_Prog_Elem/CPE_2014_corewar/ASM/parsing
** 
** Made by msa_m
** Login   <msa_m@epitech.net>
** 
** Started on  Mon Mar 23 09:57:08 2015 msa_m
** Last update Sun Apr 12 19:39:49 2015 msa_m
*/

#include "proto.h"
#include "struct.h"

int		main(int ac, char **av)
{
  header_t	h;
  t_labels	*labels;
  t_data	*data;
  int		i;

  data = NULL;
  labels = NULL;
  i = my_strlen(av[1]);
  if (av[1][i - 1] != 's' || av[1][i - 2] != '.')
    file_error(av[1]);
  my_bzero((char *)&h, sizeof(header_t));
  if (ac >= 2)
    {
      labels = parse(av[1], &h, labels, &data);
      check_label_in_list(labels, data);
      write_in_file(av[1], &h, labels, data);
    }
  my_putchar('\n');
  return (0);
}
