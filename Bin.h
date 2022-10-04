#include <iostream>
#include <vector>
#include <iterator>

class Bin
{
private:
	int weight;
	int capacity;
	int numValue;
	std::vector<int> items;

public:
	Bin(int capacity);
	~Bin();
	bool insert(int item);
	int getValue();
	bool equals(Bin *bin);
	void print();
	
};