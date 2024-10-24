/*
** reinit_champ.c for  in /home/belfio_u/rendu/CPE/CPE_2014_corewar/bonus3/src
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Sat Apr 11 01:56:44 2015 ugo belfiore
** Last update Sat Apr 11 01:58:21 2015 ugo belfiore
*/

#include "mlx.h"
#include "mini.h"
#include "my.h"

/*
** initialise à chaque boucle du graphique le nombre de particule de chaque
** champion à 0 et décrémente le nombre de live (de 10 à 0, pour l'effet
** de boule qui diminue sur le graphique).
*/

void	nbr_of_champ(t_data *d)
{
  int	t;

  t = -1;
  while (++t < 4)
    {
      d->ow[t].m.nb_par[0] = 0;
      d->ow[t].m.nb_par[1] = 0;
      d->ow[t].m.nb_par[2] = 0;
      d->ow[t].m.nb_par[3] = 0;
    }
  d->ch.lived[0] -= (d->ch.lived[0] > 0) ? 1 : 0;
  d->ch.lived[1] -= (d->ch.lived[1] > 0) ? 1 : 0;
  d->ch.lived[2] -= (d->ch.lived[2] > 0) ? 1 : 0;
  d->ch.lived[3] -= (d->ch.lived[3] > 0) ? 1 : 0;
}
