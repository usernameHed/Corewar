/*
** creat_file.c for  in /home/msa_m/Epitech/C_Prog_Elem/CPE_2014_corewar/ASM/parsing/src
** 
** Made by msa_m
** Login   <msa_m@epitech.net>
** 
** Started on  Sat Apr 11 15:52:52 2015 msa_m
** Last update Sun Apr 12 12:54:38 2015 msa_m
*/

#include "proto.h"

int	creat_file(char *name_file)
{
  char	*file;
  char	*cor;
  int	c;
  int	i;

  c = 0;
  cor = ".cor";
  i = my_strlen(name_file);
  if (name_file[i - 1] != 's' || name_file[i - 2] != '.')
    file_error(name_file);
  if ((file = malloc(sizeof(char) * (my_strlen(name_file)) + 3)) == NULL)
    exit(-1);
  while (name_file[i--] != '/' && i >= -1)
    c = i;
  c++;
  i = 0;
  while (name_file[c] != '.' && name_file[c] != '\0')
    file[i++] = name_file[c++];
  c = 0;
  while (cor[c] != '\0')
    file[i++] = cor[c++];
  file[i] = '\0';
  return (open(file, O_CREAT | O_TRUNC | O_WRONLY,
   	       S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH));
}

