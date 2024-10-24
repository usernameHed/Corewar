/*
** my_op_str.c for printf in /home/pallua_j/rendu/unix/PSU_2014_my_printf
** 
** Made by jules palluau
** Login   <pallua_j@epitech.net>
** 
** Started on  Wed Nov 12 13:17:55 2014 jules palluau
** Last update Sat Apr 11 21:30:11 2015 ugo belfiore
*/

#include "printf.h"

int	my_zero(char x)
{
  int	cpt;

  cpt = 0;
  if (x < 10)
    {
      my_putstr("00");
      cpt += 2;
    }
  if (x > 9 && x < 100)
    {
      my_putchar('0');
      cpt++;
    }
  return (cpt);
}

int	my_op_str(char *str)
{
  int	x;
  int	cpt;

  x = 0;
  cpt = 0;
  while (str[x])
    {
      if (str[x] < 32 || str[x] >= 127)
        {
          my_putchar('\\');
          cpt++;
	  cpt += my_zero(str[x]);
          my_putnbr_base(str[x], "01234567");
        }
      else
        my_putchar(str[x]);
      x++;
    }
  x += cpt;
  return (x + 1);
}
