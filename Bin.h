#include <iostream>
#include <vector>
#include <iterator>

class Bin
{
private:
	int weight;
	int maxWeight;
	int numValue;
	std::vector<int> items;
public:
	Bin(int maxWeight);
	~Bin();
	bool insert(int item);
	bool equals(Bin *set);
	void print();
};