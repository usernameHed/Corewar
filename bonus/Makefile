##
## Makefile for  in /home/belfio_u/rendu/CPE/CPE_2014_corewar/bonus
## 
## Made by ugo belfiore
## Login   <belfio_u@epitech.net>
## 
## Started on  Sat Apr 11 21:38:20 2015 ugo belfiore
## Last update Sun Apr 12 14:02:26 2015 ugo belfiore
##

SRC     =       ./src/main.c				\
		./src/aff_pix_img.c			\
		./src/sound.c				\
		./src/quitt.c				\
		./src/super_boucle.c			\
		./src/pic_init.c			\
		./src/rec_init.c			\
		./src/aff_circle.c			\
		./src/aff_circle_tred1.c		\
		./src/aff_circle_tred2.c		\
		./src/init_cor.c			\
		./src/cible_move.c			\
		./src/particle_one.c			\
		./src/particle_one_aff.c		\
		./src/particle_two.c			\
		./src/particle_two_aff.c		\
		./src/particle_tree.c			\
		./src/particle_tree_aff.c		\
		./src/particle_four.c			\
		./src/particle_four_aff.c		\
		./src/particle_one_normized.c		\
		./src/particle_two_normized.c		\
		./src/particle_tree_normized.c		\
		./src/particle_four_normized.c		\
		./src/aff_info.c			\
		./src/aff_info_weird.c			\
		./src/aff_pix_rec.c			\
		./src/init_vmm.c			\
		./src/reinit_champ.c			\
		./src/check_winner.c			\
		./src/header.c			 	\
                ./src/check.c                     	\
		./src/sequel_check.c			\
                ./src/my_vm.c                     	\
                ./src/init.c                      	\
                ./src/place_champs.c              	\
                ./src/right_place.c               	\
                ./src/game_checks.c			\
                ./src/ins_checks.c			\
                ./src/play.c                      	\
                ./src/int_graph.c                 	\
		./src/dump.c				\
                ./src/my_strcmp.c                	\
                ./src/my_strdup.c                	\
                ./src/aff_error.c                	\
                ./src/my_aff_list.c              	\
                ./src/my_put_in_list.c           	\
                ./src/my_strncmp.c               	\
                ./src/my_getnbr.c                	\
                ./src/list_len.c                 	\
		./src/delete_node.c		  	\
                ./src/instructions/converters.c   	\
                ./src/instructions/my_add.c       	\
                ./src/instructions/my_aff.c       	\
                ./src/instructions/my_and.c       	\
                ./src/instructions/my_fork.c      	\
                ./src/instructions/my_ld.c        	\
                ./src/instructions/my_ldi.c       	\
                ./src/instructions/my_lldi.c      	\
                ./src/instructions/my_live.c      	\
                ./src/instructions/my_or.c        	\
                ./src/instructions/my_st.c        	\
                ./src/instructions/my_sti.c       	\
                ./src/instructions/my_sub.c       	\
                ./src/instructions/my_xor.c       	\
                ./src/instructions/my_zjmp.c      	\
		./src/printf/my_printf.c		\
		./src/printf/my_func.c			\
		./src/printf/my_func2.c			\
		./src/printf/my_op_str.c		\
		./src/printf/my_vafunc.c		\
		./src/printf/my_va_func2.c		\

OBJ     =       $(SRC:.c=.o)

NAME    =       coreware

CC      =       gcc

CFLAGS  +=      -W -Wall -Wextra
CFLAGS	+=	-I ./include

LIB     =       ./lib/my/libmy.a

LIBMINI =       ./lib/minilibx/libmlx.a

LDFLAGS	=	-L/usr/lib64/X11 -lXext -lX11 -lm -Llib/my/ -lmy -Llib/minilibx/ -lmlx ./lib/libson.so -lpthread

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)

clean:
	@rm -f $(OBJ)

fclean:		clean
	@rm -f $(NAME)

re: fclean all
