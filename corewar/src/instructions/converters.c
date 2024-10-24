/*
** convert_direct.c for corewar in /home/toozs-_c/Prog_tests/corewar_tests/instructions
** 
** Made by cristopher toozs-hobson
** Login   <toozs-_c@epitech.net>
** 
** Started on  Thu Mar 26 14:45:13 2015 cristopher toozs-hobson
** Last update Thu Apr  9 16:37:40 2015 cristopher toozs-hobson
*/

/*
** The int nb is coded in LITTLE ENDIAN, where chain[0] is 0->255.
**
** However, the data recieved from the ASM that'll be put into the
** arena will be in BIG_ENDIAN, therefore the first char must be
** set to the last byte of the information being picked up from the
** arena's memory, etc.
**
** Ex: To have an int nb = 32, the memory would have to look like this:
**
** 0x20 0x00 0x00 0x00
**
** Whereas 32 in the arena would look like this:
** 
** 0x00 0x00 0x00 0x20
**
** So in order to collect the right value, you must collect the
** bytes the other way around.
*/

#include "corewar.h"

int		convert(unsigned char *arena, int pc, int type)
{
  int		nb;
  char		chain[4];

  if (type == 10)
    {
      chain[0] = arena[(pc + 3) % MEM_SIZE];
      chain[1] = arena[(pc + 2) % MEM_SIZE];
      chain[2] = arena[(pc + 1) % MEM_SIZE];
      chain[3] = arena[pc % MEM_SIZE];
      nb = *((int *) chain);
      return (nb);
    }
  else if (type == 11)
    {
      chain[0] = arena[(pc + 1) % MEM_SIZE];
      chain[1] = arena[pc % MEM_SIZE];
      chain[2] = 0;
      chain[3] = 0;
      nb = *((int *) chain);
      if (nb > 0x7FFF)
        nb = nb + 0xFFFF0000;
      return (nb);
    }
  aff_error("Invalid convert type\n");
  return (-1);
}
