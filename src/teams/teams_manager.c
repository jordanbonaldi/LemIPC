/*
** EPITECH PROJECT, 2018
** team manager class
** File description:
** managing team
*/

# include "project.h"

int count_teams(container_t *container,
		int (*counter)(container_t *container, color_t color))
{
	short teams_number = 0;

	for (size_t i = 1; i < 5; i++)
		teams_number += counter(container, i) > 0 ? 1 : 0;
	return teams_number;
}
bool is_one_team(container_t *container)
{
	return count_teams(container, count_player_by_team) == 1;
}

color_t get_winner_team(container_t *container)
{
	for (size_t i = 0; i < WIDTH; i++)
		for (size_t j = 0; j < HEIGHT; j++)
			if (container->map[i * WIDTH + j] != 0)
				return container->map[i * WIDTH + j];
	return SPECTATOR;
}

int count_player_by_team(container_t *container, color_t team)
{
	short c = 0;

	for (size_t i = 0; i < WIDTH; i++)
		for (size_t j = 0; j < HEIGHT; j++)
			if (container->map[i * WIDTH + j] != 0 &&
				container->map[i * WIDTH + j] == (short)team)
				c++;
	return c;
}
