/*
** EPITECH PROJECT, 2018
** manager
** File description:
** game
*/

# include "project.h"

void init_game(container_t *container)
{
	bool first;
	short round = 0;

	signal(SIGINT, LAMBDA(void _(int sig) {
		(void) sig;
		clear_players_memory(container);
		exit(84);
	}));
	build_map(container);
	container->players_online = PLAYERS;
	init_moves_possibility(container);
	first = container->first;
	while (!is_one_team(container) || round < 10) {
		if (handle_fight(container))
			kill_player(container);
		path_to_enemy(container);
		if (first)
			displayer(container);
		usleep(WAITING_GAME);
		round++;
	}
	if (first)
		printf("Winner team is : %d\n", get_winner_team(container));
	clear_players_memory(container);
}
