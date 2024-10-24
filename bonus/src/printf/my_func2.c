/*
** my_func2.c for printf in /home/pallua_j/rendu/unix/PSU_2014_my_printf
** 
** Made by jules palluau
** Login   <pallua_j@epitech.net>
** 
** Started on  Mon Nov 10 12:41:41 2014 jules palluau
** Last update Sat Apr 11 21:29:50 2015 ugo belfiore
*/

#include <stdlib.h>
#include "printf.h"

int	my_strlen(char *str)
{
  int	x;

  x = 0;
  if (str == NULL)
    return (0);
  while (str[x])
    x++;
  return (x);
}

int	my_put_unbr(unsigned int nb)
{
  int	div;
  int	x;

  x = 0;
  div = 1;
  while (nb / div > 9)
    div *= 10;
  while (div != 0)
    {
      my_putchar('0' + (nb / div) % 10);
      nb %= div;
      div /= 10;
      x++;
    }
  return (x - 1);
}

int		my_show_adr(void *p)
{
  unsigned long	adr;
  char		*base;
  char		res[9];
  int		x;

  x = 8;
  base = "0123456789abcdef";
  adr = (unsigned long) p;
  while (((adr / 16) > 0) || (x >= 8))
    {
      res[x] = base[(adr % 16)];
      adr /= 16;
      x--;
    }
  res[x] = base[(adr % 16)];
  my_putchar('0');
  my_putchar('x');
  while (x < 9)
    {
      my_putchar(res[x]);
      x++;
    }
  return (8);
}

int	my_putl_nbr(long nb)
{
  int	div;
  int	x;

  if (nb < 0)
    {
      nb = (-1) * nb;
      my_putchar('-');
      my_putchar(nb);
    }
  div = 1;
  x = 0;
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

int	va_my_put_lnbr(va_list ap)
{
  int	x;

  x = my_putl_nbr(va_arg(ap, long));
  return (x);
}
