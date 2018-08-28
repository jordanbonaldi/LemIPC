/*
** EPITECH PROJECT, 2018
** map
** File description:
** manager
*/

# include "project.h"

void displayer(container_t *container)
{
	for (size_t i = 0; i < WIDTH; i++) {
		for (size_t j = 0; j < HEIGHT; j++)
			if (container->map[i * WIDTH + j] != 0)
				printf("%d", container->map[i * WIDTH + j]);
			else
				printf(".");
		printf("\n");
	}
	printf("\n\n");
}

int map_setter(register xetter_t setter)
{
	if (!setter.player.dir || setter.player.x < 0 ||
			setter.player.y < 0 || setter.player.x >= HEIGHT
			|| setter.player.y >= WIDTH)
		return -1;
	m_lock(setter.container);
	setter.map[setter.player.x * WIDTH + setter.player.y] = setter.value;
	m_unlock(setter.container);
	return 0;
}

player_t map_getter(register xetter_t getter)
{
	player_t player = {
		.exists = false
	};

	m_lock(getter.container);
	if (getter.map[getter.player.x * WIDTH + getter.player.y] != 0) {
		player = getter.player;
		player.exists = true;
		player.color =
			getter.map[getter.player.x * WIDTH + getter.player.y];
	}
	m_unlock(getter.container);
	return player;
}

void fill_map(container_t *container)
{
	init_player(container);
	if (!load_player(container)) {
		create_player(container);
		get_player(container, SETVAL, true);
	} else
		get_player(container, IPC_RMID, false);
	place_player(container);
}

void build_map(container_t *container)
{
	container->key = ftok(container->args.path, 0);
	if (container->key < 0)
		exit_error("key");
	if (!load_map(container)) {
		container->first = true;
		create_map(container);
	} else {
		container->first = false;
		get_map(container);
	}
	fill_map(container);
}
