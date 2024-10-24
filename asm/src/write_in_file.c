/*
** write_in_file.c for corewar in /home/pallua_j/rendu/Progelem/CPE_2014_corewar/ASM/write
** 
** Made by jules palluau
** Login   <pallua_j@epitech.net>
** 
** Started on  Fri Apr 10 23:55:22 2015 jules palluau
** Last update Sun Apr 12 14:29:59 2015 msa_m
*/

#include "proto.h"
#include "struct.h"

int	write_int(int value, int fd)
{
  t_int	convert;

  convert.val = value;
  write(fd, &(convert.set[3]), 1);
  write(fd, &(convert.set[2]), 1);
  write(fd, &(convert.set[1]), 1);
  write(fd, &(convert.set[0]), 1);
  return (4);
}

int		write_short(short value, int fd)
{
  t_short	convert;

  convert.val = value;
  write(fd, &(convert.set[1]), 1);
  write(fd, &(convert.set[0]), 1);
  return (2);
}

int	write_char(char value, int fd)
{
  write(fd, &value, 1);
  return (1);
}

int	write_code(char *value, int fd)
{
  int	hex;

  if (value != NULL)
    {
      hex = my_atoi_base(value, "0123456789ABCDEF");
      write(fd, &hex, 1);
      return (1);
    }
  return (0);
}
