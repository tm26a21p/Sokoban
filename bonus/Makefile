##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## makefile
##

NAME		=	my_sokoban

SRC		=	$(SRC_DIR)main.c			\
			$(SRC_DIR)man.c			\
			$(SRC_DIR)get_total_target.c			\
			$(SRC_DIR)get_player_position.c			\
			$(SRC_DIR)get_pos_char.c			\
			$(SRC_DIR)init_data_set.c			\
			$(SRC_DIR)sokoban.c			\
			$(SRC_DIR)listen_user_input.c			\
			$(SRC_DIR)display_map.c			\
			$(SRC_DIR)move_player.c			\
			$(SRC_DIR)check_end.c			\
			$(SRC_DIR)listen_replay.c			\
			$(SRC_DIR)free_set.c			\
			$(SRC_DIR)len_map.c			\
			$(SRC_DIR)game_end.c			\
			$(SRC_DIR)check_window_size.c			\
			$(SRC_DIR)timer.c			\

TESTS		=	unit_tests

CC		=	gcc

RM		=	rm -f

GCOVR		=	gcovr

INC		=	-I./include

LIB 		=	-L./lib -lmylibc -lncurses

CRIT		=	-lcriterion

COVER		=	--coverage

BRANCH		=	--branches

EXCLUD		=	--exclude

CFLAGS		=	-Wall -Wextra

CPPFLAGS 	=	$(INC)

SRC_DIR		=	src/

ERR_DIR		=	src/error/

TESTS_DIR	=	tests/

TESTS_SRC	=	$(SRC_DIR)get_player_position.c			\
				$(SRC_DIR)get_total_target.c			\
				$(SRC_DIR)get_pos_char.c			\
				$(SRC_DIR)init_data_set.c			\
				$(SRC_DIR)check_end.c			\
				$(SRC_DIR)len_map.c			\
				$(SRC_DIR)free_set.c			\



OBJ		=	$(SRC:.c=.o)

UNIT_TEST	=	$(TESTS_DIR)tests_$(NAME).c		\

all:	$(NAME)

$(NAME):	$(OBJ)
	$(MAKE) -C lib/my
	$(CC) -o $(NAME) $(OBJ) $(LIB)

db:	CFLAGS += -g3
db: $(OBJ)
	$(MAKE) -C lib/my db
	$(CC) -o $(NAME) $(OBJ) $(LIB)


unit_test:	fclean $(NAME)
	$(CC) -o $(TESTS) $(TESTS_SRC) $(UNIT_TEST) $(LIB) $(INC) $(COVER) $(CRIT)

tests_run: 	unit_test
	./$(TESTS)
	$(GCOVR) $(EXCLUD) $(TESTS_DIR)
	$(GCOVR) $(EXCLUD) $(TESTS_DIR) $(BRANCH)

clean:
	$(MAKE) -C lib/my clean
	$(RM) $(OBJ) *gc*

fclean:		clean
	$(MAKE) -C lib/my fclean
	$(RM) $(NAME) $(TESTS)

re:	fclean all

redb:	fclean db

.PHONY:		all tests fclean re

##.SILENT: 	all tests_run clean fclean re
