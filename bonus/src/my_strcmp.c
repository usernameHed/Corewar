/*
** my_strcmp.c for my_strcmp in /home/toozs-_c/rendu/Piscine_C_J06/ex_05
** 
** Made by cristopher toozs-hobson
** Login   <toozs-_c@epitech.net>
** 
** Started on  Wed Oct  8 15:04:55 2014 cristopher toozs-hobson
** Last update Sun Apr 12 16:53:23 2015 jules palluau
*/

#include "corewar.h"

int	my_strcmp(char *first, char *second)
{
  int	i;

  i = 0;
  if (first != NULL && second != NULL)
    {
      while (first[i] && first[i] == second[i])
	i++;
      if (first[i] < second[i])
	return (-1);
      if (first[i] > second[i])
	return (1);
      if (my_strlen(first) == my_strlen(second))
	return (0);
    }
  return (-2);
}
