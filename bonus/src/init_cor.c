/*
** init_cor.c for  in /home/belfio_u/rendu/CPE/CPE_2014_corewar/bonus/src
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Fri Apr  3 21:57:56 2015 ugo belfiore
** Last update Sat Apr 11 17:45:54 2015 ugo belfiore
*/

#include "mlx.h"
#include "mini.h"
#include "my.h"

/*
** >initialisation du big tableau avec les variables des particules
**	la première boucle correspond aux 4 différent thread:
**	chaque thread va avoir dans la structure ow[t] son propre tableau de
**	structure tab[j] avec une taille de MEM_SIZE_CUT, soit la taille
**	de la mémoire globale de l'arène divisé par 4.
** >deuxième boucle, on initialise chaque variable pour chaque particule:
**	- sa couleur	-un timer (changer la vitesse par rapport à sa valeur)
**	- sa position en x, y, z	- son angle
**	- son vecteur vitesse x,y
**	- ses tail_: enregistrement des 4 dernière coordonnée précédente
**			(pour un effet de traiçante de la particule).
*/

static void	tab_init_vec_tail(t_data *d, int t, int j)
{
  d->ow[t].m.tab[j].XVel += cos((d->ow[t].m.tab[j].angl / 180.0 * PI))
    * d->ow[t].m.tab[j].vel;
  d->ow[t].m.tab[j].YVel += -sin((d->ow[t].m.tab[j].angl / 180.0 * PI))
    * d->ow[t].m.tab[j].vel;
  d->ow[t].m.tab[j].turn = 15 + random() % 5;
  d->ow[t].m.tab[j].tail_x[0] = d->ow[t].m.tab[j].XPos;
  d->ow[t].m.tab[j].tail_y[0] = d->ow[t].m.tab[j].YPos;
  d->ow[t].m.tab[j].tail_x[1] = d->ow[t].m.tab[j].XPos;
  d->ow[t].m.tab[j].tail_y[1] = d->ow[t].m.tab[j].YPos;
  d->ow[t].m.tab[j].tail_x[2] = d->ow[t].m.tab[j].XPos;
  d->ow[t].m.tab[j].tail_y[2] = d->ow[t].m.tab[j].YPos;
  d->ow[t].m.tab[j].tail_x[3] = d->ow[t].m.tab[j].XPos;
  d->ow[t].m.tab[j].tail_y[3] = d->ow[t].m.tab[j].YPos;
  d->ow[t].m.tab[j].curs = 0;
}

void	tab_init(t_data *d)
{
  int	j;
  int	t;

  t = -1;
  while (++t < 4)
    {
      j = -1;
      d->ow[t].m.y_file = MEM_SIZE_CUT;
      d->ow[t].m.tab = malloc(d->ow[t].m.y_file * sizeof(*d->ow[t].m.tab));
      (d->ow[t].m.tab == NULL) ? exit(0) : 1;
      while (++j < d->ow[t].m.y_file)
	{
	  d->ow[t].m.tab[j].color_particle = 0;
	  d->ow[t].m.tab[j].colo = 0;
	  d->ow[t].m.tab[j].timer = 0;
	  d->ow[t].m.tab[j].zzz = random() % 30;
	  d->ow[t].m.tab[j].XPos = 753;
	  d->ow[t].m.tab[j].YPos = 515;
	  d->ow[t].m.tab[j].vel = 2 + random() % 5;
	  d->ow[t].m.tab[j].angl = random() % 360;
	  tab_init_vec_tail(d, t, j);
	}
    }
  d->ch.bla = 0;
}

/*
** >initialisation des cible mouvante.
**	les cibles mouvante vont tourner en suivant un cercle imaginaire
**	autour du centre de l'écran, cela va définir le positionnement
**	des champions.
** >initalisation de _cible: position centrale de la mémoire
** >initialisation de butt_count: position futur des champion.
** ---->set la valeur butt_count de chaque champion à une valeur de 0 à 360°
**	ceci va déterminer la position initiale du champion autour d'un cercle
**	imaginaire de centre _cible (centre du jeux).
**		ex de positionnement de 4 ou 3 champions:
**			champ 1: 0°	| ou alors:	 champ 1: 0°
**			champ 2: 90°	|		 champ 2: 120°
**			champ 3: 180°	|	         champ 3: 240°
**			champ 4: 275°	|
**	Le placement est géré selon le nombre de champion: 2, 3 ou 4.
** >initialisation du position et rayon du cercle imaginaire
** > initalisation d'un timer: temps de transition en début de jeu.
*/

void	cible_init(t_data *d)
{
  int	i;

  i = -1;
  d->ch.x_cible[0] = 753;
  d->ch.y_cible[0] = 515;
  d->ch.butt_count[0] = 0;
  d->ch.butt_count[1] = 0;
  d->ch.butt_count[2] = 0;
  d->ch.butt_count[3] = 0;
  d->ch.bigg[0] = 0;
  d->ch.bigg[1] = 0;
  d->ch.bigg[2] = 0;
  d->ch.bigg[3] = 0;
  while (++i < d->ch.nbr_champ)
    d->ch.butt_count[i] = (360 / d->ch.nbr_champ) * (i + 1)
      - (360 / d->ch.nbr_champ);
  d->ch.x_center_circle = 753;
  d->ch.y_center_circle = 500;
  d->ch.circle_radius = 515 + 100;
  d->ch.timer = 3000;
  d->ch.style = 1;
  d->ch.timer2 = 0;
  d->ch.slow = 1;
  d->win = 0;
  d->ch.hidecurs = 1;
}
