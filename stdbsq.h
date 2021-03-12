#ifndef stdbsq_h
# define stdbsq_h

//#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#include "bsq_struct.h"

int	is_valid_char(char *setting, char c);
int map_maker(int fd, t_map *map);
int	put_mapsetting(t_map *map, char* temp);
void free_map(t_map* map);

void print_error();
void ultimate_printer(t_map *map, t_box *box);

#endif // !stdbsq.h

