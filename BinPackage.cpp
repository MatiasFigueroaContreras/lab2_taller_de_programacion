#include "BinPackage.h"

BinPackage::BinPackage(int length, int capacity)
{
	this->length = length;
	for(int i = 0; i < length; i++)
	{
		bins.push_back(Bin(capacity));
	}
}

bool BinPackage::insert(int element, int index)
{
	// return length 
}