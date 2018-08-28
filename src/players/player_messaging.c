/*
** EPITECH PROJECT, 2018
** messaging class
** File description:
** messages
*/

# include "project.h"

bool load_messages(container_t *container)
{
	container->msg = msgget(container->key, SHM_R | SHM_W);
	return container->msg < 0 ? false : true;
}

void create_messages(container_t *container)
{
	container->msg = msgget(container->key, IPC_CREAT | SHM_R | SHM_W);
	if (container->msg < 0)
		exit_error("sem");
}

void send_message(container_t *container, player_t _enemy)
{
	m_lock(container);
	serialize_message(container, _enemy);
	msgsnd(container->msg, &container->msg_manager,
			sizeof(container->msg_manager), IPC_NOWAIT);
	m_unlock(container);
}

bool receive_message(container_t *container)
{
	bool a = false;

	m_lock(container);
	a = msgrcv(container->msg, &container->msg_manager,
				sizeof(container->msg_manager),
					container->player->color, IPC_NOWAIT);
	m_unlock(container);
	return a;
}
