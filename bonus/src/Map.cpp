/*
** EPITECH PROJECT, 2018
** map
** File description:
** Implementation of map
*/

#include "Map.hpp"

Map::Map(std::string const &path)
{
	this->path = path;
	this->init_keys();
	if (!this->init_sharedmemory())
		this->create_map();
	else
		this->init_map();
}

void Map::resetMap()
{
	memset(this->map, 0, WIDTH * HEIGHT * sizeof(short *));
}

int Map::get_shared() const
{
	return this->shared_mem;
}

std::vector<std::string> Map::get_map() const
{
	std::vector<std::string> vec;
	std::string tmp;

	for (size_t i = 0; i < HEIGHT; i++)
	{
		tmp = "";
		for (size_t j = 0; j < WIDTH; j++) {
			tmp += 48 + this->map[i * WIDTH + j];
		}
		vec.push_back(tmp);
	}
	return vec;
}

void Map::init_keys()
{
	this->key = ftok(this->path.c_str(), 0);
	if (this->key < 0)
		exit(81);
}

bool Map::init_sharedmemory()
{
	this->shared_mem = shmget(this->key, WIDTH * HEIGHT * sizeof(short *), SHM_R | SHM_W);
	return !(this->shared_mem < 0);
}

void Map::init_map()
{
	this->ptrs = (shared_ptrs_t *)shmat(this->shared_mem, 0, SHM_R | SHM_W);
	if (this->ptrs == (void *) -1)
		exit(82);
	this->map = (short *)(&(this->ptrs->map));
}

void Map::create_map()
{
	this->shared_mem = shmget(this->key, WIDTH * HEIGHT * sizeof(short *), IPC_CREAT | SHM_R | SHM_W);
	if (this->shared_mem < 0)
		exit(83);
	this->init_map();
	this->resetMap();
}

Map::~Map()
{

}
