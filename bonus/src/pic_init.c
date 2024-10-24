/*
** init_xmp.c for  in /home/belfio_u/rendu/CPE/CPE_2014_corewar/bonus/src
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Sat Apr  4 22:37:27 2015 ugo belfiore
** Last update Sun Apr 12 13:57:54 2015 ugo belfiore
*/

#include "mlx.h"
#include "mini.h"
#include "my.h"

void	xmp_one(t_data *d)
{
  d->pa.pan.n0 = mlx_xpm_file_to_image(d->mlx_ptr, "./texture/pic/0.xpm", SAF);
  d->pa.pan.n1 = mlx_xpm_file_to_image(d->mlx_ptr, "./texture/pic/1.xpm", SAF);
  d->pa.pan.n2 = mlx_xpm_file_to_image(d->mlx_ptr, "./texture/pic/2.xpm", SAF);
  d->pa.pan.n3 = mlx_xpm_file_to_image(d->mlx_ptr, "./texture/pic/3.xpm", SAF);
  d->pa.pan.n4 = mlx_xpm_file_to_image(d->mlx_ptr, "./texture/pic/4.xpm", SAF);
  d->pa.pan.n5 = mlx_xpm_file_to_image(d->mlx_ptr, "./texture/pic/5.xpm", SAF);
  d->pa.pan.n6 = mlx_xpm_file_to_image(d->mlx_ptr, "./texture/pic/6.xpm", SAF);
  d->pa.pan.n7 = mlx_xpm_file_to_image(d->mlx_ptr, "./texture/pic/7.xpm", SAF);
  d->pa.pan.n8 = mlx_xpm_file_to_image(d->mlx_ptr, "./texture/pic/8.xpm", SAF);
  d->pa.pan.n9 = mlx_xpm_file_to_image(d->mlx_ptr, "./texture/pic/9.xpm", SAF);
  (!d->pa.pan.n0) ? quitt(d) : 1;
  (!d->pa.pan.n1) ? quitt(d) : 1;
  (!d->pa.pan.n2) ? quitt(d) : 1;
  (!d->pa.pan.n3) ? quitt(d) : 1;
  (!d->pa.pan.n4) ? quitt(d) : 1;
  (!d->pa.pan.n5) ? quitt(d) : 1;
  (!d->pa.pan.n6) ? quitt(d) : 1;
  (!d->pa.pan.n7) ? quitt(d) : 1;
  (!d->pa.pan.n8) ? quitt(d) : 1;
  (!d->pa.pan.n9) ? quitt(d) : 1;
}

void	xmp_two(t_data *d)
{
  d->pa.pa1.A = mlx_xpm_file_to_image(d->mlx_ptr, "./texture/pic/A.xpm", SAF);
  d->pa.pa1.B = mlx_xpm_file_to_image(d->mlx_ptr, "./texture/pic/B.xpm", SAF);
  d->pa.pa1.C = mlx_xpm_file_to_image(d->mlx_ptr, "./texture/pic/C.xpm", SAF);
  d->pa.pa1.D = mlx_xpm_file_to_image(d->mlx_ptr, "./texture/pic/D.xpm", SAF);
  d->pa.pa1.E = mlx_xpm_file_to_image(d->mlx_ptr, "./texture/pic/E.xpm", SAF);
  d->pa.pa1.F = mlx_xpm_file_to_image(d->mlx_ptr, "./texture/pic/F.xpm", SAF);
  d->pa.pa1.G = mlx_xpm_file_to_image(d->mlx_ptr, "./texture/pic/G.xpm", SAF);
  d->pa.pa1.H = mlx_xpm_file_to_image(d->mlx_ptr, "./texture/pic/H.xpm", SAF);
  (!d->pa.pa1.A) ? quitt(d) : 1;
  (!d->pa.pa1.B) ? quitt(d) : 1;
  (!d->pa.pa1.C) ? quitt(d) : 1;
  (!d->pa.pa1.D) ? quitt(d) : 1;
  (!d->pa.pa1.E) ? quitt(d) : 1;
  (!d->pa.pa1.F) ? quitt(d) : 1;
  (!d->pa.pa1.G) ? quitt(d) : 1;
  (!d->pa.pa1.H) ? quitt(d) : 1;
}

void	xmp_tree(t_data *d)
{
  d->pa.pa2.I = mlx_xpm_file_to_image(d->mlx_ptr, "./texture/pic/I.xpm", SAF);
  d->pa.pa2.J = mlx_xpm_file_to_image(d->mlx_ptr, "./texture/pic/J.xpm", SAF);
  d->pa.pa2.K = mlx_xpm_file_to_image(d->mlx_ptr, "./texture/pic/K.xpm", SAF);
  d->pa.pa2.L = mlx_xpm_file_to_image(d->mlx_ptr, "./texture/pic/L.xpm", SAF);
  d->pa.pa2.M = mlx_xpm_file_to_image(d->mlx_ptr, "./texture/pic/M.xpm", SAF);
  d->pa.pa2.N = mlx_xpm_file_to_image(d->mlx_ptr, "./texture/pic/N.xpm", SAF);
  d->pa.pa2.O = mlx_xpm_file_to_image(d->mlx_ptr, "./texture/pic/O.xpm", SAF);
  d->pa.pa2.P = mlx_xpm_file_to_image(d->mlx_ptr, "./texture/pic/M.xpm", SAF);
  (!d->pa.pa2.I) ? quitt(d) : 1;
  (!d->pa.pa2.J) ? quitt(d) : 1;
  (!d->pa.pa2.K) ? quitt(d) : 1;
  (!d->pa.pa2.L) ? quitt(d) : 1;
  (!d->pa.pa2.M) ? quitt(d) : 1;
  (!d->pa.pa2.N) ? quitt(d) : 1;
  (!d->pa.pa2.O) ? quitt(d) : 1;
  (!d->pa.pa2.P) ? quitt(d) : 1;
  d->pa.pp = mlx_xpm_file_to_image(d->mlx_ptr, "./texture/pic/pp.xpm", SAF);
  (!d->pa.pp) ? quitt(d) : 1;
}

void	xmp_four(t_data *d)
{
  d->pa.pa3.Q = mlx_xpm_file_to_image(d->mlx_ptr, "./texture/pic/Q.xpm", SAF);
  d->pa.pa3.R = mlx_xpm_file_to_image(d->mlx_ptr, "./texture/pic/R.xpm", SAF);
  d->pa.pa3.S = mlx_xpm_file_to_image(d->mlx_ptr, "./texture/pic/S.xpm", SAF);
  d->pa.pa3.T = mlx_xpm_file_to_image(d->mlx_ptr, "./texture/pic/T.xpm", SAF);
  d->pa.pa3.U = mlx_xpm_file_to_image(d->mlx_ptr, "./texture/pic/U.xpm", SAF);
  d->pa.pa3.V = mlx_xpm_file_to_image(d->mlx_ptr, "./texture/pic/V.xpm", SAF);
  d->pa.pa3.W = mlx_xpm_file_to_image(d->mlx_ptr, "./texture/pic/W.xpm", SAF);
  d->pa.pa3.X = mlx_xpm_file_to_image(d->mlx_ptr, "./texture/pic/X.xpm", SAF);
  d->pa.pa3.Y = mlx_xpm_file_to_image(d->mlx_ptr, "./texture/pic/Y.xpm", SAF);
  d->pa.pa3.Z = mlx_xpm_file_to_image(d->mlx_ptr, "./texture/pic/Z.xpm", SAF);
  d->pa.pa3.MI = mlx_xpm_file_to_image(d->mlx_ptr, "./texture/pic/MI.xpm",
				       SAF);
  (!d->pa.pa3.Q) ? quitt(d) : 1;
  (!d->pa.pa3.R) ? quitt(d) : 1;
  (!d->pa.pa3.S) ? quitt(d) : 1;
  (!d->pa.pa3.T) ? quitt(d) : 1;
  (!d->pa.pa3.U) ? quitt(d) : 1;
  (!d->pa.pa3.V) ? quitt(d) : 1;
  (!d->pa.pa3.W) ? quitt(d) : 1;
  (!d->pa.pa3.X) ? quitt(d) : 1;
  (!d->pa.pa3.Y) ? quitt(d) : 1;
  (!d->pa.pa3.Z) ? quitt(d) : 1;
  (!d->pa.pa3.MI) ? quitt(d) : 1;
}

/*
** initialisation de l'image de fond
** pourquoi y'en a deux ? à la fin de la transition, l'image numéro 1
**      à été changer, pour éviter de recalculer l'image, on passe
**      direct sur l'image numéro deux pour pas perdre en vitesse.
** (deux fois plus de chagement au tout début, mais aucun lag durant
**                                      l'affichage ;) ).
*/

void	pic_init(t_data *d)
{
  d->p.back = mlx_xpm_file_to_image(d->mlx_ptr, "./texture/pic/back.xpm", SAF);
  (!d->p.back) ? quitt(d) : 1;
  d->p.bData = mlx_get_data_addr(d->p.back, &d->p.bpp, &d->p.size, &d->p.end);
  d->p.back2 = mlx_xpm_file_to_image(d->mlx_ptr, "./texture/pic/back.xpm",
				     SAF);
  (!d->p.back2) ? quitt(d) : 1;
  d->p.bData2 = mlx_get_data_addr(d->p.back2, &d->p.bpp2,
                                  &d->p.size2, &d->p.end2);
  xmp_one(d);
  xmp_two(d);
  xmp_tree(d);
  xmp_four(d);
}
