/*
** EPITECH PROJECT, 2018
** LibSFMLWithOpenGL
** File description:
** Implementation of LibSFMLWithOpenGL
*/

#include "LibOpenGL.hpp"

LibOpenGL::LibOpenGL()
{
}

LibOpenGL::~LibOpenGL()
{

}

void LibOpenGL::setMap(const std::vector<std::string> &v)
{
	map = v;
}

void LibOpenGL::init()
{
	SDL_Init(SDL_INIT_VIDEO);
	atexit(SDL_Quit);
	SDL_WM_SetCaption("SDL GL Application", nullptr);
	SDL_SetVideoMode(1600, 900, 32, SDL_OPENGL);

	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();
	gluPerspective(70,(double)1600/900,1,1000);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);

	cameraPos[0] = 30;
	cameraPos[1] = 0;
	cameraPos[2] = 50;
}

void LibOpenGL::stop()
{
	SDL_Quit();
}

void LibOpenGL::display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(cameraPos[0], cameraPos[1], cameraPos[2], 0, 0, 0, 0, 0, 1);
	displayMap();
	glFlush();
	SDL_GL_SwapBuffers();
}

bool LibOpenGL::getEvents()
{
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym)
				{
					case SDLK_ESCAPE:
						return true;
						break;
					case SDLK_PAGEUP:
						cameraPos[2] += 1;
						break;
					case SDLK_PAGEDOWN:
						cameraPos[2] -= 1;
						break;
					case SDLK_z:
						cameraPos[0] += 1;
						break;
					case SDLK_s:
						cameraPos[0] -= 1;
						break;
					case SDLK_q:
						cameraPos[1] += 1;
						break;
					case SDLK_d:
						cameraPos[1] -= 1;
						break;
					default:
						break;
				}
				break;
			case SDL_QUIT:
				return true;
				break;
			default:
				break;
		}
	}
	return false;
}

void LibOpenGL::displayMap()
{
	int r = 0;
	int g = 0;
	int b = 0;

	for (unsigned int i = 0; i < map.size(); ++i)
		for (unsigned int j = 0; j < map[i].size(); ++j)
		{
			switch (map[i][j]) {
				case '1':
					r = 255;
					g = 0;
					b = 0;
					break;
				case '2':
					r = 255;
					g = 255;
					b = 0;
					break;
				case '3':
					r = 0;
					g = 255;
					b = 0;
					break;
				case '4':
					r = 0;
					g = 0;
					b = 255;
					break;
				default:
					break;
			}
			if (map[i][j] >= '1')
			{
				mapCube.display(1, (i - map.size() / 2) * 2, (j - map[i].size() / 2) * 2, 0, r, g, b);
			}
			sol.display(1, (i - map.size() / 2) * 2, (j - map[i].size() / 2) * 2, 0);
		}
}
