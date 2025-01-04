#include "Utils.h"
#include <cstdlib>
#include <time.h>
using namespace std;

int Utils::getRandomNumberInRange(int lowerBound, int upperBound)
{
	// Retrieve a random number between 'lowerBound' and 'upperBound'
	int random = lowerBound + (rand() % upperBound);

	return random;
}