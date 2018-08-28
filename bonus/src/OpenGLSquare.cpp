/*
** EPITECH PROJECT, 2018
** OpenGLSquare
** File description:
** Implementation of OpenGLSquare
*/

#include "OpenGLSquare.hpp"

OpenGLSquare::OpenGLSquare()
{

}

void OpenGLSquare::display(int size, int x, int y, int z)
{
	glBegin(GL_QUADS);
	glColor3ub(255,255,255);
	glTexCoord2d(0,1); glVertex3d(size + x, size + y, -size + z);
	glTexCoord2d(0,0); glVertex3d(size + x, -size + y, -size + z);
	glTexCoord2d(1,0); glVertex3d(-size + x, -size + y, -size + z);
	glTexCoord2d(1,1); glVertex3d(-size + x, size + y, -size + z);
	glEnd();
}

void OpenGLSquare::setTexture(const char *filename)
{
	texture = OpenGLImage::loadImage(std::string(filename));
}
