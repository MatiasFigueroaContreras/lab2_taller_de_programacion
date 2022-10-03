#include "Bin.h"

Bin::Bin(int maxWeight)
{
	this->maxWeight = maxWeight;
	this->weight = 0;
}

Bin::~Bin()
{
}

bool Bin::insert(int item)
{
	if(maxWeight >= weight + item)
	{
		items.push_back(item);
		if(item == 1 || weight == 0)
		{
			numValue += item;
		}
		else
		{
			numValue *= item;
		}

		weight += item;
		return true;
	}

	return false;
}

void Bin::print()
{
	std::vector<int>::iterator itr;
	for(itr = items.begin(); itr != items.end(); itr++)
	{
		std::cout << *itr << " ";
	}
	std::cout << std::endl;
}

bool Bin::equals(Bin *bin)
{
	return bin->numValue == this->numValue;
}
