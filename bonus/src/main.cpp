/*
** EPITECH PROJECT, 2018
** Implementation
** File description:
** main
*/

#include "Map.hpp"
#include "LibOpenGL.hpp"

int main(const int argc, char const * const * argv)
{
	Map *m;
	if (argc < 2)
		return 84;
	m = new Map(argv[1]);

	LibOpenGL libOpenGL;
	libOpenGL.init();
	while (1)
	{
		libOpenGL.setMap(m->get_map());
		libOpenGL.display();
		if (libOpenGL.getEvents())
			break;
	}
	return 0;
}
