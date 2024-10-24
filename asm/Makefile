##
## Makefile for  in /home/msa_m/Epitech/C_Prog_Elem/CPE_2014_corewar/ASM/parsing
## 
## Made by msa_m
## Login   <msa_m@epitech.net>
## 
## Started on  Mon Mar 23 10:00:55 2015 msa_m
## Last update Sun Apr 12 22:11:22 2015 cristopher toozs-hobson
##

NAME	=	asm

SRC	=	src/aff_functions.c		\
		src/check_param.c		\
		src/cmt.c			\
		src/creat_file.c		\
		src/error.c			\
		src/get_next_line.c		\
		src/header.c			\
		src/line.c			\
		src/lists.c			\
		src/main.c			\
		src/my_atoi_base.c		\
		src/my_realloc.c		\
		src/my_str_to_wordtab.c		\
		src/nbr_functions.c		\
		src/new_str.c			\
		src/op.c			\
		src/parse.c 			\
		src/str_functions.c		\
		src/tools_label.c		\
		src/tools_write.c		\
		src/word.c			\
		src/write.c			\
		src/write_in_file.c		\

OBJ	=	$(SRC:.c=.o)

CC	=	gcc

CFLAGS	+=	-W -Wall -Wextra
CFLAGS	+=	-I./include

all:		$(NAME)

$(NAME): 	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all
