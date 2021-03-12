#ifndef bsq_struct_h 
# define bsq_struct_h

#include <stdio.h>
#include <unistd.h>

typedef struct bsq_solution
{
	int row;
	int col;
	int length;
}	t_box;

typedef struct bsq_map
{
	//char empty;
	//char barrier;
	//char box;
	char setting[4];
	int row;
	int col; 
	char** arr;
}	t_map;
#endif 