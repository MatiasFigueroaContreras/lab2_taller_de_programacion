#include "Bin.h"
#include <vector>
#include <map>
#include <algorithm>

class BinPackage
{
private:
	std::vector<Bin*> bins;
	std::multiset<std::string> binsOrdered;

public:
	int length;
	int capacity;
	BinPackage(int length, int capacity);
	~BinPackage();
	bool insert(int element, int index);
	void insertBin();
	long int getBinsValue();
	bool equals(BinPackage *binPackage);
	BinPackage *copy();
	std::string toString();
	void print();
};
