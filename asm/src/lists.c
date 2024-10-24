/*
** lists.c for  in /home/msa_m/Epitech/C_Prog_Elem/CPE_2014_corewar/ASM/parsing/src
** 
** Made by msa_m
** Login   <msa_m@epitech.net>
** 
** Started on  Fri Apr 10 22:03:52 2015 msa_m
** Last update Sun Apr 12 19:40:49 2015 msa_m
*/

#include "proto.h"
#include "struct.h"

/*
**Cette fonction permet de stocket les noms de labels dans une
**liste chainée, pour permettre la vérification de l'existance
**de d'un label appellé par la suite dans le code
*/

t_labels	*put_in_label(char *str, t_labels *labels)
{
  t_labels	*elem;
  t_labels	*tmp;
  int		c;

  c = -1;
  elem = malloc(sizeof(*elem));
  if (elem == NULL)
    return (NULL);
  if ((elem->label = malloc(sizeof(char) * my_strlen(str))) == NULL)
    my_error_exit("Error: Error Malloc");
  while (str[++c] != ':')
    elem->label[c] = str[c];
  elem->label[c] = '\0';
  tmp = labels;
  while (tmp->next != NULL)
    tmp = tmp->next;
  tmp->next = elem;
  elem->prev = tmp;
  while (tmp->prev != NULL)
    tmp = tmp->prev;
  elem->pos = tmp->pos;
  return (labels);
}

/*
**Remplis le maillon de l'action fait par le programme
*/

t_data		*put_data_list(t_data *list, char *name, char **p)
{
  t_data	*elem;
  t_data	*tmp;

  if ((elem = malloc(sizeof(*elem))) == NULL)
    exit(EXIT_FAILURE);
  elem->function = my_strdup(name);
  elem->param = p;
  tmp = list;
  while (tmp->next != NULL)
    tmp = tmp->next;
  tmp->next = elem;
  elem->prev = tmp;
  while (tmp->prev != NULL)
    tmp = tmp->prev;
  elem->nbr_line = tmp->nbr_line;
  return (list);
}

/*
** Fonction qui initialise les 2 listes chainees
*/

t_data	*init_chained(t_data *d, t_labels **b)
{
  if ((*b) == NULL)
    {
      if (((*b) = malloc(sizeof(t_labels))) == NULL)
        exit(EXIT_FAILURE);
      (*b)->prev = NULL;
      (*b)->next = NULL;
      (*b)->pos = 1;
    }
  if (d == NULL)
    {
      if ((d = malloc(sizeof(t_data))) == NULL)
        exit(EXIT_FAILURE);
      d->prev = NULL;
      d->next = NULL;
      d->nbr_line = 3;
    }
  return (d);
}

/*
** Fonction permettant de remettre les listes
** au premier maillon de la chaine.
*/

t_labels	*start_list(t_labels *l, t_data **d)
{
  while (l->prev != NULL)
    l = l->prev;
  while ((*d)->prev != NULL)
    (*d) = (*d)->prev;
  l = l->next;
  (*d) = (*d)->next;
  return (l);
}

t_labels	*start_label(t_labels *l)
{
  while (l->prev != NULL)
    l = l->prev;
  l = l->next;
  return (l);
}
