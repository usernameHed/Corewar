/*
** proto.h for  in /home/msa_m/Epitech/C_Prog_Elem/CPE_2014_corewar/ASM/parsing
** 
** Made by msa_m
** Login   <msa_m@epitech.net>
** 
** Started on  Mon Mar 23 10:54:15 2015 msa_m
** Last update Sun Apr 12 22:04:09 2015 cristopher toozs-hobson
*/

#ifndef PROTO_H_
# define PROTO_H_
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "op.h"
#include "struct.h"

void		my_putchar(char n);
void		my_put_nbr(int nb);
void		my_fputchar(char n);
void		my_putstr(char *str);
void		my_fputstr(char *str);
void		aff_header(header_t *h);
void		my_error_exit(char *str);
void		syntax_error(int line);
void		file_error(char *file);
void		error_label(int line, char *label);
void		syntax_error(int line);
void		write_struct(header_t *h, int fd);
void		write_core(t_labels *labels, t_data *data, int fd);
void		my_bzero(char *struc, int size);
void		check_label_in_list(t_labels *label, t_data *data);
void		manage_function(char **tab, t_data **data, t_labels **l);
void		cmp_octet(t_labels **label, int c, char **tab, t_data **data);
void		check_param_loop(char **tab, int c,
				 t_check *check, t_data **data);
void		write_in_file(char *file, header_t *h,
			      t_labels *labels, t_data *data);
int		my_getnbr_asm(char *str, t_labels *label, int pos);
int		my_strlen(char *str);
int		my_getnbr(char *str);
int		check_name(char *line, header_t *h);
int		check_comment(char *line, header_t *h);
int		write_int(int value, int fd);
int		write_short(short value, int fd);
int		write_char(char value, int fd);
int		my_strcmp(char *s1, char *s2);
int		my_condition(char x);
int		creat_file(char *name_file);
int		write_code(char *value, int fd);
int		my_atoi_base(char *str, char *base);
int		cmp_char_in_str(char *str);
int		cmp_word_in_tab(char **tab, int check);
int		check_label_pos(t_labels *label, char *str, int pos);
char		*new_str(char *first, char *second);
char		*my_strdup(char *src);
char		*get_next_line(int fd);
char		coding(int x1, int x2, int x3);
char		word_to_type_code(char *word);
char		*my_strcpy(char *dest, char *src);
char		*my_strcat(char *first, char *second);
char		**my_str_to_wordtab(char *str);
char		**check_param(int c, char **tab, t_labels **label, t_data **d);
char		word_to_type_write(char *word, int c);
char		word_to_type_size(char *word, int line, int c);
char		word_to_type(char *word, int line);
t_data          *put_data_list(t_data *list, char *name, char **p);
t_data		*init_chained(t_data *d, t_labels **b);
t_labels	*put_in_label(char *str, t_labels *labels);
t_labels	*start_label(t_labels *l);
t_labels	*read_line(char *line, t_labels *labels, t_data **d);
t_labels	*start_list(t_labels *b, t_data **d);
t_labels	*parse(char *file, header_t *h,
		       t_labels *labels, t_data **data);

#endif
