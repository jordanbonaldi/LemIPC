/*
** EPITECH PROJECT, 2018
** moves
** File description:
** player moves
*/

# include "project.h"

bool action(container_t *container,
		player_t (*_fake)(container_t *container),
		void (*func)(player_t *player))
{
	player_t old = *container->player;
	player_t fake = _fake(container);

	if (can_move_here(container, fake)) {
		func(container->player);
		map_setter(SETTER_P(0, old));
		map_setter(SETTER(container->player->color));
		return true;
	}
	return false;
}

bool can_move_here(container_t const *container, player_t _fake)
{
	if (_fake.x < 0 || _fake.y < 0 ||
			_fake.x > HEIGHT - 1 || _fake.y > WIDTH - 1)
		return false;
	return !map_getter(GETTER(_fake)).exists;
}

void random_moves(container_t *container)
{
	choose_direction(container);
}

bool find_enemy(container_t *container)
{
	player_t nearest = {
		.exists = false
	};

	if (!receive_good_pos(container))
		nearest = send_nearest_position(container);
	if (nearest.exists) {
		try_move_to(container, nearest);
		return true;
	}
	return false;
}
