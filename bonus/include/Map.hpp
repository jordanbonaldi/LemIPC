/*
** EPITECH PROJECT, 2018
** map
** File description:
** Declaration of map
*/

#ifndef map_HPP
	#define map_HPP

#include <stdio.h>
#include <iostream>

#include <string.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <unistd.h>
#include <vector>

# define WIDTH 50
# define HEIGHT 50

typedef enum color_e
{
	RED = 1,
	YELLOW = 2,
	GREEN = 3,
	BLUE = 4,
	SPECTATOR = 0
} color_t;

typedef struct shared_ptrs_s
{
	short *map;
} shared_ptrs_t;

class Map {
public:
	Map(std::string const &);
	int get_shared() const;
	std::vector<std::string> get_map() const;
	~Map();
protected:
private:
	void init_keys();
	void resetMap();
	bool init_sharedmemory();
	void init_map();
	void create_map();
	int shared_mem;
	key_t key;
	short *map;
	shared_ptrs_t *ptrs;
	std::string path;
};

#endif /* map_HPP */
