##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## makefile
##

NAME		=	libmylibc.a

TESTS		=	unit_tests

CC		=	gcc

RM		=	rm -f

GCOVR		=	gcovr

INC		=	-I../../include

CRIT		=	-lcriterion

COVER		=	--coverage

BRANCH		=	--branches

EXCLUD		=	--exclude

CFLAGS		=	-Wall -Wextra

CPPFLAGS 	=	$(INC)

SRC_DIR		=	src/

TESTS_DIR	=	tests/

OBJ		=	$(SRC:.c=.o)

GCNO		=	$(UNIT_TEST:.c=.gcno)

GCDA		=	$(UNIT_TEST:.c=.gcda)

UNIT_TEST	=	$(TESTS_DIR)tests_my_printf.c		\
				$(SRC_DIR)my_printf.c

SRC		=	$(SRC_DIR)my_ctostr.c			\
			$(SRC_DIR)my_revstr.c			\
			$(SRC_DIR)my_alphanum.c			\
			$(SRC_DIR)my_wordlen.c			\
			$(SRC_DIR)my_str_count_word.c			\
			$(SRC_DIR)my_strlen.c			\
			$(SRC_DIR)my_putchar.c			\
			$(SRC_DIR)my_putstr.c			\
			$(SRC_DIR)my_putnbr.c			\
			$(SRC_DIR)my_itoa.c			\
			$(SRC_DIR)my_putunbr.c			\
			$(SRC_DIR)my_octal.c			\
			$(SRC_DIR)my_realloc.c			\
			$(SRC_DIR)my_put_error.c			\
			$(SRC_DIR)my_hexa.c			\
			$(SRC_DIR)my_nbrlen.c			\
			$(SRC_DIR)my_getnbr.c			\
			$(SRC_DIR)my_strcmp.c			\
			$(SRC_DIR)my_binary.c			\
			$(SRC_DIR)my_strlowcase.c		\
			$(SRC_DIR)my_strcpy.c			\
			$(SRC_DIR)my_strcat.c			\
			$(SRC_DIR)wrap_percent.c		\
			$(SRC_DIR)wrap_print_adress.c		\
			$(SRC_DIR)my_printf.c			\
			$(SRC_DIR)show_word_array.c		\
			$(SRC_DIR)word_array.c	\
			$(SRC_DIR)word_array_delim.c	\
			$(SRC_DIR)my_strtol.c			\
			$(SRC_DIR)my_strncat.c			\
			$(SRC_DIR)my_strncmp.c			\
			$(SRC_DIR)my_strncpy.c			\
			$(SRC_DIR)my_str_isupper.c		\
			$(SRC_DIR)my_str_islower.c		\
			$(SRC_DIR)my_str_isnum.c		\
			$(SRC_DIR)my_strdup.c			\
			$(SRC_DIR)open_file.c			\
			$(SRC_DIR)init_list.c			\
			$(SRC_DIR)push_back.c			\
			$(SRC_DIR)push_front.c			\
			$(SRC_DIR)print_list.c			\
			$(SRC_DIR)len_list.c			\
			$(SRC_DIR)free_list.c			\
			$(SRC_DIR)load_file_in_mem.c			\
			$(SRC_DIR)free_word_array.c			\
			$(SRC_DIR)my_str_isalpha.c

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	mv $(NAME) ..

db:	CFLAGS += -g3
db:	$(NAME)

unit_test:	fclean $(NAME)
	$(CC) -o $(TESTS) $(UNIT_TEST) $(INC) $(COVER) $(CRIT)

tests_run: unit_test
	./$(TESTS)
	$(GCOVR) $(EXCLUD) $(TESTS_DIR)
	$(GCOVR) $(EXCLUD) $(TESTS_DIR) $(BRANCH)

clean:
	$(RM) $(OBJ) *gc*

fclean:	clean
	$(RM) ../$(NAME) $(TESTS)

re:	fclean all

.PHONY: all tests fclean re db
