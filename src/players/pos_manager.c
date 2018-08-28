/*
** EPITECH PROJECT, 2018
** position manager
** File description:
** share positions
*/

# include "project.h"

bool receive_good_pos(container_t *container)
{
	errno = 0;
	register player_t tmp;

	for (;errno != ENOMSG;) {
		if (!receive_message(container)) {
			tmp = deserialize_message(container);
			if (map_getter(GETTER(tmp)).exists) {
				send_message(container, tmp);
				return true;
			}
		}
		return false;
	}
	return false;
}

static player_t find_closest_enemy(container_t *container)
{
	for (size_t i = 0; i < WIDTH; i++)
		for (size_t j = 0; j < HEIGHT; j++)
			if (container->map[i * WIDTH + j] != 0 &&
				container->map[i * WIDTH + j] !=
					(short)container->player->color)
				return map_getter(GETTER(FAKE_PLAYER(i, j)));
	return (player_t){ .exists = false };
}

player_t send_nearest_position(container_t *container)
{
	register player_t p = find_closest_enemy(container);

	if (p.exists)
		send_message(container, p);
	return p;
}
