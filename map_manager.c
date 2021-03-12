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
  //0-3까지 돌고, 
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
  int i;
	
	buf = malloc(sizeof(char) * 8124);
	index = -1;

  //Setting
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

  //put actual map to buf
  while (read(fd, buf, 8124) > 0)
  {
    index++;
  }
  //printf("\n%s\n", buf);

  //parse buf to map->**arr
  map->arr = ft_split(buf, '\n');
  if (map->arr == NULL)
    return (0);
  //printf("%s\n", map->arr[0]);
  i = 0;
  while (++i < map->row)
    printf("%s\n", map->arr[i]);
	free(buf);
	return 1;
}

