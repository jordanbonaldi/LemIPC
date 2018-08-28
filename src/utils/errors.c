/*
** EPITECH PROJECT, 2018
** errors
** File description:
** errors
*/

# include "project.h"

bool exit_error(char *error)
{
	perror(error);
	exit(84);
	return false;
}

bool custom_errors(char *error)
{
	printf("%s\n", error);
	exit(84);
}
