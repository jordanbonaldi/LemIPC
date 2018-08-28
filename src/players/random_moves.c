/*
** EPITECH PROJECT, 2018
** random
** File description:
** random moves SNEW
*/

# include "project.h"

bool move_north(container_t *container)
{
	return action(container, LAMBDA(player_t _(container_t *container) {
			return FAKE_PLAYER(container->player->x - 1,
					container->player->y);
		}),
		LAMBDA(void _(player_t *player) {
			player->x--;
		}));
}

bool move_south(container_t *container)
{
	return action(container, LAMBDA(player_t _(container_t *container) {
			return FAKE_PLAYER(container->player->x + 1,
					container->player->y);
		}),
		LAMBDA(void _(player_t *player) {
			player->x++;
		}));
}

bool move_east(container_t *container)
{
	return action(container, LAMBDA(player_t _(container_t *container) {
			return FAKE_PLAYER(container->player->x,
					container->player->y - 1);
		}),
		LAMBDA(void _(player_t *player) {
			player->y--;
		}));
}

bool move_west(container_t *container)
{
	return action(container, LAMBDA(player_t _(container_t *container) {
			return FAKE_PLAYER(container->player->x,
					container->player->y + 1);
		}),
		LAMBDA(void _(player_t *player) {
			player->y++;
		}));
}

void choose_direction(container_t *container)
{
	static dir_t direction;
	srand(time(NULL));
	container->player->direction = rand() % 4;
	if (direction)
		while (direction == container->player->direction)
			container->player->direction = rand() % 4;
	direction = container->player->direction;
	for (size_t i = 0; i < 4; i++)
		if (container->player->direction ==
			container->player->dir[i].dir)
			if (!container->player->dir[i].moves(container)){
				if (container->player->direction == NORTH)
					move_south(container);
				else
					choose_direction(container);
			}
}
