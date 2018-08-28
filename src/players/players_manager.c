/*
** EPITECH PROJECT, 2018
** players
** File description:
** manager
*/

# include "project.h"

int count_player(container_t *container)
{
	short c = 0;

	for (size_t i = 0; i < WIDTH; i++)
		for (size_t j = 0; j < HEIGHT; j++)
			if (container->map[i * WIDTH + j] != 0)
				c++;
	return c;
}

void change_player_coordinates(player_t *player)
{
	srand(time(NULL));
	player->x = rand() % HEIGHT;
	player->y = rand() % WIDTH;
}

void kill_player(container_t *container)
{
	container->player->exists = false;
	container->player->color = SPECTATOR;
	map_setter(SETTER(0));
}

void clear_players_memory(container_t *container)
{
	semctl(container->semaphore, 1, IPC_RMID);
	shmctl(container->shared_memory, IPC_RMID, NULL);
	msgctl(container->msg, IPC_RMID, NULL);
	free(container->player->moves);
	free(container->player->dir);
	free(container->player);
}
