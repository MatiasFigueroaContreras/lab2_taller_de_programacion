#include "BinPackingSolver.h"

int main()
{
    BinPackingSolver *bps = new BinPackingSolver();
    std::vector<int> elements = bps->generateElements(50, 20);
    std::vector<int>::iterator itr;
    for (itr = elements.begin(); itr != elements.end(); itr++)
    {
        std::cout << *itr << " ";
    }
    std::cout << std::endl;

    std::cout << bps->solve(elements, 20) << std::endl;

    delete bps;
}