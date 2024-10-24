/*
** list_len.c for corewar in /home/pallua_j/rendu/Progelem/CPE_2014_corewar/graphique/corewar/func
** 
** Made by jules palluau
** Login   <pallua_j@epitech.net>
** 
** Started on  Sat Apr  4 11:21:49 2015 jules palluau
** Last update Sat Apr 11 21:32:39 2015 ugo belfiore
*/

#include "corewar.h"

int		list_len(t_list *list)
{
  t_list	*tmp;
  int		x;

  tmp = list;
  x = 0;
  while (tmp != NULL)
    {
      x++;
      tmp = tmp->next;
    }
  return (x);
}
