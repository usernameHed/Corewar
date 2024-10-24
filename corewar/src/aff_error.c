/*
** aff_error.c for korewar in /home/pallua_j/rendu/Progelem/korewar/func
** 
** Made by jules palluau
** Login   <pallua_j@epitech.net>
** 
** Started on  Mon Feb 16 14:39:57 2015 jules palluau
** Last update Sat Apr 11 19:26:53 2015 cristopher toozs-hobson
*/

#include "corewar.h"

int	aff_error(char *str)
{
  my_printf("\033[31m");
  write(2, str, my_strlen(str));
  my_printf("\033[0m");
  exit(1);
}
