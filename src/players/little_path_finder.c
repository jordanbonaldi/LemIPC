/*
** EPITECH PROJECT, 2018
** finder
** File description:
** find fastest path through an enemy
*/

# include "project.h"

static bool movement_on_north_and_south(container_t *container, player_t _enemy)
{
	if (container->player->x > _enemy.x && move_north(container))
		return true;
	else if (container->player->x < _enemy.x &&
			move_south(container))
		return true;
	return false;
}

static void move_east_or_west(container_t *container, player_t _enemy)
{
	if (container->player->y > _enemy.y && move_east(container))
		return;
	else if (container->player->y < _enemy.y &&
			move_west(container))
		return;
	else if (!movement_on_north_and_south(container, _enemy))
		(*container->player->moves).random(container);
}

static void move_north_or_south(container_t *container, player_t _enemy)
{
	if (!movement_on_north_and_south(container, _enemy))
		move_east_or_west(container, _enemy);
}

void try_move_to(container_t *container, player_t _enemy)
{
	dir_t dir = rand() % 2;
	if (dir == NORTH)
		move_north_or_south(container, _enemy);
	else
		move_east_or_west(container, _enemy);
}
