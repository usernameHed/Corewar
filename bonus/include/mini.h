/*
** mini.h for  in /home/belfio_u/rendu/CPE/CPE_2014_corewar/bonus/include
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Sat Apr  4 13:09:11 2015 ugo belfiore
** Last update Sun Apr 12 17:08:05 2015 ugo belfiore
*/

#ifndef MINI_H_
#define MINI_H_

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <math.h>
#include <time.h>
#include <pthread.h>
#include "fmod.h"
#include "corewar.h"

/*
** define: couleur en hexadécimale.
*/

#define RD		random()
#define COLOR_BLACK	(0x000000)
#define	COLOR_GREY	(0x808080)
#define COLOR_TURQ	(0x99FFFF)
#define COLOR_WHITE	(0xFFFFFF)
#define COLOR_RED	(0xFF0000 + (RD % 1000) * (RD % 2) * (RD % 2))
#define COLOR_YELLOW	(0xFFFF00 + (0xFF6600 * (RD % 2)) * (RD % 2))
#define COLOR_GREEN	(0x33FF00 + (0x0D8762 * (RD % 2)))
#define COLOR_BLUE	(0x0000CC + (0x330033 * (RD % 3)) * (RD % 2))

/*
** define: clavier.
*/

#define KEY_ENTER	65293
#define KEY_ESC		65307
#define KEY_REFRESH	65471
#define KEY_KILL	107
#define KEY_PAGE_DOWN	65365
#define KEY_PAGE_UP	65366
#define KEY_RIGHT	65363
#define KEY_LEFT	65361
#define KEY_UP		65362
#define KEY_DOWN	65364
#define KEY_CURS	99
#define KEY_STYLE	115
#define KEY_PAUSE	32

/*
** define: Memoire globale
*/

#define MEM_SIZE	(6*1024)
#define MEM_SIZE_CUT	(MEM_SIZE / 4)

/*
** define: math
*/

#define MAX(a, b) ((a) > (b)) ? (a) : (b)
#define MIN(a, b) ((a) < (b)) ? (a) : (b)
#define MY_ABS(a) ((a) < 0) ? (-a) : (a)
#define PI 3.14159265
#define SAF &d->p.save1, &d->p.save2
#define MLX mlx_put_image_to_window

/*
** define couleur
*/

#define A10 d->ow[0].m.tab[j].color_particle == 0
#define A11 d->ow[0].m.tab[j].color_particle == 1
#define A12 d->ow[0].m.tab[j].color_particle == 2
#define A13 d->ow[0].m.tab[j].color_particle == 3
#define A14 d->ow[0].m.tab[j].color_particle == 4
#define A20 d->ow[1].m.tab[j].color_particle == 0
#define A21 d->ow[1].m.tab[j].color_particle == 1
#define A22 d->ow[1].m.tab[j].color_particle == 2
#define A23 d->ow[1].m.tab[j].color_particle == 3
#define A24 d->ow[1].m.tab[j].color_particle == 4
#define A30 d->ow[2].m.tab[j].color_particle == 0
#define A31 d->ow[2].m.tab[j].color_particle == 1
#define A32 d->ow[2].m.tab[j].color_particle == 2
#define A33 d->ow[2].m.tab[j].color_particle == 3
#define A34 d->ow[2].m.tab[j].color_particle == 4
#define A40 d->ow[3].m.tab[j].color_particle == 0
#define A41 d->ow[3].m.tab[j].color_particle == 1
#define A42 d->ow[3].m.tab[j].color_particle == 2
#define A43 d->ow[3].m.tab[j].color_particle == 3
#define A44 d->ow[3].m.tab[j].color_particle == 4

/*
** define big calcule en une ligne !!
*/

#define C10 d->ow[0].m.tab[j].YPos
#define C11 - d->ch.y_cible[d->ow[0].m.tab[j].color_particle]
#define C12 d->ow[0].m.tab[j].XPos
#define C13 - d->ch.x_cible[d->ow[0].m.tab[j].color_particle]
#define C14 abs(d->ow[0].m.tab[j].XPos) < 10000
#define C15 abs(d->ow[0].m.tab[j].YPos) < 10000
#define C20 d->ow[1].m.tab[j].YPos
#define C21 - d->ch.y_cible[d->ow[1].m.tab[j].color_particle]
#define C22 d->ow[1].m.tab[j].XPos
#define C23 - d->ch.x_cible[d->ow[1].m.tab[j].color_particle]
#define C24 abs(d->ow[1].m.tab[j].XPos) < 10000
#define C25 abs(d->ow[1].m.tab[j].YPos) < 10000
#define C30 d->ow[2].m.tab[j].YPos
#define C31 - d->ch.y_cible[d->ow[2].m.tab[j].color_particle]
#define C32 d->ow[2].m.tab[j].XPos
#define C33 - d->ch.x_cible[d->ow[2].m.tab[j].color_particle]
#define C34 abs(d->ow[2].m.tab[j].XPos) < 10000
#define C35 abs(d->ow[2].m.tab[j].YPos) < 10000
#define C40 d->ow[3].m.tab[j].YPos
#define C41 - d->ch.y_cible[d->ow[3].m.tab[j].color_particle]
#define C42 d->ow[3].m.tab[j].XPos
#define C43 - d->ch.x_cible[d->ow[3].m.tab[j].color_particle]
#define C44 abs(d->ow[3].m.tab[j].XPos) < 10000
#define C45 abs(d->ow[3].m.tab[j].YPos) < 10000
#define CYC d->vmm.cycle_to_die
#define DUMP d->vm->dump != -1 && d->vm->total_cycle >= d->vm->dump
/*
** structure cercle
*/

typedef struct	s_circle
{
  int		x_mid;
  int		y_mid;
  int		x;
  int		y;
  int		r;
  int		di;
}		t_circle;

typedef struct	s_circle1
{
  int		x_mid;
  int		y_mid;
  int		x;
  int		y;
  int		r;
  int		di;
}		t_circle1;

typedef struct	s_circle2
{
  int		x_mid;
  int		y_mid;
  int		x;
  int		y;
  int		r;
  int		di;
}		t_circle2;

typedef struct	s_circle3
{
  int		x_mid;
  int		y_mid;
  int		x;
  int		y;
  int		r;
  int		di;
}		t_circle3;

typedef struct	s_circle4
{
  int		x_mid;
  int		y_mid;
  int		x;
  int		y;
  int		r;
  int		di;
}		t_circle4;

/*
** stucture son
*/

typedef struct	s_sound
{
  FMOD_SYSTEM	*system;
  FMOD_SOUND	*bonus1;
}		t_sound;

/*
** tructure picture
** ... oui y'en a beaucoup
**
** ... beaucoup beaucoup
*/

typedef struct	s_pic
{
  void		*back;
  void		*back2;
  char		*bData;
  char		*bData2;
  int		bpp;
  int		bpp2;
  int		size;
  int		size2;
  int		end;
  int		end2;
  int		save1;
  int		save2;
}		t_pic;

typedef struct	s_pica1
{
  void		*A;
  void		*B;
  void		*C;
  void		*D;
  void		*E;
  void		*F;
  void		*G;
  void		*H;
}		t_pica1;

typedef struct	s_pica2
{
  void		*I;
  void		*J;
  void		*K;
  void		*L;
  void		*M;
  void		*N;
  void		*O;
  void		*P;
}		t_pica2;

typedef struct	s_pica3
{
  void		*Q;
  void		*R;
  void		*S;
  void		*T;
  void		*U;
  void		*V;
  void		*W;
  void		*X;
  void		*Y;
  void		*Z;
  void		*MI;
}		t_pica3;

typedef struct	s_pican
{
  void		*n0;
  void		*n1;
  void		*n2;
  void		*n3;
  void		*n4;
  void		*n5;
  void		*n6;
  void		*n7;
  void		*n8;
  void		*n9;
}		t_pican;

typedef struct	s_pica
{
  t_pica1	pa1;
  t_pica2	pa2;
  t_pica3	pa3;
  t_pican	pan;
  void		*pp;
}		t_pica;

/*
** le tableau de structure !!! chaque particule à sa propre sutructure
** obj pour elle ! c'est un peu de la POO sans POO...
*/

typedef struct	s_obj
{
  int		color_particle;
  int		timer;
  int		zzz;
  double	XPos;
  double	YPos;
  double	XVel;
  double	YVel;
  int		vel;
  int		angl;
  double	turn;
  int		tail_x[4];
  int		tail_y[4];
  int		colo;
  int		curs;
}		t_obj;

/*
** tableau de 4 structure mod: une pour chaque thread. chaque thread contient
** un quart de la mémoire.
*/

typedef struct	s_mod
{
  t_obj		*tab;
  int		y_file;
  int		nb_par[4];
}		t_mod;

/*
** struture avec un peu tout ce qu'il y a d'utile par rapport aux champion,
** variable qui ne sont pas contenue dans CHAQUE particule mais pour chaque
** champion.
*/

typedef struct	s_chmp
{
  int		nbr_champ;
  int		butt_count[4];
  int		bigg[4];
  int		x_center_circle;
  int		y_center_circle;
  int		circle_radius;
  int		timer;
  double	x_cible[5];
  double	y_cible[5];
  int		start;
  int		style;
  int		timer2;
  int		pc[4];
  int		lived[4];
  int		slow;
  int		testali[4];
  int		hidecurs;
  int		bla;
  int		pause;
}		t_chmp;

/*
** data: structure principale contenant les pointeurs
**	de fenêtreet d'image, contient le tableau **tab,
*/

typedef struct	s_vmm
{
  char		name[4][2];
  int		cycle;
  int		cycle_to_die;
  int		total_cycle;
  int		process;
}		t_vmm;

typedef struct	s_mindbl
{
  t_mod		m;
}		t_mindbl;

typedef struct	s_data
{
  void		*mlx_ptr;
  void		*win_ptr;
  int		x_max;
  int		y_max;
  int		colo;
  char		arene[MEM_SIZE];
  int		win;
  t_sound	sd;
  t_pic		p;
  t_pica	pa;
  t_chmp	ch;
  t_mindbl	ow[4];
  pthread_t	threads[4];
  t_vmm		vmm;
  t_vm		*vm;
  t_list	*list;
}		t_data;

/*
** corewar graphique
*/

/*
** initialisation
*/

void	vmm_super_init(t_data *d);
void	tab_init(t_data *d);
void	pic_init(t_data *d);
void	pic2_init(t_data *d);
void	cible_move(t_data *d, int move, int go);
void	cible_init(t_data *d);
void	rec_init(t_data *d);

/*
** particule des 4 différents thread
*/

void	blackos_one(t_data *d, int j, int test, int cosy);
void	blackos_two(t_data *d, int j, int test, int cosy);
void	blackos_tree(t_data *d, int j, int test, int cosy);
void	blackos_four(t_data *d, int j, int test, int cosy);
void	tmp_a_one(t_data *d, int j, double tmp_a);
void	tmp_a_two(t_data *d, int j, double tmp_a);
void	tmp_a_tree(t_data *d, int j, double tmp_a);
void	tmp_a_four(t_data *d, int j, double tmp_a);
void	aff_one_tail_normized(t_data *d, int j, int test);
void	aff_two_tail_normized(t_data *d, int j, int test);
void	aff_tree_tail_normized(t_data *d, int j, int test);
void	aff_four_tail_normized(t_data *d, int j, int test);
void	nbr_of_champ(t_data *d);
void	particle_one(t_data *d);
void	particle_two(t_data *d);
void	particle_tree(t_data *d);
void	particle_four(t_data *d);
void	aff_particule_one(t_data *d, int j);
void	aff_particule_two(t_data *d, int j);
void	aff_particule_tree(t_data *d, int j);
void	aff_particule_four(t_data *d, int j);
void	vm(t_data *d);
void	check_winner(t_vm vm, t_data *d);

/*
** aff info
*/

void	aff_info(t_data *d);
void	my_put_nbr_weird(t_data *d, int x, int y, int nb);
void	put_charac(t_data *d, int x, int y, char c);
void	aff_rec_mem(t_data *d, int total[4]);
void	aff_rec_red(t_data *d, int z[2], int x2, int y2);
void	aff_rec_yel(t_data *d, int z[2], int x2, int y2);
void	aff_rec_blu(t_data *d, int z[2], int x2, int y2);
void	aff_rec_gre(t_data *d, int z[2], int x2, int y2);
void	aff_rec_bla(t_data *d, int z[2], int x2, int y2);
void	aff_pix_img_rec(t_data *d, int x, int y, char *img);

/*
** fonction divers.
*/

int	transpose_name(t_data *d);
void	aff_win();
void	aff_pix_img(t_data *d, int x, int y, char *img);
void	aff_pix_img_one(t_data *d, int x, int y, int j);
void	aff_pix_img_two(t_data *d, int x, int y, int j);
void	aff_pix_img_tree(t_data *d, int x, int y, int j);
void	aff_pix_img_four(t_data *d, int x, int y, int j);
void	aff_circle(t_data *d, int z[2], int r, char *img);
void	aff_circle_one(t_data *d, int z[2], int r, int j);
void	aff_circle_two(t_data *d, int z[2], int r, int j);
void	aff_circle_tree(t_data *d, int z[2], int r, int j);
void	aff_circle_four(t_data *d, int z[2], int r, int j);
void	sound_init(t_data *d);
void	quitt(t_data *d);

/*
** fonction evenement minilibix
*/

int	manage_frame(void *param);
int	manage_key(int keycode, void *param);
int	manage_expose(void *param);

#endif
