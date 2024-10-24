/*
** particle.c for  in /home/belfio_u/rendu/CPE/CPE_2014_corewar/bonus/src
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Thu Apr  2 18:21:07 2015 ugo belfiore
** Last update Sat Apr 11 17:50:11 2015 ugo belfiore
*/

#include "mlx.h"
#include "mini.h"
#include "my.h"

/*
** >fonction modif et modif_color et modif_pos_particle:
** >modification des particules par rapport à la partie de mémoire
**	correspondant au thread: ci la case mémoire est différente de
**	sa précédente couleur associé, alors cette case mémoire à changé
**	d'appartenance depuis le dernier cycle. Par exemple on a une case
**	rouge: la casee mémoire est 'R' et la variable couleur est rouge.
**	ensuite lors du prochain cycle la vm va changer la mémoire, on
**	va donc devoir revérifier chaque case mémoire si elle a changé ou
**	pas, dans notre exemple, la case contient alors 'V': sa couleur associé
**	étant le rouge (couleur du précédent cycle), la couleur va changer
**	en vert, couleur du nouveau cycle.
**	Comme la particule à changé d'état, un timer se met en place pour
**	accélérer sa vitesse pendant un temps limité.
** >si la particule est de la couleur d'un champion et que start = 1,
**	autrement dis si c'est le premier cycle du jeu, alors on place
**	le champion directement sur sa cible initiale.
** >explication de la mémoire: la mémoire est le char[MEM_SIZE] contenant
**	TOUTE la mémoire. chaque thread ne s'occupe que d'un quart de cette
**	mémoire. Donc le thread 1 va s'occuper du début du char*, de 0
**	à MEM_SIZE / 4: MEM_SIZE_CUT.
**	le thread 2 va soccuper du MEM_SIZE_CUT à (MEM_SIZE_CUT * 2) etc...
** >Chaque thread contient MEM_SIZE_CUT particule.
*/

static void	one_modif_color_bis(t_data *d, int i, int j)
{
  if (d->arene[i] == '3' && d->ow[0].m.tab[j].color_particle != 3)
    {
      (d->ch.start == 2) ? d->ow[0].m.tab[j].XPos = d->ch.x_cible[3] : 1;
      (d->ch.start == 2) ? d->ow[0].m.tab[j].YPos = d->ch.y_cible[3] : 1;
      (d->ch.start != 2) ? d->ow[0].m.tab[j].color_particle = 3 : 1;
      (d->ch.start != 2) ? d->ow[0].m.tab[j].timer = 20 : 1;
    }
  if (d->arene[i] == '4' && d->ow[0].m.tab[j].color_particle != 4)
    {
      (d->ch.start == 2) ? d->ow[0].m.tab[j].XPos = d->ch.x_cible[4] : 1;
      (d->ch.start == 2) ? d->ow[0].m.tab[j].YPos = d->ch.y_cible[4] : 1;
      (d->ch.start != 2) ? d->ow[0].m.tab[j].color_particle = 4 : 1;
      (d->ch.start != 2) ? d->ow[0].m.tab[j].timer = 20 : 1;
    }
}

static void	one_modif_color(t_data *d, int i, int j)
{
  if (d->arene[i] == '1' && d->ow[0].m.tab[j].color_particle != 1)
    {
      (d->ch.start == 2) ? d->ow[0].m.tab[j].XPos = d->ch.x_cible[1] : 1;
      (d->ch.start == 2) ? d->ow[0].m.tab[j].YPos = d->ch.y_cible[1] : 1;
      (d->ch.start != 2) ? d->ow[0].m.tab[j].color_particle = 1 : 1;
      (d->ch.start != 2) ? d->ow[0].m.tab[j].timer = 20 : 1;
    }
  if (d->arene[i] == '2' && d->ow[0].m.tab[j].color_particle != 2)
    {
      (d->ch.start == 2) ? d->ow[0].m.tab[j].XPos = d->ch.x_cible[2] : 1;
      (d->ch.start == 2) ? d->ow[0].m.tab[j].YPos = d->ch.y_cible[2] : 1;
      (d->ch.start != 2) ? d->ow[0].m.tab[j].color_particle = 2 : 1;
      (d->ch.start != 2) ? d->ow[0].m.tab[j].timer = 20 : 1;
    }
  one_modif_color_bis(d, i, j);
}

static void	one_modif(t_data *d)
{
  int	i;
  int	j;
  int	end;

  i = MEM_SIZE_CUT * 0;
  end = i + MEM_SIZE_CUT;
  j = 0;
  while (i < end)
    {
      if (d->arene[i] == '0' && d->ow[0].m.tab[j].color_particle != 0)
	{
	  d->ow[0].m.tab[j].color_particle = 0;
	  d->ow[0].m.tab[j].timer = 20;
	}
      one_modif_color(d, i, j);
      if (d->ch.style == -1)
	d->ow[0].m.tab[j].timer = 0;
      i++;
      j++;
    }
}

/*
** >première portion de la mémoire:
** >alors c'est ici qu'on va calculer le déplacement de chaque particule
**  selon son vercteur et l'afficher:
**	>après modification de la mémoire modif(d);
**	>une chance sur 3 de modifier la particule (si on ne change rien,
**	      la particule va avancer en ligne droite sans changer ni
**	      de forme, ni de vitesse ni d'angle.
**	>si on modifie:
**		>décrémente le timer si y'en a un
**		>décrémente la variable qui permet de changer l'axe Z.
**		>GROS calcule qui permet de faire tourner la particule
**			vers la droite ou vers la gauche de manière plus ou
**			moin élevé selon une variable turnRatio.
**			la paticule va donc tourner vers sa cible.
**		>changement du vecteur selon les calcules précédent
**	>enfin, fait avancer la particule en ajoutant à sa position
**		actuelle la vecteur fraichement calculé.
**	>affiche la particule
*/

static void	one_big_calcule(t_data *d, int j)
{
  double	tmp_a;
  int		tmpj;
  int		tmpx;
  int		xx;
  int		yy;

  tmpj = j;
  tmpx = 0;
  tmp_a = 0;
  if (d->ch.style == 1)
    tmp_a = (atan2(((C10 C11) * -1), (C12 C13) * 1)) * (180.0 / PI) + 180;
  else
    {
      while (tmpj >= 128)
        {
          tmpj -= 128;
          tmpx += 19;
        }
      xx = 57 + (tmpj * 11);
      yy = 50 + tmpx;
      tmp_a = (atan2(((d->ow[0].m.tab[j].YPos - yy) * -1),
		     (d->ow[0].m.tab[j].XPos - xx) * 1)) * (180.0 / PI) + 180;
    }
  tmp_a_one(d, j, tmp_a);
}

void		particle_one(t_data *d)
{
  int		j;

  one_modif(d);
  j = -1;
  while (++j < d->ow[0].m.y_file)
    {
      d->ow[0].m.nb_par[0] += (d->ow[0].m.tab[j].color_particle == 1) ? 1 : 0;
      d->ow[0].m.nb_par[1] += (d->ow[0].m.tab[j].color_particle == 2) ? 1 : 0;
      d->ow[0].m.nb_par[2] += (d->ow[0].m.tab[j].color_particle == 3) ? 1 : 0;
      d->ow[0].m.nb_par[3] += (d->ow[0].m.tab[j].color_particle == 4) ? 1 : 0;
      if ((d->ch.style == 1 && !(random() % 3)) || (d->ch.style == -1))
  	{
  	  if (d->ow[0].m.tab[j].timer > 0)
  	    d->ow[0].m.tab[j].timer--;
  	  if (!(random() % 3))
  	    d->ow[0].m.tab[j].zzz--;
  	  if (d->ow[0].m.tab[j].zzz < 0)
  	    d->ow[0].m.tab[j].zzz = 30;
	  one_big_calcule(d, j);
  	}
      d->ow[0].m.tab[j].XPos += (C14) ? d->ow[0].m.tab[j].XVel : 0;
      d->ow[0].m.tab[j].YPos += (C15) ? d->ow[0].m.tab[j].YVel : 0;
      aff_particule_one(d, j);
    }
}
