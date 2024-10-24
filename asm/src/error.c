/*
** error.c for  in /home/msa_m/Epitech/C_Prog_Elem/CPE_2014_corewar/ASM/parsing/src
** 
** Made by msa_m
** Login   <msa_m@epitech.net>
** 
** Started on  Sat Apr 11 01:49:07 2015 msa_m
** Last update Sun Apr 12 19:26:36 2015 msa_m
*/

#include "proto.h"
#include "struct.h"

void	syntax_error(int line)
{
  my_fputstr("Error: syntax error line ");
  my_put_nbr(line);
  my_fputchar('\n');
  exit(EXIT_FAILURE);
}

void	error_label(int	line, char *label)
{
  my_fputstr(label);
  my_fputstr(" undefine line : ");
  my_put_nbr(line);
  my_fputchar('\n');
  exit(EXIT_FAILURE);
}

void	file_error(char *file)
{
  my_fputstr("Error: The file ");
  my_fputchar('"');
  my_fputstr(file);
  my_fputchar('"');
  my_fputstr(" must have an extension '.s'\n");
  exit(EXIT_FAILURE);
}

void	my_error_exit(char *str)
{
  my_fputstr("\e[0;31m");
  my_fputstr(str);
  my_fputstr("\n\e[0m");
  exit(EXIT_FAILURE);
}

