/*
** EPITECH PROJECT, 2018
** PROJECT
** File description:
** project
*/

#ifndef HH_PROJECT
	#define HH_PROJECT

# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <time.h>
# include <sys/ipc.h>
# include <sys/msg.h>
# include <sys/sem.h>
# include <sys/shm.h>
# include <stdbool.h>
# include <unistd.h>
# include <errno.h>
# include <signal.h>

# define _GNU_SOURCE

# define LAMBDA(c_) ({ c_ _;})
# define WAITING_GAME 500000
# define WIDTH 50
# define HEIGHT 50
# define TOTAL ((WIDTH * HEIGHT * sizeof(short *)))
# define NSEMS 1

# define FAKE_PLAYER(X, Y) (player_t) { \
				.x = X, \
				.y = Y \
			}

# define CHECK_EAST FAKE_PLAYER(container->player->x, container->player->y + 1)
# define CHECK_WEST FAKE_PLAYER(container->player->x, container->player->y - 1)
# define CHECK_NORTH FAKE_PLAYER(container->player->x + 1, container->player->y)
# define CHECK_SOUTH FAKE_PLAYER(container->player->x - 1, container->player->y)

# define GETTER(P) (xetter_t) { \
		.map = container->map, \
		.container = container, \
		.player = P, \
		.value = 0 \
	}

# define SETTER(X) (xetter_t) {  \
		.map = container->map, \
		.container = container, \
		.player = *container->player, \
		.value = X \
	}

# define SETTER_P(X, P) (xetter_t) {  \
		.map = container->map, \
		.container = container, \
		.player = P, \
		.value = X \
	}

# define POSEDMAP map_getter(GETTER(*container->player)).exists
# define PLAYERS count_player(container)

typedef enum color_e
{
	RED = 1,
	YELLOW = 2,
	GREEN = 3,
	BLUE = 4,
	SPECTATOR = 0
} color_t;

typedef enum dir_e
{
	NORTH = 0,
	EAST = 1,
	WEST = 2,
	SOUTH = 3,
	NONE = -1
} dir_t;

typedef struct msg_s
{
	long mtype;
	char mtext[12];
} msg_t;

typedef struct args_s
{
	char const *path;
	int team_number;
} args_t;

typedef struct shared_pointers
{
	short *map;
} shared_pointers_t;

typedef struct player_s
{
	short x;
	short y;
	color_t color;
	bool exists;
	struct moves_s *moves;
	struct direction_s *dir;
	dir_t direction;
} player_t;

typedef struct battle_s
{
	short count;
} battle_t;

typedef struct container_s
{
	shared_pointers_t *pointers;
	args_t args;
	key_t key;
	int shared_memory;
	int semaphore;
	int control_op_semaphore;
	int msg;
	short *map;
	player_t *player;
	short players_online;
	battle_t battle;
	msg_t msg_manager;
	bool first;
} container_t;

typedef struct direction_s
{
	bool (*moves)(container_t *container);
	dir_t dir;
} direction_t;

typedef struct moves_s
{
	void (*random)(container_t *);
	bool (*finder)(container_t *);
} moves_t;

typedef struct xetter_s
{
	short *map;
	const container_t *container;
	const player_t player;
	const short value;
} xetter_t;

int count_teams(container_t *container,
		int (*counter)(container_t *container, color_t color));
bool is_one_team(container_t *container);
color_t get_winner_team(container_t *container);
void build_map(container_t *container);
void try_move_to(container_t *container, player_t _enemy);
player_t send_nearest_position(container_t *container);
bool receive_good_pos(container_t *container);
void send_message(container_t *container, player_t _enemy);
player_t deserialize_message(container_t *container);
bool receive_message(container_t *container);
void serialize_message(container_t *container, player_t _enemy);
int count_player_by_team(container_t *container, color_t team);
void clear_players_memory(container_t *container);
bool move_north(container_t *container);
bool move_south(container_t *container);
bool move_east(container_t *container);
bool move_west(container_t *container);
bool can_move_here(container_t const *container, player_t _fake);
bool action(container_t *container,
		player_t (*_fake)(container_t *container),
		void (*func)(player_t *player));
void path_to_enemy(container_t *container);
void choose_direction(container_t *container);
void init_moves_possibility(container_t *container);
void random_moves(container_t *container);
bool find_enemy(container_t *container);
bool handle_fight(container_t *container);
void kill_player(container_t *container);
player_t map_getter(xetter_t setter);
int map_setter(xetter_t setter);
void init_game(container_t *container);
bool exit_error(char *error);
void init_map(container_t *container);
void fill_map(container_t *container);
bool load_map(container_t *container);
void get_map(container_t *container);
void create_map(container_t *container);
void displayer(container_t *container);
void init_player(container_t *container);
void place_player(container_t *container);
bool load_player(container_t *container);
void get_player(container_t *container, int num, bool sems);
void create_player(container_t *container);
void m_lock(container_t const *container);
void m_unlock(container_t const *container);
void change_player_coordinates(player_t *player);
int count_player(container_t *container);
bool custom_errors(char *error);
bool load_messages(container_t *container);
void create_messages(container_t *container);

#endif
