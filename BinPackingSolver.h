#include "SetW.h"

class BinPackingSolver
{
public:
	BinPackingSolver();
	~BinPackingSolver();
	int solve(std::vector elements, int capacity);
	std::vector generateElements(int num);
	int upperLimit(std::vector elements, int capacity);
	int lowerLimit(std::vector elements, int capacity);
	
};