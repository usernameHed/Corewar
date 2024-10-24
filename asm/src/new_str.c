/*
** my_fonctions_3.c for  in /home/msa_m/Epitech/C_Prog_Elem/CPE_2014_corewar/ASM/parsing/src
** 
** Made by msa_m
** Login   <msa_m@epitech.net>
** 
** Started on  Tue Mar 24 14:56:49 2015 msa_m
** Last update Sat Apr 11 18:03:44 2015 msa_m
*/

#include "proto.h"

char	*new_str(char *first, char *second)
{
  char	*new;
  int	size_one;
  int	size_two;
  int	i;
  int	n;

  size_one = my_strlen(first);
  size_two = my_strlen(second);
  i = 0;
  n = 0;
  if ((new = malloc(sizeof(char) * (size_one + size_two + 1))) == NULL)
    exit(0);
  while (first[i] != '\0')
    {
      new[i] = first[i];
      i++;
    }
  while (second != NULL && second[n] != '\0')
    {
      new[i] = second[n];
      i++;
      n++;
    }
  new[i] = '\0';
  return (new);
}
