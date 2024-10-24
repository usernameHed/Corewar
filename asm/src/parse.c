/*
** parse.c for  in /home/msa_m/Epitech/C_Prog_Elem/CPE_2014_corewar/ASM/parsing
** 
** Made by msa_m
** Login   <msa_m@epitech.net>
** 
** Started on  Mon Mar 23 10:11:20 2015 msa_m
** Last update Sun Apr 12 18:28:00 2015 msa_m
*/

#include "proto.h"
#include "struct.h"

void	init_header(int fd, header_t *h)
{
  char	*line;
  int	check;

  check = 0;
  while (check != 2 && ((line = get_next_line(fd)) != NULL))
    {
      if (check == 0 && (check_name(line, h) == 0))
	check = 1;
      if (check == 1 && (check_comment(line, h) == 0))
	check = 2;
    }
  if (check == 0)
    my_error_exit("Error: Champion must have a name");
  if (check == 1)
    my_error_exit("Error: Champion must have a comment");
}

t_labels	*parse(char *file, header_t *h, t_labels *label, t_data **data)
{
  int		fd;
  char		*line;

  if ((fd = open(file, O_RDONLY)) == -1)
    my_error_exit("Error: Open fail");
  init_header(fd, h);
  aff_header(h);
  (*data) = init_chained((*data), &label);
  while ((line = get_next_line(fd)) != NULL)
  {
    if (my_strcmp(line, ".extend") != 0 && line[0] != '#' && line != NULL)
      label = read_line(line, label, data);
    (*data)->nbr_line++;
  }
  h->prog_size = (label->pos - 1);
  return (label);
}
