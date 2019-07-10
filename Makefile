##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Compile files
##


NAME =	42sh

SRC =	lib/my/my_realloc.c \
		lib/my/sort_array.c \
		lib/my/rmv_space.c \
		lib/my/my_strcomp.c \
		lib/my/my_strcat.c \
		lib/my/count_nb_spaces.c \
		lib/my/multi_realloc.c \
		lib/my/search_env.c \
		lib/my/my_printf/my_printf.c \
		lib/my/my_printf/my_putstr.c \
		lib/my/my_printf/my_put_nbr.c \
		files/functions_sh/in_env.c \
		files/functions_sh/path.c \
		files/main.c \
		files/exec.c \
		files/exec2.c \
		files/exec_cmd.c \
		files/exec_file.c \
		files/env.c \
		files/exit.c \
		files/setenv.c \
		files/unsetenv.c \
		files/mdf_dir.c \
		files/manage_separator_buffer.c \
		files/echo.c	\
		files/alias.c	\
		files/chg_pwd.c \

INCLUDE_PATH =	include

CFLAGS = -I $(INCLUDE_PATH) -g

CC = gcc

OBJ = 	$(SRC:.c=.o)

START_OF_LINE =	"\e[44m \e[0m "

$(NAME): $(OBJ)
	@echo "\n"$(START_OF_LINE)" \e[92mFINISH\e[0m"
	@$(CC) $(OBJ) -o $(NAME) -I $(INCLUDE_PATH) $(CFLAGS)
	@echo "   - Compilation : Achieve"
	@echo "\n"$(START_OF_LINE)"\e[34mBINARY NAME:\e[0m\n   - $(NAME)\n"

all: $(NAME)

clean:
	@echo $(START_OF_LINE)" \e[31mCLEAN\e[0m"
	@echo "   - Folder is clean"
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

msg_compile:
	@echo "\n"$(START_OF_LINE)" \e[93mCOMPILING\e[0m"

re:	fclean msg_compile all

.PHONY: all clean fclean re msg_compile
