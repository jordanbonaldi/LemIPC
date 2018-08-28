/*
** EPITECH PROJECT, 2018
** map class
** File description:
** map
*/

# include "project.h"

void init_map(container_t *container)
{
	memset(container->map, 0, WIDTH * HEIGHT);
}

bool load_map(container_t *container)
{
	container->shared_memory = shmget(container->key, TOTAL, SHM_R | SHM_W);
	return container->shared_memory < 0 ? false : true;
}

void get_map(container_t *container)
{
	container->pointers = (shared_pointers_t *)
		shmat(container->shared_memory, 0, SHM_R | SHM_W);
	if (container->pointers == (void *) - 1)
		exit_error("shmat");
	container->map = (short *)(&(container->pointers->map));
}

void create_map(container_t *container)
{
	container->shared_memory = shmget(container->key, TOTAL, IPC_CREAT
							| SHM_R | SHM_W);
	if (container->shared_memory < 0)
		exit_error("shm");
	get_map(container);
	init_map(container);
}
