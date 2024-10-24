/*
** my_printf.h for printf in /home/pallua_j/rendu/unix/PSU_2014_my_printf
** 
** Made by jules palluau
** Login   <pallua_j@epitech.net>
** 
** Started on  Mon Nov 10 12:47:45 2014 jules palluau
** Last update Sat Apr 11 20:26:50 2015 cristopher toozs-hobson
*/

#include <stdarg.h>
#include <unistd.h>
#include "printf.h"

t_modulo	gmy_flags[]=
  {
    {'d', &va_my_putnbr},
    {'i', &va_my_putnbr},
    {'o', &va_my_putnbr_base_oct},
    {'X', &va_my_putnbr_base_hexcap},
    {'b', &va_my_putunbr_base},
    {'x', &va_my_putnbr_base_hexmin},
    {'u', &va_my_put_unbr},
    {'c', &va_my_putchar},
    {'s', &va_my_putstr},
    {'S', &va_my_op_str},
    {'p', &va_my_show_adr},
    {'l', &va_my_put_lnbr},
    {'\0', NULL}
  };

int		my_normal(char x, va_list ap)
{
  int		y;
  int		cpt;

  cpt = 0;
  y = 0;
  if (x == '%')
    {
      my_putchar('%');
      cpt++;
    }
  while (gmy_flags[y].fl != '\0')
    {
      if (gmy_flags[y].flags == x)
	cpt += gmy_flags[y].fl(ap);
      y++;
    }
  return (cpt);
}

int		my_printf(char *str, ...)
{
  va_list	ap;
  int		x;
  int		cpt;

  x = 0;
  cpt = 0;
  va_start(ap, str);
  while (str[x])
    {
      if (str[x] == '%')
	{
	  x++;
	  cpt += my_normal(str[x], ap);
	}
      else
	{
	  my_putchar(str[x]);
	  cpt++;
	}
      x++;
    }
  va_end(ap);
  return (cpt);
}
