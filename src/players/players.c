/*
** EPITECH PROJECT, 2018
** player class
** File description:
** player
*/

# include "project.h"

void init_player(container_t *container)
{
	container->player = malloc(sizeof(player_t));
	if (!load_messages(container))
		create_messages(container);
	if (!container->player)
		exit_error("player");
	container->player->x = 0;
	container->player->y = 0;
	container->player->exists = true;
	container->player->color = container->args.team_number;
}

void place_player(container_t *container)
{
	change_player_coordinates(container->player);
	if (!POSEDMAP) {
		map_setter(SETTER(container->player->color));
		return;
	}
	for (; POSEDMAP; )
		change_player_coordinates(container->player);
	map_setter(SETTER(container->player->color));
}

bool load_player(container_t *container)
{
	container->semaphore = semget(container->key, NSEMS, SHM_R | SHM_W);
	return container->semaphore < 0 ? false : true;
}

void get_player(container_t *container, int num, bool sems)
{
	if (sems)
		container->control_op_semaphore =
				semctl(container->shared_memory, 0, num, NSEMS);
	else
		container->control_op_semaphore =
				semctl(container->shared_memory, 0, num);
}

void create_player(container_t *container)
{
	container->semaphore = semget(container->key, NSEMS, IPC_CREAT
							| SHM_R | SHM_W);
	if (container->semaphore < 0)
		exit_error("sem");
}
