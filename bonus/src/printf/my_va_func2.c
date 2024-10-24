/*
** my_va_func2.c for printf in /home/pallua_j/rendu/unix/PSU_2014_my_printf
** 
** Made by jules palluau
** Login   <pallua_j@epitech.net>
** 
** Started on  Tue Nov 11 12:52:39 2014 jules palluau
** Last update Tue Mar 24 10:23:40 2015 jules palluau
*/

#include <stdarg.h>
#include "printf.h"

int	va_my_putnbr_base_hexcap(va_list ap)
{
  int	x;

  x = my_putnbr_base(va_arg(ap, unsigned int), "0123456789ABCDEF");
  return (x);
}

int	va_my_put_unbr(va_list ap)
{
  int	x;

  x = my_put_unbr(va_arg(ap, unsigned int));
  return (x);
}

int	va_my_op_str(va_list ap)
{
  int	x;

  x = my_op_str(va_arg(ap, char *));
  return (x);
}

int	va_my_show_adr(va_list ap)
{
  int	x;

  x = my_show_adr(va_arg(ap, void *));
  return (x);
}

int	va_my_putunbr_base(va_list ap)
{
  int	x;

  x = my_putnbr_base(va_arg(ap, unsigned int), "01");
  return (x);
}
