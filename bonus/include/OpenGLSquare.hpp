/*
** EPITECH PROJECT, 2018
** OpenGLSquare
** File description:
** Declaration of OpenGLSquare
*/

#ifndef NANOTEKSPICE_OPENGLSQUARE_HPP
	#define NANOTEKSPICE_OPENGLSQUARE_HPP

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <string>
#include "OpenGLImage.hpp"

class OpenGLSquare
{
public:
	OpenGLSquare();
	void display(int size, int x, int y, int z);
	void setTexture(const char *filename);
private:
	GLuint texture;
};

#endif //NANOTEKSPICE_OPENGLSQUARE_HPP
