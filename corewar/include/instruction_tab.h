/*
** instruction_tab.h for corewar in /home/toozs-_c/rendu/C_Prog_Elem/CPE_2014_corewar/bonus/include
** 
** Made by cristopher toozs-hobson
** Login   <toozs-_c@epitech.net>
** 
** Started on  Sat Apr 11 14:00:19 2015 cristopher toozs-hobson
** Last update Sat Apr 11 20:34:22 2015 cristopher toozs-hobson
*/

t_ins	gl_ins[] =
  {
    {&my_live, 1},
    {&my_ld, 2},
    {&my_st, 3},
    {&my_add, 4},
    {&my_sub, 5},
    {&my_and, 6},
    {&my_or, 7},
    {&my_xor, 8},
    {&my_zjmp, 9},
    {&my_ldi, 10},
    {&my_sti, 11},
    {&my_fork, 12},
    {&my_lld, 13},
    {&my_lldi, 14},
    {&my_lfork, 15},
    {&my_aff, 16},
    {NULL, 0}
  };

t_set	gl_set[] =
  {
    {&set_ins, 1, 10, 0},
    {&set_ins, 2, 5, 1},
    {&set_ins, 3, 8, 1},
    {&set_ins, 4, 10, 1},
    {&set_ins, 5, 10, 1},
    {&set_ins, 6, 6, 1},
    {&set_ins, 7, 6, 1},
    {&set_ins, 8, 6, 1},
    {&set_ins, 9, 20, 0},
    {&set_ins, 10, 25, 1},
    {&set_ins, 11, 25, 1},
    {&set_ins, 12, 800, 0},
    {&set_ins, 13, 10, 1},
    {&set_ins, 14, 50, 1},
    {&set_ins, 15, 1000, 0},
    {&set_ins, 16, 2, 1},
    {NULL, 0, 0, 0}
  };
