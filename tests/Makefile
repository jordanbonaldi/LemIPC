##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

CC = gcc

RM = rm -f

NAME = tests

CFLAGS += -W -Wextra -Wall -Werror
CFLAGS += -I../include/ --coverage

SRCS	=	../src/game/game_manager.c 		\
		../src/map/map_manager.c 		\
		../src/map/map.c 			\
		../src/teams/teams_manager.c 		\
		../src/players/player_messaging.c 	\
		../src/players/message_manager.c 	\
		../src/players/players_manager.c 	\
		../src/players/player_move.c 		\
		../src/players/player_move_manager.c 	\
		../src/players/players_battle.c 	\
		../src/players/pos_manager.c 		\
		../src/players/little_path_finder.c 	\
		../src/players/random_moves.c 		\
		../src/players/players.c 		\
		../src/utils/errors.c 			\
		../src/utils/locker.c			\
		basic.c \
		advanced.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -lcriterion --coverage -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	find .. -type f -name '*.gcno' -delete
	find .. -type f -name '*.gcda' -delete
	find .. -type f -name '*.gcov' -delete

re: fclean all

.PHONY: all clean fclean re
