##
## Makefile for  in /home/renard_e/poubelle_test/test_strace
## 
## Made by Gregoire Renard
## Login   <renard_e@epitech.net>
## 
## Started on  Mon Apr  3 11:33:34 2017 Gregoire Renard
## Last update Sun Apr 16 16:19:37 2017 Rodrigue RENE
##

CC	=	gcc -Iinclude

RM	=	rm -fr

SRCS	=	main.c \
		src/printf_error.c \
		src/fill_info.c \
		src/ident_flag.c \
		src/check_pid.c \
		src/start_strace.c \
		src/remp_exec_arg.c \
		src/init_syscall.c \
		src/map_function.c \
		src/my_str_to_word_tab.c \
		src/print_int.c \
		src/print_char.c \
		src/print_long.c \
		src/print_struct.c \
		src/print_void.c \
		src/print_ret.c \
		src/print_end.c \
		src/print_char2.c \
		src/child_exec.c \
		src/all_prog.c \

OBJS	=	$(SRCS:.c=.o)

NAME	=	strace

CFLAGS	=	-W -Werror -Wall -Wextra

TRASH	=	trash.txt

all	:	$(NAME)

$(NAME)	:	$(OBJS)
		$(CC) -o $(NAME) $(SRCS)

clean	:
		$(RM) $(OBJS)
		$(RM) $(TRASH)

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all

.PHONY	:	all re clean fclean

