/*
** particle_one_aff.c for  in /home/belfio_u/rendu/CPE/CPE_2014_corewar/bonus/src
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Fri Apr  3 22:31:51 2015 ugo belfiore
** Last update Sat Apr 11 02:48:37 2015 ugo belfiore
*/

#include "mlx.h"
#include "mini.h"
#include "my.h"

/*
** >affichage de la particule.
** >tout d'abord, un calcule de cosinus par rapport à la variable zzz de la
**	particule. ce calcule par rapport à Z, un eniter positif qui croit à
**	chaque cycle permet d'obtenir un nombre allant de 0 à 7, avec la
**	particularité suivante: ce nombre occille de 0 à 7, puis de 7 à 0.
**		la taille globale de la particule va alors dépendre
**		de cette valeur, comme ça on a l'impression que la particule
**		va et vient sur l'axe des Z en rapetissant ou en grossisant,
**		ce qui donne un effet 3D.
** >ensuite, un petit changement de vitesse et de turnatio aléatoire,
**	pour agmenter l'effet random de la particule à chaque cycle différent.
**	(ces valeurs sont accrus si timer = 0 (si elle a subit récement
**		un changement d'état).
** >enregistrement de la position actuelle de la particule dans sa tail_1
**	la position précédente de la particule qui était dans tail_1 se rerouve
**	alors dans tail_2, et la position de tail_2 dans tail_3.
** >les 3 positions (x, y) sont alors enregistré, et on va pouvoir alors
**	afficher la traçante de la particule.
** >pour afficher: 
**	>on trace d'abord à toute les positions connu de la particule
**		(les 3 dernières donc) un cercle noir pour effacer son
**		affichage précédent. 
**	>ensuite on défini la couleur suivant le champion (color_particue_)
**	>Ensuite on va afficher chaque positon connu de la particule
**		avec un cercle, en diminuant le rayon progressivement pour les
**		ancienne positions.
*/

static void	color_particule_one(t_data *d, int j)
{
  t_list	*tmp;
  int		test;

  test = 0;
  tmp = d->list;
  (A10) ? d->ow[0].m.tab[j].colo = COLOR_WHITE : 1;
  (A11) ? d->ow[0].m.tab[j].colo = COLOR_RED : 1;
  (A12) ? d->ow[0].m.tab[j].colo = COLOR_YELLOW : 1;
  (A13) ? d->ow[0].m.tab[j].colo = COLOR_GREEN : 1;
  (A14) ? d->ow[0].m.tab[j].colo = COLOR_BLUE : 1;
  while (tmp && d->ch.hidecurs == 1)
    {
      test++;
      if (test > 100 && d->ow[0].m.tab[j].curs < 3)
	{
	  d->ch.hidecurs *= -1;
	  d->ch.bla = 1;
	}
      if (tmp->pc == (MEM_SIZE_CUT * 0) + (j * 1))
	d->ow[0].m.tab[j].colo = COLOR_TURQ;
      tmp = tmp->next;
    }
}

void	aff_one_tail(t_data *d, int j, int test, int cosy)
{
  test = 3 + (cosy);
  if (d->ow[0].m.tab[j].curs > 3)
    {
      test = d->ow[0].m.tab[j].curs;
      d->ow[0].m.tab[j].curs--;
    }
  if (d->ow[0].m.tab[j].color_particle == 1 && d->ch.lived[0] > 2
      && d->ch.hidecurs == 1)
    test = d->ch.lived[0] + 1;
  if (d->ow[0].m.tab[j].color_particle == 2 && d->ch.lived[1] > 2
      && d->ch.hidecurs == 1)
    test = d->ch.lived[1] + 1;
  if (d->ow[0].m.tab[j].color_particle == 3 && d->ch.lived[2] > 2
      && d->ch.hidecurs == 1)
    test = d->ch.lived[2] + 1;
  if (d->ow[0].m.tab[j].color_particle == 4 && d->ch.lived[3] > 2
      && d->ch.hidecurs == 1)
    test = d->ch.lived[3] + 1;
  while (--test > 0)
    aff_one_tail_normized(d, j, test);
  color_particule_one(d, j);
  blackos_one(d, j, test, cosy);
}

static void	bigger_one(t_data *d, int j)
{
  if (d->ow[0].m.tab[j].color_particle != 0)
    {
      d->ow[0].m.tab[j].vel +=
	d->ch.bigg[d->ow[0].m.tab[j].color_particle - 1] / 2;
      d->ow[0].m.tab[j].turn -=
	+ d->ch.bigg[d->ow[0].m.tab[j].color_particle - 1] / 10;
    }
  else
    d->ow[0].m.tab[j].vel += 1 + random() % 2;
}

static void	modify_tail_one(t_data *d, int j)
{
  d->ow[0].m.tab[j].tail_x[3] = d->ow[0].m.tab[j].tail_x[2];
  d->ow[0].m.tab[j].tail_x[2] = d->ow[0].m.tab[j].tail_x[1];
  d->ow[0].m.tab[j].tail_x[1] = d->ow[0].m.tab[j].tail_x[0];
  d->ow[0].m.tab[j].tail_x[0] = d->ow[0].m.tab[j].XPos;
  d->ow[0].m.tab[j].tail_y[3] = d->ow[0].m.tab[j].tail_y[2];
  d->ow[0].m.tab[j].tail_y[2] = d->ow[0].m.tab[j].tail_y[1];
  d->ow[0].m.tab[j].tail_y[1] = d->ow[0].m.tab[j].tail_y[0];
  d->ow[0].m.tab[j].tail_y[0] = d->ow[0].m.tab[j].YPos;
  d->ow[0].m.tab[j].colo = COLOR_BLACK;
}

void	aff_particule_one(t_data *d, int j)
{
  int	test;
  int	cosy;

  test = 0;
  cosy = abs(4 * cos(0.1 * (double)d->ow[0].m.tab[j].zzz));
  if (d->ow[0].m.tab[j].timer <= 0)
    {
      d->ow[0].m.tab[j].vel = (d->ch.timer2 > 0) ? 11 : 1 + random() % 4;
      d->ow[0].m.tab[j].turn = (d->ch.timer2 > 0) ? 100 : 17 + random() % 6;
      bigger_one(d, j);
    }
  else
    {
      d->ow[0].m.tab[j].vel = 15 + random() % 5;
      d->ow[0].m.tab[j].turn = 100 + random() % 5;
    }
  if (d->ch.style == -1)
    {
      d->ow[0].m.tab[j].vel = (d->ch.timer2 > 0) ? 11 : 1;
      d->ow[0].m.tab[j].turn = 100;
    }
  modify_tail_one(d, j);
  aff_one_tail(d, j, test, cosy);
}
