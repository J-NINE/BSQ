#include "stdbsq.h"

void bsq_starter(char *file)
{
	int fd;
	t_map *map;
     // 파일열기
	map = malloc(sizeof(t_map*));
    if((fd = open(file, O_RDONLY)) < 0){
       print_error();
       exit(1);
	}
	if (!map_maker(fd, map))
	{
		print_error();
		exit(1);
	}
  
	//solution(map) here
	close(fd);
	//free_map(map);
}

int		main(int argc, char **argv){
	int i;
	
	if (argc <= 1)
	{
		print_error();
		return (0);
	}
	i = 0;
	while (++i < argc)
		bsq_starter(argv[i]);
	return (0);
}
