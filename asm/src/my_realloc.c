/*
** my_realloc.c for allum1 in /home/toozs-_c/Prog_tests/allum1
** 
** Made by cristopher toozs-hobson
** Login   <toozs-_c@epitech.net>
** 
** Started on  Wed Feb 11 17:26:37 2015 cristopher toozs-hobson
** Last update Mon Mar 16 17:41:19 2015 cristopher toozs-hobson
*/

#include <stdlib.h>

char		*my_realloc(char *buffer, int size)
{
  int		i;
  char		*tmp;

  if ((tmp = malloc(size)) == NULL)
    exit(0);
  i = 0;
  while (buffer[i] != '\0')
    {
      tmp[i] = buffer[i];
      i++;
    }
  while (i < size)
    tmp[i++] = '\0';
  free(buffer);
  return (tmp);
}
