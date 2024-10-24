/*
** basic_fonction.c for  in /home/msa_m/C_Prog_Elem/CPE_2014_bsq/fonctions
** 
** Made by matheo msa
** Login   <msa_m@epitech.net>
** 
** Started on  Wed Jan  7 11:37:05 2015 matheo msa
** Last update Sat Apr 11 17:35:27 2015 msa_m
*/

#include "proto.h"

void	my_putchar(char n)
{
  write(1, &n, 1);
}

void	my_fputchar(char n)
{
  write(2, &n, 1);
}

void	my_putstr(char *str)
{
  int	c;

  c = 0;
  while (str[c] != '\0')
    {
      my_putchar(str[c]);
      c++;
    }
}

void	my_fputstr(char *str)
{
  int	c;

  c = 0;
  while (str[c] != '\0')
    {
      my_putchar(str[c]);
      c++;
    }
}
