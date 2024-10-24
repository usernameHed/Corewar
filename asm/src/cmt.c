/*
** cmp.c for  in /home/msa_m/Epitech/C_Prog_Elem/CPE_2014_corewar/ASM/parsing/src
** 
** Made by msa_m
** Login   <msa_m@epitech.net>
** 
** Started on  Fri Apr 10 22:25:58 2015 msa_m
** Last update Sun Apr 12 14:57:48 2015 msa_m
*/

#include "struct.h"
#include "proto.h"

/*
** Compte le nombre de mots dans un double
** tableau de charactères.
*/

int	cmp_word_in_tab(char **tab, int check)
{
  int	nb_word;
  int	check_com;

  nb_word = 0;
  check_com = 0;
  while (tab[nb_word] != NULL && check_com == 0)
    {
      if (tab[nb_word][0] == ';'
          || tab[nb_word][0] == '#')
        check_com = 1;
      nb_word++;
    }
  nb_word--;
  nb_word -= (check + check_com);
  return (nb_word);
}

/*
** Fontion permettant de compter le nombre de caracteres
** dans un tableau de char, il se basse sur les condtions
** du str to wordatab.
*/

int	cmp_char_in_str(char *str)
{
  int	c;

  c = 0;
  while (my_condition(str[c]) == 0 || str[c] != '\0')
    c++;
  return (c);
}

/*
** Permet de compter les octets dans une lignes pour donner
** une position a un label plus facilement, tout est stocke
** dans la liste chainé des labels, donc au dernier maillon
** il doit y avoir la taille total du programme.
*/

void	cmp_octet(t_labels **label, int c, char **tab, t_data **data)
{
  int	x;

  x = 0;
  (*label)->pos++;
  if (op_tab[c].code == 9 || op_tab[c].code == 12 ||
      op_tab[c].code == 15)
    (*label)->pos += 2;
  else
    {
      if (op_tab[c].nbr_args > 1)
        (*label)->pos++;
      while (tab[x] != NULL)
        (*label)->pos += word_to_type_size(tab[x++], (*data)->nbr_line, c);
    }
}
