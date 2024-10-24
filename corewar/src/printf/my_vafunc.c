/*
** my_vafunc.c for printf in /home/pallua_j/rendu/unix/PSU_2014_my_printf
** 
** Made by jules palluau
** Login   <pallua_j@epitech.net>
** 
** Started on  Tue Nov 11 12:23:37 2014 jules palluau
** Last update Wed Apr  1 10:24:10 2015 jules palluau
*/

#include <stdarg.h>
#include "printf.h"

int	va_my_putchar(va_list ap)
{
  my_putchar((char) va_arg(ap, int));
  return (1);
}

int	va_my_putstr(va_list ap)
{
  int	x;

  x = my_putstr(va_arg(ap, char *));
  return (x);
}

int	va_my_putnbr(va_list ap)
{
  int	x;

  x = my_put_nbr(va_arg(ap, int));
  return (x);
}

int	va_my_putnbr_base_oct(va_list ap)
{
  int	x;

  x = my_putnbr_base(va_arg(ap, unsigned int), "01234567");
  return (x);
}

int	va_my_putnbr_base_hexmin(va_list ap)
{
  int	x;

  x = my_putnbr_base(va_arg(ap, unsigned int), "0123456789ABCDEF");
  return (x);
}
