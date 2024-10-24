/*
** my_vm.c for corewar in /home/pallua_j/rendu/Progelem/CPE_2014_corewar/corewar/src
** 
** Made by jules palluau
** Login   <pallua_j@epitech.net>
** 
** Started on  Fri Apr  3 16:58:25 2015 jules palluau
** Last update Sun Apr 12 15:26:19 2015 ugo belfiore
*/

#include "mlx.h"
#include "mini.h"
#include "my.h"

/*
** >evenememnt clavier
**      >echap pour quitter
**      >flèches directionnelle pour changer la positions des champions
**              par rapport au centre du jeu.
**	>touche 'S' pour changer de style de jeu
**	>touche 'BACK_UP' & 'BACK_DOWN'
*/

static void	manage_key_normized(t_data *d, int keycode)
{
  if (keycode == KEY_CURS)
    {
      d->ch.hidecurs *= -1;
      (d->ch.hidecurs == -1) ? d->ch.bla = 1 : 1;
    }
  if (keycode == KEY_STYLE && d->win == 0 && d->vm->n == 0)
    {
      d->ch.style *= -1;
      d->ch.timer2 = 125;
    }
  if (keycode == KEY_PAGE_UP)
    {
      d->ch.slow++;
      d->ch.slow += (d->ch.slow == 0) ? 1 : 0;
    }
  if (keycode == KEY_PAGE_DOWN)
    {
      d->ch.slow--;
      d->ch.slow -= (d->ch.slow == 0) ? 1 : 0;
    }
  d->ch.slow = (d->ch.slow > 10000000) ? 10000000 : d->ch.slow;
  d->ch.slow = (d->ch.slow < -10000000) ? -10000000 : d->ch.slow;
}

int		manage_key(int keycode, void *param)
{
  t_data	*d;

  d = (t_data *)param;
  if (keycode == KEY_KILL || keycode == KEY_ESC)
    quitt(d);
  if (keycode == KEY_RIGHT && d->ch.pause == 1)
    cible_move(d, 4, 0);
  if (keycode == KEY_LEFT && d->ch.pause == 1)
    cible_move(d, -5, 0);
  if (keycode == KEY_UP && d->ch.pause == 1)
    cible_move(d, 0, 10);
  if (keycode == KEY_DOWN && d->ch.pause == 1)
    cible_move(d, 0, -10);
  if (keycode == KEY_PAUSE && d->ch.start != 0)
    d->ch.pause *= -1;
  manage_key_normized(d, keycode);
  return (0);
}

/*
** evenement expose
** est appelé dès que la fenêtre à besoin d'être recalculé
** PS: est appelé aussi la première fois que le pregramme s'active.
*/

int		manage_expose(void *param)
{
  t_data	*d;

  d = (t_data *)param;
  mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->p.back2, 0, 0);
  return (0);
}

int		my_vm(char **av, int ac)
{
  t_data	d;

  d.list = NULL;
  if ((d.vm = malloc(sizeof(*d.vm))) == NULL)
    aff_error("Can't perform malloc\n");
  init_arena(d.vm);
  check_option(av, d.vm, ac);
  d.list = place_champs(d.vm, d.list);
  create_name(d.vm);
  d.ch.nbr_champ = d.vm->nb_player;
  vmm_super_init(&d);
  d.mlx_ptr = mlx_init();
  if (d.mlx_ptr == NULL)
    aff_error("[ERROR]: problem with mlx_ptr!\n");
  d.win_ptr = mlx_new_window(d.mlx_ptr, d.x_max + 500, d.y_max, "corewar");
  tab_init(&d);
  pic_init(&d);
  game(d.vm);
  mlx_expose_hook(d.win_ptr, &manage_expose, (void *)(&d));
  mlx_hook(d.win_ptr, 3, 3, &manage_key, (void *)(&d));
  mlx_loop_hook(d.mlx_ptr, &manage_frame, (void *)(&d));
  mlx_loop(d.mlx_ptr);
  return (0);
}
