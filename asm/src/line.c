/*
** line.c for  in /home/msa_m/Epitech/C_Prog_Elem/CPE_2014_corewar/ASM/parsing/src
** 
** Made by msa_m
** Login   <msa_m@epitech.net>
** 
** Started on  Thu Apr  2 12:15:34 2015 msa_m
** Last update Sun Apr 12 16:05:20 2015 msa_m
*/

#include "proto.h"
#include "struct.h"

/*
** Vérifie si l'oppération voulu par le programe existe, et si c'est le cas
** elle appelle la fonction qui stock dans la liste chainée
*/

int	check_code(char **tab, t_data **data, t_labels **l)
{
  int	c;

  c = 0;
  if ((my_strcmp(tab[0], ".code")) == 0)
    {
      (*data) = put_data_list((*data), tab[0], tab);
      while (c < cmp_word_in_tab(tab, 0))
	{
	  c++;
	  (*l)->pos++;
	}
      return (1);
    }
  return (0);
}

void	manage_function(char **tab, t_data **data, t_labels **l)
{
  int	check;
  int	c;
  int	find;

  c = -1;
  find = -1;
  check = 0;
  if (tab[0][(my_strlen(tab[0]) - 1)] == LABEL_CHAR)
    if (tab[1] != '\0')
      check = 1;
  if ((tab[check][0] != COMMENT_CHAR && tab[check][0] != ';')
      && tab[0] != NULL)
    if (check_code(tab, data, l) == 0)
      {
	while (c++ != 15 && find != 0)
	  if (my_strcmp(tab[check], op_tab[c].mnemonique) == 0)
	    find = 0;
	c--;
	if (find == -1)
	  syntax_error((*data)->nbr_line);
	else
	  (*data) = put_data_list((*data),
				  op_tab[c].mnemonique,
				  check_param(c, tab, l, data));
      }
}

/*
** Analyse la ligne envoyé par le get_next_line, et la traite en l'envoyant
** vers differentes fonction, faite à cette effet
*/

t_labels	*read_line(char *line, t_labels *label, t_data **d)
{
  char		**tab;

  tab = my_str_to_wordtab(line);
  if (*d == NULL)
    {
      if (((*d) = malloc(sizeof(t_data))) == NULL)
	exit(EXIT_FAILURE);
      (*d)->prev = NULL;
      (*d)->next = NULL;
      (*d)->nbr_line = 3;
    }
  if (tab[0] != NULL)
    manage_function(tab, d, &label);
  return (label);
}
