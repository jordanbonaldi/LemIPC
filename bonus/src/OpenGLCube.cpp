/*
** EPITECH PROJECT, 20size8
** OpenGLCube
** File description:
** Implementation of OpenGLCube
*/

#include "OpenGLCube.hpp"

OpenGLCube::OpenGLCube()
{
}

void OpenGLCube::display(int size, int x, int y, int z, int r, int g, int b)
{
	glBegin(GL_QUADS);
	glColor3ub(r,g,b);

	glVertex3d(size + x, size + y, size + z);
	glVertex3d(size + x, size + y, -size + z);
	glVertex3d(-size + x, size + y, -size + z);
	glVertex3d(-size + x, size + y, size + z);

	glVertex3d(size + x, -size + y, size + z);
	glVertex3d(size + x, -size + y, -size + z);
	glVertex3d(size + x, size + y, -size + z);
	glVertex3d(size + x, size + y, size + z);

	glVertex3d(-size + x, -size + y, size + z);
	glVertex3d(-size + x, -size + y, -size + z);
	glVertex3d(size + x, -size + y, -size + z);
	glVertex3d(size + x, -size + y, size + z);

	glVertex3d(-size + x, size + y, size + z);
	glVertex3d(-size + x, size + y, -size + z);
	glVertex3d(-size + x, -size + y, -size + z);
	glVertex3d(-size + x, -size + y, size + z);

	glVertex3d(size + x, size + y, -size + z);
	glVertex3d(size + x, -size + y, -size + z);
	glVertex3d(-size + x, -size + y, -size + z);
	glVertex3d(-size + x, size + y, -size + z);

	glVertex3d(size + x,-size + y,size + z);
	glVertex3d(size + x,size + y,size + z);
	glVertex3d(-size + x,size + y,size + z);
	glVertex3d(-size + x,-size + y,size + z);

	glEnd();
}

void OpenGLCube::setTexture(const char *filename)
{
	texture = OpenGLImage::loadImage(std::string(filename));
}
