/*
** my_aff_list.c for pushswap.c in /home/pallua_j/rendu/Progelem/CPE_2014_Pushswap/function
**
** Made by jules palluau
** Login   <pallua_j@epitech.net>
**
** Started on  Wed Dec  3 14:16:47 2014 jules palluau
** Last update Wed Mar 18 14:09:12 2015 jules palluau
*/

#include "corewar.h"

int		my_aff_list(t_list *list)
{
  t_list	*tmp;

  if (list == NULL)
    return (-1);
  tmp = list;
  while (tmp != NULL)
    {
      my_printf("%d\n", tmp->pc);
      tmp = tmp->next;
    }
  return (0);
}
