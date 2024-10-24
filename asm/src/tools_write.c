/*
** tools_write.c for  in /home/msa_m/Epitech/C_Prog_Elem/CPE_2014_corewar/ASM/parsing/src
** 
** Made by msa_m
** Login   <msa_m@epitech.net>
** 
** Started on  Sat Apr 11 15:44:44 2015 msa_m
** Last update Sat Apr 11 21:24:29 2015 ugo belfiore
*/

#include "proto.h"
#include "struct.h"

int	reverse_endian(int x)
{
  int	en;

  en = ((x << 8) & 0xFF00FF00) | ((x >> 8) & 0x00FF00FF);
  return ((en << 16) | ((en >> 16) & 0xFFFF));
}

void	my_bzero(char *struc, int size)
{
  int	i;

  i = 0;
  while (i <= size)
    struc[i++] = '\0';
}

void	write_struct(header_t *h, int fd)
{
  h->prog_size = reverse_endian(h->prog_size);
  h->magic = reverse_endian(COREWAR_EXEC_MAGIC);
  write(fd, h, sizeof(header_t));
}

char	coding(int x1, int x2, int x3)
{
  char	result;

  result = 0;
  result += x1 << 6;
  result += x2 << 4;
  result += x3 << 2;
  return (result);
}
