/*
** word.c for  in /home/msa_m/Epitech/C_Prog_Elem/CPE_2014_corewar/ASM/parsing/src
** 
** Made by msa_m
** Login   <msa_m@epitech.net>
** 
** Started on  Fri Apr 10 22:34:24 2015 msa_m
** Last update Sat Apr 11 18:27:07 2015 msa_m
*/

#include "proto.h"
#include "struct.h"

/*
**  Prend un des arguments d'une fonction et retourne sa
**  taille.
*/

char	word_to_type_size(char *word, int line, int c)
{
  if (word[0] == 'r')
    return (1);
  else if (word[0] == '%')
    {
      if (op_tab[c].code == 10 || op_tab[c].code == 11 ||
	  op_tab[c].code == 14)
	return (IND_SIZE);
      else
	return (DIR_SIZE);
    }
  else if ((word[1] >= '0' && word[1] <= '9') || word[1] == '-')
    return (IND_SIZE);
  else if (word[0] == ':')
    return (IND_SIZE);
  else
    syntax_error(line);
  return (-1);
}

/*
** Prend un des arguments d'une fonction et retourne son
** type.
*/

char	word_to_type(char *word, int line)
{
  if (word[0] == 'r')
    return (T_REG);
  else if (word[0] == '%')
    {
      if (word[1] == ':')
        return (T_DIR);
      else if ((word[1] >= '0' && word[1] <= '9') || word[1] == '-')
        return (T_DIR);
      else
        syntax_error(line);
    }
  else if ((word[1] >= '0' && word[1] <= '9') || word[1] == '-')
    return (T_IND);
  else if (word[0] == ':')
    return (T_IND);
  else
    syntax_error(line);
  return (-1);
}

/*
** Meme principe que la fonction précédente mais
** Avec une gestion d'erreur moins précise.
*/

char	word_to_type_write(char *word, int c)
{
  if (word[0] == 'r')
    return (1);
  else if (word[0] == '%')
    {
      if (op_tab[c].code == 9 || op_tab[c].code == 10 ||
	  op_tab[c].code == 11 || op_tab[c].code == 12 ||
	  op_tab[c].code == 14 || op_tab[c].code == 15)
	return (IND_SIZE);
      else
	return (DIR_SIZE);
    }
  else if ((word[1] >= '0' && word[1] <= '9') || word[1] == '-')
    return (IND_SIZE);
  else if (word[0] == ':')
    return (IND_SIZE);
  return (-1);
}

/*
** Fonction renvoyant 1, 2 ou 3 en fonction du type
** de l'argument donné, elle permet de calculer l'octet
** de codage.
*/

char	word_to_type_code(char *word)
{
  if (word[0] == 'r')
    return (1);
  else if (word[0] == '%')
    {
      if (word[1] == ':')
	return (2);
      else if ((word[1] >= '0' && word[1] <= '9') || word[1] == '-')
	return (2);
    }
  else if ((word[1] >= '0' && word[1] <= '9') || word[1] == '-')
    return (3);
  else if (word[0] == ':')
    return (3);
  return (0);
}

