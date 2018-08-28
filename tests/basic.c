/*
** EPITECH PROJECT, 2018
** Tests
** File description:
** Tests
*/

#include <criterion/criterion.h>
#include "project.h"

Test(misc, buildmap, .exit_code = 84)
{
	container_t container;

	container.args.path = "";
	build_map(&container);
}

Test(misc, loadmap, .exit_code = 84)
{
	container_t container;

	container.key = 0;
	get_map(&container);
}

Test(misc, posplayer)
{
	container_t *container;

	container = malloc(sizeof(container_t));
	init_player(container);
	container->player->x = -1;
	container->player->y = -1;
	cr_assert(map_setter(SETTER(0)) < 0);
	cr_assert(map_setter(SETTER_P(0, { .exists = false})) < 0);
}

Test(misc, killP)
{
	container_t *container;

	container = malloc(sizeof(container_t));
	init_player(container);
	container->player->x = 1;
	container->player->y = 1;
	container->player->exists = false;
	container->player->color = SPECTATOR;
	path_to_enemy(container);
	cr_assert(container->player->x == 1 && container->player->y == 1);
}
