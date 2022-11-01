#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <map>
#include <algorithm>

class BinPackage
{
private:
    std::vector<int> bins;
    std::multiset<int> binsOrdered;

public:
    int length;
    int capacity;
    BinPackage(int length, int capacity);
    ~BinPackage();
    bool insert(int element, int index);
    void insertBin();
    std::string getValue();
    BinPackage *copy();
    std::string toString();
    void print();

};
