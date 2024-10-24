/*
** my_put_in_list.c for push_swap in /home/pallua_j/rendu/Progelem/CPE_2014_Pushswap/function
**
** Made by jules palluau
** Login   <pallua_j@epitech.net>
**
** Started on  Tue Dec  2 14:17:15 2014 jules palluau
** Last update Fri Apr 10 18:09:26 2015 cristopher toozs-hobson
*/

#include "corewar.h"

t_list		*my_put_start_list(t_list *list, int pc, int player)
{
  t_list	*elem;

  elem = malloc(sizeof(*elem));
  elem->prev = NULL;
  elem->next = NULL;
  elem->pc = pc;
  elem->carry = 0;
  elem->r = init_reg(player);
  elem->wait = -1;
  elem->instruction = 0;
  elem->live = 0;
  elem->cod = 0;
  if (list == NULL)
    return (elem);
  elem->next = list;
  elem->next->prev = elem;
  return (elem);
}

t_list			*my_put_end_list(t_list *list, int pc, int player)
{
  t_list		*elem;
  t_list		*tmp;

  elem = malloc(sizeof(*elem));
  elem->prev = NULL;
  elem->next = NULL;
  elem->pc = pc % MEM_SIZE;
  elem->r = init_reg(player);
  elem->carry = 0;
  elem->wait = -1;
  elem->instruction = 0;
  elem->live = 0;
  elem->cod = 0;
  if (list == NULL)
    return (elem);
  tmp = list;
  while (tmp->next != NULL)
    tmp = tmp->next;
  tmp->next = elem;
  elem->prev = tmp;
  return (list);
}

t_list		*remp_list(t_list *list, t_list *elem)
{
  int		x;

  x = 0;
  if ((elem->r = malloc(sizeof(int) * REG_NUMBER)) == NULL)
    aff_error("Can't perform malloc\n");
  while (x < REG_NUMBER)
    {
      elem->r[x] = list->r[x];
      x++;
    }
  elem->carry = list->carry;
  elem->wait = list->wait;
  elem->instruction = list->instruction;
  elem->live = list->live;
  elem->cod = list->cod;
  return (elem);
}

t_list		*my_put_fork_list(t_list *list, int pc)
{
  t_list	*elem;
  t_list	*tmp;

  elem = malloc(sizeof(*elem));
  elem->prev = NULL;
  elem->next = NULL;
  elem = remp_list(list, elem);
  elem->pc = pc % MEM_SIZE;
  if (list == NULL)
    return (elem);
  tmp = list;
  while (tmp->next != NULL)
    tmp = tmp->next;
  tmp->next = elem;
  elem->prev = tmp;
  return (list);
}
