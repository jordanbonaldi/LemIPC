##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

CC = gcc

RM = rm -f

NAME = lemipc

CFLAGS += -W -Wextra -Wall -Werror
CFLAGS += -Iinclude/ -g3

SRCS =  src/main.c 				\
	src/game/game_manager.c 		\
	src/map/map_manager.c 			\
	src/map/map.c 				\
	src/teams/teams_manager.c 		\
	src/players/player_messaging.c 		\
	src/players/message_manager.c 		\
	src/players/players_manager.c 		\
	src/players/player_move.c 		\
	src/players/player_move_manager.c 	\
	src/players/players_battle.c 		\
	src/players/pos_manager.c 		\
	src/players/little_path_finder.c 	\
	src/players/random_moves.c 		\
	src/players/players.c 			\
	src/utils/errors.c 			\
	src/utils/locker.c 			\

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean tests_clean
	$(RM) $(NAME)

re: fclean all

tests_clean:
	make -C tests/ fclean

tests_run:
	make -C tests/ all
	tests/tests

.PHONY: all clean fclean re
