#include <iostream>
#include <map>
#include <vector>
#include <iterator>

int main()
{
    std::multimap<int, int> myMap;
    std::multimap<int, int>::iterator itr1;
    std::multimap<int, int>::iterator itrMain;

    std::vector<std::multimap<int, int>::iterator> itrs;
    


    itr1 = myMap.emplace(1, 1);
    itrs.push_back(itr1);
    itr1 = myMap.emplace(4, 4);
    itrs.push_back(itr1);
    myMap.emplace(2, 20);
    myMap.emplace(5, 5);
    myMap.emplace(6, 6);
    
    for(int i = 0; i < itrs.size(); i++)
    {
        std::cout << itrs[i]->first << " -> " << itrs[i]->second << " | ";
    }
    std::cout << std::endl;

    std::cout << itr1->first << " -> " << itr1->second << std::endl;

    for (itrMain = myMap.begin(); itrMain != myMap.end(); itrMain++)
    {
        std::cout << itrMain->first << " -> " << itrMain->second << " | ";
    }
    std::cout << std::endl;

    auto x = myMap.extract(2);

    std::cout << x.key() << " -> " << x.mapped() << std::endl;

    for (itrMain = myMap.begin(); itrMain != myMap.end(); itrMain++)
    {
        std::cout << itrMain->first << " -> " << itrMain->second << " | ";
    }
    std::cout << std::endl;

    std::cout << itr1->first << " -> " << itr1->second << std::endl;

}