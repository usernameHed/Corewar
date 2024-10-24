/*
** sound.c for  in /home/belfio_u/rendu/CPE/CPE_2014_corewar/bonus/src
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Fri Apr  3 22:15:11 2015 ugo belfiore
** Last update Sat Apr 11 21:05:53 2015 ugo belfiore
*/

#include "mlx.h"
#include "mini.h"
#include "my.h"

/*
** focntion qui initialise les sons.
*/

void	sound_init(t_data *d)
{
  FMOD_System_Create(&d->sd.system);
  FMOD_System_Init(d->sd.system, 1, FMOD_INIT_NORMAL, NULL);
  FMOD_System_CreateSound(d->sd.system, "./texture/sound/bonus1.wav",
  				 FMOD_CREATESAMPLE, 0, &d->sd.bonus1);
  FMOD_Sound_SetLoopCount(d->sd.bonus1, -1);
  FMOD_System_PlaySound(d->sd.system, FMOD_CHANNEL_FREE,
                        d->sd.bonus1, 0, NULL);
}
