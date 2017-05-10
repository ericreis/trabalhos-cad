#include <iostream>			// See Legal Information at the bottom of the file.
#include <random>
using namespace std;


#define TYPE float
const int REPEAT = 4000;
const int HEIGHT =  100;
const int WIDTH  = 35001;

const int PADDED_WIDTH = WIDTH;


void setup (TYPE ** table);

int main ()
{

  int x,i,j;

  TYPE *mem;
	TYPE **table;

	mem    = (TYPE*) _mm_malloc (HEIGHT*PADDED_WIDTH*sizeof(TYPE), 16);
	table  = (TYPE**) malloc (HEIGHT*sizeof(TYPE*));

	for(i =0; i < HEIGHT; i++)
		table[i] = &mem[i*HEIGHT];

	setup(table);

	for (x = 0; x < REPEAT; x++)	// Extend runtime by repeating entire array.
	{

		for (i = 0; i < HEIGHT; i++)
		{

			#pragma vector aligned
			for (j = 0; j < PADDED_WIDTH; j++)
			{
				table[i][j] = (table[i][j] / 5.3f) * (table[i][j]  * table[i][j] + table[i][j]) - (12.5f / (table[i][j] + 0.3f))
											+ (table[i][j] / (14.3f / (table[i][j] + 1.4f))) - (table[i][j] / 23.0f) + (14.8f / (2.4f + table[i][j]))
											- ((table[i][j] * (3.4f / (1.2f + table[i][j]))) / (4.5f + table[i][j] - (3.4f / (table[i][j] + 1.2f))));
			}
		}
	}


	free(table);
	_mm_free(mem);

	return EXIT_SUCCESS;
}

void setup (TYPE **table)
{
	#pragma ivdep
	for (int h = 0; h < HEIGHT; h++)
	{
		#pragma ivdep
		for (int w = 0; w < WIDTH; w++)
		{
			table[h][w] = rand() % 10000 / 3;
		}
		#pragma ivdep
		for (int w = WIDTH; w < PADDED_WIDTH; w++)
		{
			table[h][w] = 0;
		}
	}
}
