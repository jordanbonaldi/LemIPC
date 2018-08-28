/*
** EPITECH PROJECT, 2018
** message srz
** File description:
** serializer and deserialize
*/

# include "project.h"

void serialize_message(container_t *container, player_t _enemy)
{
	container->msg_manager.mtype = _enemy.color;
	sprintf(container->msg_manager.mtext, "x:%d y:%d", _enemy.x, _enemy.y);
}

player_t deserialize_message(container_t *container)
{
	char *msg = container->msg_manager.mtext;
	player_t fakep;

	if (!msg)
		return (player_t){ .exists = false };
	msg += 2;
	fakep.x = atoi(msg);
	while (*msg != ' ')
		msg++;
	msg += 3;
	fakep.y = atoi(msg);
	fakep.color = container->msg_manager.mtype;
	return fakep;
}
