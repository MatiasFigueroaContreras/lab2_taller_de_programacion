#include "BinPackingSolver.h"

int main()
{
    BinPackingSolver *bps = new BinPackingSolver();
    std::vector<int> elements = bps->generateElements(50, 7);
    std::vector<int>::iterator itr;
    for (itr = elements.begin(); itr != elements.end(); itr++)
    {
        std::cout << *itr << " ";
    }
    std::cout << std::endl;

    std::cout << bps->solve(elements, 7) << std::endl;

    std::vector<int> elements2 {1, 6, 1, 6, 1, 6, 1, 6, 2, 2, 3, 2, 2, 3, 2, 5, 2, 5, 2, 5, 2, 5, 2, 5, 3, 3, 3, 4, 3, 4, 3, 4, 3, 4, 3, 4, 3, 4, 3, 4, 6, 6, 7, 7, 7, 7};
    std::cout << bps->solve(elements2, 7) << std::endl;

    delete bps;
}
