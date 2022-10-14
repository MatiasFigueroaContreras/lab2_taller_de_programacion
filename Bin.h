#include <iostream>
#include <string>
#include <set>
#include <iterator>

class Bin
{
private:
	int weight;
	int capacity;
	std::multiset<int> items;

public:
	Bin(int capacity);
	~Bin();
	bool insert(int item);
	long int getValue();
	bool equals(Bin *bin);
	Bin *copy();
	std::string toString();
	void print();
	
};