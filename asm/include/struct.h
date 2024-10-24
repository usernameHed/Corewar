/*
** struct.h for  in /home/msa_m/Epitech/C_Prog_Elem/CPE_2014_corewar/ASM/parsing
** 
** Made by msa_m
** Login   <msa_m@epitech.net>
** 
** Started on  Thu Apr  2 14:47:58 2015 msa_m
** Last update Sat Apr 11 08:02:28 2015 msa_m
*/

#ifndef STRUCT_H_
#define STRUCT_H_

typedef struct		s_labels
{
  char			*label;
  int			pos;
  struct s_labels	*next;
  struct s_labels	*prev;
}			t_labels;

typedef struct		s_data
{
  int			nbr_line;
  int			inc_lab;
  char			*function;
  char			**param;
  struct s_data		*next;
  struct s_data		*prev;
}			t_data;

typedef struct		s_check
{
  int			check;
  char			**param;
  int			nb_word;
  int			x;
  int			t;
}			t_check;

typedef union	u_int
{
  int		val;
  char		set[4];
}		t_int;

typedef union	u_short
{
  short		val;
  char		set[2];
}		t_short;

#endif /* !STRUCT_H_ */
