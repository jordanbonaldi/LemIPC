/*
** EPITECH PROJECT, 2018
** LibSFMLWithOpenGL
** File description:
** Declaration of LibSFMLWithOpenGL
*/

#ifndef NANOTEKSPICE_LIBSFMLWITHOPENGL_HPP
	#define NANOTEKSPICE_LIBSFMLWITHOPENGL_HPP

#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <string>
#include <vector>
#include "OpenGLCube.hpp"
#include "OpenGLSquare.hpp"

class LibOpenGL
{
public:
	LibOpenGL();
	~LibOpenGL();
	void setMap(const std::vector<std::string> &v);
	void init();
	void stop();
	void display();
	bool getEvents();
	void displayMap();
private:
	SDL_Event event;
	OpenGLCube mapCube;
	OpenGLSquare sol;
	int cameraPos[3];
	std::vector<std::string> map;
};

#endif //NANOTEKSPICE_LIBSFMLWITHOPENGL_HPP
