/*
** printf.h for printf in /home/pallua_j/rendu/unix/PSU_2014_my_printf/include
** 
** Made by jules palluau
** Login   <pallua_j@epitech.net>
** 
** Started on  Mon Nov 10 12:43:57 2014 jules palluau
** Last update Sat Nov 29 18:28:54 2014 Jules Palluau
*/

#include <stdarg.h>

#ifndef PRINTF_H_
# define PRINTF_H_

typedef struct s_modulo
{
  char  flags;
  int   (*fl)(va_list);
}       t_modulo;
void	my_putchar(char c);
int	my_putl_nbr(long nb);
int	my_zero(char x);
int	my_putstr(char *str);
int	my_put_nbr(int nb);
int	my_strncmp(char *s1, char *s2, int n);
int	my_putnbr_base(unsigned int nbr, char *base);
int	my_strlen(char *str);
int	my_put_unbr(unsigned int nb);
int	my_op_str(char *str);
int	my_show_adr(void *);
int	va_my_putnbr_base_hexcap(va_list ap);
int	va_my_put_lnbr(va_list ap);
int	va_my_put_unbr(va_list ap);
int	va_my_op_str(va_list ap);
int	va_my_show_adr(va_list ap);
int	va_my_putunbr_base(va_list ap);
int	va_my_putchar(va_list ap);
int	va_my_putstr(va_list ap);
int	va_my_putnbr(va_list ap);
int	va_my_putnbr_base_oct(va_list ap);
int	va_my_putnbr_base_hexmin(va_list ap);
int	my_printf(char *str, ...);

#endif /* !PRINTF_H_ */
