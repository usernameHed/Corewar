/*
** nbr_functions.c for  in /home/msa_m/Epitech/C_Prog_Elem/CPE_2014_corewar/ASM/parsing
** 
** Made by msa_m
** Login   <msa_m@epitech.net>
** 
** Started on  Sat Apr 11 17:38:38 2015 msa_m
** Last update Sat Apr 11 21:22:28 2015 ugo belfiore
*/

#include "proto.h"
#include "struct.h"

void	my_put_nbr(int nb)
{
  int	c;
  char	*base;

  c = 1;
  base = "0123456789";
  if (nb < 0)
    {
      nb = -nb;
      my_putchar('-');
    }
  while (nb / c >= 10)
    c = c * 10;
  while (c > 0)
    {
      my_putchar(base[nb / c % 10]);
      c = c / 10;
    }
}

void	my_fput_nbr(int nb)
{
  int	c;
  char	*base;

  c = 1;
  base = "0123456789";
  if (nb < 0)
    {
      nb = -nb;
      my_fputchar('-');
    }
  while (nb / c >= 10)
    c = c * 10;
  while (c > 0)
    {
      my_fputchar(base[nb / c % 10]);
      c = c / 10;
    }
}

int	my_getnbr_asm(char *str, t_labels *label, int pos)
{
  int	nb;
  int	sign;
  int	i;

  nb = 0;
  sign = 0;
  i = 0;
  if (str[0] == ':')
    return (check_label_pos(label, str, pos));
  if (str[0] == '%')
    {
      if (str[1] == ':')
        return (check_label_pos(label, str, pos));
      i++;
    }
  else if (str[0] == 'r')
    i++;
  if (!str)
    return (0);
  while (str[i] != '\0' && (str[i] == '-' || str[i] == '+'))
    if (str[i++] == '-')
      ++sign;
  while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
    nb = (nb * 10) + (str[i++] - '0');
  return (((sign % 2) == 1) ? ((nb) * (-1)) : (nb));
}
