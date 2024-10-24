/*
** aff_info.c for  in /home/belfio_u/rendu/CPE/CPE_2014_corewar/bonus/src
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Fri Apr  3 21:12:50 2015 ugo belfiore
** Last update Sun Apr 12 13:57:22 2015 ugo belfiore
*/

#include "mlx.h"
#include "mini.h"
#include "my.h"

/*
** affichage des information alphanumérique sur le menu de droite de l'image.
*/

static void	put_charac_bis(t_data *d, int x, int y, char c)
{
 (c == 'Y' || c == 'y') ? MLX(d->mlx_ptr, d->win_ptr, d->pa.pa3.Y, x, y) : 1;
 (c == 'Z' || c == 'z') ? MLX(d->mlx_ptr, d->win_ptr, d->pa.pa3.Z, x, y) : 1;
 (c == '0') ? MLX(d->mlx_ptr, d->win_ptr, d->pa.pan.n0, x, y) : 1;
 (c == '1') ? MLX(d->mlx_ptr, d->win_ptr, d->pa.pan.n1, x, y) : 1;
 (c == '2') ? MLX(d->mlx_ptr, d->win_ptr, d->pa.pan.n2, x, y) : 1;
 (c == '3') ? MLX(d->mlx_ptr, d->win_ptr, d->pa.pan.n3, x, y) : 1;
 (c == '4') ? MLX(d->mlx_ptr, d->win_ptr, d->pa.pan.n4, x, y) : 1;
 (c == '5') ? MLX(d->mlx_ptr, d->win_ptr, d->pa.pan.n5, x, y) : 1;
 (c == '6') ? MLX(d->mlx_ptr, d->win_ptr, d->pa.pan.n6, x, y) : 1;
 (c == '7') ? MLX(d->mlx_ptr, d->win_ptr, d->pa.pan.n7, x, y) : 1;
 (c == '8') ? MLX(d->mlx_ptr, d->win_ptr, d->pa.pan.n8, x, y) : 1;
 (c == '9') ? MLX(d->mlx_ptr, d->win_ptr, d->pa.pan.n9, x, y) : 1;
 (c == '-') ? MLX(d->mlx_ptr, d->win_ptr, d->pa.pa3.MI, x, y) : 1;
}

void	put_charac(t_data *d, int x, int y, char c)
{
  (c == 'A' || c == 'a') ? MLX(d->mlx_ptr, d->win_ptr, d->pa.pa1.A, x, y) : 1;
  (c == 'B' || c == 'b') ? MLX(d->mlx_ptr, d->win_ptr, d->pa.pa1.B, x, y) : 1;
  (c == 'C' || c == 'c') ? MLX(d->mlx_ptr, d->win_ptr, d->pa.pa1.C, x, y) : 1;
  (c == 'D' || c == 'd') ? MLX(d->mlx_ptr, d->win_ptr, d->pa.pa1.D, x, y) : 1;
  (c == 'E' || c == 'e') ? MLX(d->mlx_ptr, d->win_ptr, d->pa.pa1.E, x, y) : 1;
  (c == 'F' || c == 'f') ? MLX(d->mlx_ptr, d->win_ptr, d->pa.pa1.F, x, y) : 1;
  (c == 'G' || c == 'g') ? MLX(d->mlx_ptr, d->win_ptr, d->pa.pa1.G, x, y) : 1;
  (c == 'H' || c == 'h') ? MLX(d->mlx_ptr, d->win_ptr, d->pa.pa1.H, x, y) : 1;
  (c == 'I' || c == 'i') ? MLX(d->mlx_ptr, d->win_ptr, d->pa.pa2.I, x, y) : 1;
  (c == 'J' || c == 'j') ? MLX(d->mlx_ptr, d->win_ptr, d->pa.pa2.J, x, y) : 1;
  (c == 'K' || c == 'k') ? MLX(d->mlx_ptr, d->win_ptr, d->pa.pa2.K, x, y) : 1;
  (c == 'L' || c == 'l') ? MLX(d->mlx_ptr, d->win_ptr, d->pa.pa2.L, x, y) : 1;
  (c == 'M' || c == 'm') ? MLX(d->mlx_ptr, d->win_ptr, d->pa.pa2.M, x, y) : 1;
  (c == 'N' || c == 'n') ? MLX(d->mlx_ptr, d->win_ptr, d->pa.pa2.N, x, y) : 1;
  (c == 'O' || c == 'o') ? MLX(d->mlx_ptr, d->win_ptr, d->pa.pa2.O, x, y) : 1;
  (c == 'P' || c == 'p') ? MLX(d->mlx_ptr, d->win_ptr, d->pa.pa2.P, x, y) : 1;
  (c == 'Q' || c == 'q') ? MLX(d->mlx_ptr, d->win_ptr, d->pa.pa3.Q, x, y) : 1;
  (c == 'R' || c == 'r') ? MLX(d->mlx_ptr, d->win_ptr, d->pa.pa3.R, x, y) : 1;
  (c == 'S' || c == 's') ? MLX(d->mlx_ptr, d->win_ptr, d->pa.pa3.S, x, y) : 1;
  (c == 'T' || c == 't') ? MLX(d->mlx_ptr, d->win_ptr, d->pa.pa3.T, x, y) : 1;
  (c == 'U' || c == 'u') ? MLX(d->mlx_ptr, d->win_ptr, d->pa.pa3.U, x, y) : 1;
  (c == 'V' || c == 'v') ? MLX(d->mlx_ptr, d->win_ptr, d->pa.pa3.V, x, y) : 1;
  (c == 'W' || c == 'w') ? MLX(d->mlx_ptr, d->win_ptr, d->pa.pa3.W, x, y) : 1;
  (c == 'X' || c == 'x') ? MLX(d->mlx_ptr, d->win_ptr, d->pa.pa3.X, x, y) : 1;
  put_charac_bis(d, x, y, c);
}

static void	aff_champi(t_data *d)
{
  put_charac(d, 1577, 277, d->vmm.name[0][0]);
  put_charac(d, 1599, 277, d->vmm.name[0][1]);
  put_charac(d, 1646, 277, d->vmm.name[1][0]);
  put_charac(d, 1668, 277, d->vmm.name[1][1]);
  put_charac(d, 1726, 277, d->vmm.name[2][0]);
  put_charac(d, 1748, 277, d->vmm.name[2][1]);
  put_charac(d, 1795, 277, d->vmm.name[3][0]);
  put_charac(d, 1817, 277, d->vmm.name[3][1]);
}

void	aff_info(t_data *d)
{
  int	total[4];

  total[0] = d->ow[0].m.nb_par[0] + d->ow[1].m.nb_par[0]
    + d->ow[2].m.nb_par[0] + d->ow[3].m.nb_par[0];
  total[1] = d->ow[0].m.nb_par[1] + d->ow[1].m.nb_par[1]
    + d->ow[2].m.nb_par[1] + d->ow[3].m.nb_par[1];
  total[2] = d->ow[0].m.nb_par[2] + d->ow[1].m.nb_par[2]
    + d->ow[2].m.nb_par[2] + d->ow[3].m.nb_par[2];
  total[3] = d->ow[0].m.nb_par[3] + d->ow[1].m.nb_par[3]
    + d->ow[2].m.nb_par[3] + d->ow[3].m.nb_par[3];
  d->ch.bigg[0] = total[0] / 100;
  d->ch.bigg[1] = total[1] / 100;
  d->ch.bigg[2] = total[2] / 100;
  d->ch.bigg[3] = total[3] / 100;
  aff_champi(d);
  aff_rec_mem(d, total);
  rec_init(d);
  my_put_nbr_weird(d, 1730, 779, d->vmm.cycle);
  my_put_nbr_weird(d, 1730, 826, d->vmm.cycle_to_die);
  my_put_nbr_weird(d, 1730, 874, d->vmm.total_cycle);
  my_put_nbr_weird(d, 1730, 920, d->vmm.process);
}
