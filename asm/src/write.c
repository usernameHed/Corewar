/*
** write.c for  in /home/msa_m/Epitech/C_Prog_Elem/CPE_2014_corewar/ASM/parsing/src
** 
** Made by msa_m
** Login   <msa_m@epitech.net>
** 
** Started on  Sat Apr 11 00:41:56 2015 msa_m
** Last update Sun Apr 12 15:40:01 2015 msa_m
*/

#include "proto.h"
#include "struct.h"

int	check_write_code(t_data *data, int fd, int *pos)
{
  int	x;

  x = 0;
  if ((my_strcmp(data->function, ".code")) == 0)
    {
      while (data->param[x++] != NULL)
	*(pos) += write_code(data->param[x], fd);
      return (1);
    }
  return (0);
}

int	write_function(t_data *data, int fd, int *pos)
{
  int	check;
  int	find;
  int	arg[3];
  int	x;
  int	c;

  find = 1;
  x = 0;
  c = -1;
  while (++c != 15 && find != 0)
    find = my_strcmp(data->function, op_tab[c].mnemonique);
  c--;
  *(pos) += write_char(op_tab[c].code, fd);
  check = 0;
  if ((op_tab[c].nbr_args > 1) || (op_tab[c].code == 16 && c != 12))
    {
      while (data->param[x] != NULL)
	arg[check++] = word_to_type_code(data->param[x++]);
      while (check <= 2)
	arg[check++] = 0;
      *(pos) += write_char(coding(arg[0], arg[1], arg[2]), fd);
    }
  return (*(pos));
}

int	write_core_loop(t_data *data, t_labels *labels, int pos_line, int fd)
{
  int	result;
  int	find;
  int	pos;
  int	x;
  int	c;

  x = 0;
  find = 1;
  c = -1;
  pos = 0;
  while (data->param[x] != NULL)
    {
      while (c++ != 15 && find != 0)
	find = my_strcmp(data->function, op_tab[c].mnemonique);
      c--;
      result = my_getnbr_asm(data->param[x], labels, pos_line);
      if (word_to_type_write(data->param[x], c) == T_REG)
	pos += write_char((char)result, fd);
      if (word_to_type_write(data->param[x], c) == IND_SIZE)
	pos += write_short((short)result, fd);
      if (word_to_type_write(data->param[x], c) == DIR_SIZE)
	pos += write_int(result, fd);
      x++;
    }
  return (pos);
}

void	write_core(t_labels *labels, t_data *data, int fd)
{
  int	pos_line;
  int	pos;

  pos = 0;
  labels = start_list(labels, &data);
  pos_line = 0;
  while (data != NULL)
    {
      if (data->inc_lab == 1)
	labels = labels->next;
      pos_line = pos + 1;
      if (check_write_code(data, fd, &pos) == 0)
	{
	  write_function(data, fd, &pos);
	  pos += write_core_loop(data, labels, pos_line, fd);
	}
      data = data->next;
    }
}

void	write_in_file(char *file, header_t *h, t_labels *labels, t_data *data)
{
  int	fd;

  if ((fd = creat_file(file)) == -1)
    my_error_exit("Error: Open failed");
  write_struct(h, fd);
  write_core(labels, data, fd);
}
