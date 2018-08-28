/*
** EPITECH PROJECT, 2018
** battle class
** File description:
** check all battle events
*/

# include "project.h"

void check_here(container_t *container,
		player_t (*_fake)(container_t *container))
{
	player_t player = map_getter(GETTER((_fake(container))));

	if (!player.exists)
		return;
	if (player.color != container->player->color)
		container->battle.count++;
}

static void near_player(register container_t *container)
{
	if (container->player->y + 1 < WIDTH)
		check_here(container,
			LAMBDA(player_t _(container_t *container) {
				return CHECK_EAST;
			}));
	if (container->player->y - 1 >= 0)
		check_here(container,
			LAMBDA(player_t _(container_t *container) {
				return CHECK_WEST;
			}));
	if (container->player->x + 1 < HEIGHT)
		check_here(container,
			LAMBDA(player_t _(container_t *container) {
				return CHECK_NORTH;
			}));
	if (container->player->x - 1 >= 0)
		check_here(container,
			LAMBDA(player_t _(container_t *container) {
				return CHECK_SOUTH;
			}));
}

bool handle_fight(container_t *container)
{
	container->battle.count = 0;
	near_player(container);
	return container->battle.count > 1;
}
