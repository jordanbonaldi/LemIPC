/*
** EPITECH PROJECT, 2018
** Tests
** File description:
** Tests
*/

#include <criterion/criterion.h>
#include "project.h"

Test(misc, playerinit)
{
	container_t container;

	container.args.path = "";
	init_player(&container);
	cr_assert(container.player->exists);
}

Test(misc, find_enemy)
{
	container_t container;

	container.args.path = "";
	container.map = malloc(TOTAL);
	memset(container.map, 0, TOTAL);
	cr_assert(send_nearest_position(&container).exists == false);
}
