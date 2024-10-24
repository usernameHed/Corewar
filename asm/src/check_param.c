/*
** check_param.c for  in /home/msa_m/Epitech/C_Prog_Elem/CPE_2014_corewar/ASM/parsing/src
** 
** Made by msa_m
** Login   <msa_m@epitech.net>
** 
** Started on  Fri Apr 10 22:37:58 2015 msa_m
** Last update Sat Apr 11 17:18:38 2015 msa_m
*/

#include "proto.h"
#include "struct.h"

void	check_param_loop(char **tab, int c, t_check *check, t_data **data)
{
  char	type_word;

  check->t = 0;
  while (tab[check->check] != NULL)
    {
      check->x = 0;
      while (check->x <= op_tab[c].nbr_args && check->check <= check->nb_word
             && op_tab[c].type[check->x] != 0)
        {
          type_word = word_to_type(tab[++check->check], (*data)->nbr_line);
          if ((type_word & op_tab[c].type[check->x]) != type_word)
            my_error_exit("Error: Argument invalid  tototoa");
          else
            {
              check->param[check->t] = my_strdup(tab[check->check]);
              check->param[check->t++]
		[cmp_char_in_str(tab[check->check])] = '\0';
            }
          check->x++;
        }
      check->check++;
    }
  check->param[check->t] = NULL;
}

/*
** Fonction permettant de vérifier les parametres des
** fonctions appelées.
*/

char		**check_param(int c, char **tab, t_labels **label, t_data **d)
{
  t_check	check;

  check.check = 0;
  (*d)->inc_lab = 0;
  if (tab[0][(my_strlen(tab[0]) - 1)] == LABEL_CHAR)
    {
      (*d)->inc_lab = 1;
      (*label) = put_in_label(tab[0], (*label));
      if (tab[1] != '\0')
        check.check = 1;
    }
  check.param = malloc(sizeof(char *) * (4));
  check.nb_word = cmp_word_in_tab(tab, check.check);
  if (op_tab[c].nbr_args != check.nb_word)
    my_error_exit("Not enough argument");
  check.t = 0;
  check_param_loop(tab, c, &check, d);
  cmp_octet(label, c, check.param, d);
  return (check.param);
}
