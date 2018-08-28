/*
** EPITECH PROJECT, 2018
** OpenGLCube
** File description:
** Declaration of OpenGLCube
*/

#ifndef NANOTEKSPICE_OPENGLCUBE_HPP
	#define NANOTEKSPICE_OPENGLCUBE_HPP

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <string>
#include "OpenGLImage.hpp"

class OpenGLCube
{
public:
	OpenGLCube();
	void display(int size, int x, int y, int z, int r, int g, int b);
	void setTexture(const char *filename);
private:
	GLuint texture;
};

#endif //NANOTEKSPICE_OPENGLCUBE_HPP
