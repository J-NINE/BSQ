#include "stdbsq.h"

void print_error()
{
	printf("Error\n");
}

void print_map(t_map *map)
{
  int i;

  i = -1;
  while (++i < map->row)
    printf("%s\n", map->arr[i]);
  printf("row: %d, col: %d\n", map->row, map->col);
  printf("empty: %c\n", map->setting[0]);
  printf("barrier: %c\n", map->setting[1]);
  printf("box: %c\n", map->setting[2]);
}

void ultimate_printer(t_map *map, t_box *box)
{
	return ;
}