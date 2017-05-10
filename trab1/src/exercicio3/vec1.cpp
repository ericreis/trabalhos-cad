#include <iostream>		
#include <random>
using namespace std;


const long SIZE        = 75000;
long arrayA[SIZE];
long arrayB[SIZE];

int main ()
{
	// Setup
	for (long i = 0; i < SIZE; i++)
	{
		arrayA[i] = rand() % 5000;
		arrayB[i] = rand() % 5000;
	}

	/****************** Normal, unit stride loop ******************/
	cout << "Normal Unit Stride Loop: \n";
	for (long i = 0; i < SIZE; i++)
	{
		arrayA[i] = i + 15;
	}
	cout << " --- DONE --- \n\n";

	/************* Not vectorizable due to dependency *************/
	cout << "Dependency loop: \n";
	for (long i = 1; i < SIZE - 1; i++)
	{
		arrayB[i] = 5 + arrayB[i - 1];

	}
	cout << " --- DONE --- \n\n";

	/********************** Constant stride ***********************/
	cout << "Constant Stride Loop: \n";
	for (long i = 0; i < SIZE; i += 2)
	{
		arrayB[i] = 2 + i;

	}
	cout << " --- DONE --- \n\n";

	/********************** Non-unit stride ***********************/
	cout << "Non-unit Stride Loop: \n";
	for (long i = 0; i < SIZE; i += (i > 10000)? 1 : 50)
	{
		arrayA[i] = i;
	}
	cout << " --- DONE --- \n\n";

	return EXIT_SUCCESS;
}
