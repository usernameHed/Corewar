/*
** corewar.h for korewar in /home/pallua_j/rendu/Progelem/korewar/include
** 
** Made by jules palluau
** Login   <pallua_j@epitech.net>
** 
** Started on  Mon Feb 16 14:36:25 2015 jules palluau
** Last update Sun Apr 12 16:57:09 2015 jules palluau
*/

#ifndef COREWAR_H_

# define COREWAR_H_

/*
********** Include ***********
*/

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <fcntl.h>
# include <sys/stat.h>
#include "op.h"

/*
*********** Liste chainée ***********
*/

typedef struct	s_list
{
  struct s_list	*next;
  int		pc;
  int		carry;
  int		*r;
  int		wait;
  int		instruction;
  int		live;
  int		cod;
  struct s_list	*prev;
}		t_list;

/*
************ Structure ***************
*/

typedef struct	s_champ
{
  int		endian;
  char		*path;
  int		fd;
  int		player;
  int		add;
  int		live;
  header_t	head;
}		t_champ;

typedef struct	s_vm
{
  t_champ	*c;
  int		dump;
  int		nb_cycle;
  int		total_cycle;
  int		cycle_to_die;
  int		nb_player;
  int		lives;
  int		last;
  int		cpt;
  int		n;
  unsigned char	*arena;
  char		graph[MEM_SIZE];
}		t_vm;

/*
************ Instructions ************
*/

typedef struct  s_ins
{
  void          (*ptr)(t_list *champ, t_vm *vm);
  int           instruction;
}               t_ins;

typedef struct  s_set
{
  void          (*ptr)(t_list *champ, t_vm vm, int i);
  int           ins;
  int		wait;
  int		cod;
}               t_set;

/*
********** PROTOTYPES affichages **********
*/

int	my_printf(char *str, ...);
int	aff_arena(unsigned char *arena);
int	aff_error(char *str);

/*
********** Prototypes listes ***********
*/

void	delete_node(t_list **list);
int	my_aff_list(t_list *list);
t_list	*my_put_start_list(t_list *list, int pc, int player);
t_list	*my_put_end_list(t_list *list, int pc, int player);
t_list	*my_put_fork_list(t_list *list, int pc);

/*
********* Prototypes autres ************
*/

int	my_strlen(char *str);
int	my_strcmp(char *first, char *second);
int	my_strncmp(const char *s1, const char *s2, int n);
char	*my_strdup(char *src);
int	my_getnbr(char *str);
int	my_str_isnum(char *str);
void	my_putchar(char c);
int	reverse_endian(int x);

/*
********** Init VM **********
*/

int	*init_order();
int	init_arena(t_vm *vm);
int	*init_reg(int player);

/*
********* Prototypes VM ***************
*/

int	my_header(char *av, t_vm *vm, int x, int add);
int	my_vm(char **av, int ac);
void	check_option(char **av, t_vm *vm, int ac);
int	my_condition(char **av, int x, t_vm *vm);
int	parse_multiple_option(char **av, int *x);
int	check_cor(char *str);
int	less_champ(t_vm *vm, int *order);
t_list	*place_champs(t_vm *vm, t_list *list);
t_list	*right_place(t_vm *vm, t_list *list, int ch, char *champ);
t_list	*placement_with_add(t_vm *vm, t_list *list, int ch, char *champ);
void	game(t_list *champ, t_vm *vm);
int	dump(t_vm *vm);
int	check_live_champ(t_vm *vm);
void	reset_champ_lives(t_vm *vm);
int	dead_champ(t_list *champ, t_vm vm);
void	check_live_process(t_list *pc, t_vm vm);
void	set_ins(t_list *champ, t_vm vm, int i);
int	check_for_instruction(t_list *champ, t_vm vm);
void	execute_instruction(t_list *champ, t_vm *vm);

/*
********** Prototype instructions ***********
*/

void	set_ins(t_list *champ, t_vm vm, int i);
void	carry_set(t_list *champ);
int	convert(unsigned char *arena, int pc, int type);
void	my_add(t_list *champ, t_vm *vm);
void	my_aff(t_list *champ, t_vm *vm);
void	set_aff(t_list *champ, t_vm vm);
void	my_and(t_list *champ, t_vm *vm);
void	and_reg_dir(t_list *champ, t_vm vm);
void	and_ind_dir(t_list *champ, t_vm vm);
void	and_dir_reg(t_list *champ, t_vm vm);
void	my_fork(t_list *champ, t_vm *vm);
void	my_lfork(t_list *champ, t_vm *vm);
void	my_ld(t_list *champ, t_vm *vm);
void	my_lld(t_list *champ, t_vm *vm);
void	my_ldi(t_list *champ, t_vm *vm);
void	my_live(t_list *champ, t_vm *vm);
void	my_lldi(t_list *champ, t_vm *vm);
void	my_or(t_list *pc, t_vm *vm);
void	or_reg_dir(t_list *champ, t_vm vm);
void	or_ind_dir(t_list *champ, t_vm vm);
void	or_dir_reg(t_list *champ, t_vm vm);
void	my_st(t_list *pc, t_vm *vm);
void	my_sti(t_list *champ, t_vm *vm);
void	my_sub(t_list *champ, t_vm *vm);
void	my_xor(t_list *pc, t_vm *vm);
void	xor_reg_dir(t_list *champ, t_vm vm);
void	xor_ind_dir(t_list *champ, t_vm vm);
void	xor_dir_reg(t_list *champ, t_vm vm);
void	set_zjmp(t_list *champ, t_vm vm);
void	my_zjmp(t_list *champ, t_vm *vm);
int	calcul_first(t_list *pc, t_vm vm);
int	calcul_second(t_list *pc, t_vm vm);
int	calculate_jmp(t_list *pc, int param);
void	stock(t_list *pc, t_vm *vm, int loc, int val);
int	calculate_first(t_list *pc, t_vm vm);
int	calculate_second(t_list *pc, t_vm vm);
int	set_jump(t_list *pc);

#endif /* !COREWAR_H_ */
