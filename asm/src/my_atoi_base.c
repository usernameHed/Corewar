/*
** my_atoi_base.c for  in /home/msa_m/Desktop/test_asm/asm_d/src
** 
** Made by msa_m
** Login   <msa_m@epitech.net>
** 
** Started on  Sun Apr 12 14:21:13 2015 msa_m
** Last update Sun Apr 12 14:24:34 2015 msa_m
*/

#include "proto.h"

int	my_pow(int nb, int power)
{
  int	result;
  int	c;

  c = 1;
  result = nb;
  if (power == 0)
    return (1);
  while (c != power)
    {
      result *= nb;
      c++;
    }
  return (result);
}

int	value_char(char c, char *base)
{
  int	i;

  i = 0;
  while (c != base[i])
    i++;
  return (i);
}

int	my_atoi_base(char *str, char *base)
{
  int	c;
  int	neg;
  int	cmp;
  int	len_base;
  int	result;

  cmp = 0;
  neg = 0;
  c = my_strlen(str);
  if (str[0] == '-')
    neg = 1;
  len_base = my_strlen(base);
  result = 0;
  while (c != (0 + neg))
    {
      result += my_pow(len_base, cmp) *
	value_char(str[--c], base);
      cmp++;
    }
  if (neg == 1)
    result *= -1;
  return (result);
}
