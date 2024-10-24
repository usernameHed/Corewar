/*
** cible_move.c for  in /home/belfio_u/rendu/CPE/CPE_2014_corewar/bonus/src
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Fri Apr  3 21:52:30 2015 ugo belfiore
** Last update Sun Apr 12 15:00:29 2015 ugo belfiore
*/

#include "mlx.h"
#include "mini.h"
#include "my.h"

/*
** >gerer la position mouvante des 4 champions par rapport au centre
**	quand je dis champions, ça va jsutre être un point (x,y).
**	les particules iront alors vers la cible assortie à leur couleur.
** >premier if (dans cible_move): affichage du cercle et de la transition.
** >while de chaque champion pour avoir sa position (cible_move_each_champ)
**	>défini la direction de mouvement suivant la variable move
**		(cete valeur peut être modifié par les fleche derectionnelle).
**	>(aff_cible_move): affiche un cercle sur la positon du champion
**			   si la transition est en court (à la bonne couleur).
**	>si le jeu est en court, vérifi si le rayon du cercle imaginaire
**		sur lequel passe les champions soit entre 0 et 800.
**		(car il peut changer avec les flèche directionnelle).
*/

static void	aff_cible_move(t_data *d, int i)
{
  int		z[2];

  (i == 0) ? d->colo = COLOR_RED : 1;
  (i == 1) ? d->colo = COLOR_YELLOW : 1;
  (i == 2) ? d->colo = COLOR_GREEN : 1;
  (i == 3) ? d->colo = COLOR_BLUE : 1;
  if ((d->ch.timer < 600 && d->ch.timer > 1)
      || (d->ch.circle_radius < 130 && d->ch.start == 0))
    {
      if (d->ch.circle_radius < 130 && d->ch.start == 0)
	{
	  d->ch.start = 1;
	  d->ch.circle_radius = 650;
	  mlx_put_image_to_window(d->mlx_ptr, d->win_ptr,
				  d->p.back2, 0, 0);
	}
      d->colo = COLOR_BLACK;
    }
  z[0] = d->ch.x_cible[i + 1];
  z[1] = d->ch.y_cible[i + 1];
  aff_circle(d, z, 5, d->p.bData);
  aff_circle(d, z, 4, d->p.bData);
  aff_circle(d, z, 3, d->p.bData);
  aff_circle(d, z, 2, d->p.bData);
  aff_circle(d, z, 1, d->p.bData);
}

static void	cible_middle(t_data *d)
{
  d->ch.x_cible[1] = d->ch.x_cible[0];
  d->ch.y_cible[1] = d->ch.y_cible[0];
  d->ch.x_cible[2] = d->ch.x_cible[0];
  d->ch.y_cible[2] = d->ch.y_cible[0];
  d->ch.x_cible[3] = d->ch.x_cible[0];
  d->ch.y_cible[3] = d->ch.y_cible[0];
  d->ch.x_cible[4] = d->ch.x_cible[0];
  d->ch.y_cible[4] = d->ch.y_cible[0];
}

static void	cible_move_each_champ(t_data *d, int move,
				      int go, int i, int test)
{
  if (d->win != 0)
    {
      cible_middle(d);
      return;
    }
  if (!test)
    {
      if (move > 0)
        d->ch.butt_count[i] += 200 * move / 150;
      else
        d->ch.butt_count[i] -= 200 * abs(move) / 150;
    }
  if (d->ch.start == 0)
    aff_cible_move(d, i);
  else
    {
      d->ch.circle_radius -= go;
      if (d->ch.circle_radius < 0)
        d->ch.circle_radius = 0;
      if (d->ch.circle_radius > 800)
        d->ch.circle_radius = 800;
    }
}

void	cible_move(t_data *d, int move, int go)
{
  int	i;
  int	test;

  i = -1;
  test = random() % 10;
  if (d->ch.start == 0)
    {
      test = random() % 4;
      if (d->ch.timer > 0)
        d->ch.timer--;
      else
        d->ch.circle_radius--;
    }
  while (++i < d->ch.nbr_champ)
    {
      d->ch.x_cible[i + 1] = d->ch.x_center_circle
        + sin(d->ch.butt_count[i] / 180.0 * PI) * d->ch.circle_radius;
      d->ch.y_cible[i + 1] = d->ch.y_center_circle
        + cos(d->ch.butt_count[i] / 180.0 * PI)
        * d->ch.circle_radius / 1.5;
      d->ch.butt_count[i] -= (d->ch.butt_count[i] > 360) ? 360 : 0;
      d->ch.butt_count[i] += (d->ch.butt_count[i] < 0) ? 360 : 0;
      cible_move_each_champ(d, move, go, i, test);
    }
}
