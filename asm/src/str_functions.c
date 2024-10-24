/*
** str_function.c for  in /home/msa_m/Epitech/C_Prog_Elem/CPE_2014_corewar/ASM/parsing
** 
** Made by msa_m
** Login   <msa_m@epitech.net>
** 
** Started on  Sat Apr 11 17:34:34 2015 msa_m
** Last update Sat Apr 11 19:44:57 2015 ugo belfiore
*/

#include "proto.h"

int	my_strlen(char *str)
{
  int	c;

  c = 0;
  while (str[c] != '\0')
    c++;
  return (c);
}

int	my_strcmp(char *s1, char *s2)
{
  int	c;

  c = 0;
  while (s1[c] == s2[c] && s1[c] != '\0')
    c++;
  if (c == my_strlen(s1))
    return (0);
  else
    return (-1);
}

char	*my_strdup(char *src)
{
  int	c;
  char	*d;

  c = my_strlen(src);
  d = malloc(sizeof(char) * (c) + 1);
  if (d == NULL)
    return (NULL);
  my_strcpy(d, src);
  return (d);
}

char	*my_strcat(char *first, char *second)
{
  char	*new;

  if (first == NULL && second == NULL)
    return (NULL);
  new = new_str(first, second);
  return (new);
}

char	*my_strcpy(char *dest, char *src)
{
  int	c;

  c = 0;
  while (src[c] != '\0')
    {
      dest[c] = src[c];
      c += 1;
    }
  dest[c] = '\0';
  return (dest);
}
