/*
** my_fonctions_2.c for  in /home/msa_m/Epitech/C_Prog_Elem/CPE_2014_allum1
** 
** Made by msa_m
** Login   <msa_m@epitech.net>
** 
** Started on  Fri Feb 20 13:37:30 2015 msa_m
** Last update Sun Apr 12 21:31:47 2015 msa_m
*/

#include "proto.h"

int	my_strcmp_lab(char *s1, char *s2)
{
  int	x;
  int	y;

  x = 0;
  if (s2[0] == '%')
    y = 2;
  else
    y = 1;
  while (s1[x] || s2[y])
    {
      if (s1[x] != s2[y])
	return (-1);
      x++;
      y++;
    }
  if (s1[x] == ':')
    return (-1);
  if (s1[x] != '\0' && s2[y] == '\0')
    return (-1);
  if (s2[y] != '\0' && s1[x] == '\0')
    return (-1);
  return (0);
}

int		check_label_pos(t_labels *label, char *str, int pos)
{
  int		find;
  t_labels	*tmp;

  tmp = label;
  find = 1;
  while (tmp->next != NULL && find != 0)
    {
      if ((find = my_strcmp_lab(tmp->label, str)) == 0)
	return ((tmp->pos - pos));
      tmp = tmp->next;
    }
  return ((tmp->pos - pos));
}

char	*epur_label(char *label)
{
  char	*lab_epur;
  int	x;
  int	c;

  c = 1;
  x = 0;
  if (label != NULL)
    {
      if ((lab_epur = malloc(sizeof(char) * my_strlen(label) + 1)) == NULL)
	my_error_exit("Error: Malloc can't perform");
      if (label[0] == '%')
	c++;
      while (label[c] != '\0')
	lab_epur[x++] = label[c++];
      lab_epur[x] = '\0';
      return (lab_epur);
    }
  return (NULL);
}

int	cmp_label(t_labels *label, t_data *data, int x, int check)
{
  while (label != NULL && check == -1)
    {
      check = my_strcmp(epur_label(data->param[x]),
			label->label);
      if (label->next == NULL)
	check = 2;
      else
	label = label->next;
    }
  return (check);
}

void	check_label_in_list(t_labels *label, t_data *data)
{
  int	x;
  int	check;

  label = start_list(label, &data);
  while (data != NULL)
    {
      x = 0;
      check = -1;
      while (check == -1 && data->param[x] != NULL)
	{
	  if (data->param[x][0] == '%' && data->param[x][1] == ':')
	    check = cmp_label(label, data, x, check);
	  else if (data->param[x][0] == ':' && check == -1)
	    while (label != NULL)
	      check = cmp_label(label, data, x, check);
	  else
	    check = 0;
	  x++;
	  label = start_label(label);
	}
      if (check == 2)
	error_label(data->nbr_line, epur_label(data->param[--x]));
      data = data->next;
    }
}
