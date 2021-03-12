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

	//같은 문자 두개면 return 0;
	i = -1;
	while (++i < 4)
	{
		j = i;
		while (++j < 4)
		{
			if(temp[i] == temp[j])
				return (0);
		}
	}
	printf("!!");
	//일단 넣어놓고 봐도 되나?
	map->row = temp[0] - '0';
	map->setting[0] = temp[1];
	map->setting[1] = temp[2];
	map->setting[2] = temp[3];
printf("%d%c%c%c", map->row, map->setting[0], map->setting[1], map->setting[2]);
	return (1);	
}


int map_maker(int fd, t_map *map)
{
	char *buf;
	char temp[4];
	int rd_size;
	int index;
	
	buf = malloc(sizeof(char) * 8124);
	index = 0;
	while ((rd_size = read(fd, buf, 1)))
	{
		if (index < 4)
		{
			temp[index] = buf[0];
			if (index == 4)
				if (!put_mapsetting(map, temp))
					return (0);
		}
		//printf("%c", buf[0]);
		index++;
	}
	//printf("%d%c%c%c", map->row, map->setting[0], map->setting[1], map->setting[2]);
	free(buf);
	return 1;
}

