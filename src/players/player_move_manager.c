/*
** EPITECH PROJECT, 2018
** move events manager
** File description:
** check better moves
*/

# include "project.h"

void init_moves_possibility(container_t *container)
{
	container->player->moves = malloc(sizeof(moves_t) * 1);
	container->player->dir = malloc(sizeof(direction_t) * 5);
	container->player->moves[0] = (moves_t){
			.random = &random_moves,
			.finder = find_enemy
		};
	container->player->dir[0] = (direction_t) {
		.moves = move_north, .dir = NORTH
	};
	container->player->dir[1] = (direction_t) {
		.moves = move_south, .dir = SOUTH
	};
	container->player->dir[2] = (direction_t) {
		.moves = move_east, .dir = EAST
	};
	container->player->dir[3] = (direction_t) {
		.moves = move_west, .dir = WEST
	};
}

void path_to_enemy(container_t *container)
{
	if (!container->player->exists)
		return;
	if (!(*container->player->moves).finder(container))
		(*container->player->moves).random(container);
}
