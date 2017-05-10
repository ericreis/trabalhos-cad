#include <iostream>			// See Legal Information at the bottom of the file.
#include <random>
using namespace std;


#define TYPE float
const int CALL_COUNT = 1000000;
const int WIDTH = 35;

const int PADDED_WIDTH = WIDTH;

void setup (TYPE *table);

int main ()
{

	TYPE *table;

	table = (TYPE*)malloc(PADDED_WIDTH*sizeof(TYPE));


	setup(table);

	for (int x = 0; x < CALL_COUNT; x++)
	{

		for (int j = 0; j < PADDED_WIDTH; j++)
		{
			table[j] = (table[j] / 5.3f) * (table[j]  * table[j] + table[j]) - (12.5f / (table[j] + 0.3f))
								 + (table[j] / (14.3f / (table[j] + 1.4f))) - (table[j] / 23.0f) + (14.8f / (2.4f + table[j]));
		}
	}

  free(table);
	return EXIT_SUCCESS;
}

void setup (TYPE *table)
{
	for (int w = 0; w < WIDTH; w++)
	{
		table[w] = rand() % 10000 / 3;
	}

}
