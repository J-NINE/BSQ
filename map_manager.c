#include "stdbsq.h"

int	is_valid_char(char *setting, char c)
{
	int i;
	int flag;
	flag = 2;
	i = -1;
	while (setting[++i])
		if (setting[i] != c){
			flag--;
		}
	return flag;
}

int is_map_valid(t_map *map)
{
  int i; 

  i = -1;
  while (++i < map->row)
  {

  }

  //모든 글자가 setting에 있는 애인지 검사
  //각 row의 크기가 같고, 전체 row수가 map->row 와 같은지
  return (1);
}

void free_map(t_map *map)
{
	int i;

	i = -1;
	while (++i < map->row)
		free(map->arr[i]);
	free(map->arr);
	free(map);
}


int	put_mapsetting(t_map *map, char* temp)
{
  int i;
  int j;

  i = -1;
  while (++i < 4 && temp[i] <= 126 && temp [i] >= 32)
  {
    j = i;
    while (++j < 4)
    {
      if (temp[i] == temp[j])
        return (0);
    }
  }
  map->row = temp[0] - '0';
  map->setting[0] = temp[1];
  map->setting[1] = temp[2];
  map->setting[2] = temp[3];
  
  printf("Map Settings: %d%c%c%c\n", map->row, map->setting[0], map->setting[1], map->setting[2]);
	return (1);	
}

int map_maker(int fd, t_map *map)
{
	char *buf;
	char temp[4];
	int index;
	
  buf = malloc(sizeof(char) * 8124);
	index = -1;
  while ((read(fd, buf, 1) > 0) && (++index < 4))
	{
		if (index < 4)
		{
			temp[index] = buf[0];
			if (index == 3)
      {
				if (!put_mapsetting(map, temp))
					return (0);
      }
		}
	}
  while (read(fd, buf, 8124) > 0)
    index++;
  map->arr = ft_split(buf, '\n', map);
  if (map->arr == NULL)
    return (0);
  if (!is_map_valid(map))
    return (0);
  int i = -1;
  while (++i < map->row)
    printf("%s\n", map->arr[i]);
  printf("row: %d\n", map->row);
  printf("empty: %c\n", map->setting[0]);
  printf("barrier: %c\n", map->setting[1]);
  printf("box: %c\n", map->setting[2]);
  free(buf);
	return 1;
}