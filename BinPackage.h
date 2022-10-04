#include "Bin.h"

class BinPackage
{
private:
	std::vector<Bin> bins;
	int length;

public:
	BinPackage(int length, int capacity);
	~BinPackage();
	bool insert(int element, int index);
	int getBinsValue();
	bool equals(BinPackage *binPackage);
	void print();
};
