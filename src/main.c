/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

# include "project.h"

int main(int const argc, char const * const * argv)
{
	container_t container;

	if (argc < 3)
		return 84;
	container.args.path = argv[1];
	container.args.team_number = atoi(argv[2]);
	if (container.args.team_number <= SPECTATOR
			|| container.args.team_number > BLUE)
		custom_errors("Team color doesn't exists !");
	init_game(&container);
	return 0;
}
