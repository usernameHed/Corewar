/*
** my_func.c for printf in /home/pallua_j/rendu/unix/PSU_2014_my_printf
** 
** Made by jules palluau
** Login   <pallua_j@epitech.net>
** 
** Started on  Mon Nov 10 12:31:01 2014 jules palluau
** Last update Sat Apr 11 20:16:29 2015 cristopher toozs-hobson
*/

#include <unistd.h>
#include "printf.h"

void		my_putchar(char c)
{
  write(1, &c, 1);
}

int		my_putstr(char *str)
{
  int		x;

  x = 0;
  while (str[x])
    {
      my_putchar(str[x]);
      x++;
    }
  return (x);
}

int		my_put_nbr(int nb)
{
  int		div;
  int		x;

  x = 0;
  if (nb < 0)
    {
      nb = (-1) * nb;
      my_putchar('-');
      my_putchar(nb);
      x += 2;
    }
  div = 1;
  while (nb / div > 9)
    div = div * 10;
  while (div != 0)
    {
      my_putchar('0' + (nb / div) % 10);
      nb = nb % div;
      div = div / 10;
      x++;
    }
  return (x - 1);
}

int		my_putnbr_base(unsigned int nbr, char *base)
{
  unsigned int	result;
  unsigned int	div;
  unsigned int	x;
  int		cpt;

  cpt = 0;
  div = 1;
  x = my_strlen(base);
  while ((nbr / div) >= x)
    div *= x;
  while (div > 0)
    {
      result = (nbr / div) % x;
      my_putchar(base[result]);
      cpt++;
      div /= x;
    }
  return (cpt);
}
