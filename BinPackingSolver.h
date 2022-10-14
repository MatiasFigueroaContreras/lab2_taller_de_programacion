#include "BinPackage.h"
#include <utility>

class BinPackingSolver
{
private:
	int upperBound(std::vector<int> elements, int capacity);
	int lowerBound(std::vector<int>  elements, int capacity);
	void deleteBinPackagesGenerated(std::unordered_map<std::string, BinPackage *> binPackages);

public:
	BinPackingSolver();
	~BinPackingSolver();
	int solve(std::vector<int>, int capacity);
	bool hasSolution(std::vector<int>, int capacity, int numBins);
	std::vector<int> generateElements(int numElements, int capacity);
};