##
## Makefile for corewar in /home/pallua_j/rendu/Progelem/CPE_2014_corewar/corewar
## 
## Made by jules palluau
## Login   <pallua_j@epitech.net>
## 
## Started on  Tue Mar 17 15:37:17 2015 jules palluau
## Last update Sun Apr 12 15:46:48 2015 cristopher toozs-hobson
##

CC	=	gcc

RM	=	rm -f

NAME	=	corewar

SRCS	=	src/main.c			\
		src/header.c			\
		src/check.c			\
		src/sequel_check.c		\
		src/my_vm.c			\
		src/init.c			\
		src/place_champs.c		\
		src/right_place.c		\
		src/game_checks.c		\
		src/ins_checks.c		\
		src/play.c			\
		src/dump.c			\
		src/my_strcmp.c			\
		src/my_strdup.c			\
		src/aff_error.c			\
		src/my_aff_list.c		\
		src/my_put_in_list.c		\
		src/my_strncmp.c		\
		src/my_getnbr.c			\
		src/delete_node.c		\
		src/instructions/converters.c	\
		src/instructions/my_add.c	\
		src/instructions/my_aff.c	\
		src/instructions/my_and.c	\
		src/instructions/my_fork.c	\
		src/instructions/my_ld.c	\
		src/instructions/my_ldi.c	\
		src/instructions/my_lldi.c	\
		src/instructions/my_live.c	\
		src/instructions/my_or.c	\
		src/instructions/my_st.c	\
		src/instructions/my_sti.c	\
		src/instructions/my_sub.c	\
		src/instructions/my_xor.c	\
		src/instructions/my_zjmp.c	\
		src/printf/my_printf.c		\
		src/printf/my_func.c		\
		src/printf/my_func_ex.c		\
		src/printf/my_op_str.c		\
		src/printf/my_vafunc.c		\
		src/printf/my_va_func_ex.c	\

OBJ	=	$(SRCS:.c=.o)

CFLAGS	+=	-W -Wall -Wextra
CFLAGS	+=	-I ./include

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
