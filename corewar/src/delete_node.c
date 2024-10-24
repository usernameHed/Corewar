/*
** delete_node.c for pushswap in /home/pallua_j/rendu/Progelem/CPE_2014_Pushswap/function
** 
** Made by jules palluau
** Login   <pallua_j@epitech.net>
** 
** Started on  Thu Dec  4 13:24:03 2014 jules palluau
** Last update Sat Apr 11 19:32:31 2015 cristopher toozs-hobson
*/

#include "corewar.h"

void		delete_node(t_list **list)
{
  t_list	*tmp_next;
  t_list	*tmp_prev;

  tmp_next = NULL;
  tmp_prev = NULL;
  if ((*list)->next)
    tmp_next = (*list)->next;
  if ((*list)->prev)
    tmp_prev = (*list)->prev;
  if (*list)
    {
      if (tmp_next)
	(*list) = tmp_next;
      else if (tmp_prev)
	(*list) = tmp_prev;
      else
	(*list) = NULL;
      if (tmp_prev)
	tmp_prev->next = tmp_next;
      if (tmp_next)
	tmp_next->prev = tmp_prev;
    }
}
