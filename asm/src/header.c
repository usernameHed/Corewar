/*
** header.c for  in /home/msa_m/Epitech/C_Prog_Elem/CPE_2014_corewar/ASM/parsing/src
** 
** Made by msa_m
** Login   <msa_m@epitech.net>
** 
** Started on  Wed Apr  1 08:41:12 2015 msa_m
** Last update Sun Apr 12 18:19:14 2015 msa_m
*/

#include "proto.h"
#include "struct.h"

int	check_name(char *line, header_t *h)
{
  char	**tab;
  int	i;
  int	n;
  int	c;

  i = 1;
  c = 1;
  n = 0;
  tab = my_str_to_wordtab(line);
  if (tab[0] == NULL || (my_strcmp(tab[0], NAME_CMD_STRING) != 0))
    return (1);
  while (tab[i] != NULL)
    {
      while (tab[i][c] != '\0' && tab[i][c] != '"')
	h->prog_name[n++] = tab[i][c++];
      h->prog_name[n++] = ' ';
      c = 0;
      i++;
    }
  h->prog_name[--n] = '\0';
  return (0);
}

int	check_comment(char *line, header_t *h)
{
  char	**tab;
  int	i;
  int	n;
  int	c;

  i = 1;
  c = 1;
  n = 0;
  tab = my_str_to_wordtab(line);
  if (tab[0] == NULL || (my_strcmp(tab[0], COMMENT_CMD_STRING) != 0))
    return (1);
  while (tab[i] != NULL)
    {
      while (tab[i][c] != '\0' && tab[i][c] != '"')
	h->comment[n++] = tab[i][c++];
      h->comment[n++] = ' ';
      c = 0;
      i++;
    }
  h->comment[--n] = '\0';
  return (0);
}

void	aff_header(header_t *h)
{
  my_putstr("Name of the Champion: ");
  my_putstr(h->prog_name);
  my_putchar('\n');
  my_putstr("Comment: ");
  my_putstr(h->comment);
  my_putchar('\n');
}
