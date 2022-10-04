#include "BinPackage.h"

class BinPackingSolver
{
public:
	BinPackingSolver();
	~BinPackingSolver();
	int solve(std::vector<int> elements, int capacity);
	std::vector<int> generateElements(int numElements, int capacity);

private:
	int upperLimit(std::vector<int> elements, int capacity);
	int lowerLimit(std::vector<int> elements, int capacity);
};