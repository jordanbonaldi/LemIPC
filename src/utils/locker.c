/*
** EPITECH PROJECT, 2018
** locker
** File description:
** locker
*/

# include "project.h"

void m_lock(container_t const *container)
{
	struct sembuf locker = {
		.sem_num = 0,
		.sem_flg = 0,
		.sem_op = -1
	};

	semop(container->shared_memory, &locker, NSEMS);
}

void m_unlock(container_t const *container)
{
	struct sembuf locker = {
		.sem_num = 0,
		.sem_flg = 0,
		.sem_op = +1
	};

	semop(container->shared_memory, &locker, NSEMS);
}
